#!/bin/python

import os
import sys


#
# Complete the fillBoard function below.
#
def fillBoard(n, m, x, y):
	fill = [[False for i in range(m + 1)] for j in range(n + 1)]

	for i in range(x):
		fill[0][i] = True

	for i in range(m - 1, m - y - 1, -1):
		fill[n - 1][i] = True

	for i in range(m):
		fill[n][i] = True

	for i in range(n):
		fill[i][m] = True

	empty = n * m - x - y
	res = []

	side = (n % 2 == 1)

	for i in range(n):
		if side is True:
			for j in range(m):
				if fill[i][j] is False and fill[i][j + 1] is False:
					res.append([i + 1, j + 1, i + 1, j + 1 + 1])
					empty -= 2
					fill[i][j] = fill[i][j + 1] = True
				if fill[i][j] is False and fill[i + 1][j] is False:
					res.append([i + 1, j + 1, i + 1 + 1, j + 1])
					empty -= 2
					fill[i][j] = fill[i + 1][j] = True
			side = not side
		else:
			for j in range(m - 1, -1, -1):
				if fill[i][j] is False and fill[i][j - 1] is False:
					res.append([i + 1, j + 1, i + 1, j])
					empty -= 2
					fill[i][j] = fill[i][j - 1] = True
				if fill[i][j] is False and fill[i + 1][j] is False:
					res.append([i + 1, j + 1, i + 1 + 1, j + 1])
					empty -= 2
					fill[i][j] = fill[i + 1][j] = True
			side = not side
		
	if empty == 0:
		print "YES"
		print len(res)
		for i in res:
			print ' '.join(map(str, i))
	else:
		print "NO"


if __name__ == '__main__':
    nmxy = raw_input().split()

    n = int(nmxy[0])
    m = int(nmxy[1])
    x = int(nmxy[2])
    y = int(nmxy[3])

    fillBoard(n, m, x, y)
