n, k, M, D = map(int, raw_input().split(' '))

def attempt(value, n, k, M, D):
	sweep = value * k
	if sweep <= 0:
		return [False, 0]
	for_everyone = n / sweep
	n = (n - for_everyone * sweep)
	n -= n % value

	most = for_everyone
	if n != 0:
		most += 1
	print value, sweep, for_everyone, n, most, D, most * value

	if most <= D and value <= M:
		return most * value
	else:
		return -1

best = attempt(M, n, k, M, D)

for i in range(1, D + 1):
	best = max(best, attempt(min(M, n / (k * i) - 1), n, k, M, D))
	print n / (k * i),
	best = max(best, attempt(min(M, n / (k * i)    ), n, k, M, D))
	best = max(best, attempt(min(M, n / (k * i) + 1), n, k, M, D))

print best