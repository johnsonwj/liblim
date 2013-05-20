table_head = '{0:<25} {1:<25} {2:<20}'

table_lines = [
        table_head.format('Isolated Lepton', 'iso lep', 'true'),
        table_head.format('Hadronic Tau', 'tau_had', 'true'),
        table_head.format('Charge Correlation', 'opp ch', 'true'),
        table_head.format('Tau pT', 'tau p_T', 'p_T > 20 GeV'),
        table_head.format('Lepton eta', 'lep eta', 'eta < 2.1'),
        table_head.format('Tau eta', 'tau eta', 'eta < 2.3'),
        table_head.format('Lepton pT', 'lep p_T', 'p_T > 35 GeV'),
        table_head.format('Delta phi (MET, tau)', 'Delta phi (MET, tau)', 'Delta phi < pi/2'),
        table_head.format('Collinear mass [old]', 'colMassOld', 'm > 100 GeV'),
        table_head.format('Delta R (MET, tau)', 'Delta R (MET, tau)', 'Delta R < 2.5'),
        table_head.format('Tau+Lep Invariant Mass', 'vis M_H', 'M > 75 GeV')
        ]

with open('cut_desc','w') as f:
    f.write( table_head.format('Cut Description', 'Name on Histogram', 'Selection') + '\n')
    f.write( '='*(25+25+16+2) + '\n')
    for line in table_lines:
        f.write(line + '\n')
