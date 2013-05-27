/*
 * =====================================================================================
 *
 *       Filename:  DatasetIter.h
 *
 *    Description:  This class iterates through the list of datasets given in 
 *                  ../data/datasets and creates a LimTree which is used to fill
 *                  histograms.
 *
 *        Version:  1.0
 *        Created:  05/24/2013 05:14:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#ifndef DSIter_h
#define DSIter_h

#include <vector>
#include <dirent.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include <TChain.h>

#include "LimTree.h"
#include "common.h"

using namespace std;

class DatasetIter {
    public:
        DatasetIter();
        virtual ~DatasetIter();

        bool next();

        LimTree* get_limtree();
        string get_output_filename();

    private:
        unsigned current_dataset_index;

        static const string ds_dir; 
        static const string dslist_file;  

        static const float integrated_luminosity;

        vector<string> names;
        vector<string> dsids;
        vector<float>  yields;
        vector<float>  scales;
};

#endif

#ifdef DSIter_impl

const string DatasetIter::ds_dir = "/phys/groups/tev/scratch3/users/dataset/lhCNv01-04/";
const string DatasetIter::dslist_file  = "data/datasets";
const float DatasetIter::integrated_luminosity = 20.3398; // fb-1

DatasetIter::DatasetIter() {
    
    current_dataset_index = -1;

    ifstream infile(dslist_file.data());

    string line;
    while (getline(infile,line)) {
        if (line.size() < 10 || line.at(0) == '#') continue;

        istringstream iss(line);
        string name,dsid;
        float a,b,c,n
        if (iss >> name >> dsid >> a >> b >> c >> n) {
            names.push_back(name);
            dsids.push_back(dsid);

            float y = a*b*c*1000*integrated_luminosity; // 1000 factor is because xsecs are in pb
            yields.push_back(y);
            scales.push_back(y/n);
        }
    }
}

DatasetIter::~DatasetIter() {};

string DatasetIter::get_output_filename() { return "hists/" + names.at(current_dataset_index); }

#endif
