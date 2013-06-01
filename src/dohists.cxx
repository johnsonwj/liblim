/*
 * =====================================================================================
 *
 *       Filename:  dohists.cxx
 *
 *    Description:  Iterates over datasets given by DatasetIter and fills histograms
 *                  from data in a LimTree created for each dataset.
 *
 *        Version:  1.0
 *        Created:  05/25/2013 01:43:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include <TFile.h>
#include <TH1F.h>

#include "DatasetIter.h"
#include "LimTree.h"
#include "common.h"

using namespace std;

map<string,TH1F*> hists;

TFile* book_hists(string fname_base) {
    string fname = "hists/" + fname_base + ".root";

    TFile* fout = new TFile(fname.data(), "recreate");

    hists["h_vismass"] 
        = new TH1F("h_vismass",";Higgs Visible Mass (GeV);Counts", 20, 0, 300);

    hists["h_collim_old"] 
        = new TH1F("h_collim_old",";Higgs Collinear Mass (old method) (GeV);Counts", 24, 0, 360);

    hists["h_collim_new"] 
        = new TH1F("h_collim_new",";Higgs Collinear Mass (new method) (GeV);Counts", 24, 0, 360);

    int ncuts = LimTree::ncuts + 1; // +1 for including a bin for zero cuts

    hists["cutflow_full"] 
        = new TH1F("cutflow_full",";Cuts Passed;Counts", ncuts, 0, ncuts);

    hists["yield_full"] 
        = new TH1F("yield_full",";Cuts Passed;Yield", ncuts, 0, ncuts);

    hists["h_pt"] 
        = new TH1F("h_pt",";Higgs p_{T} (GeV);Counts", 100, 0, 200);

    hists["h_eta"] 
        = new TH1F("h_eta",";Higgs #eta;Counts", 100, -4, 4);

    hists["lep_pt"]  
        = new TH1F("lep_pt",";Lepton p_{T} (GeV);Counts", 50, 0, 100);

    hists["lep_eta"] 
        = new TH1F("lep_eta",";Lepton #eta;Counts", 100, -4, 4);

    hists["lep_phi"] 
        = new TH1F("lep_phi",";Lepton #phi;Counts", 64, -3.2, 3.2);

    hists["tau_pt"] 
        = new TH1F("tau_pt",";Tau p_{T} (GeV);Counts", 50, 0, 100);

    hists["tau_eta"] 
        = new TH1F("tau_eta",";Tau #eta;Counts", 100, -4, 4);

    hists["tau_phi"] 
        = new TH1F("tau_phi",";Tau #phi;Counts", 64, -3.2, 3.2);
   
    hists["met"] 
        = new TH1F("met",";MET (GeV);Counts", 50, 0, 100);

    hists["dr_met_tau"] 
        = new TH1F("dr_met_tau",";#Delta R(MET, tau);Counts", 50, 0, 5);

    hists["dphi_met_tau"] 
        = new TH1F("dphi_met_tau",";#Delta#phi(MET, tau);Counts", 64, 0, 3.2);

    gDirectory -> cd();

    return fout;
}

int success;

void fill_hists(LimTree* lt, int cut_tolerance) {
    int cf_result = lt->cutflow();

    for (float i = 0.5; i < (LimTree::ncuts + 1 - cf_result); i++) {
        hists["cutflow_full"]->Fill(i);
        hists["yield_full"]->Fill(i, lt->get_hist_scale());

//        if (115 < lt->collim_mH_new() && lt->collim_mH_new() < 135) {
//            hists["cutflow_sig_region"]->Fill(i);
//            hists["yield_sig_region"]->Fill(i, lt->get_hist_scale());
//        }
    }

    if ( cf_result > cut_tolerance ) return;

    success++;

    float weight = (lt->weight) * (lt->get_hist_scale());
    hists["h_vismass"]->Fill(lt->vis_mH(), weight);
    hists["h_collim_old"]->Fill(lt->collim_mH_old(), weight);
    hists["h_collim_new"]->Fill(lt->collim_mH_new(), weight);

    TLorentzVector higgsp = lt->pTau + lt->pLep + lt->pMet;

    hists["h_pt"]->Fill(higgsp.Pt(), weight);
    hists["h_eta"]->Fill(higgsp.Eta(), weight);

    hists["lep_pt"]->Fill(lt->pLep.Pt(), weight);
    hists["lep_eta"]->Fill(lt->pLep.Eta(), weight);
    hists["lep_phi"]->Fill(lt->pLep.Phi(), weight);

    hists["tau_pt"]->Fill(lt->pTau.Pt(), weight);
    hists["tau_eta"]->Fill(lt->pTau.Eta(), weight);
    hists["tau_phi"]->Fill(lt->pTau.Phi(), weight);
   
    hists["met"]->Fill(lt->pMet.Pt(), weight);
  
    hists["dr_met_tau"]->Fill(lt->pMet.DeltaR(lt->pTau), weight);
    hists["dphi_met_tau"]->Fill(lt->pMet.DeltaPhi(lt->pTau), weight);
}

void check_entry_number(long n) {
    if (n % 5000 == 0) cout << "At entry " << n << " successful " << success << endl;
}

void do_hists(string dataset_name, LimTree* lt, int cut_tolerance) {
    success = 0;
    long total_cn_events = 0;
    
    cout << "STARTING " << dataset_name << ", cut tolerance " << cut_tolerance << endl;

    stringstream sname_with_ct;
    sname_with_ct << dataset_name << "_CT" << cut_tolerance;
    string name_with_ct = sname_with_ct.str();

    TFile* fout = book_hists(name_with_ct);

    while (lt->load_next() >= 0) {
        fill_hists(lt, cut_tolerance);
        total_cn_events++;
        check_entry_number(total_cn_events);
    }

    fout->Write(); fout->Close();
}

int main() {
    DatasetIter di;
    LimTree* lt;

    while ( (lt = di.next()) ) {
        do_hists(di.get_dataset_name(), lt, 0);
        lt->reset();

        do_hists(di.get_dataset_name(), lt, 4);
        delete lt;
    }

    return 0;
}
