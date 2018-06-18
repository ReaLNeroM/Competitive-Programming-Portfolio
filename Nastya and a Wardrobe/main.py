import sys

x, k = map(int, raw_input().split(' '))

if k == 0 or x == 0:
	print 2 * x
	sys.exit()

def fast_pow(a, b, m):
	res = 1

	while b > 0:
		if b & 1:
			res *= a
			res %= m

		a *= a
		a %= m
		b /= 2

	return res

x = 2 * x + 2 * x - 1

mod = 10**9+7

print ((fast_pow(2, k - 1, mod) * (x - 1)) + 1) % mod