/*
 * =====================================================================================
 *
 *       Filename:  LimTree.h
 *
 *    Description:  LimTree is a wrapper class for a TTree which handles branch
 *                  assignment, tree loading, herp derp
 *
 *        Version:  1.0
 *        Created:  05/24/2013 09:49:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#ifndef LimTree_h
#define LimTree_h

#include <iostream>
#include <vector>

#include <TROOT.h>
#include <TBranch.h>
#include <TTree.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TString.h>
#include <TObjArray.h>
#include <TChain.h>

#include "common.h"

using namespace std;

class LimTree {
    public:
        LimTree(TChain*, float, float);
        virtual ~LimTree();

//        LimTree* clone();
        
        void reset();

        float weight;
        unsigned run_number;
        unsigned evt_number;

        float get_hist_scale();
        float get_total_yield();

        void set_mutau();
        void set_etau();

        long get_events_remaining();
        
        /* 
         *  Loads the next event and returns the event number.
         *  If there is no next event (tree->LoadTree(n) returns -1)
         *  then load_next() returns -1. If there was an event but no
         *  bytes were loaded (tree->GetEvent(n) returns <= 0)
         */
        long load_next();

        vector<bool> cuts;
        static const int ncuts;
        /*
         * Returns an integer for how many cuts were left INCLUDING and AFTER
         * the first cut that failed.
         */
        int cutflow();

        float vis_mH();
        float collim_mH_new();
        float collim_mH_old();

        TLorentzVector pTau, pLep, pMet, pJetLeading, pJetSubleading;

    private:
        void do_cuts();

        TChain* tree;

        float total_yield;
        float hist_scale;

        bool mutau;

        static const float e_mass;
        static const float mu_mass;
        static const float tau_mass;

        static const float GeV;

        TBranch* b_weight;
        TBranch* b_run_number;
        TBranch* b_evt_number;

        int vertices;
        bool is_tau;
        bool is_tauHad;
        bool is_mutau;
        bool is_eltau;
        bool is_chargeCorrelated;
        bool is_isoLep;
        bool dilepton_veto;
        int jets_n;
        float jet_leadingPt;
        float jet_leadingEta;
        float jet_leadingPhi;
        float jet_leadingM;
        float jet_subleadingPt;
        float jet_subleadingEta;
        float jet_subleadingPhi;
        float jet_subleadingM;
        float jets_deltaEta;
        float jets_eta1eta2;
        float jets_dijetM;
        bool jets_centrality;
        
        TBranch* b_vertices;
        TBranch* b_is_tau;
        TBranch* b_is_tauHad;
        TBranch* b_is_mutau;
        TBranch* b_is_eltau;
        TBranch* b_is_chargeCorrelated;
        TBranch* b_is_isoLep;
        TBranch* b_dilepton_veto;
        TBranch* b_jets_n;
        TBranch* b_jet_leadingPt;
        TBranch* b_jet_leadingEta;
        TBranch* b_jet_leadingPhi;
        TBranch* b_jet_leadingM;
        TBranch* b_jet_subleadingPt;
        TBranch* b_jet_subleadingEta;
        TBranch* b_jet_subleadingPhi;
        TBranch* b_jet_subleadingM;
        TBranch* b_jets_deltaEta;
        TBranch* b_jets_eta1eta2;
        TBranch* b_jets_dijetM;
        TBranch* b_jets_centrality;

        // kinem branches and variables
        float met;
        float metPhi;

        float tauPt;
        float tauPhi;
        float tauEta;

        float lepPt;
        float lepEta;
        float lepPhi;

        TBranch* b_met;
        TBranch* b_metPhi;

        TBranch* b_tauPt;
        TBranch* b_tauPhi;
        TBranch* b_tauEta;

        TBranch* b_lepPt;
        TBranch* b_lepEta;
        TBranch* b_lepPhi;

        long current_event_idx;
};

#endif

#ifdef LimTree_impl

// avg values from PDG
const float LimTree::e_mass = 0.000510998928;
const float LimTree::mu_mass = 0.1056583715;
const float LimTree::tau_mass = 1.77682;

const float LimTree::GeV = 1000.;

