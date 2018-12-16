import random
import math

def f(x):
	return 1.0/(x**2+3)

def satisfies(delta, eps):
	for i in range(10000):
		randx = random.uniform(-2.0, 2.0)
		randy = random.uniform(-delta, delta)
		if abs(f(randx) - f(randx + randy)) >= eps:
			return False
	return True

def findBiggestDelta(eps):
	l = 10**(-10)
	r = 10**10

	best = 10**(-10)
	for i in range(300):
		mid = (l + r) / 2.0

		if satisfies(mid, eps):
			best = mid
			l = mid
		else:
			r = mid

	return best

print findBiggestDelta(0.1)
