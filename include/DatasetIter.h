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

#include <TChain.h>

#include "LimTree.h"
#include "liblim.h"

using namespace std;

class DatasetIter {
    public:
        DatasetIter();
        virtual ~DatasetIter();

        bool next();

        LimTree* get_limtree();
        const char* get_output_filename();

    private:
        unsigned current_dataset_index;

        LimTree* current_limtree;
        string current_output_name;

        const string bkg_filebase = "/phys/groups/tev/scratch3/users/dataset/lhCNv01-04/";
        const string lfv_filebase = "/phys/groups/tev/scratch3/users/wjohnson/datasets/";
        const string dslist_file = "data/datasets";

        vector<string> names;
        vector<string> dsids;
};

#endif

#ifdef DSIter_impl

DatasetIter::DatasetIter() {
    current_dataset_index = -1;

    ifstream infile(DatasetIter::dslist_file);

    string line;
    while (getline(infile,line)) {
        if (line.size() < 1 || line.at(0) == '#') continue;

        istringstream iss(line);
        string name,dsid;
        if (iss >> name >> dsid) {
            names.push_back(name);
            dsids.push_back(dsid);
        }
    }
}

DatasetIter::~DatasetIter() {};

LimTree* DatasetIter::get_limtree() { return current_limtree; };
string DatasetIter::get_output_filename() { return current_output_name; }

#endif
