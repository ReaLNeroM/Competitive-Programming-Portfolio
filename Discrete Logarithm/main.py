import sys
import random

def log_exponentiation(x, e):
	if e == 0:
		return 1
	elif e % 2 == 0:
		return log_exponentiation((x * x), e / 2)
	elif e % 2 == 1:
		return (x * log_exponentiation((x * x), e / 2))

r = 0

def binary(a, e):
	l = 2
	global r

	while l <= r:
		mid = int((l + r) / 2)

		if log_exponentiation(mid, e) == a:
			return mid
		elif log_exponentiation(mid, e) < a:
			l = mid + 1
		else:
			r = mid - 1

	return False

min_base = 1000
base_range = 20000
min_exponent = 10
exponent_range = 200

a = int(random.random() * base_range + min_base)
b = int(random.random() * exponent_range + min_exponent)
x = a ** b

r = x - 1

for i in range(min_exponent, min_exponent + exponent_range + 1):
	if binary(x, i) != False:
		print binary(x, i), i
		# sys.exit()

print 
print a, b