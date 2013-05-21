/*
 * =====================================================================================
 *
 *       Filename:  draw.cxx
 *
 *    Description:  Draws the histograms in the .root file(s) specified by arguments
 *                  on the command line.
 *
 *        Version:  1.0
 *        Created:  05/02/13 08:18:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson, wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <string>
#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

/*
 * I use an unordered_map in a couple places; using it means
 * I need to compile with C++11, but the fact that I can construct them
 * with a bracket list makes me keep it around.
 */
#include <unordered_map>

#include "AtlasStyle.h"

#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <TString.h>
#include <THStack.h>
#include <TList.h>

#include "xsec_data.h"

using namespace std;

int nfiles;
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
    "cutflow_mH115to135",
    "yield_full",
    "yield_mH115to135"
};

/*
 * Name of each cut done, for labeling bins in the cutflow histogram
 */
const int ncuts = 11;
const string cut_names[ncuts] = {
    "all",
    "iso lep",
    "#tau_{had}",
    "opp ch",
    "tau p_{T}",
    "lep #eta",
    "tau #eta",
    "lep pt",
    "#Delta#phi(MET,#tau)",
//    "colMassOld",
    "#Delta R(MET,#tau)",
    "vis M_{H}"
};

const int n_modes = 4;
const string pmodes[n_modes] = {
    "gg", "vbf", "wh", "zh"
};

const bool draw_low_stats = false;

float get_expected_yield(string fname) {
    // fname currently looks like X_CTn
    // want to just get X
    string nname = fname.substr(0, fname.size()-4);
    return integrated_luminosity*xsecs[nname];
}

string get_base_name(string big_filename) {
    return big_filename.substr(
            big_filename.find_last_of('/') + 1,
            big_filename.size() - big_filename.find_last_of('/') - 6);
}

vector<float> get_cut_efficiencies(bool sig_region_only) {
    vector<float> effs;

    for (int i = 0; i < nfiles; i++) {
        TH1F* cf_hist = 0;
        
        if (sig_region_only) cf_hist = (TH1F*) files[i] -> Get("cutflow_mH115to135");
        else cf_hist = (TH1F*) files[i] -> Get("cutflow_full");

        float begin = cf_hist -> GetBinContent(1);
        float end = cf_hist -> GetBinContent( 4 );

        effs.push_back( end/begin );
    }

    return effs;
}

void draw_sig() {
    for (int i = 0; i < n_modes; i++) {
        TLegend leg(0.75, 0.8, 0.95, 0.95);
        TCanvas canv( "sig", "sig" );

        vector<float> effs = get_cut_efficiencies(true);

        THStack stack("sigstack", "Signal, 115 GeV < m_{H} < 135 GeV;Mass (GeV);Counts");

        TH1F* current_hist = 0;
        int ndrawn = 0;

        for (int j = 0; j < nfiles; j++) {
            string file_base = get_base_name( files[j]->GetName() );
            if (file_base.find("CT0") == string::npos) continue;
            if ( file_base.find("htt") != string::npos || file_base.find("htm") != string::npos )
                if ( file_base.find( pmodes[i] ) == string::npos ) continue;

            current_hist = (TH1F*) files[j]->Get("h_collimNew");
            current_hist -> SetLineColor(ndrawn+1);
            current_hist -> SetFillColor(ndrawn+1);

            while (current_hist->GetNbinsX() > 30) current_hist->Rebin();

            stack.Add( current_hist );
            leg.AddEntry( current_hist, file_base.data(), "f" );

            ndrawn++;
        }

        canv.cd();
        stack.Draw("H");
        leg.Draw();
        canv.Print( ("pix_sig/" + pmodes[i] + ".png").data() );
    }
}

