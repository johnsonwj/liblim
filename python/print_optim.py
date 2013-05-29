#! /usr/bin/env python

from ROOT import *
from math import sqrt

data_line_head = '{0:<16}  {1:<16}  {2:<16}\n'.format('Cut name', 'Max sigma', 'Cut val') + '='*( 3*16 + 4 ) + '\n'
data_line = '{0:<16}  {1:<16.4e}  {2} {3:<14.2f}\n'

edges = dict();
edges['lep_pt']        =  (0., 100.)
edges['tau_pt']        =  (0., 100.)
edges['dr_met_tau']    =  (0., 5.  )
edges['dphi_met_tau']  =  (0., 3.2 )
edges['met']           =  (0., 100.)
edges['h_vismass']     =  (0., 150.)
edges['lep_eta']       =  (0., 4. )
edges['tau_eta']       =  (0., 4. )

def get_binval(cn, bn):
    ledge,hedge = edges[cn]
    bw = (hedge-ledge)/100

    return ledge + bw*bn

with open('data/optim','w') as data_out:
    data_out.write(data_line_head)

    tf = TFile('hists/optim.root')

    for cn in edges.iterkeys():
        print 'starting',cn

        sigbname = cn + '_sig_below_bin_'
        siganame = cn + '_sig_above_bin_'
        bkgbname = cn + '_bkg_below_bin_'
        bkganame = cn + '_bkg_above_bin_'

        max_b_sigma = 0
        max_b_bin = 0

        max_a_sigma = 0
        max_a_bin = 0

        for i in xrange(100):
            sigbhist = tf.Get(sigbname+str(i))
            sigahist = tf.Get(siganame+str(i))
            bkgbhist = tf.Get(bkgbname+str(i))
            bkgahist = tf.Get(bkganame+str(i))

            if sigbhist.Integral() > 0 and bkgbhist.Integral() > 0:

                b_sigma = sigbhist.Integral() / sqrt( sigbhist.Integral() + bkgbhist.Integral() )
                if b_sigma > max_b_sigma:
                    max_b_sigma = b_sigma
                    max_b_bin = i

            if sigahist.Integral() > 0 and bkgahist.Integral() > 0:

                a_sigma = sigahist.Integral() / sqrt( sigahist.Integral() + bkgahist.Integral() )
                if a_sigma > max_a_sigma:
                    max_a_sigma = a_sigma
                    max_a_bin = i

        if max_b_sigma > max_a_sigma:
            data_out.write( data_line.format(cn, max_b_sigma, '<', get_binval(cn, max_b_bin)) )
        else:
            data_out.write( data_line.format(cn, max_a_sigma, '>', get_binval(cn, max_a_bin)) )
