from os import listdir
from math import sqrt

target = '/phys/users/bromayn/workarea/truth_study/mg5_lhef/'

brs = {
    'gg' : list(),
    'vbf': list(),
    'wh' : list(),
    'zh' : list()
    }

xsecs = {
    'gg' : list(),
    'vbf': list(),
    'wh' : list(),
    'zh' : list()
    }

def avg(l):
  return sum(l)/len(l)

def std(l):
  return sqrt( avg( [ (x - avg(l))**2 for x in l ] ) )

for fn in listdir(target):
  if 'Pythia' not in fn or 'group.phys-gener' not in fn:
    continue

  f = target + fn
  with open(f) as data:
    zone = list()
    nread = 0

    go = False
    while nread < 460:
      ll = data.readline(); nread += 1
      if '</MGGenerationInfo>' in ll:
        go = False

      if go:
        zone.append(ll[:-1])

      if '<MGGenerationInfo>' in ll:
        go = True

  #print fn

  partial_xsec = 0.
  for line in zone:
    #print line
    if 'Integrated weight' in line:
      if '(pb)' not in line:
        print 'NOT PICOBARNS', line
      partial_xsec = float( line.split()[-1] )

  if len(zone) < 4:
    raise Exception("OH SHIT " + fn)

  #print


  if 'ggH' in fn:
    brs['gg'].append(partial_xsec/7.441)
    xsecs['gg'].append(partial_xsec)
  elif 'VBFH' in fn:
    brs['vbf'].append(partial_xsec/1.521)
    xsecs['vbf'].append(partial_xsec)
  elif 'WH' in fn:
    brs['wh'].append(partial_xsec/0.56)
    xsecs['wh'].append(partial_xsec)
  elif 'ZH' in fn:
    brs['zh'].append(partial_xsec/.2909)
    xsecs['zh'].append(partial_xsec)

#print '{0:.3f}'.format(avg(xsecs['gg']))
#print '{0:.3f}'.format(avg(xsecs['vbf']))
#print '{0:.3f}'.format(avg(xsecs['wh']))
#print '{0:.3f}'.format(avg(xsecs['zh']))
#
#print
#
print 'gg  {0:.6f} pm {1:.2%}'.format(avg(brs['gg']), std(brs['gg'])/avg(brs['gg']))
print 'vbf {0:.6f} pm {1:.2%}'.format(avg(brs['vbf']), std(brs['vbf'])/avg(brs['vbf']))
print 'wh  {0:.6f} pm {1:.2%}'.format(avg(brs['wh']), std(brs['wh'])/avg(brs['wh']))
print 'zh  {0:.6f} pm {1:.2%}'.format(avg(brs['zh']), std(brs['zh'])/avg(brs['zh']))
print 'TOTAL {0:.6f} pm {1:.2%}'.format(avg( sum( brs.itervalues(), [] )), std( sum( brs.itervalues(), [] ))/avg( sum( brs.itervalues(), [] )))

#print 'gg  {0:.6f}'.format(avg(brs['gg']))
#print 'vbf {0:.6f}'.format(avg(brs['vbf']))
#print 'wh  {0:.6f}'.format(avg(brs['wh']))
#print 'zh  {0:.6f}'.format(avg(brs['zh']))
