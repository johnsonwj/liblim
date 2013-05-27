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
#include "yield_data.h"

using namespace std;

map<string,TH1F> hists;

void book_hists() {
    hists["h_vismass"] 
        = TH1F("h_vismass", ";Higgs Visible Mass (GeV);Counts", 75, 0, 150);

    hists["h_collim_old"] 
        = TH1F("h_collim_old", ";Higgs Collinear Mass (old method) (GeV);Counts", 75, 0, 150);

    hists["h_collim_new"] 
        = TH1F("h_collim_new", ";Higgs Collinear Mass (new method) (GeV);Counts", 75, 0, 150);

    int ncuts = LimTree::ncuts + 1; // +1 for including a bin for zero cuts

    hists["cutflow_full"] 
        = TH1F("cutflow_full", ";Cuts Passed;Counts", ncuts, 0, ncuts);

    hists["cutflow_sig_region"] 
        = TH1F("cutflow_sig_region", ";Cuts passed, 115 GeV < m_{H} < 135 GeV;Counts", ncuts, 0, ncuts);

    hists["yield_full"] 
        = TH1F("yield_full", ";Cuts Passed;Yield", ncuts, 0, ncuts);

    hists["yield_sig_region"] 
        = TH1F("yield_sig_region", ";Cuts Passed, 115 GeV < m_{H} < 135 GeV;Yield", ncuts, 0, ncuts);

    hists["h_pT"] 
        = TH1F("h_pT", ";Higgs p_{T} (GeV);Counts", 100, 0, 200);

    hists["h_eta"] 
        = TH1F("h_eta", ";Higgs #eta;Counts", 100, -4, 4);

    hists["lep_pt"]  
        = TH1F("lep_pt", ";Lepton p_{T} (GeV);Counts", 50, 0, 100);

    hists["lep_eta"] 
        = TH1F("lep_eta", ";Lepton #eta;Counts", 100, -4, 4);

    hists["lep_phi"] 
        = TH1F("lep_phi", ";Lepton #phi;Counts", 64, -3.2, 3.2);

    hists["tau_pt"] 
        =  TH1F("tau_pt",  ";Tau p_{T} (GeV);Counts", 50, 0, 100);

    hists["tau_eta"] 
        = TH1F("tau_eta", ";Tau #eta;Counts", 100, -4, 4);

    hists["tau_phi"] 
        = TH1F("tau_phi", ";Tau #phi;Counts", 64, -3.2, 3.2);
   
    hists["met"] 
        = TH1F("met", ";MET (GeV);Counts", 50, 0, 100);

    hists["dr_met_tau"] 
        = TH1F("dr_met_tau", ";#Delta R(MET, tau);Counts", 50, 0, 5);

    hists["dphi_met_tau"] 
        = TH1F("dphi_met_tau", ";#Delta#phi(MET, tau);Counts", 64, 0, 3.2);
}

int success;

