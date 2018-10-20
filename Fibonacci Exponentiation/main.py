from math import log	
import sys

res = 0
INF = -10**18
phi = 1.618033989

def square(mat):
	global res
	res += 4.0 * mat[0][0]
	res += 4.0 * mat[0][1]
	res += 4.0 * mat[1][0]
	res += 4.0 * mat[1][1]
	newMat = [[2.0 * mat[0][0] + log(2.0), 2.0 * mat[0][0] - log(phi) + log(2.0)],
			  [2.0 * mat[0][0] - log(phi) + log(2.0), 2.0 * mat[0][0] + log(2.0) - 2.0 * log(phi)]]

	return newMat

def exponentiate(a, n):
	for i in range(n):
		a = square(a)

	return a

exponentiate([[log(2), 0], [0, 0]], int(sys.argv[1]))

print res