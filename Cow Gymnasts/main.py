def equal(v):
	cycle_v = [0] * len(v)

	for i in range(len(v)):
		for j in range(i, i + len(v)):
			if v[j % len(v)] >= (j - i + 1):
				cycle_v[i] += 1

		if cycle_v[i] != v[i]:
			return False

	return True

def generate(pos, v, n):
	if pos == n:
		if equal(v) is True:
			# print v
			return 1
		else:
			return 0

	res = 0

	for i in range(1, n + 1):
		v[pos] = i;
		res += generate(pos + 1, v, n)

	return res

def brute(n):
	return generate(0, [0] * n, n)

for i in range(1, 20):
	print brute(i)
