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
 * 1) tau tag
 * 2) dilepton veto
 * 3) charge correlation
 * 4) isolated lepton
 * 5) hadronic tau
 * 6) tau pt
 * 7) lep eta
 * 8) tau eta
 * --------------------LFV
 * 9) lep pt
 * 10) dphi(met,tau)
 * 11) dr(met,tau)
 */
void LimTree::do_cuts() {
    cuts = vector<bool>();

    cuts.push_back( is_tau );
    cuts.push_back( dilepton_veto );
    cuts.push_back( is_chargeCorrelated );
    cuts.push_back( is_isoLep );
    cuts.push_back( is_tauHad );
    cuts.push_back( (tauPt > 49) );
    cuts.push_back( (lepPt > 54) );
    cuts.push_back( (pTau.DeltaPhi(pMet) < 1.66) );
    cuts.push_back( (pTau.DeltaR(pMet) < 1.80) );
}

const int LimTree::ncuts = 9;

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
