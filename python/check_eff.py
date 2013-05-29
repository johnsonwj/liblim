#! /usr/bin/env python

from os import listdir as ls
from ROOT import *

data_line = '{0:<18}{1:<12.2e}{2:<12.2e}{3:<12.2%}{4:<12.2e}{5:<12.2%}\n'
data_line_head = '# {0:<16}{1:<12}{2:<12}{3:<12}{4:<12}{5:<12}\n'.format(
    'Dataset name', 'Total', 'CT0 Passed', 'CT0 Eff', 'CT5 Passed', 'CT5 Eff')

chan = ['gg','vbf','wh','zh']

groups = [ 'htm_' + x for x in chan ] + [ 'htt_' + x for x in chan ] + ['z+jets', 'w+jets', 'top+lep', 'diboson']

totals = dict()
ct0_pass = dict()
ct5_pass = dict()

with open('data/eff','w') as data_out:
    data_out.write(data_line_head)

    for fn in ls('hists'):
        if 'optim' in fn:
            continue

        words = fn.split('_')
        if words[0] in chan:
            group = '_'.join(words[:2])
        else:
            group = words[0]

        tf = TFile('hists/'+fn)
        cfh = tf.Get('cutflow_full')

        t = cfh.GetBinContent(1)
        c0p = cfh.GetBinContent( cfh.GetNbinsX() )
        c5p = cfh.GetBinContent( cfh.GetNbinsX() - 5 )

        if group in totals:
            totals[group] += t
            ct0_pass[group] += c0p
            ct5_pass[group] += c5p
        else:
            totals[group] = t
            ct0_pass[group] = c0p
            ct5_pass[group] = c5p

    for k in totals:
        data_out.write( data_line.format(k, totals[k], ct0_pass[k], ct0_pass[k]/totals[k], ct5_pass[k], ct5_pass[k]/totals[k]) )
