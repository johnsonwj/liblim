#! /usr/bin/env python

from os import listdir as ls
from ROOT import *

data_line = '{0:<18}{1:<12d}{2:<12d}{3:<12.2%}{4:<12d}{5:<12.2%}\n'
data_line_head = '# {0:<16}{1:<12}{2:<12}{3:<12}{4:<12}{5:<12}\n'.format(
    'Dataset name', 'Total', 'CT0 Passed', 'CT0 Eff', 'CT4 Passed', 'CT4 Eff')

files = [ 'gg_htm', 'vbf_htm', 'wh_htm', 'zh_htm',
          'gg_htt', 'vbf_htt', 'wh_htt', 'zh_htt',
          'diboson', 'top+lep', 'w+jets', 'z+jets' ]

with open('data/eff','w') as data_out:
  data_out.write(data_line_head)

  for fn in files:
    tf_ct0 = TFile('hists/' + fn + '_CT0.root')
    tf_ct4 = TFile('hists/' + fn + '_CT4.root')

    cfhist0 = tf_ct0.Get("cutflow")
    cfhist4 = tf_ct4.Get("cutflow")

    begin0 = cfhist0.GetBinContent(1)
    begin4 = cfhist4.GetBinContent(1)

    end0 = cfhist0.GetBinContent( cfhist0.GetNbinsX() )
    end4 = cfhist4.GetBinContent( cfhist4.GetNbinsX() - 5 )

    if begin0 > 0:
        eff0 = float(end0)/begin0
    else:
        eff0 = float('nan')

    if begin4 > 0:
        eff4 = float(end4)/begin4
    else:
        eff4 = float('nan')

    data_out.write( data_line.format(fn,int(begin0),int(end0),eff0,int(end4),eff4) )

    #except:
    #  print 'oops',rootfn