LimTree::LimTree(TChain* chain, float y, float s) {
    tree = chain;
    total_yield = y;
    hist_scale = s;

    is_mutau = true;

    weight = 0;
    run_number = 0;
    evt_number = 0;

    vertices = 0;
    is_tau = 0;
    is_tauHad = 0;
    is_mutau = 0;
    is_eltau = 0;
    is_chargeCorrelated = 0;
    is_isoLep = 0;
    dilepton_veto = 0;
    jets_n = 0;
    jet_leadingPt = 0;
    jet_leadingEta = 0;
    jet_leadingPhi = 0;
    jet_leadingM = 0;
    jet_subleadingPt = 0;
    jet_subleadingEta = 0;
    jet_subleadingPhi = 0;
    jet_subleadingM = 0;
    jets_deltaEta = 0;
    jets_eta1eta2 = 0;
    jets_dijetM = 0;
    jets_centrality = 0;

    met = 0;
    metPhi = 0;
    tauPt = 0;
    tauPhi = 0;
    tauEta = 0;
    lepPt = 0;
    lepEta = 0;
    lepPhi = 0;

    current_event_idx = -1;

    if (tree -> GetEntries() == 0) return;

    tree -> SetBranchAddress("evtsel_weight", &weight, &b_weight);
    tree -> SetBranchAddress("EventNumber", &evt_number, &b_evt_number);
    tree -> SetBranchAddress("RunNumber", &run_number, &b_run_number);
    tree -> SetBranchAddress("evtsel_MET", &met, &b_met);
    tree -> SetBranchAddress("evtsel_MET_phi", &metPhi, &b_metPhi);
    tree -> SetBranchAddress("evtsel_tau_et", &tauPt, &b_tauPt);
    tree -> SetBranchAddress("evtsel_tau_phi", &tauPhi, &b_tauPhi);
    tree -> SetBranchAddress("evtsel_tau_eta", &tauEta, &b_tauEta);
    tree -> SetBranchAddress("evtsel_lep_pt", &lepPt, &b_lepPt);
    tree -> SetBranchAddress("evtsel_lep_eta", &lepEta, &b_lepEta);
    tree -> SetBranchAddress("evtsel_lep_phi", &lepPhi, &b_lepPhi);
    tree -> SetBranchAddress("evtsel_is_eltau", &is_eltau, &b_is_eltau);
    tree -> SetBranchAddress("evtsel_is_mutau", &is_mutau, &b_is_mutau);
    tree -> SetBranchAddress("evtsel_is_oppositeSign", &is_chargeCorrelated, &b_is_chargeCorrelated);
    tree -> SetBranchAddress("evtsel_is_isoLep", &is_isoLep, &b_is_isoLep);
    tree -> SetBranchAddress("evtsel_is_dilepVeto", &dilepton_veto, &b_dilepton_veto);
    tree -> SetBranchAddress("evtsel_is_tau", &is_tau, &b_is_tau);
    tree -> SetBranchAddress("evtsel_tau_is_had", &is_tauHad, &b_is_tauHad);
    tree -> SetBranchAddress("evtsel_vertices", &vertices, &b_vertices);
    tree -> SetBranchAddress("evtsel_jets_num", &jets_n, &b_jets_n);
    tree -> SetBranchAddress("evtsel_jet_leading_pt", &jet_leadingPt, &b_jet_leadingPt);
    tree -> SetBranchAddress("evtsel_jet_leading_eta", &jet_leadingEta, &b_jet_leadingEta);
    tree -> SetBranchAddress("evtsel_jet_leading_phi", &jet_leadingPhi, &b_jet_leadingPhi);
    tree -> SetBranchAddress("evtsel_jet_leading_m", &jet_leadingM, &b_jet_leadingM);
    tree -> SetBranchAddress("evtsel_jet_subleading_pt", &jet_subleadingPt, &b_jet_subleadingPt);
    tree -> SetBranchAddress("evtsel_jet_subleading_eta", &jet_subleadingEta, &b_jet_subleadingEta);
    tree -> SetBranchAddress("evtsel_jet_subleading_phi", &jet_subleadingPhi, &b_jet_subleadingPhi);
    tree -> SetBranchAddress("evtsel_jet_subleading_m", &jet_subleadingM, &b_jet_subleadingM);
    tree -> SetBranchAddress("evtsel_jetEta1_jetEta2", &jets_eta1eta2, &b_jets_eta1eta2);
    tree -> SetBranchAddress("evtsel_is_jet_centrality", &jets_centrality, &b_jets_centrality);
    tree -> SetBranchAddress("evtsel_jets_deltaEta", &jets_deltaEta, &b_jets_deltaEta);
    tree -> SetBranchAddress("evtsel_dijet_mass", &jets_dijetM, &b_jets_dijetM);
}

LimTree::~LimTree() {
    if (!tree) return;
    delete tree->GetCurrentFile();
}

void LimTree::set_mutau() { is_mutau = true; }
void LimTree::set_etau()  { is_mutau = false; }

#endif