void _draw(vector<TH1F*> hists, vector<string> labels, string out_name, bool logy) {
    TH1F* first_hist = 0;
    int ndrawn = 0;

    TCanvas canv;

    TLegend leg(0.75, 0.8, 0.95, 0.95);

    for (unsigned i = 0; i < hists.size(); i++) {
        TH1F* this_hist = hists.at(i);
        if (!first_hist) first_hist = this_hist;

        this_hist -> SetLineColor(ndrawn+1);
        this_hist -> SetMarkerColor(ndrawn+1);
        this_hist -> SetMarkerStyle(20);

        if (this_hist != first_hist && this_hist->GetMaximum() > first_hist->GetMaximum())
            first_hist -> SetMaximum( this_hist->GetMaximum() * 1.1 );

        canv.cd();
        if (ndrawn == 0) this_hist -> Draw("h");
        else this_hist -> Draw("hsame");

        leg.AddEntry(this_hist, labels.at(i).data(), "pl");

        ndrawn++;
    }

    TList* l = canv.GetListOfPrimitives();
    for (int k = 0; k < l->GetEntries(); k++)

    if (logy) { 
        for (unsigned i = 0; i < hists.size(); i++) hists.at(i) -> SetMinimum(1.);
        canv.SetLogy();
    }

    

    leg.Draw();
    canv.Print(out_name.data());

}

void draw_cuts() {
    for (int i = 0; i < n_modes; i++) {
        for (int j = 0; j < n_cuthists; j++) {
            vector<TH1F*> hists;
            vector<string> legend_labels;

            bool is_yield_hist = (cut_hists[j].find("yield") != string::npos);

            for (int k = 0; k < nfiles; k++) {
                string file_base = get_base_name( files[k]->GetName() );
                if ( file_base.find("CT0") == string::npos ) continue;
                if ( file_base.find("htt") != string::npos || file_base.find("htm") != string::npos )
                    if ( file_base.find( pmodes[i] ) == string::npos ) continue;

                TH1F* this_hist = (TH1F*) files[k] -> Get( cut_hists[j].data() );

                if (!is_yield_hist) this_hist -> Scale(1./this_hist->GetBinContent(1));

                this_hist -> SetMinimum(0.);

                for (int k = 0; k < ncuts; k++)
                    this_hist -> GetXaxis() -> SetBinLabel(k+1, cut_names[k].data());

                hists.push_back(this_hist);
                legend_labels.push_back(file_base);
            }

            _draw(hists, legend_labels, ("pix_cut/" + pmodes[i] + "_" + cut_hists[j] + ".png"), is_yield_hist);
        }
    }
}

void draw_kinem() {
    for (int i = 0; i < n_modes; i++) {
        for (int j = 0; j < n_kinemhists; j++) {
            vector<TH1F*> hists;
            vector<string> legend_labels;

            vector<float> effs = get_cut_efficiencies(false);

            for (int k = 0; k < nfiles; k++) {
                string file_base = get_base_name( files[k]->GetName() );
                if ( file_base.find("CT0") != string::npos ) continue;
                if ( file_base.find("htt") != string::npos || file_base.find("htm") != string::npos )
                    if ( file_base.find( pmodes[i] ) == string::npos ) continue;

                TH1F* this_hist = (TH1F*) files[k] -> Get( kinem_hists[j].data() );

                float hint = this_hist->Integral();
                if (!draw_low_stats && hint < 200) continue;

                if (hint > 0) this_hist -> Scale( 1./hint );

                hists.push_back(this_hist);
                legend_labels.push_back(file_base);
            }

            _draw(hists, legend_labels, ("pix_kinem/" + pmodes[i] + "_" + kinem_hists[j] + ".png"), false);
        }
    }
}

void loadFiles() {
    DIR *dp;
    struct dirent *dirp;

    nfiles = 0;

    dp = opendir("hists");
    while ( (dirp = readdir(dp)) ) {
        if (!TString(dirp->d_name).Contains(".root")) continue;

        files.push_back(new TFile( TString("hists/") + dirp -> d_name ));
        nfiles++;
    }

    closedir(dp);
}

/*
 * Does what it looks like: sets atlas style, calls loadFiles(),
 * then goes through each of the histograms and calls the draw()
 * method for it.
 */
int main() {
    SetAtlasStyle();

    loadFiles();

    draw_kinem();
    draw_cuts();
    draw_sig();

    return 0;
}
