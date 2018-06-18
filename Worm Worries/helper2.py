x = 500.0

res = 0

while x > 1.0:
	res += x * x
	res += x * x / 2.0
	res += x * x / 4.0
	x /= 2.0

print res