void fill_hists(LimTree* lt, string out_filename) {
    unsigned nname_start = out_filename.find_last_of('/') + 1;
    string nname = out_filename.substr( nname_start, out_filename.size() - nname_start - 9 );

    float this_yield = yield[nname];
    int cf_result = lt->cutflow();

    for (float i = 0.5; i < (LimTree::ncuts - cf_result); i++) {
        hists["cutflow_full"].Fill(i);
        hists["yield_full"].Fill(i, this_yield);

        if (115 < lt->collim_mH_new() && lt->collim_mH_new() < 135) {
            hists["cutflow_sig_region"].Fill(i);
            hists["yield_sig_region"].Fill(i, this_yield);
        }
    }

    if ( contains(out_filename, "CT0") && cf_result > 0 ) return;

    success++;

    float weight = (lt->weight) * scale[nname];
//    cout << "  h_vismass " << lt->vis_mH() << " --- " << hists["h_vismass"].Integral() << endl;
    hists["h_vismass"].Fill(lt->vis_mH(), weight);
//    cout << "  h_vismass " << lt->vis_mH() << " --- " << hists["h_vismass"].Integral() << endl;
    hists["h_collim_old"].Fill(lt->collim_mH_old(), weight);
//    cout << "  h_collim_old " << lt->collim_mH_old() << " --- " << hists["h_collim_old"].Integral() << endl;
    hists["h_collim_new"].Fill(lt->collim_mH_new(), weight);
//    cout << "  h_collim_new " << lt->collim_mH_new() << " --- " << hists["h_collim_new"].Integral() << endl;

    TLorentzVector higgsp = lt->pTau + lt->pLep + lt->pMet;

    hists["h_pt"].Fill(higgsp.Pt(), weight);
//    cout << "  h_pt " << higgsp.Pt() << " --- " << hists["h_pt"].Integral() << endl;
    hists["h_eta"].Fill(higgsp.Eta(), weight);
//    cout << "  h_eta " << higgsp.Eta() << " --- " << hists["h_eta"].Integral() << endl;

    hists["lep_pt"].Fill(lt->pLep.Pt(), weight);
//    cout << "  lep_pt " << lt->pLep.Pt() << " --- " << hists["lep_pt"].Integral() << endl;
    hists["lep_eta"].Fill(lt->pLep.Eta(), weight);
//    cout << "  lep_eta " << lt->pLep.Eta() << " --- " << hists["lep_eta"].Integral() << endl;
    hists["lep_phi"].Fill(lt->pLep.Phi(), weight);
//    cout << "  lep_phi " << lt->pLep.Phi() << " --- " << hists["lep_phi"].Integral() << endl;

    hists["tau_pt"].Fill(lt->pTau.Pt(), weight);
//    cout << "  tau_pt " << lt->pTau.Pt() << " --- " << hists["tau_pt"].Integral() << endl;
    hists["tau_eta"].Fill(lt->pTau.Eta(), weight);
//    cout << "  tau_eta " << lt->pTau.Eta() << " --- " << hists["tau_eta"].Integral() << endl;
    hists["tau_phi"].Fill(lt->pTau.Phi(), weight);
//    cout << "  tau_phi " << lt->pTau.Phi() << " --- " << hists["tau_phi"].Integral() << endl;
   
    hists["met"].Fill(lt->pMet.Pt(), weight);
//    cout << "  met " << lt->pMet.Pt() << " --- " << hists["met"].Integral() << endl;
  
    hists["dr_met_tau"].Fill(lt->pMet.DeltaR(lt->pTau), weight);
//    cout << "  dr_met_tau " << lt->pMet.DeltaR(lt->pTau) << " --- " << hists["dr_met_tau"].Integral() << endl;
    hists["dphi_met_tau"].Fill(lt->pMet.DeltaPhi(lt->pTau), weight);
//    cout << "  dphi_met_tau " << lt->pMet.DeltaPhi(lt->pTau) << " --- " << hists["dphi_met_tau"].Integral() << endl;
}

void check_entry_number(long n) {
    if (n % 5000 == 0) cout << "At entry " << n << " successful " << success << endl;
}

void do_hists(DatasetIter di, int cut_tolerance) {
    success = 0;
    long total_cn_events = 0;
    
    cout << "STARTING " << di.get_output_filename() << endl;

    stringstream fn_stream;
    fn_stream << di.get_output_filename() << "_CT" << cut_tolerance << ".root";
    string out_filename = fn_stream.str();

    TFile* fout = new TFile(out_filename.data(), "recreate");

    book_hists();

    LimTree* limtree = di.get_limtree();

    while (limtree->load_next() >= 0) {
        fill_hists(limtree, out_filename);
        total_cn_events++;
        check_entry_number(total_cn_events);
    }

    fout->Write();
    fout->Close();
}

int main() {
    DatasetIter di;

//    while (di.next()) {
        di.next();
        do_hists(di, 0);
        do_hists(di, 4);
//    }

    return 0;
}
