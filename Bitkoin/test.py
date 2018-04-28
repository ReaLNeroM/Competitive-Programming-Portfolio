import sys
import filecmp

a = sys.argv[1]
b = sys.argv[2]

fa = open(a, 'r').readlines()
fb = open(b, 'r').readlines()

fa = [fa[i].replace('\r', '') for i in range(len(fa))]
fb = [fb[i].replace('\r', '') for i in range(len(fb))]

if fa != fb:
	print "NOOO"
