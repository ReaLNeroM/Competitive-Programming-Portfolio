import sys

n = input()
v = map(int, raw_input().split(' '))
startHere = [0 for i in range(n)]

if sum(v) % ((n * (n + 1)) / 2) != 0:
	print "NO"
	sys.exit()

operations = sum(v) / ((n * (n + 1)) / 2)
operationsFound = 0

for i in range(n):
	diff = v[(i + 1) % n] - v[i]

	if (operations - diff) % n != 0 or operations - diff < 0:
		print "NO"
		sys.exit()
	else:
		operationsFound += (operations - diff) / n

if operationsFound == operations:
	print "YES"
else:
	print "NO"
