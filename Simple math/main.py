n = int(raw_input())

sum = 0

for i in range(1, int(1e6) + 1):
	if i ** 2 > n:
		break

	l = max(1, (i - 1) ** 2 + 1)
	r = i ** 2
	sum += i * (r - l + 1)

for i in range(1, int(1e4) + 1):
	if i ** 3 > n:
		break

	l = i ** 3
	r = min(n, (i + 1) ** 3 - 1)

	sum += i * (r - l + 1)

print sum