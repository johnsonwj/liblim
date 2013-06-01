/*
 * =====================================================================================
 *
 *       Filename:  draw.cxx
 *
 *    Description:  draws histograms created by dohists
 *
 *        Version:  1.0
 *        Created:  05/25/2013 02:36:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <vector>
#include <dirent.h>

#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <THStack.h>

#include "AtlasStyle.h"
#include "LimTree.h"
#include "common.h"

using namespace std;

vector<TFile*> files;

const int n_kinemhists = 14;
const string kinem_hists[n_kinemhists] = {
    "h_vismass",
    "h_collim_old",
    "h_collim_new",
    "h_pt",
    "h_eta",
    "lep_pt",
    "lep_eta",
    "lep_phi",
    "tau_pt",
    "tau_eta",
    "tau_phi",
    "met",
    "dr_met_tau",
    "dphi_met_tau" };

const int n_cuthists = 2;
const string cut_hists[n_cuthists] = {
    "cutflow_full",
    "yield_full",
};

const int n_cuts = LimTree::ncuts + 1;
vector<string> cut_names() {
    vector<string> cn;
    cn.push_back("all");
    cn.push_back("tau tag");
    cn.push_back("dilepton veto");
    cn.push_back("opp ch");
    cn.push_back("iso lep");
    cn.push_back("#tau_{had}");
    cn.push_back("tau p_{T}");
    cn.push_back("lep pt");
    cn.push_back("#Delta#phi(MET,#tau)");
    cn.push_back("#Delta R(MET,#tau)");
    return cn;
}


const int n_chan = 4;
string chan[n_chan] = {
    "gg", "vbf", "wh", "zh"
};

const int n_bkg_groups = 4;
const string bkg_groups[n_bkg_groups] = {
    "diboson", "z+jets", "w+jets", "top+lep"
};

string get_base_name(string big_filename) {
    return big_filename.substr(
            big_filename.find_last_of('/') + 1,
            big_filename.size() - big_filename.find_last_of('/') - 6);
}

vector<TH1F*> get_hists(string hist_name, string p_chan, bool cut_tolerance_nonzero) {
    TH1F* htt = 0;
    TH1F* lfv = 0;

    map< string,vector<TH1F*> > bkgs;
    // initialize map values
    for (int i = 0; i < n_bkg_groups; i++)
        bkgs[bkg_groups[i]] = vector<TH1F*>();

    for (unsigned i = 0; i < files.size(); i++) {
        string bname = get_base_name( files.at(i) -> GetName() );

        if ( !(cut_tolerance_nonzero ^ contains(bname, "CT0")) ) continue;
        if ( contains(bname, "ht") && !contains(bname, p_chan) ) continue;

        TH1F* hhist = (TH1F*) files.at(i) -> Get(hist_name.data());

        for (int j = 0; j < n_bkg_groups; j++) {
            if ( contains(bname, bkg_groups[j]) )
                bkgs[bkg_groups[j]].push_back(hhist);
        }

        if ( contains(bname, "htm") && !lfv ) lfv = hhist; 

        if ( contains(bname, "htt") && !htt ) htt = hhist; 
    }

    vector<TH1F*> combined_hists;

    combined_hists.push_back(lfv);
    combined_hists.push_back(htt);

    for (int i = 0; i < n_bkg_groups; i++) {
        TH1F* combi = bkgs[bkg_groups[i]].at(0);
        for (unsigned j = 1; j < bkgs[bkg_groups[i]].size(); j++) {
            combi -> Add( bkgs[bkg_groups[i]].at(j) );
        }
        combined_hists.push_back(combi);
    }

    return combined_hists;
}

void draw_sig() {
    for (int c = 0; c < n_chan; c++) {
        TLegend leg(0.2, 0.7, 0.4, 0.9);
        TCanvas canv;
        
        THStack stack("sigstack", ";Collim. m_{H} with #tau mass constraint;Yield");

        vector<TH1F*> hists = get_hists("h_collim_new", chan[c], false);

        for ( unsigned i = 0; i < hists.size(); i++ ) {
            hists.at(i) -> SetLineColor(i+1);
            hists.at(i) -> SetFillColor(i+1);

            if (i == 0) continue; // save lfv hist for last

            string nname;
            if (i == 1) nname = "htt";
            else nname = bkg_groups[i-2];

            stack.Add( hists.at(i) );
            leg.AddEntry( hists.at(i), nname.data(), "f" );
        }

        stack.Add( hists.at(0) );
        leg.AddEntry( hists.at(0), "lfv", "f" );

        stack.Draw("h");
        leg.Draw();
        canv.Print( ("pix_sig/" + chan[c] + ".png").data() );
    }
}

void _draw(vector<TH1F*> hists, string out_name, bool logy) {
    TCanvas canv;
    TLegend leg(0.75, 0.8, 0.95, 0.95);

    for (unsigned i = 0; i < hists.size(); i++) {
        hists.at(i) -> SetLineColor(i+1);
        hists.at(i) -> SetMarkerColor(i+1);
        hists.at(i) -> SetMarkerStyle(20);

        // if we want to plot on a logarithmic scale, the x axis should start at a positive number!
        if (logy) // && hists.at(i) -> GetMinimum() < 1.)
            hists.at(i) -> SetMinimum(1.);

        // make sure no one goes off the page
        if (i > 0 && hists.at(i)->GetMaximum() > hists.at(0)->GetMaximum())
            hists.at(0) -> SetMaximum( hists.at(i) -> GetMaximum() * 1.1 );

        string nname;
        if (i==0)
            nname = "lfv";
        else if (i==1) 
            nname = "htt";
        else 
            nname = bkg_groups[i-2];

        leg.AddEntry( hists.at(i), nname.data(), "l" );
    }

    canv.cd();
    hists.at(0) -> Draw("h");
    for (unsigned i = 1; i < hists.size(); i++)
        hists.at(i) -> Draw("hsame");

    if (logy) canv.SetLogy();

    leg.Draw();
    canv.Print(out_name.data());
}

void draw_cuts() {
    for (int c = 0; c < n_chan; c++) {
        for (int h = 0; h < n_cuthists; h++) {
            bool is_yield_hist = contains(cut_hists[h], "yield");

            vector<TH1F*> hists = get_hists( cut_hists[h], chan[c], false );

            for (unsigned i = 0; i < hists.size(); i++) {
                if (!is_yield_hist) {
                    hists.at(i) -> Scale( 1./ (hists.at(i) -> GetBinContent(1)) );
                    hists.at(i) -> SetMinimum(0.);
                }

                for (int k = 0; k < n_cuts; k++)
                    hists.at(i) -> GetXaxis() -> SetBinLabel(k+1, cut_names().at(k).data());

            }

            _draw(hists, ("pix_cut/" + chan[c] + "_" + cut_hists[h] + ".png"), is_yield_hist);
        }
    }
}

void draw_kinem() {
    for (int c = 0; c < n_chan; c++) {
        for (int h = 0; h < n_kinemhists; h++) {
            vector<TH1F*> hists = get_hists( kinem_hists[h], chan[c], true );

            vector<TH1F*> hists_good_statistics;

            for (unsigned i = 0; i < hists.size(); i++) {
                float hint = hists.at(i) -> Integral();
                if (hint > 0) hists.at(i) -> Scale(1./hint);

                if ( hists.at(i) -> GetEntries() > 500 ) hists_good_statistics.push_back(hists.at(i));
            }

            _draw(hists_good_statistics, ("pix_kinem/" + chan[c] + "_" + kinem_hists[h] + ".png"), false);
        }
    }
}

void load_files() {
    DIR* dp;
    struct dirent* dirp;

    dp = opendir("hists");
    if (dp) {
        while ( (dirp = readdir(dp)) ) {
            if ( contains(dirp->d_name, "hte") || !contains(dirp->d_name, ".root") ) continue;

            files.push_back( new TFile( (string("hists/") + dirp->d_name).data() ) );
        }

        closedir(dp);
    }
}

int main() {
    SetAtlasStyle();

    load_files();

    draw_kinem();
    draw_cuts();
    draw_sig();

    return 0;
}
