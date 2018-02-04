import sys

def ask(x):
    print "Q", x
    sys.stdout.flush()
    get = int(raw_input())
    return get
    
res = (2**(ask(2)))*(3**(ask(3)))*(5**ask(5))*(7**ask(7))

print "A", res