/*
 * =====================================================================================
 *
 *       Filename:  doHists.cxx
 *
 *    Description:  Creates a LimTree and iterates over it, producing histograms for
 *                  kinematics, cut flow, and mass distribution.
 *
 *        Version:  1.0
 *        Created:  04/30/2013 02:23:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <dirent.h>

#include <TFile.h>
#include <TH1F.h>
#include "DatasetIter.h"

#include "xsec_data.h"

using namespace std;

LimTree* limtree;

std::map<string,TH1F> hists;

const int NCUTS = 11;

void book_hists() {
    hists["hVisMass"] = TH1F("h_vismass", "Higgs Visible Mass;Mass (GeV);Counts/5GeV", 75, 0, 150);
    hists["hCollimMassOld"] = TH1F("h_collimOld", "Higgs Collinear Mass (old method);Mass (GeV);Counts/5GeV", 75, 0, 150);
    hists["hCollimMassNew"] = TH1F("h_collimNew", "Higgs Collinear Mass (new method);Mass (GeV);Counts/5GeV", 100, 115, 135);

    hists["cutflow_full"] = TH1F("cutflow_full", "Cut Flow;Cuts Passed;Count", NCUTS, 0, NCUTS);
    hists["cutflow_mH115to135"] = TH1F("cutflow_mH115to135", "Cut flow, 115 GeV < m_{H} < 135 GeV;Cuts passed;Count", NCUTS, 0, NCUTS);

    hists["yield_full"] = TH1F("yield_full", "Expected Yield;Cuts Passed;Count", NCUTS, 0, NCUTS);
    hists["yield_mH115to135"] = TH1F("yield_mH115to135", "Expected Yield, 115 GeV < m_{H} < 135 GeV;Cuts passed;Count", NCUTS, 0, NCUTS);

    hists["hPt"] = TH1F("h_pT", "Higgs p_{T};p_{T} (GeV);Counts/5GeV", 100, 0, 200);
    hists["hEta"] = TH1F("h_eta", "Higgs #eta;#eta;Counts/0.2", 100, -4, 4);

    hists["lepPt"] = TH1F("lep_pt", "Lepton p_{T};p_{T} (GeV);Counts/5GeV", 50, 0, 100);
    hists["lepEta"] = TH1F("lep_eta", "Lepton #eta;#eta;Counts/0.2", 100, -4, 4);
    hists["lepPhi"] = TH1F("lep_phi", "Lepton #phi;#phi;Counts/0.2", 64, -3.2, 3.2);

    hists["tauPt"] =  TH1F("tau_pt",  "Tau p_{T};p_{T} (GeV);Counts/5GeV", 50, 0, 100);
    hists["tauEta"] = TH1F("tau_eta", "Tau #eta;#eta;Counts/0.2", 100, -4, 4);
    hists["tauPhi"] = TH1F("tau_phi", "Tau #phi;#phi;Counts/0.2", 64, -3.2, 3.2);
   
    hists["met"] = TH1F("met", "MET;MET (GeV);Counts/5GeV", 50, 0, 100);

    hists["drMetTau"] = TH1F("dr_met_tau", "#Delta R(MET, tau);#Delta R;Counts/0.2", 50, 0, 5);
    hists["dphiMetTau"] = TH1F("dphi_met_tau", "#Delta#phi(MET, tau);#Delta#phi;Counts/0.1", 64, 0, 3.2);
}

int success = 0;

void fillHists(string out_filename) {
    int cf_result = limtree->cutflow();

    unsigned nname_start = out_filename.find_last_of('/') + 1;
    string nname = out_filename.substr( nname_start, out_filename.size() - nname_start - 9 );

    float yield = integrated_luminosity * xsecs[nname];

    for (float i = 0.5; i < (NCUTS - cf_result); i++) {
        hists["cutflow_full"].Fill(i);
        hists["yield_full"].Fill(i, yield);

        if (115 < limtree->collinearMassNew() && limtree->collinearMassNew() < 135) {
            hists["cutflow_mH115to135"].Fill(i);
            hists["yield_mH115to135"].Fill(i, yield);
        }
    }

    if (out_filename.find("CT0") != string::npos && cf_result > 0) return;

    success++;

    float weight = (limtree->weight) * yield;
    hists["hVisMass"].Fill(limtree->visHiggsMass(), weight);
    hists["hCollimMassOld"].Fill(limtree->collinearMassOld(), weight);
    hists["hCollimMassNew"].Fill(limtree->collinearMassNew(), weight);

    TLorentzVector higgsp = limtree->pTau + limtree->pLep + limtree->pMet;

    hists["hPt"].Fill(higgsp.Pt(), weight);
    hists["hEta"].Fill(higgsp.Eta(), weight);

    hists["lepPt"].Fill(limtree->pLep.Pt(), weight);
    hists["lepEta"].Fill(limtree->pLep.Eta(), weight);
    hists["lepPhi"].Fill(limtree->pLep.Phi(), weight);

    hists["tauPt"].Fill(limtree->pTau.Pt(), weight);
    hists["tauEta"].Fill(limtree->pTau.Eta(), weight);
    hists["tauPhi"].Fill(limtree->pTau.Phi(), weight);
   
    hists["met"].Fill(limtree->pMet.Pt(), weight);
  
    hists["drMetTau"].Fill(limtree->pMet.DeltaR(limtree->pTau), weight);
    hists["dphiMetTau"].Fill(limtree->pMet.DeltaPhi(limtree->pTau), weight);
}

void checkEntryNumber(long n) {
  if (n % 5000 == 0) cout << "At entry " << n << " successful " << success << endl;
}

void doHists(DatasetIter di, int cut_tolerance) {
    success = 0;
    long total_mc_events = 0;
    int res = 0;
    cout << "STARTING " << di.getOutputFilename() << endl;

    stringstream fn_stream;
    fn_stream << di.getOutputFilename() << "_CT" << cut_tolerance << ".root";
    string out_filename = fn_stream.str();

    book_hists();
    while (true) {
        res = di.nextInput();
        if (res < 0) break;
        if (res == 0) continue;

        limtree = di.getLimTree();

        while ( limtree->loadNext() >= 0 ) {
            fillHists(out_filename);
            total_mc_events++;
            checkEntryNumber(total_mc_events);
        }
    }

    for (std::map<string,TH1F>::iterator it = hists.begin(); it != hists.end(); ++it) {
        TString histname((it->second).GetName());
        if (histname.Contains("cutflow")) continue;
        (it->second).Scale(1./total_mc_events);
    }

    TFile* fout = new TFile(out_filename.data(),"recreate");
    fout->cd();
    for (std::map<string,TH1F>::iterator it = hists.begin(); it != hists.end(); ++it) {
        (it -> second).Write();
    }
    fout -> Close();
}

int main() {
    DatasetIter di;
    while (di.nextOutput()) {
        doHists(di, 0); // all cuts
        doHists(di, 5); // no LFV specific cuts
    }

    return 0;
}

