from math import ceil

def f(i):
	return int(ceil(i**2 / 4))

def count(x):
	res = 0

	for i in range(1, x + 1):
		res += i * (i + 1) / 2
		res += f(i)

	return res

for i in range(20):
	print i, count(i)