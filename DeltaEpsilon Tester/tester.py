import math
import random

def f(x):
	return x**3+2*math.sin(x**2/math.cos(x))
def fd(x):
	return 3*x**2+math.cos(x**2/math.cos(x))*(math.cos(x)*2*x+math.sin(x)*x**2)/(math.cos(x)**2)

def satisfies(delta, eps):
	for i in range(10000):
		randx = random.uniform(-2.0, 2.0)
		randy = random.uniform(-delta, delta)
		if math.abs(math.abs(f(randx) - f(randx + randy))/math.abs(randx - randy) - fd((randx+randy)/2.0)) >= eps:
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

print findBiggestDelta(0.5)