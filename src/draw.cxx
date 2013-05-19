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

#include "xsec_data.h"

using namespace std;

int nfiles;
vector<TFile*> files;

const int nhists = 18;
const string histNames[nhists] = {
    "h_vismass",
    "h_collimOld",
    "h_collimNew",
    "x_tau",
    "x_lep",
    "cutflow",
    "yield",
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

/*
 * Name of each cut done, for labeling bins in the cutflow histogram
 */
const int ncuts = 12;
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
    "colMassOld",
    "#Delta R(MET,#tau)",
    "vis M_{H}"
};

const bool draw_low_stats = false;

float getExpectedYield(string fname) {
    // fname currently looks like X_CTN
    // want to just get X
    string nname = fname.substr(0, fname.size()-4);
    return integrated_luminosity*xsecs[nname];
}

string getBaseName(string big_filename) {
    return big_filename.substr(
            big_filename.find_last_of('/') + 1,
            big_filename.size() - big_filename.find_last_of('/') - 6);
}

vector<float> getCutEfficiencies() {
    vector<float> effs;

    for (int i = 0; i < nfiles; i++) {
        TH1F* cf_hist = (TH1F*) files[i] -> Get("cutflow");
        float begin = cf_hist -> GetBinContent(1);
        float end = cf_hist -> GetBinContent( 4 );

        effs.push_back( end/begin );
    }

    return effs;
}

void draw(string name, string filename_suffix) {
    bool is_yield_hist = (name.find("yield") != string::npos);

    TH1F* first_hist = 0;
    int ndrawn = 0;

    TLegend* leg = new TLegend(0.75, 0.8, 0.95, 0.95);

    TCanvas canv(name.data(), name.data());
    if (is_yield_hist) canv.SetLogy();

    vector<float> effs = getCutEfficiencies();

    for (int i = 0; i < nfiles; i++) {
        /*
         * "/phys/users/.../filename.root" --> "filename"
         */
        string file_base = getBaseName( files[i] -> GetName() );

        if ( file_base.find(filename_suffix) == string::npos ) continue;

        TH1F* this_hist = 0;
        if ( !is_yield_hist )
            this_hist = (TH1F*) files[i] -> Get(name.data());
        else
            this_hist = (TH1F*) files[i] -> Get("cutflow");

        if ( !first_hist) first_hist = this_hist;


        /*
         * I treat the cutflow histogram and the kinematic ones differently.
         * cutflow gets bin labels and is scaled so that the first bin is at 1,
         * so the histogram represents the proportion of events left after each cut
         * regardless of how many events were put in it.
         *
         * Kinematic histograms get scaled to expected yield.
         */
        if ( TString(this_hist->GetName()).Contains("cutflow") ) {
            this_hist -> Scale( 1. / this_hist->GetBinContent(1) );
            this_hist -> SetMinimum(0.);

            if (is_yield_hist) {
                float y = getExpectedYield(file_base);
                this_hist -> SetMaximum(y);
                this_hist->Scale(y);
            }

            for (int j = 1; j <= ncuts; j++)
                this_hist -> GetXaxis() -> SetBinLabel(j, cut_names[j-1].data());

        } else {
            float hint = this_hist -> Integral();

            if (filename_suffix.at(2) == '0') {
                while (this_hist->GetNbinsX() > 25)
                    this_hist->Rebin();

                // first scale to expected yield
                if (hint>0)
                    this_hist -> Scale( getExpectedYield(file_base) / hint / 10000);

                // now scale to non kinem cuts
                this_hist -> Scale( effs.at(i) );
                this_hist -> Sumw2();
            } else {
                if (!draw_low_stats && hint < 200 && filename_suffix.at(2) != '0') continue;

                if (hint > 0)
                    this_hist->Scale(1./hint);
                else
                { cout << hint << endl; this_hist->Scale(0); }
            }
            
            //this_hist -> Scale( 1./hint );
            
//            TCanvas secret_canvas("secret","secret");
//            secret_canvas.cd();
//            this_hist->Draw();
//            secret_canvas.Print((file_base + "-" + name + ".png").data());
        }

        this_hist -> SetLineColor(ndrawn+1);
        this_hist -> SetMarkerColor(ndrawn+1);
        this_hist -> SetMarkerStyle(20);


        /*
         * Make sure none of them go off the top of the page
         */
        if ( this_hist != first_hist && this_hist->GetMaximum() > first_hist->GetMaximum())
          first_hist -> SetMaximum( this_hist -> GetMaximum() * 1.1 );
        
        canv.cd();
        if (ndrawn == 0) {
            this_hist -> Draw("h");
        } else
            this_hist -> Draw("hsame");

        leg -> AddEntry( this_hist, file_base.data(), "pl" );
        ndrawn++;
    }

    leg -> Draw();

    canv.Print(("pix_" + filename_suffix + "/" + name + ".png").data());
    // augh, blank picture!
}

/*
 * Goes through the hists/ directory and opens each file in there, pushing it
 * on to the files vector.
 */
void loadFiles(string pmode) {
  DIR *dp;
  struct dirent *dirp;

  nfiles = 0;

  dp = opendir("hists");
  while ( (dirp = readdir(dp)) ) {
    if (!TString(dirp->d_name).Contains(".root")) continue;

    if ( (TString(dirp->d_name).Contains("htt") || TString(dirp->d_name).Contains("htm")) 
            && !TString(dirp->d_name).Contains(pmode.data()) ) continue;

    // if (!TString(dirp->d_name).Contains("noKinemCuts")) continue;

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
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "name a production mode: gg,vbf,wh,zh" << endl;
        return 1;
    }

    if (string("gg vbf wh zh").find(argv[1]) == string::npos) {
        cout << "invalid production mode" << endl;
        return 1;
    }

    SetAtlasStyle();

    loadFiles(argv[1]);

    for (int i = 0; i < nhists; i++) {
        draw( histNames[i], "CT0" );
        draw( histNames[i], "CT5" );
    }

    return 0;
}
