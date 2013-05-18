/*
 * =====================================================================================
 *
 *       Filename:  LimTree.h
 *
 *    Description:  Header file for LimTree; also includes constructor
 *
 *        Version:  1.0
 *        Created:  04/29/2013 01:39:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson, wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#ifndef LimTree_h
#define LimTree_h

#include <stdlib.h>
#include <iostream>
#include <math.h>

#include <vector>
#include <TROOT.h>
#include <TBranch.h>
#include <TTree.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TString.h>

using namespace std;

class LimTree {
    public:
        LimTree(TTree*);
        virtual ~LimTree();

        // MC stuff
        float weight;
        unsigned int runNumber;
        unsigned int evtNumber;

        long getEventsRemaining();

        /*
         * Loads the next event and returns the event number.
         * If there is no next event [[ tree -> LoadTree(n) returns -1 ]]
         * then it returns -1. If there is an event but no bytes were loaded
         * [[ tree -> GetEvent(n) returns <= 0 ]] it returns -2.
         */
        long loadNext(); 

        /*
         * Performs a cut flow which does or does not include dijet cuts
         * depending on the doDijetCuts field. 
         * Returns an integer for how many cuts were left
         * INCLUDING and AFTER the first failure. So passing all cuts returns 0
         */
        int cutflow();
        int getNCuts();

        /*
         * Sets whether we are looking for H -> mu tau or H -> e tau.
         * Default to mu tau.
         */
        void setETau();
        void setMuTau();

        /*
         * Decide whether to use dijet cuts
         */
        void setUseDijetCuts(bool);

        float visHiggsMass(); // returns the *visible* Higgs mass

        // returns the Higgs mass reconstructed with the collinear approx.
        float collinearMassOld();

        /*
         * Returns the Higgs mass reconstructed with the collinear approximation,
         * and the tau mass constraint--we can solve the Higgs mass exactly
         * (assuming collinear MET) for FV decays.
         */
        float collinearMassNew();

        // access to 4 vectors for the shits of it
        TLorentzVector pTau;
        TLorentzVector pLep;
        TLorentzVector pMet;
        TLorentzVector pJetLeading;
        TLorentzVector pJetSubleading;

    private:
        TTree* tree;

        bool mutau; // true = H -> mu tau; false = H -> e tau
        bool useDijetCuts;

        // constants
        // masses in MeV; avg values reported by PDG
        static const float elMass;
        static const float muMass;
        static const float tauMass;

        static const float GeV;


        TBranch* b_weight;
        TBranch* b_runNumber;
        TBranch* b_evtNumber;

        // selection branches and variables
        int vertices;
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

        long currentEventIdx;

        int tauLepCutFlow(); // cuts involving tau and lep which apply to all production channels
        int dijetCutFlow(); // cuts involving dijet
};

#endif

#ifdef LimTree_impl

const float LimTree::elMass = 0.000510998928;
const float LimTree::muMass = 0.1056583715;
const float LimTree::tauMass = 1.77682;
const float LimTree::GeV = 1000.;

LimTree::LimTree(TTree* chain) {
    tree = chain;

    mutau = true;
    useDijetCuts = false;

    weight = 0;
    runNumber = 0;
    evtNumber = 0;

    vertices = 0;
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

    currentEventIdx = -1;

    if (tree -> GetEntries() == 0) return;

    tree -> SetBranchAddress("evtsel_weight", &weight, &b_weight);
    tree -> SetBranchAddress("EventNumber", &evtNumber, &b_evtNumber);
    tree -> SetBranchAddress("RunNumber", &runNumber, &b_runNumber);
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
    delete tree -> GetCurrentFile();
};

void LimTree::setMuTau() { mutau = true; }
void LimTree::setETau()  { mutau = false; }
void LimTree::setUseDijetCuts(bool u) { useDijetCuts = u; }

#endif
