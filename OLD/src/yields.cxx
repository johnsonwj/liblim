/*
 * =====================================================================================
 *
 *       Filename:  yields.cxx
 *
 *    Description:  Calculates expected yields and writes out to data/yield. 
 *
 *        Version:  1.0
 *        Created:  05/17/13 02:53:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "xsec_data.h"

using namespace std;

vector<string> names;
vector<float> cut_effs;
vector<float> precut_yield;
vector<float> final_yield;

int main() {
    ifstream cut_eff("data/eff");
    string line;
    while (getline(cut_eff, line)) {
        stringstream ls(line);
        string name;
        float start,end;
        if ( !( ls >> name >> start >> end ) ) continue;

        names.push_back(name);
        cut_effs.push_back(end/start);
        precut_yield.push_back( xsecs[name]*integrated_luminosity );
        final_yield.push_back( xsecs[name]*integrated_luminosity*end/start );
    }
    cut_eff.close();

    ofstream ystr("data/yraw");

    for ( unsigned int i = 0; i < names.size(); i++ ) {
        ystr << names.at(i) 
            << " " << cut_effs.at(i) 
            << " " << precut_yield.at(i)
            << " " << final_yield.at(i)
            << endl;
    }

    ystr.close();
}
