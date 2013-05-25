/*
 * =====================================================================================
 *
 *       Filename:  xsec_data.h
 *
 *    Description:  contains xsec*BR data for signal and backgrounds.
 *
 *        Version:  1.0
 *        Created:  05/08/13 11:38:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <map> // use of bracket list constructor requires C++11
#include <string>

#ifndef xsec_data_h
#define xsec_data_h

using namespace std;

const int pb = 1000; // fb in pb
const int nb = pb*pb; // fb in nb

const float integrated_luminosity = 20.3398; // fb-1, from twiki->HiggsToTauTauToLH2013Winter8TeV

std::map<string,float> xsecs( {
        {"gg_htm",  0.05*1.22976*1.0*0.456192*pb}, // arbitrary choice of LFVH BR, 0 < BR < 10%
        {"gg_hte",  0.05*1.22976*1.0*0.456192*pb},
        {"vbf_htm", 0.05*0.98217*1.0*.456192*pb},
        {"vbf_hte", 0.05*0.98217*1.0*.456192*pb},
        {"wh_htm",  0.05*0.0438858*1.0*0.456192*pb},
        {"wh_hte",  0.05*0.0438858*1.0*0.456192*pb},
        {"zh_htm",  0.05*0.0248409*1.0*0.456192*pb},
        {"zh_hte",  0.05*0.0248409*1.0*0.456192*pb},
        {"gg_htt",  0.0632*1.22976*1.0*0.456192*pb}, // from higgs xsec WG: 125H->tautau has BR 6.32%
        {"vbf_htt", 0.0632*0.98217*1.0*.456192*pb},
        {"wh_htt",  0.0632*0.0438858*1.0*0.456192*pb},
        {"zh_htt",  0.0632*0.0248409*1.0*0.456192*pb},
        {"diboson", 
            ( 53.9*1.0*0.38212*pb // ww
            + 7.32*1.0*0.21165*pb // zz
            + 22.3*1.0*0.30546*pb )},// wz
        {"z+jets", 
            ( 711.77*1.23*1.0*pb // zee_np0
            + 155.17*1.23*1.0*pb // zee_np1
            + 48.745*1.23*1.0*pb // zee_np2
            + 14.225*1.23*1.0*pb // zee_np3
            + 3.7595*1.23*1.0*pb // zee_np4
            + 1.0945*1.23*1.0*pb // zee_np5
            + 712.11*1.23*1.0*pb // zmumu_np0
            + 154.77*1.23*1.0*pb // zmumu_np1
            + 48.912*1.23*1.0*pb // zmumu_np2
            + 14.226*1.23*1.0*pb // zmumu_np3
            + 3.7838*1.23*1.0*pb // zmumu_np4
            + 1.1148*1.23*1.0*pb // zmumu_np5
            + 711.81*1.23*1.0*pb // ztautau_np0
            + 155.13*1.23*1.0*pb // ztautau_np1
            + 48.804*1.23*1.0*pb // ztautau_np2
            + 14.16*1.23*1.0*pb // ztautau_np3
            + 3.7744*1.23*1.0*pb // ztautau_np4
            + 1.1163*1.23*1.0*pb // ztautau_np5
            + 3477.2*1.19*1.0*pb // zee_np0_mll10to60
            + 108.8*1.19*1.0*pb // zee_np1_mll10to60
            + 52.767*1.19*1.0*pb // zee_np2_mll10to60
            + 11.297*1.19*1.0*pb // zee_np3_mll10to60
            + 2.5836*1.19*1.0*pb // zee_np4_mll10to60
            + 0.69267*1.19*1.0*pb // zee_np5_mll10to60
            + 3477.1*1.19*1.0*pb // zmumu_np0_mll10to60
            + 108.75*1.19*1.0*pb // zmumu_np1_mll10to60
            + 52.741*1.19*1.0*pb // zmumu_np2_mll10to60
            + 11.241*1.19*1.0*pb // zmumu_np3_mll10to60
            + 2.6005*1.19*1.0*pb // zmumu_np4_mll10to60
            + 0.69373*1.19*1.0*pb // zmumu_np5_mll10to60
            + 3477.1*1.19*1.0*pb // ztautau_np0_mll10to60
            + 108.74*1.19*1.0*pb // ztautau_np1_mll10to60
            + 52.732*1.19*1.0*pb // ztautau_np2_mll10to60
            + 11.326*1.19*1.0*pb // ztautau_np3_mll10to60
            + 2.592*1.19*1.0*pb // ztautau_np4_mll10to60
            + 0.6929*1.19*1.0*pb // ztautau_np5_mll10to60
            + 712.08*1.23*0.033522*pb // vbf_zee_np0
            + 154.99*1.23*0.080913*pb // vbf_zee_np1
            + 48.833*1.23*0.2463*pb // vbf_zee_np2
            + 14.183*1.23*0.4692*pb // vbf_zee_np3
            + 3.7909*1.23*0.67933*pb // vbf_zee_np4
            + 1.1331*1.23*1*pb // vbf_zee_np5
            + 712.11*1.23*0.0065069*pb // vbf_zmumu_np0
            + 155*1.23*0.038308*pb // vbf_zmumu_np1
            + 48.945*1.23*0.14105*pb // vbf_zmumu_np2
            + 14.187*1.23*0.35368*pb // vbf_zmumu_np3
            + 3.7943*1.23*0.5921*pb // vbf_zmumu_np4
            + 1.1342*1.23*1*pb // vbf_zmumu_np5
            + 712.1*1.23*0.008043*pb // vbf_atau_ztautau_np0
            + 154.99*1.23*0.02242*pb // vbf_atau_ztautau_np1
            + 48.85*1.23*0.083617*pb // vbf_atau_ztautau_np2
            + 14.185*1.23*0.19376*pb // vbf_atau_ztautau_np3
            + 3.7934*1.23*0.30956*pb // vbf_atau_ztautau_np4
            + 1.1366*1.23*1*pb)}, // vbf_atau_ztautau_np5
        {"w+jets", 
            ( 8037.1*1.19*1.0*pb // wenu_np0
            + 1579.2*1.19*1.0*pb // wenu_np1
            + 477.2*1.19*1.0*pb // wenu_np2
            + 133.93*1.19*1.0*pb // wenu_np3
            + 35.622*1.19*1.0*pb // wenu_np4
            + 10.553*1.19*1.0*pb // wenu_np5
            + 8040*1.19*1.0*pb // wmunu_np0
            + 1580.3*1.19*1.0*pb // wmunu_np1
            + 477.5*1.19*1.0*pb // wmunu_np2
            + 133.94*1.19*1.0*pb // wmunu_np3
            + 35.636*1.19*1.0*pb // wmunu_np4
            + 10.571*1.19*1.0*pb // unu_np5
            + 8035.8*1.19*1.0*pb // wtaunu_np0
            + 1579.8*1.19*1.0*pb // wtaunu_np1
            + 477.55*1.19*1.0*pb // wtaunu_np2
            + 133.79*1.19*1.0*pb // wtaunu_np3
            + 35.583*1.19*1.0*pb // wtaunu_np4
            + 10.54*1.19*1.0*pb )}, // wtaunu_np5
        {"top+lep", 
            ( 9.48*1.0*1.0*pb // top_tchan_e
            + 9.48*1.0*1.0*pb // top_tchan_mu
            + 9.48*1.0*1.0*pb)} // top_tchan_tau
        } );

#endif
