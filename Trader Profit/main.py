#!/bin/python

import sys

def traderProfit(k, n, A):
	dp = [[0 for i in range(50)] for j in range(50)]

	for i in range(n - 1, -1, -1):
		for j in range(k):
			dp[i][j] = dp[i + 1][j]
			for l in range(i + 1, n):
				dp[i][j] = max(dp[i][j], A[l] - A[i] + dp[l + 1][j + 1])

	return dp[0][0]

if __name__ == "__main__":
    q = int(raw_input().strip())
    for a0 in xrange(q):
        k = int(raw_input().strip())
        n = int(raw_input().strip())
        arr = map(int, raw_input().strip().split(' '))
        result = traderProfit(k, n, arr)
        print result

