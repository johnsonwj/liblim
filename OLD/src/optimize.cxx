/*
 * =====================================================================================
 *
 *       Filename:  optimize.cxx
 *
 *    Description:  Optimizes cuts for five kinematic variables:
 *                  lepton pt
 *                  delta_phi (met, tau)
 *                  met
 *                  delta_R (met, tau)
 *                  mass (lep, tau)
 *
 *        Version:  1.0
 *        Created:  05/15/13 23:30:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <iostream>
#include <dirent.h>
#include <math.h>

#include <TH1F.h>
#include <TFile.h>
#include <TString.h>
#include <TCanvas.h>

#include "xsec_data.h"

const int nvars = 5;
const string cut_vars[nvars] = {
    "lep_pt", "dphi_met_tau", "dr_met_tau", "met", "h_vismass"
};

/*
 * Returns a vector of histograms; the one at place 0 is signal, the rest are bkg.
 */
vector<TH1F*> get_hists(string chan, string var_name) {
    vector<TH1F*> hists;
    vector<float> xsec_vec;

    vector<float> non_kinem_cut_eff;

    DIR *dp;
    struct dirent *dirp;

    TFile* currentf = 0;

    dp = opendir("hists");
    while ( (dirp = readdir(dp)) ) {
        TString tname( dirp -> d_name );
        string nname = string(tname.Data()).substr(0, tname.Sizeof()-18);


        if (!tname.Contains(".root")) continue;
        if (!tname.Contains("noKinemCuts")) continue;

        currentf = new TFile( "hists/" + tname );

        TH1F* cuth = (TH1F*)currentf->Get("cutflow");


        if ( tname.Contains("ht") ) {
            if ( !tname.Contains(chan.data()) ) continue;
            else if ( tname.Contains("htm") ) {
                hists.insert( hists.begin(), (TH1F*) currentf -> Get( var_name.data() ) );
                xsec_vec.insert( xsec_vec.begin(), xsecs[nname] );

                non_kinem_cut_eff.insert( non_kinem_cut_eff.begin(), cuth->GetBinContent(4)/cuth->GetBinContent(1));
                continue;
            }
        }

        hists.push_back( (TH1F*) currentf->Get( var_name.data() ) );
        xsec_vec.push_back( xsecs[nname] );
        non_kinem_cut_eff.push_back( cuth->GetBinContent(4)/cuth->GetBinContent(1));
    }

    for (unsigned int i = 0; i < hists.size(); i++) {
        float hint = hists.at(i) -> Integral();

        //hists.at(i) -> Scale( integrated_luminosity*xsec_vec.at(i) / hint / 10000);
        hists.at(i) -> Scale( 1. / hint );

    }

    return hists;
}

int choose_best_cut(int nbins, float eff_from_below[], float eff_from_above[]) {
    int max_below_bin = 0;
    float max_below_val = 0.;
    for (int i = 0; i < nbins; i++) {
        if (eff_from_below[i] > max_below_val) {
            max_below_val = eff_from_below[i];
            max_below_bin = i;
        }
    }

    int max_above_bin = 0;
    float max_above_val = 0;
    for (int i = 0; i < nbins; i++) {
        if (eff_from_above[i] > max_above_val) {
            max_above_val = eff_from_above[i];
            max_above_bin = i;
        }
    }

    if (max_above_val > max_below_val)
        return max_above_bin;

    return -1*max_below_bin;
}

void judge(int index, TH1F* sig_hist, int cut_bin) {
    float hist_lo   = sig_hist->GetXaxis()->GetXmin();
    float hist_hi   = sig_hist->GetXaxis()->GetXmax();
    float bin_width = (hist_hi-hist_lo)/sig_hist->GetNbinsX();

    // if the best sig:bkg ratio was obtained coming from above (cut_bin>0),
    // then cut values BELOW that bin. Likewise, if the best sig:bkg was
    // obtained from below (cut_bin<0), then cut values ABOVE that bin.
    
    cout << cut_vars[index] << ": ";

    if (cut_bin > 0)
        cout << "cut below " << hist_hi - cut_bin*bin_width << endl;
    else
        cout << "cut above " << hist_lo - cut_bin*bin_width << endl;
}

bool check_bin(TH1F* hist, int bin_number, bool from_below) {
    float half_max = 0.5*hist->GetMaximum();

    if (from_below) {
        return (bin_number > hist->FindLastBinAbove(half_max));
    }

    return (bin_number < hist->FindFirstBinAbove(half_max));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "need to supply a production channel: gg, vbf, wh, zh" << endl;
        return 1;
    }

    if ( !TString("gg vbf wh zh").Contains( argv[1] ) ) {
        cout << "invalid production channel" << endl;
        return 1;
    }

    for (int i = 0; i < nvars; i++) {
        vector<TH1F*> hists = get_hists( argv[1], cut_vars[i] );

        TH1F* sig_hist = hists.at(0);
        TH1F* bkg_hist = hists.at(1);

        for (unsigned int i = 2; i < hists.size(); i++)
            bkg_hist -> Add( hists.at(i) );

        TCanvas c1; sig_hist->Draw("h"); c1.Print("pix_opt/" + TString(cut_vars[i]) + "_opt_sig.png");
        TCanvas c2; bkg_hist->Draw("h"); c2.Print("pix_opt/" + TString(cut_vars[i]) + "_opt_bkg.png");

        int nbins = sig_hist -> GetNbinsX();

        float cumsigsum = 0.;
        float cumbkgsum = 0.;

        float eff_from_below[ nbins ];
        for (int i = 1; i <= nbins; i++) {
            if (!check_bin(sig_hist, i, true)) {
                eff_from_below[i] = 0.; continue;
            }

            cumsigsum += sig_hist -> GetBinContent(i);
            cumbkgsum += bkg_hist -> GetBinContent(i);
            //cout << cumsigsum << " " << cumbkgsum << endl;
            eff_from_below[i] = cumsigsum/cumbkgsum;
            //cout << "below " << i << " " << eff_from_below[i] << endl;
        }

        cumsigsum = 0.;
        cumbkgsum = 0.;

        float eff_from_above[ sig_hist -> GetNbinsX() ];
        for (int i = nbins; i >= 1; i--) {
            if (!check_bin(sig_hist, i, false)) {
                eff_from_above[i] = 0.; continue;
            }

            cumsigsum += sig_hist -> GetBinContent(i);
            cumbkgsum += bkg_hist -> GetBinContent(i);
            eff_from_above[i] = cumsigsum/cumbkgsum;
            //cout << "above " << i << " " << eff_from_above[i] << endl;
        }

        judge(i, sig_hist, choose_best_cut(nbins, eff_from_below, eff_from_above));
    }
}
