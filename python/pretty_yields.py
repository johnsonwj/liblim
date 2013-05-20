table_form =      '{0:<15} {1:<15.5%} {2:<15.5e} {3:<15.5f}'
table_form_head = '{0:<15} {1:<15} {2:<15} {3:<15}'

with open('yraw') as infile:
    with open('yields','w') as outfile:
        outfile.write(table_form_head.format('Dataset name', 'Cut efficiency', 'Total events', 'Yield') + '\n')
        outfile.write('='*(15*4+3) + '\n')

        for line in infile.readlines():
            sl = line.split()
            for i in xrange(3):
                sl[i+1] = float(sl[i+1])
            outfile.write( table_form.format(*sl) + '\n' )
