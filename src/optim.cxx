/*
 * =====================================================================================
 *
 *       Filename:  optim.cxx
 *
 *    Description:  Optimizes cuts. Is very sneaky.
 *
 *        Version:  1.0
 *        Created:  05/28/2013 07:33:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <utility>
#include <vector>
#include <sstream>
#include <math.h>

#include <TH1F.h>

#include "DatasetIter.h"
#include "LimTree.h"
#include "common.h"

using namespace std;

/*
 * Here's the idea:
 *
 * Deep inside these maps is a vector of histograms. Each entry in the vector is a "bin" for
 * the cut variable; the lower and upper edges will be defined somewhere else. The histogram at a given
 * "bin" is the signal (or background) mass distribution given that a cut exists at that point.
 *
 * These vectors are arranged in pairs: one for cutting BELOW (pair->first) and one for cutting ABOVE (pair->second).
 *
 * Say we have an event where v = 15, and the vector's "lower edge" is 0, "upper edge" is 100, in steps of 1. Then:
 *      pair->first: each bin x means we throw away events where v is LESS than x. So we fill the histograms from
 *      vector->at(0) from vector->at(14), since v=15 will escape those cuts.
 *
 *      pair->second: each bin x means we throw away events where v is MORE than x. So we fill the histograms from
 *      vector->at(16) to vector->at(100), since v=15 will escape those cuts.
 *  
 *  So we have one of these pairs for every cut variable; that is where the map comes in, mapping the name of a
 *  cut variable to the pair it corresponds to.
 */

map< string, pair< vector<TH1F*>, vector<TH1F*> > > sig_hists;
map< string, pair< vector<TH1F*>, vector<TH1F*> > > bkg_hists;

map< string, pair<float,float> > vec_edges;

// the above maps are initialized in init() below.

const int n_cuts = 8;
const string cut_names[n_cuts] = {
    "lep_pt",
    "dr_met_tau",
    "dphi_met_tau",
    "met",
    "h_vismass",
    "tau_pt",
    "tau_eta",
    "lep_eta"
};

// initialize maps and such, because I can't use c++11
TFile* init() {
    vec_edges["lep_pt"]        = make_pair( 0., 100. );
    vec_edges["tau_pt"]        = make_pair( 0., 100. );
    vec_edges["dr_met_tau"]    = make_pair( 0., 5.   );
    vec_edges["dphi_met_tau"]  = make_pair( 0., 3.2  );
    vec_edges["met"]           = make_pair( 0., 100. );
    vec_edges["h_vismass"]     = make_pair( 0., 150. );
    vec_edges["lep_eta"]       = make_pair( 0., 4.  );
    vec_edges["tau_eta"]       = make_pair( 0., 4.  );

    // okay now initializing the hist maps will be complicated. First we'll open a file to throw the
    // histograms into:
    TFile* fout = new TFile("hists/optim.root", "recreate");
    
    //iterate over each cut name:
    for (int i = 0; i < n_cuts; i++) {
        // before we do make_pair(v1,v2) we need to actually come up with the vectors.
        vector<TH1F*> sig_vfirst;
        vector<TH1F*> sig_vsecond;

        vector<TH1F*> bkg_vfirst;
        vector<TH1F*> bkg_vsecond;

        // and push histograms onto each of them. But! Each histogram needs a unique name.
        // the name will look like:
        //                                  <cut-name>_<sig|bkg>_<below|above>_bin_<bin-number>
        for (int j = 0; j < 100; j++) {
            stringstream ssuffix;
            ssuffix << "bin_" << j;
            string suffix = ssuffix.str();

            sig_vfirst.push_back(  new TH1F( (cut_names[i] + "_sig_below_" + suffix).data(), ";Collinear Higgs mass w/ m_{#tau} constraint;Counts", 100, 0., 150. ) );
            sig_vsecond.push_back( new TH1F( (cut_names[i] + "_sig_above_" + suffix).data(), ";Collinear Higgs mass w/ m_{#tau} constraint;Counts", 100, 0., 150. ) );

            bkg_vfirst.push_back(  new TH1F( (cut_names[i] + "_bkg_below_" + suffix).data(), ";Collinear Higgs mass w/ m_{#tau} constraint;Counts", 100, 0., 150. ) );
            bkg_vsecond.push_back( new TH1F( (cut_names[i] + "_bkg_above_" + suffix).data(), ";Collinear Higgs mass w/ m_{#tau} constraint;Counts", 100, 0., 150. ) );
        }

        // now make a pair and send it to the map
        sig_hists[ cut_names[i] ] = make_pair( sig_vfirst, sig_vsecond );
        bkg_hists[ cut_names[i] ] = make_pair( bkg_vfirst, bkg_vsecond );
    }

    gDirectory -> cd();

    return fout;
}

/*
 * returns the bin number that val corresponds to for the given cut name.
 * All the vectors have a hundred bins, so the bottom and top cut variable edges
 * are all we need.
 *
 * assumes that cut_name is a valid name.
 */
int get_bin_number(string cut_name, float val) {
    pair<float,float> edges = vec_edges[cut_name];
    float bin_width = (edges.second - edges.first)/100.;
    int bn = floor( (val - edges.first)/bin_width );
    return bn;
}

void fill(string cut_name, bool is_sig, float cut_var, float sig_var, float weight) {
    pair< vector<TH1F*>, vector<TH1F*> > hv;

    if (is_sig) hv = sig_hists[cut_name];
    else hv = bkg_hists[cut_name];

    int bn = get_bin_number( cut_name, cut_var );

    for (int i = 0; i < 100; i++) {
        if (i < bn)
            (hv.first).at(i) -> Fill(sig_var, weight);
        else if (i > bn)
            (hv.second).at(i) -> Fill(sig_var, weight);
    }
}

int main() {
    TFile* fout = init();

    DatasetIter di;
    LimTree* lt;

    // loop over all datasets
    while ( (lt = di.next()) ) {
        string ds_name = di.get_dataset_name();

        // only do htm for now
        if ( contains(ds_name, "hte") ) {
            delete lt;
            cout << "   ... skipping ..." << endl;
            continue;
        }

        // loop over events in each dataset
        long events_read = 0;
        while ( (events_read = lt -> load_next() + 1) ) {
            if (events_read % 5000 == 0) cout << "  " << events_read << " events read" << endl;

            // first make sure that the first few tags were done (tauhad, isolated lep, ...)
            // these are the first five cuts in LimTree
            for (int i = 0; i < 5; i++)
                if ( !(lt->cuts).at(i) ) continue;

            bool sig = contains(ds_name, "htm");
            float sval = lt->collim_mH_new();
            float weight = (lt->weight)*(lt->get_hist_scale());

            fill( "lep_pt",        sig,  lt->pLep.Pt(),                sval, weight );
            fill( "tau_pt",        sig,  lt->pTau.Pt(),                sval, weight );
            fill( "dr_met_tau",    sig,  lt->pTau.DeltaR(lt->pMet),    sval, weight );
            fill( "dphi_met_tau",  sig,  lt->pTau.DeltaPhi(lt->pMet),  sval, weight );
            fill( "met",           sig,  lt->pMet.Pt(),                sval, weight );
            fill( "h_vismass",     sig,  lt->vis_mH(),                 sval, weight );
            fill( "lep_eta",       sig,  fabs(lt->pLep.Eta()),         sval, weight );
            fill( "tau_eta",       sig,  fabs(lt->pTau.Eta()),         sval, weight );
        }

        delete lt;
    }

    fout -> Write(); fout -> Close();

    return 0;
}
