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
#include "yield_data.h"

using namespace std;

vector<TFile*> files;

const int n_kinemhists = 14;
const string kinem_hists[n_kinemhists] = {
    "h_vismass",
    "h_collimOld",
    "h_collimNew",
    "h_pT",
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

const int n_cuthists = 4;
const string cut_hists[n_cuthists] = {
    "cutflow_full",
    "cutflow_sig_region",
    "yield_full",
    "yield_sig_region"
};

const int n_cuts = LimTree::ncuts + 1;
vector<string> cut_names() {
    vector<string> cn;
    cn.push_back("all");
    cn.push_back("iso lep");
    cn.push_back("#tau_{had}");
    cn.push_back("opp ch");
    cn.push_back("tau p_{T}");
    cn.push_back("lep #eta");
    cn.push_back("tau #eta");
    cn.push_back("lep pt");
    cn.push_back("#Delta#phi(MET,#tau)");
//  cn.push_back(  "colMassOld");
    cn.push_back("#Delta R(MET,#tau)");
    cn.push_back("vis M_{H}");
    return cn;
}

const int n_chan = 4;
string chan[n_chan] = {
    "gg", "vbf", "wh", "zh"
};

string get_base_name(string big_filename) {
    return big_filename.substr(
            big_filename.find_last_of('/') + 1,
            big_filename.size() - big_filename.find_last_of('/') - 6);
}

map<string,TH1F*> get_hists(string hist_name, string p_chan, bool cut_tolerance_nonzero) {
    map<string,TH1F*> combined_hists;

    TH1F* current_combined;
    TH1F* htt_hist;
    TH1F* lfv_hist;

    bool first_done = false;

    for (int i = 0; i < n_bkg_groups; i++) {
        for (unsigned f = 0; f < files.size(); f++) {
            string file_base = get_base_name( files.at(f) -> GetName() );

            if ( contains(file_base, "CT0") ) {
                if (cut_tolerance_nonzero) continue;
            } else {
                if (!cut_tolerance_nonzero) continue;
            }

            cout << file_base << endl;

            if ( contains(file_base, bkg_groups[i]) ) {
                if (first_done) {
                    TH1F* hhh = (TH1F*) files.at(f) -> Get(hist_name.data());

                    cout << "current_combined int " << current_combined->Integral() << endl;
                    cout << "hhh              int " << hhh -> Integral() << endl;

                    current_combined -> Add( hhh );
                } else {
                    cout << "initializing c_c" << endl;
                    current_combined = new TH1F(*((TH1F*)files.at(f) -> Get(hist_name.data())));
                    first_done = true;
                }
            } else {
                if ( !contains(file_base, p_chan) ) continue;
                else {
                    if (!htt_hist && contains(file_base, "htt")) 
                        htt_hist = (TH1F*) files.at(f) -> Get(hist_name.data());
                    else if (!lfv_hist && contains(file_base, "htm"))
                        lfv_hist = (TH1F*) files.at(f) -> Get(hist_name.data());
                }
            }
        }

        combined_hists[bkg_groups[i]] = current_combined;
    }

    combined_hists["htt"] = htt_hist;
    combined_hists["lfv"] = lfv_hist;

    return combined_hists;
}

void draw_sig() {
    for (int c = 0; c < n_chan; c++) {
        TLegend leg(0.05, 0.8, 0.25, 0.95);
        TCanvas canv;
        
        THStack stack("sigstack", ";Collim. m_{H} with #tau mass constraint;Yield");

        map<string,TH1F*> hists = get_hists("h_collim_new", chan[c], false);

        TH1F* this_hist = 0;
        int ndrawn = 0;
        for ( map<string,TH1F*>::iterator it = hists.begin(); it != hists.end(); ++it ) {
            if ( contains( it->first, "lfv" ) ) continue; // save lfv for later
            this_hist = it->second;

            this_hist -> SetLineColor(ndrawn+2);
            this_hist -> SetFillColor(ndrawn+2);

            stack.Add( this_hist );
            leg.AddEntry( this_hist, (it->first).data(), "f" );

            ndrawn++;
        }

        hists["lfv"] -> SetLineColor(1);
        hists["lfv"] -> SetFillColor(1);

        stack.Add( hists["lfv"] );
        leg.AddEntry( hists["lfv"], "htm", "f" );

        canv.cd();
        stack.Draw("h");
        leg.Draw();
        canv.Print( ("pix_sig/" + chan[c] + ".png").data() );
    }
}

void _draw(map<string,TH1F*> hists, string out_name, bool logy) {
    TCanvas canv;
    TLegend leg(0.75, 0.8, 0.95, 0.95);

    int ndrawn = 0;
    for (map<string,TH1F*>::iterator it = hists.begin(); it != hists.end(); ++it) {
        TH1F* this_hist = it->second;

        if (contains(it->first, "lfv")) {
            this_hist -> SetLineColor(1);
            this_hist -> SetMarkerColor(1);
        } else {
            this_hist -> SetLineColor(ndrawn + 2);
            this_hist -> SetMarkerColor(ndrawn + 2);

            if ( this_hist->GetMaximum() > hists["lfv"]->GetMaximum() )
                hists["lfv"] -> SetMaximum( this_hist->GetMaximum() * 1.1 );
        }
        
        this_hist -> SetMarkerStyle(20);

        if (logy && this_hist->GetMinimum() < 1) this_hist->SetMinimum(1.);

        canv.cd();
        if (ndrawn == 0) this_hist->Draw("h");
        else this_hist->Draw("hsame");

        leg.AddEntry(this_hist, (it->first).data(), "pl");

        ndrawn++;
    }

    if (logy) canv.SetLogy();

    leg.Draw();
    canv.Print(out_name.data());
}

void draw_cuts() {
    for (int c = 0; c < n_chan; c++) {
        for (int h = 0; h < n_cuthists; h++) {
            bool is_yield_hist = contains(cut_hists[h], "yield");

            map<string,TH1F*> hists = get_hists( cut_hists[h], chan[c], false );

            for (map<string,TH1F*>::iterator it = hists.begin(); it != hists.end(); ++it) {
                TH1F* this_hist = it->second;

                if (!is_yield_hist) {
                    this_hist -> Scale(1./this_hist->GetBinContent(1));
                    this_hist -> SetMinimum(0.);
                } else {
                    this_hist -> SetMinimum(1.); // for ploting on a log scale
                }
                
                for (int k = 0; k < n_cuts; k++)
                    this_hist -> GetXaxis() -> SetBinLabel(k+1, cut_names().at(k).data());

            }

            _draw(hists, ("pix_cut/" + chan[c] + "_" + cut_hists[h] + ".png"), is_yield_hist);
        }
    }
}

void draw_kinem() {
    for (int c = 0; c < n_chan; c++) {
        for (int h = 0; h < n_kinemhists; h++) {
            map<string,TH1F*> hists = get_hists( kinem_hists[h], chan[c], true );

            for (map<string,TH1F*>::iterator it = hists.begin(); it != hists.end(); ++it) {
                TH1F* this_hist = it->second;

                float hint = this_hist -> Integral();
                if (hint > 0) this_hist -> Scale(1./hint);
            }

            _draw(hists, ("pix_kinem/" + chan[c] + "_" + kinem_hists[h] + ".png"), false);
        }
    }
}

void load_files() {
    DIR* dp;
    struct dirent* dirp;

    dp = opendir("hists");
    if (dp) {
        while ( (dirp = readdir(dp)) ) {
            if ( !contains(dirp->d_name, ".root") ) continue;

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
