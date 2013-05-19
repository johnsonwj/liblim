/*
 * =====================================================================================
 *
 *       Filename:  LimTree.cxx
 *
 *    Description:  Contains relevant branches of a Common Ntuple for event selection
 *                  and limit analysis.
 *                  Also contains convenience methods for running cut flow
 *                  and reconstructing mass.
 *
 *        Version:  1.0
 *        Created:  04/29/2013 12:49:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson, wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#define LimTree_impl
#include "LimTree.h"
#define _USE_MATH_DEFINES
#include <math.h>


long LimTree::getEventsRemaining() { return (tree->GetEntries() - currentEventIdx); }

long LimTree::loadNext() {
    if ( tree == 0 ) return -1;

    currentEventIdx++;

    int jj = tree -> LoadTree(currentEventIdx);
    int nb = tree -> GetEntry(currentEventIdx);

    if ( jj <  0 ) return -1;
    if ( nb <= 0 ) return -2;

    pTau = TLorentzVector(0.,0.,0.,0.);
    pTau.SetPtEtaPhiM(tauPt, tauEta, tauPhi, tauMass);

    pLep = TLorentzVector(0.,0.,0.,0.);
    if (mutau)
        pLep.SetPtEtaPhiM(lepPt, lepEta, lepPhi, muMass);
    else 
        pLep.SetPtEtaPhiM(lepPt, lepEta, lepPhi, elMass);

    pMet = TLorentzVector(0.,0.,0.,0.);
    pMet.SetPtEtaPhiM(met, 0., metPhi, 0.);

    pJetLeading = TLorentzVector(0.,0.,0.,0.);
    pJetLeading.SetPtEtaPhiM(jet_leadingPt, jet_leadingEta, jet_leadingPhi, jet_leadingM);
    
    pJetSubleading = TLorentzVector(0.,0.,0.,0.);
    pJetSubleading.SetPtEtaPhiM(jet_subleadingPt, jet_subleadingEta, jet_subleadingPhi, jet_subleadingM);

    return currentEventIdx;
}

float LimTree::visHiggsMass() {
    return (pTau + pLep).M();
}

float LimTree::metTauFrac() {
    float num= pTau.X()*pLep.Y() - pTau.Y()*pLep.X();
    float denh = num + pMet.X()*pLep.Y() - pMet.Y()*pLep.X();

    if (denh > 0) return num/denh;
    return -1;
}

float LimTree::metLepFrac() {
    float num= pTau.X()*pLep.Y() - pTau.Y()*pLep.X();
    float denl = num - pMet.X()*pLep.Y() + pMet.Y()*pLep.X();

    if (denl > 0) return num/denl;
    return -1;
}

float LimTree::collinearMassOld() {
    float xLep = metLepFrac();
    float xTau = metTauFrac();

    if (xTau > 0 && xLep > 0)
        return visHiggsMass() / sqrt( xTau*xLep );
    return -1;
}

float LimTree::collinearMassNew() {
    float xTau = pTau.E() / (pTau.E() + pMet.E());
    float xLep = 1.;

    if (xTau > 0 && xLep > 0)
        return visHiggsMass() / sqrt( xTau*xLep );
    else
        return -1;
}

int LimTree::cutflow() {
    if (!useDijetCuts) {
        return tauLepCutFlow();
    } else { // vbf
        if (tauLepCutFlow() > 0) return (tauLepCutFlow() + 5);
        else if (jets_n < 2) return 4;
        else return dijetCutFlow();
    }
}

int LimTree::getNCuts() {
    if (!useDijetCuts) return 8;
    else return 13; // vbf
}

/*
 * 1) isolated lepton
 * 2) tauhad
 * 3) charge correlated
 * 4) tau pt
 * 5) lepton eta
 * 6) tau eta
 * ------------------- BEGIN LFV CUTS
 *  7) lep pt
 *  8) delta phi (met, tau)
 *  9) delta R (met, tau)
 *  10) higgs vis mass
 */
int LimTree::tauLepCutFlow() {
    int nfail = 11;

    if (is_isoLep) nfail--;
    else return nfail;

    if (is_tauHad) nfail--;
    else return nfail;

    //if ((mutau && is_mutau) || (!mutau && is_eltau)) nfail--;
    //else return nfail;

    if (is_chargeCorrelated) nfail--;
    else return nfail;

    if (tauPt > 20) nfail--;
    else return nfail;

    if ((mutau && fabs(lepEta) < 2.1) || (!mutau && fabs(lepEta) < 2.1)) nfail--;
    else return nfail;

    if (fabs(tauEta) < 2.3) nfail--;
    else return nfail;

    if ((mutau && lepPt > 35) || (!mutau && lepPt > 35)) nfail--;
    else return nfail;

    if (fabs(metPhi - tauPhi) < M_PI/2) nfail--;
    else return nfail;

    if ( collinearMassOld() > 100 ) nfail--;
    else return nfail;

    if ( pTau.DeltaR(pMet) < 2.5 ) nfail--;
    else return nfail;

    if ( (pTau+pLep).M() > 75 ) nfail--;
    else return nfail;

    return nfail;
}

/*
 * 1) leading pt > 40 GeV and subleading > 25 gev
 * 2) delta eta > 4
 * 3) eta1*eta2 < 0
 * 4) dijet mass > 400 GeV
 */
int LimTree:: dijetCutFlow() {
    int nfail = 4;

    if (jets_n < 2) return nfail;

    if (jet_leadingPt > 40 && jet_subleadingPt > 25) nfail--;
    else return nfail;

    if (jets_deltaEta > 4) nfail--;
    else return nfail;

    if (jets_eta1eta2 < 0) nfail--;
    else return nfail;

    if (jets_dijetM > 400) nfail--;
    else return nfail;

    return nfail;
}
