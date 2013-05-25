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

bool DatasetIter::next() {
    current_dataset_index++;
    if (current_dataset_index >= dsids.size()) return false;

    string this_name = names.at(current_dataset_index);
    string this_dsid = dsids.at(current_dataset_index);

    current_output_name = "hists/" + this_name;

    string topdir_name;
    if ( contains(this_name, "htm") || contains(this_name, "hte") )
        topdir_name = lfv_filebase;
    else
        topdir_name = bkg_filebase;

    TChain* chain = new TChain("tau");

    DIR* topdir = opendir(topdir_name);
    struct dirent* topdir_entry;

    if (topdir) {
        while ( (topdir_entry = readdir(topdir)) ) { // iterate through dataset folders
            if ( contains(topdir_entry->d_name, this_dsid) ) {

                DIR* dataset_dir = opendir( (topdir_name + topdir_entry->d_name).data() );
                struct dirent* dsdir_entry;

                if (dataset_dir) {
                    while ( (dsdir_entry = readdir(dsdir)) ) { // iterate over files in dataset directory
                        // add all .root files to chain
                        if ( contains( dsdir_entry->d_name, ".root" ) )
                            chain -> Add((topdir_name + topdir_entry->d_name + "/" + dsdir_entry->d_name).data());
                    }

                    closedir(dataset_dir);
                }
            }
        }

        closedir(topdir);
    }

    cout << "currently doing " << this_name << << ", chain has " << chain->GetEntries() << " events" << endl;

    current_limtree = new LimTree(chain);
    current_dataset_index++;

    return true;
}
