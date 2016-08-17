
with open('in.txt', 'w') as f:
    f.write('[')
    for x in xrange(1,int(1e6)):
        f.write(str(x) + ', ')
    f.write(']')
        