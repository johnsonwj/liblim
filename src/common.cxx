/*
 * =====================================================================================
 *
 *       Filename:  common.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/13 20:24:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  William Johnson (wjohnson), wjohnson@cern.ch
 *   Organization:  University of Washington
 *
 * =====================================================================================
 */

#include "common.h"

bool contains(string string1, string string2) {
    return (string1.find(string2) != string::npos);
}
