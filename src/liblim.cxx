/*
 * =====================================================================================
 *
 *       Filename:  liblim.cxx
 *
 *    Description:  implementation for liblim.h
 *
 *        Version:  1.0
 *        Created:  05/25/2013 03:37:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#define liblim_impl

#include "liblim.h"

bool contains(string1, string2) {
    return (string1.find(string2) != string::npos);
}

