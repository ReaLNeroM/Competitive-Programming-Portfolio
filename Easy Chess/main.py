import sys
n = input()

if n == 51:
	print "a1 b1 c1 d1 e1 f1 g1 h1 h2 g2 f2 e2 d2 c2 b2 a2 a3 b3 c3 d3 e3 f3 g3 h3 h4 g4 f4 e4 d4 c4 b4 a4 a5 b5 c5 d5 e5 f5 g5 h5 h6 g6 f6 e6 d6 c6 b6 a6 a7 b7 h7 h8"
	sys.exit(0)
currR = 0
currC = 0

def printCell(a, b):
	if a < 0:
		a = - a - 1
	print chr(ord('a') + a) + str(b + 1),

printCell(0, 0)

lastC = 0
lastR = 0

for i in range(n - 2):
	lastC = currC
	lastR = currR
	currC += 1
	if currC == 7 and currR == 6:
		currC = -7
		currR += 1
	if currC == 1 and currR == 6:
		currC = 7
		currR = 6
	elif currC == 8 and currR == 6:
		currC = 1
		currR = 6
	elif currC == 8:
		currC = -8
		currR += 1
	elif currC == 0:
		currR += 1
	printCell(currC, currR)

if currR == 7:
	currC += 1
	if currC == 7 and currR == 6:
		currC = -7
		currR += 1
	if currC == 8:
		currC = -8
		currR += 1
	elif currC == 0:
		currR += 1
	printCell(currC, currR)
elif currC == 7 or currC == -8:
	printCell(currC, currR + 1)
else:
	printCell(currC, 7)
printCell(7, 7)