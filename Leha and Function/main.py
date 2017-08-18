n = int(raw_input())
a = map(int, raw_input().split(' '))
b = map(int, raw_input().split(' '))

c = []
for i in xrange(len(b)):
	c.append([b[i], i])

a.sort(reverse = True)
c.sort()

for i in xrange(len(a)):
	b[c[i][1]] = a[i];

import sys

for i in b:
	sys.stdout.write(str(i) + ' ')

sys.stdout.write('\n')