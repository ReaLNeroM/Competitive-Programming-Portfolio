def fexp(a, b):
	result = 1

	while b >= 1:
		if b % 2 == 1:
			result *= a

		a *= a
		b /= 2

	return result

print fexp(2, 1048576)