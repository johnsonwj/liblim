/*
 * =====================================================================================
 *
 *       Filename:  DatasetIter.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/13 11:54:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#define DSIter_impl

#include "DatasetIter.h"

bool DatasetIter::nextOutput() {
    currentOutputIndex++;
    if (currentOutputIndex >= 12) return false;

    currentOutputName = "hists/" + outs[currentOutputIndex];
    currentInputIndex = 0;

    return true;
}
    

int DatasetIter::nextInput() {
    if (currentInputIndex >= dsids.size()) return -1;

    if ( types.at(currentInputIndex).find( outs[currentOutputIndex] ) == string::npos) {
        currentInputIndex++;
        return 0;
    }

    string topdir_name;
    DIR* topdir;
    struct dirent* topdirEntry;

    TChain* chain = new TChain("tau");

    if ( types.at(currentInputIndex).find("bk") != string::npos ) {
        topdir_name = bkg_filebase;
        topdir = opendir( bkg_filebase );
    } else {
        topdir_name = lfv_filebase;
        topdir = opendir( lfv_filebase );
    }

    //cout << "topdir is " << topdir_name << endl;

    if (topdir) {
        while ( (topdirEntry = readdir(topdir)) != 0 ) {
            if ( ((string) topdirEntry->d_name).find( dsids.at( currentInputIndex ) ) != string::npos ) {
                DIR* dsdir;
                struct dirent* dsdirEntry;

                if ( (dsdir = opendir((topdir_name + topdirEntry->d_name).data())) != 0 ) {
                    while ( (dsdirEntry = readdir(dsdir)) != 0 ) {
                        if ( ((string)dsdirEntry->d_name).find(".root") != string::npos ) {
                            //cout << "dsdirEntry " << dsdirEntry->d_name << endl;
                            chain->Add((topdir_name + topdirEntry->d_name + "/" + dsdirEntry->d_name).data());
                        }
                    }
                }
            }
        }
    }

    cout << "currently doing " << names.at(currentInputIndex) 
        << ", chain has " << chain->GetEntries() << " events" << endl;

    currentLimTree = new LimTree(chain);

    //if ( names.at(currentInputIndex).find("vbf") != string::npos )
    //    currentLimTree->setUseDijetCuts(true);
    
    currentInputIndex++;

    return 1;
}
