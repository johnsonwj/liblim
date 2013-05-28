/*
 * =====================================================================================
 *
 *       Filename:  yields.cxx
 *
 *    Description:  Writes expected yields out to data/yield.
 *
 *        Version:  1.0
 *        Created:  05/25/2013 03:29:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (), wjohnson@cern.ch
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "common.h"

using namespace std;

vector<string> names;
//vector<float>  cut_effs;
vector<float>  precut_yield;
vector<float>  scale;
//vector<float>  final_yield;

float integrated_luminosity = 20.3398; // fb-1

int main() {
//    ifstream cut_eff("data/eff");
//    string line;
//    while (getline(cut_eff, line)) {
//        stringstream ls(line);
//        string name;
//        float start,end;
//        if (!(ls >> name >> start >> end)) continue;
//
//        names.push_back(name);
//        cut_effs.push_back(end/start);
//        precut_yield.push_back( yield[name] );
//        final_yield.push_back( yield[name] * end / start );
//    }
//    cut_eff.close();

    ifstream infile("data/datasets");

    string line;
    while (getline(infile,line)) {
        if (line.size() < 10 || line.at(0) == '#') continue;

        istringstream iss(line);
        string name,dsid;
        float a,b,c,n;
        if (iss >> name >> dsid >> a >> b >> c >> n) {
            names.push_back(name);

            float y = a*b*c*1000*integrated_luminosity; // 1000 factor is because xsecs are in pb
            precut_yield.push_back(y);
            scale.push_back(y/n);
        }
    }
    infile.close();

    ofstream ystr("data/yraw");

//    for ( unsigned int i = 0; i < names.size(); i++ ) {
//        ystr << names.at(i) 
//            << " " << cut_effs.at(i) 
//            << " " << precut_yield.at(i)
//            << " " << final_yield.at(i)
//            << endl;
//    }

    for (unsigned i = 0; i < names.size(); i++) {
        ystr << names.at(i)
            << "  " << precut_yield.at(i)
            << "  " << scale.at(i)
            << endl;
    }
    ystr.close();
}
