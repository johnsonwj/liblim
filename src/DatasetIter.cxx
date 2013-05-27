/*
 * =====================================================================================
 *
 *       Filename:  DatasetIter.cxx
 *
 *    Description:  Implements the next() method of DatasetIter.
 *
 *        Version:  1.0
 *        Created:  05/24/2013 05:29:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (), wjohnson@cern.ch
 *   Organization:  
 *
 * =====================================================================================
 */

#define DSIter_impl

#include "DatasetIter.h"

LimTree* DatasetIter::next() {
    current_dataset_index++;
    if (current_dataset_index >= dsids.size()) return false;

    string this_name = names.at(current_dataset_index);
    string this_dsid = dsids.at(current_dataset_index);

    TChain* chain = new TChain("tau");

    DIR* topdir = opendir(ds_dir.data());
    struct dirent* topdir_entry;

    if (topdir) {
        while ( (topdir_entry = readdir(topdir)) ) { // iterate through dataset folders
            if ( contains(topdir_entry->d_name, this_dsid) ) {

                DIR* dataset_dir = opendir( (ds_dir + topdir_entry->d_name).data() );
                struct dirent* dsdir_entry;

                if (dataset_dir) {
                    while ( (dsdir_entry = readdir(dataset_dir)) ) { // iterate over files in dataset directory
                        // add all .root files to chain
                        if ( contains( dsdir_entry->d_name, ".root" ) )
                            chain -> Add((ds_dir + topdir_entry->d_name + "/" + dsdir_entry->d_name).data());
                    }

                    closedir(dataset_dir);
                }
            }
        }

        closedir(topdir);
    }

    cout << "currently doing " << this_name << ", chain has " << chain->GetEntries() << " events" << endl;

    LimTree* lt = new LimTree(chain, yields.at(current_dataset_index), scales.at(current_dataset_index));
    current_dataset_index++;

    return lt;
}
