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
#include "liblim.h"

using namespace std;

map<string,TH1F> hists;

void book_hists() {
    hists["h_vismass"] 
        = TH1F("h_vismass", ";Higgs Visible Mass (GeV);Counts", 75, 0, 150);

    hists["h_collim_old"] 
        = TH1F("h_collim_old", ";Higgs Collinear Mass (old method) (GeV);Counts", 75, 0, 150);

    hists["h_collim_new"] 
        = TH1F("h_collim_new", ";Higgs Collinear Mass (new method) (GeV);Counts", 75, 0, 150);

    int ncuts = LimTree::get_ncuts() + 1; // +1 for including a bin for zero cuts

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

int success = 0;

void fill_hists(LimTree* lt, string out_filename) {
    unsigned nname_start = out_filename.find_last_of('/') + 1;
    string nname = out_filename.substr( nname_start, out_filename.size() - nname_start - 9 );

    float this_yield = yield[nname];
    int cf_result = lt->cutflow();

    for (float i = 0.5, i < (LimTree::get_ncuts() - cf_result); i++) {
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
    hists["h_vismass"].Fill(limtree->visHiggsMass(), weight);
    hists["h_collim_old"].Fill(limtree->collinearMassOld(), weight);
    hists["h_collim_new"].Fill(limtree->collinearMassNew(), weight);

    TLorentzVector higgsp = limtree->pTau + limtree->pLep + limtree->pMet;

    hists["h_pt"].Fill(higgsp.Pt(), weight);
    hists["h_eta"].Fill(higgsp.Eta(), weight);

    hists["lep_pt"].Fill(limtree->pLep.Pt(), weight);
    hists["lep_eta"].Fill(limtree->pLep.Eta(), weight);
    hists["lep_phi"].Fill(limtree->pLep.Phi(), weight);

    hists["tau_pt"].Fill(limtree->pTau.Pt(), weight);
    hists["tau_eta"].Fill(limtree->pTau.Eta(), weight);
    hists["tau_phi"].Fill(limtree->pTau.Phi(), weight);
   
    hists["met"].Fill(limtree->pMet.Pt(), weight);
  
    hists["dr_met_tau"].Fill(limtree->pMet.DeltaR(limtree->pTau), weight);
    hists["dphi_met_tau"].Fill(limtree->pMet.DeltaPhi(limtree->pTau), weight);
}

void check_entry_number(long n) {
    if (n % 5000 == 0) cout << "At entry " < n << " successfull " << success << endl;
}

void do_hists(DatasetIter di, int cut_tolerance) {
    success = 0;
    long total_cn_events = 0;
    
    cout << "STARTING " << di.get_output_filename() << endl;

    stringstream fn_stream;
    fn_stream << di.get_output_filename() << "_CT" << cut_tolerance << ".root";
    string out_filename = fn_stream.str();

    book_hists();
    while (di.next()) {
        LimTree* limtree = di.get_limtree();

        while (limtree->load_next() >= 0) {
            fill_hists(limtree, out_filename);
            total_cn_events++;
            check_entry_number(total_cn_events);
        }
    }

    TFile* fout = new TFile(out_filename.data(), "recreate");
    fout->cd();

    for (std::map<string,TH1F>::iterator it = hists.begin(); it != hists.end(); ++it)
        (it->second).Write();

    fout->Close();
}

int main() {
    DatasetIter di;
    
    do_hists(di, 0);
    do_hists(di, 4);

    return 0;
}
