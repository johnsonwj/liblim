/*
 * =====================================================================================
 *
 *       Filename:  DatasetIter.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/13 11:38:31
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
#include <sstream>
#include <iostream>
#include <stdio.h>

#include <TString.h>
#include <TChain.h>

#include "LimTree.h"

using namespace std;

class DatasetIter {
    public:
        DatasetIter();
        virtual ~DatasetIter();

        bool nextOutput();
        int nextInput();

        int getNCuts();

        LimTree* getLimTree();
        string getOutputFilename();

    private:
        unsigned int currentOutputIndex;
        unsigned int currentInputIndex;

        string currentOutputName;
        LimTree* currentLimTree;

        char bkg_filebase[128];
        char lfv_filebase[128];

        char dslist_file[128];

        const string outs[12] = 
            {"gg_htm", "vbf_htm", "wh_htm", "zh_htm", 
            "gg_htt", "vbf_htt", "wh_htt", "zh_htt", 
                "diboson", "z+jets", "w+jets", "top+lep"};

        vector<string> types;
        vector<string> names;
        vector<string> dsids;
};

#endif

#ifdef DSIter_impl

DatasetIter::DatasetIter() {
    strcpy(bkg_filebase,"/phys/groups/tev/scratch3/users/dataset/lhCNv01-04/");
    strcpy(lfv_filebase,"/phys/groups/tev/scratch3/users/wjohnson/datasets/");
    strcpy(dslist_file,"datasets");
    currentInputIndex = 0;
    currentOutputIndex = -1;

    ifstream infile(DatasetIter::dslist_file);

    string line;
    while (getline(infile,line)) {
        if (line.size() < 1 || line.at(0) == '#') continue;

        istringstream iss(line);
        string type,name,dsid;
        if (iss >> type >> name >> dsid) {
            types.push_back(type);
            names.push_back(name);
            dsids.push_back(dsid);
        }
    }
}

DatasetIter::~DatasetIter() {};

LimTree* DatasetIter::getLimTree() { return currentLimTree; }
string DatasetIter::getOutputFilename() { return currentOutputName; }


#endif
