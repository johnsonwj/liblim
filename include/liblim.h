/*
 * =====================================================================================
 *
 *       Filename:  liblim.h
 *
 *    Description:  contains common stuff to use in liblim; yields, helper methods, ...
 *
 *        Version:  1.0
 *        Created:  05/24/2013 11:54:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <map>
#include <string>

#ifndef liblim_h
#define liblim_h

using namespace std;

map<string,float> yield; // xsec*br*lumi
map<string,float> scale; // yield/total_mc_events

const int pb = 1000; // fb in pb
const int nb = pb*pb; // fb in nb

const float integrated_luminosity = 20.3398; // fb-1, from twiki->HiggsToTauTauToLH2013Winter8TeV

const int n_bkg_groups = 4;
const string bkg_groups[n_bkg_groups] = {
    "diboson", "top+lep", "w+jets", "z+jets"
};

bool contains(string,string); // "string1 contains string2"

map<string,float> get_yields() {
    map<string,float> yield;

    // arbitrary choice of LFVH BR, 0 < BR < 10% --- here I choose 5%
    //
    yield["htm_gg"]                         =  integrated_luminosity * 0.05 * 1.22976   * 1.0 * 0.456192 * pb; 
    yield["hte_gg"]                         =  integrated_luminosity * 0.05 * 1.22976   * 1.0 * 0.456192 * pb;
    yield["htm_vbf"]                        =  integrated_luminosity * 0.05 * 0.98217   * 1.0 * 0.456192 * pb;
    yield["hte_vbf"]                        =  integrated_luminosity * 0.05 * 0.98217   * 1.0 * 0.456192 * pb;
    yield["htm_wh"]                         =  integrated_luminosity * 0.05 * 0.0438858 * 1.0 * 0.456192 * pb;
    yield["hte_wh"]                         =  integrated_luminosity * 0.05 * 0.0438858 * 1.0 * 0.456192 * pb;
    yield["htm_zh"]                         =  integrated_luminosity * 0.05 * 0.0248409 * 1.0 * 0.456192 * pb;
    yield["hte_zh"]                         =  integrated_luminosity * 0.05 * 0.0248409 * 1.0 * 0.456192 * pb;
    
    // from higgs xsec WG: 125H->tautau has BR 6.32%

    yield["htt_gg"]                         =  integrated_luminosity * 0.0632 * 1.22976   * 1.0 * 0.456192 * pb; 
    yield["htt_vbf"]                        =  integrated_luminosity * 0.0632 * 0.98217   * 1.0 * 0.456192 * pb;
    yield["htt_wh"]                         =  integrated_luminosity * 0.0632 * 0.0438858 * 1.0 * 0.456192 * pb;
    yield["htt_zh"]                         =  integrated_luminosity * 0.0632 * 0.0248409 * 1.0 * 0.456192 * pb;

    yield["diboson_ww"]                     = integrated_luminosity * 53.9 * 1.0 * 0.38212 * pb;
    yield["diboson_zz"]                     = integrated_luminosity * 7.32 * 1.0 * 0.21165 * pb;
    yield["diboson_wz"]                     = integrated_luminosity * 22.3 * 1.0 * 0.30546 * pb;

    yield["z+jets_zee_np0"]                 = integrated_luminosity * 711.77  * 1.23 * 1.0 * pb;
    yield["z+jets_zee_np1"]                 = integrated_luminosity * 155.17  * 1.23 * 1.0 * pb;
    yield["z+jets_zee_np2"]                 = integrated_luminosity * 48.745  * 1.23 * 1.0 * pb;
    yield["z+jets_zee_np3"]                 = integrated_luminosity * 14.225  * 1.23 * 1.0 * pb; 
    yield["z+jets_zee_np4"]                 = integrated_luminosity * 3.7595  * 1.23 * 1.0 * pb; 
    yield["z+jets_zee_np5"]                 = integrated_luminosity * 1.0945  * 1.23 * 1.0 * pb; 
    yield["z+jets_zmumu_np0"]               = integrated_luminosity * 712.11  * 1.23 * 1.0 * pb;
    yield["z+jets_zmumu_np1"]               = integrated_luminosity * 154.77  * 1.23 * 1.0 * pb;
    yield["z+jets_zmumu_np2"]               = integrated_luminosity * 48.912  * 1.23 * 1.0 * pb;
    yield["z+jets_zmumu_np3"]               = integrated_luminosity * 14.226  * 1.23 * 1.0 * pb;
    yield["z+jets_zmumu_np4"]               = integrated_luminosity * 3.7838  * 1.23 * 1.0 * pb;
    yield["z+jets_zmumu_np5"]               = integrated_luminosity * 1.1148  * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np0"]             = integrated_luminosity * 711.81  * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np1"]             = integrated_luminosity * 155.13  * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np2"]             = integrated_luminosity * 48.804  * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np3"]             = integrated_luminosity * 14.16   * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np4"]             = integrated_luminosity * 3.7744  * 1.23 * 1.0 * pb;
    yield["z+jets_ztautau_np5"]             = integrated_luminosity * 1.1163  * 1.23 * 1.0 * pb;
    yield["z+jets_zee_np0_mll10to60"]       = integrated_luminosity * 3477.2  * 1.19 * 1.0 * pb;
    yield["z+jets_zee_np1_mll10to60"]       = integrated_luminosity * 108.8   * 1.19 * 1.0 * pb;
    yield["z+jets_zee_np2_mll10to60"]       = integrated_luminosity * 52.767  * 1.19 * 1.0 * pb;
    yield["z+jets_zee_np3_mll10to60"]       = integrated_luminosity * 11.297  * 1.19 * 1.0 * pb;
    yield["z+jets_zee_np4_mll10to60"]       = integrated_luminosity * 2.5836  * 1.19 * 1.0 * pb;
    yield["z+jets_zee_np5_mll10to60"]       = integrated_luminosity * 0.69267 * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np0_mll10to60"]     = integrated_luminosity * 3477.1  * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np1_mll10to60"]     = integrated_luminosity * 108.75  * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np2_mll10to60"]     = integrated_luminosity * 52.741  * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np3_mll10to60"]     = integrated_luminosity * 11.241  * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np4_mll10to60"]     = integrated_luminosity * 2.6005  * 1.19 * 1.0 * pb;
    yield["z+jets_zmumu_np5_mll10to60"]     = integrated_luminosity * 0.69373 * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np0_mll10to60"]   = integrated_luminosity * 3477.1  * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np1_mll10to60"]   = integrated_luminosity * 108.74  * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np2_mll10to60"]   = integrated_luminosity * 52.732  * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np3_mll10to60"]   = integrated_luminosity * 11.326  * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np4_mll10to60"]   = integrated_luminosity * 2.592   * 1.19 * 1.0 * pb;
    yield["z+jets_ztautau_np5_mll10to60"]   = integrated_luminosity * 0.6929  * 1.19 * 1.0 * pb;
    yield["z+jets_vbf_zee_np0"]             = integrated_luminosity * 712.08  * 1.23 * 0.033522  * pb;
    yield["z+jets_vbf_zee_np1"]             = integrated_luminosity * 154.99  * 1.23 * 0.080913  * pb;
    yield["z+jets_vbf_zee_np2"]             = integrated_luminosity * 48.833  * 1.23 * 0.2463    * pb;
    yield["z+jets_vbf_zee_np3"]             = integrated_luminosity * 14.183  * 1.23 * 0.4692    * pb;
    yield["z+jets_vbf_zee_np4"]             = integrated_luminosity * 3.7909  * 1.23 * 0.67933   * pb;
    yield["z+jets_vbf_zee_np5"]             = integrated_luminosity * 1.1331  * 1.23 * 1         * pb;
    yield["z+jets_vbf_zmumu_np0"]           = integrated_luminosity * 712.11  * 1.23 * 0.0065069 * pb;
    yield["z+jets_vbf_zmumu_np1"]           = integrated_luminosity * 155     * 1.23 * 0.038308  * pb;
    yield["z+jets_vbf_zmumu_np2"]           = integrated_luminosity * 48.945  * 1.23 * 0.14105   * pb;
    yield["z+jets_vbf_zmumu_np3"]           = integrated_luminosity * 14.187  * 1.23 * 0.35368   * pb;
    yield["z+jets_vbf_zmumu_np4"]           = integrated_luminosity * 3.7943  * 1.23 * 0.5921    * pb;
    yield["z+jets_vbf_zmumu_np5"]           = integrated_luminosity * 1.1342  * 1.23 * 1         * pb;
    yield["z+jets_vbf_atau_ztautau_np0"]    = integrated_luminosity * 712.1   * 1.23 * 0.008043  * pb;
    yield["z+jets_vbf_atau_ztautau_np1"]    = integrated_luminosity * 154.99  * 1.23 * 0.02242   * pb;
    yield["z+jets_vbf_atau_ztautau_np2"]    = integrated_luminosity * 48.85   * 1.23 * 0.083617  * pb;
    yield["z+jets_vbf_atau_ztautau_np3"]    = integrated_luminosity * 14.185  * 1.23 * 0.19376   * pb;
    yield["z+jets_vbf_atau_ztautau_np4"]    = integrated_luminosity * 3.7934  * 1.23 * 0.30956   * pb;
    yield["z+jets_vbf_atau_ztautau_np5"]    = integrated_luminosity * 1.1366  * 1.23 * 1         * pb;

    yield["w+jets_wenu_np0"]                = integrated_luminosity * 8037.1 * 1.19 * 1.0 * pb;
    yield["w+jets_wenu_np1"]                = integrated_luminosity * 1579.2 * 1.19 * 1.0 * pb;
    yield["w+jets_wenu_np2"]                = integrated_luminosity * 477.2  * 1.19 * 1.0 * pb;
    yield["w+jets_wenu_np3"]                = integrated_luminosity * 133.93 * 1.19 * 1.0 * pb;
    yield["w+jets_wenu_np4"]                = integrated_luminosity * 35.622 * 1.19 * 1.0 * pb;
    yield["w+jets_wenu_np5"]                = integrated_luminosity * 10.553 * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np0"]               = integrated_luminosity * 8040   * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np1"]               = integrated_luminosity * 1580.3 * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np2"]               = integrated_luminosity * 477.5  * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np3"]               = integrated_luminosity * 133.94 * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np4"]               = integrated_luminosity * 35.636 * 1.19 * 1.0 * pb;
    yield["w+jets_wmunu_np5"]               = integrated_luminosity * 10.571 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np0"]              = integrated_luminosity * 8035.8 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np1"]              = integrated_luminosity * 1579.8 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np2"]              = integrated_luminosity * 477.55 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np3"]              = integrated_luminosity * 133.79 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np4"]              = integrated_luminosity * 35.583 * 1.19 * 1.0 * pb;
    yield["w+jets_wtaunu_np5"]              = integrated_luminosity * 10.54  * 1.19 * 1.0 * pb;

    yield["top+lep_top_tchan_e"]            = integrated_luminosity * 9.48 * 1.0 * 1.0 * pb;
    yield["top+lep_top_tchan_mu"]           = integrated_luminosity * 9.48 * 1.0 * 1.0 * pb;
    yield["top+lep_top_tchan_tau"]          = integrated_luminosity * 9.48 * 1.0 * 1.0 * pb;

    return yield;
}

map<string,float> get_scale() {
    map<string,float> scale;
    map<string,float> yield = get_yield();

    scale["htm_gg"]                         =  (1./200000.) * yield["htm_gg"];
    scale["hte_gg"]                         =  (1./200000.) * yield["hte_gg"];
    scale["htm_vbf"]                        =  (1./200000.) * yield["htm_vbf"];
    scale["hte_vbf"]                        =  (1./200000.) * yield["hte_vbf"];
    scale["htm_wh"]                         =  (1./50000.)  * yield["htm_wh"];
    scale["hte_wh"]                         =  (1./50000.)  * yield["hte_wh"];
    scale["htm_zh"]                         =  (1./50000.)  * yield["htm_zh"];
    scale["hte_zh"]                         =  (1./50000.)  * yield["hte_zh"];

    scale["htt_gg"]                         =  (1./1994795.) * yield["htt_gg"];
    scale["htt_vbf"]                        =  (1./1999895.) * yield["htt_vbf"];
    scale["htt_wh"]                         =  (1./499999. ) * yield["htt_wh"];
    scale["htt_zh"]                         =  (1./499998. ) * yield["htt_zh"];

    scale["diboson_ww"]                     = (1./2494694.) * yield["diboson_ww"];
    scale["diboson_zz"]                     = (1./999797. ) * yield["diboson_zz"];
    scale["diboson_wz"]                     = (1./249999. ) * yield["diboson_wz"];

    scale["z+jets_zee_np0"]                 = (1./5984290.) * yield["z+jets_zee_np0"];
    scale["z+jets_zee_np1"]                 = (1./1329994.) * yield["z+jets_zee_np1"];
    scale["z+jets_zee_np2"]                 = (1./404798. ) * yield["z+jets_zee_np2"];
    scale["z+jets_zee_np3"]                 = (1./109998. ) * yield["z+jets_zee_np3"];
    scale["z+jets_zee_np4"]                 = (1./30000.  ) * yield["z+jets_zee_np4"];
    scale["z+jets_zee_np5"]                 = (1./10000.  ) * yield["z+jets_zee_np5"];
    scale["z+jets_zmumu_np0"]               = (1./6609982.) * yield["z+jets_zmumu_np0"];
    scale["z+jets_zmumu_np1"]               = (1./1334897.) * yield["z+jets_zmumu_np1"];
    scale["z+jets_zmumu_np2"]               = (1./404897. ) * yield["z+jets_zmumu_np2"];
    scale["z+jets_zmumu_np3"]               = (1./110000. ) * yield["z+jets_zmumu_np3"];
    scale["z+jets_zmumu_np4"]               = (1./29999.  ) * yield["z+jets_zmumu_np4"];
    scale["z+jets_zmumu_np5"]               = (1./10000.  ) * yield["z+jets_zmumu_np5"];
    scale["z+jets_ztautau_np0"]             = (1./6607090.) * yield["z+jets_ztautau_np0"];
    scale["z+jets_ztautau_np1"]             = (1./1334896.) * yield["z+jets_ztautau_np1"];
    scale["z+jets_ztautau_np2"]             = (1./404900. ) * yield["z+jets_ztautau_np2"];
    scale["z+jets_ztautau_np3"]             = (1./110000. ) * yield["z+jets_ztautau_np3"];
    scale["z+jets_ztautau_np4"]             = (1./28999.  ) * yield["z+jets_ztautau_np4"];
    scale["z+jets_ztautau_np5"]             = (1./10000.  ) * yield["z+jets_ztautau_np5"];
    scale["z+jets_zee_np0_mll10to60"]       = (1./1000000.) * yield["z+jets_zee_np0_mll10to60"];
    scale["z+jets_zee_np1_mll10to60"]       = (1./299498. ) * yield["z+jets_zee_np1_mll10to60"];
    scale["z+jets_zee_np2_mll10to60"]       = (1./396499. ) * yield["z+jets_zee_np2_mll10to60"];
    scale["z+jets_zee_np3_mll10to60"]       = (1./145499. ) * yield["z+jets_zee_np3_mll10to60"];
    scale["z+jets_zee_np4_mll10to60"]       = (1./40000.  ) * yield["z+jets_zee_np4_mll10to60"];
    scale["z+jets_zee_np5_mll10to60"]       = (1./10000.  ) * yield["z+jets_zee_np5_mll10to60"];
    scale["z+jets_zmumu_np0_mll10to60"]     = (1./997896. ) * yield["z+jets_zmumu_np0_mll10to60"];
    scale["z+jets_zmumu_np1_mll10to60"]     = (1./300000. ) * yield["z+jets_zmumu_np1_mll10to60"];
    scale["z+jets_zmumu_np2_mll10to60"]     = (1./396499. ) * yield["z+jets_zmumu_np2_mll10to60"];
    scale["z+jets_zmumu_np3_mll10to60"]     = (1./145499. ) * yield["z+jets_zmumu_np3_mll10to60"];
    scale["z+jets_zmumu_np4_mll10to60"]     = (1./39999.  ) * yield["z+jets_zmumu_np4_mll10to60"];
    scale["z+jets_zmumu_np5_mll10to60"]     = (1./10000.  ) * yield["z+jets_zmumu_np5_mll10to60"];
    scale["z+jets_ztautau_np0_mll10to60"]   = (1./949896.)  * yield["z+jets_ztautau_np0_mll10to60"];
    scale["z+jets_ztautau_np1_mll10to60"]   = (1./298899.)  * yield["z+jets_ztautau_np1_mll10to60"];
    scale["z+jets_ztautau_np2_mll10to60"]   = (1./397500.)  * yield["z+jets_ztautau_np2_mll10to60"];
    scale["z+jets_ztautau_np3_mll10to60"]   = (1./150000.)  * yield["z+jets_ztautau_np3_mll10to60"];
    scale["z+jets_ztautau_np4_mll10to60"]   = (1./39999. )  * yield["z+jets_ztautau_np4_mll10to60"];
    scale["z+jets_ztautau_np5_mll10to60"]   = (1./10000. )  * yield["z+jets_ztautau_np5_mll10to60"];
    scale["z+jets_vbf_zee_np0"]             = (1./6419080.) * yield["z+jets_vbf_zee_np0"];
    scale["z+jets_vbf_zee_np1"]             = (1./3394288.) * yield["z+jets_vbf_zee_np1"];
    scale["z+jets_vbf_zee_np2"]             = (1./3134987.) * yield["z+jets_vbf_zee_np2"];
    scale["z+jets_vbf_zee_np3"]             = (1./1685796.) * yield["z+jets_vbf_zee_np3"];
    scale["z+jets_vbf_zee_np4"]             = (1./653597. ) * yield["z+jets_vbf_zee_np4"];
    scale["z+jets_vbf_zee_np5"]             = (1./295000. ) * yield["z+jets_vbf_zee_np5"];
    scale["z+jets_vbf_zmumu_np0"]           = (1./1261797.) * yield["z+jets_vbf_zmumu_np0"];
    scale["z+jets_vbf_zmumu_np1"]           = (1./1584693.) * yield["z+jets_vbf_zmumu_np1"];
    scale["z+jets_vbf_zmumu_np2"]           = (1./1734593.) * yield["z+jets_vbf_zmumu_np2"];
    scale["z+jets_vbf_zmumu_np3"]           = (1./1345592.) * yield["z+jets_vbf_zmumu_np3"];
    scale["z+jets_vbf_zmumu_np4"]           = (1./534799. ) * yield["z+jets_vbf_zmumu_np4"];
    scale["z+jets_vbf_zmumu_np5"]           = (1./303498. ) * yield["z+jets_vbf_zmumu_np5"];
    scale["z+jets_vbf_atau_ztautau_np0"]    = (1./1459597.) * yield["z+jets_vbf_atau_ztautau_np0"];
    scale["z+jets_vbf_atau_ztautau_np1"]    = (1./963499. ) * yield["z+jets_vbf_atau_ztautau_np1"];
    scale["z+jets_vbf_atau_ztautau_np2"]    = (1./1078499.) * yield["z+jets_vbf_atau_ztautau_np2"];
    scale["z+jets_vbf_atau_ztautau_np3"]    = (1./731898. ) * yield["z+jets_vbf_atau_ztautau_np3"];
    scale["z+jets_vbf_atau_ztautau_np4"]    = (1./267899. ) * yield["z+jets_vbf_atau_ztautau_np4"];
    scale["z+jets_vbf_atau_ztautau_np5"]    = (1./308896. ) * yield["z+jets_vbf_atau_ztautau_np5"];

    scale["w+jets_wenu_np0"]                = (1./3459890.) * yield["w+jets_wenu_np0"];
    scale["w+jets_wenu_np1"]                = (1./2499491.) * yield["w+jets_wenu_np1"];
    scale["w+jets_wenu_np2"]                = (1./3769487.) * yield["w+jets_wenu_np2"];
    scale["w+jets_wenu_np3"]                = (1./1009997.) * yield["w+jets_wenu_np3"];
    scale["w+jets_wenu_np4"]                = (1./249999. ) * yield["w+jets_wenu_np4"];
    scale["w+jets_wenu_np5"]                = (1./70000.  ) * yield["w+jets_wenu_np5"];
    scale["w+jets_wmunu_np0"]               = (1./3469692.) * yield["w+jets_wmunu_np0"];
    scale["w+jets_wmunu_np1"]               = (1./2499694.) * yield["w+jets_wmunu_np1"];
    scale["w+jets_wmunu_np2"]               = (1./3719890.) * yield["w+jets_wmunu_np2"];
    scale["w+jets_wmunu_np3"]               = (1./1006698.) * yield["w+jets_wmunu_np3"];
    scale["w+jets_wmunu_np4"]               = (1./254999. ) * yield["w+jets_wmunu_np4"];
    scale["w+jets_wmunu_np5"]               = (1./69900.  ) * yield["w+jets_wmunu_np5"];
    scale["w+jets_wtaunu_np0"]              = (1./3419990.) * yield["w+jets_wtaunu_np0"];
    scale["w+jets_wtaunu_np1"]              = (1./1899800.) * yield["w+jets_wtaunu_np1"];
    scale["w+jets_wtaunu_np2"]              = (1./3765989.) * yield["w+jets_wtaunu_np2"];
    scale["w+jets_wtaunu_np3"]              = (1./1009998.) * yield["w+jets_wtaunu_np3"];
    scale["w+jets_wtaunu_np4"]              = (1./249998. ) * yield["w+jets_wtaunu_np4"];
    scale["w+jets_wtaunu_np5"]              = (1./65000.  ) * yield["w+jets_wtaunu_np5"];

    scale["top+lep_top_tchan_e"]            = (1./256853.) * yield["top+lep_top_tchan_e"];
    scale["top+lep_top_tchan_mu"]           = (1./256914.) * yield["top+lep_top_tchan_mu"];
    scale["top+lep_top_tchan_tau"]          = (1./251341.) * yield["top+lep_top_tchan_tau"];

    return scale;
}

map<string,float> yield = get_yield();
map<string,float> scale = get_scale();

#endif
