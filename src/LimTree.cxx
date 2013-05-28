/*
 * =====================================================================================
 *
 *       Filename:  LimTree.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2013 12:52:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (), wjohnson@cern.ch
 *   Organization:  
 *
 * =====================================================================================
 */

#define LimTree_impl

#include "LimTree.h"

#define _USE_MATH_DEFINES
#include <math.h>

long LimTree::get_events_remaining() { return (tree->GetEntries() - current_event_idx); }
float LimTree::get_hist_scale() { return hist_scale; }
float LimTree::get_total_yield() { return total_yield; }

//LimTree* LimTree::clone() { return new LimTree(tree, total_yield, hist_scale); }

void LimTree::reset() { current_event_idx = -1; }

long LimTree::load_next() {
    if (tree == 0) return -1;

    current_event_idx++;

    int jj = tree -> LoadTree(current_event_idx); if (jj <  0) return -1;
    int nb = tree -> GetEntry(current_event_idx); if (nb <= 0) return -2;

    pTau = TLorentzVector(0.,0.,0.,0.);
    pTau.SetPtEtaPhiM(tauPt, tauEta, tauPhi, tau_mass);

    pLep = TLorentzVector(0.,0.,0.,0.);
    if (is_mutau)
        pLep.SetPtEtaPhiM(lepPt, lepEta, lepPhi, mu_mass);
    else 
        pLep.SetPtEtaPhiM(lepPt, lepEta, lepPhi, e_mass);

    pMet = TLorentzVector(0.,0.,0.,0.);
    pMet.SetPtEtaPhiM(met, 0., metPhi, 0.);

    pJetLeading = TLorentzVector(0.,0.,0.,0.);
    pJetLeading.SetPtEtaPhiM(jet_leadingPt, jet_leadingEta, jet_leadingPhi, jet_leadingM);
    
    pJetSubleading = TLorentzVector(0.,0.,0.,0.);
    pJetSubleading.SetPtEtaPhiM(jet_subleadingPt, jet_subleadingEta, jet_subleadingPhi, jet_subleadingM);

    do_cuts();

    return current_event_idx;
    
}

/*
 * 1)  isolated lepton
 * 2)  hadronic tau
 * 3)  charge correlated
 * 4)  tau pt
 * 5)  lepton eta
 * 6)  tau eta
 * -------------------LFV CUTS
 * 7)  lep pt
 * 8)  delta phi (MET, tau)
 * 9)  delta R   (MET, tau)
 * 10) vis mH
 */
void LimTree::do_cuts() {
    cuts = vector<bool>();

    cuts.push_back( is_isoLep );
    cuts.push_back( is_tauHad );
    cuts.push_back( is_chargeCorrelated );
    cuts.push_back( (tauPt > 20) );
    cuts.push_back( (lepEta < 2.1) );
    cuts.push_back( (tauEta < 2.3) );
    cuts.push_back( (lepPt > 50) );
    cuts.push_back( (pTau.DeltaPhi(pMet) < M_PI/2) );
    cuts.push_back( (pTau.DeltaR(pMet) < 2.5) );
    cuts.push_back( (vis_mH() > 90) );
}

const int LimTree::ncuts = 10;

int LimTree::cutflow() {
    unsigned nfail = cuts.size();

    for (unsigned i = 0; i < cuts.size(); i++) {
        if ( cuts.at(i) ) nfail--;
        else return nfail;
    }

    return nfail;
}

float LimTree::vis_mH() {
    return (pTau + pLep).M();
}

float LimTree::collim_mH_new() {
    float x_tau = pTau.E() / (pTau.E() + pMet.E());
    float x_lep = 1.;

    if (x_tau > 0 && x_lep > 0)
        return ( vis_mH() / sqrt( x_tau*x_lep ) );

    return -1;
}

float LimTree::collim_mH_old() {
    float num  = pTau.X()*pLep.Y() - pTau.Y()*pLep.X();
    float denh = num + pMet.X()*pLep.Y() - pMet.Y()*pLep.X();
    float denl = num - pMet.X()*pLep.Y() + pMet.Y()*pLep.X();

    float x_tau = num/denh;
    float x_lep = num/denl;

    if (x_tau > 0 && x_lep > 0)
        return (vis_mH() / sqrt(x_tau*x_lep));

    return -1;
}
