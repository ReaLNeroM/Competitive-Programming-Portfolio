big_n = input()

N = 25

res = [0 for i in range(N + 1)]

for n in range(1, N + 1):
	m = {}

	for i in range(n + 1):
		if i == n:
			m[i * 50] = True

		for j in range(n - i + 1):
			if i + j == n:
				m[i * 50 + j * 10] = True

			for k in range(n - i - j + 1):
				if i + j + k == n:
					m[i * 50 + j * 10 + k * 5] = True

				m[i * 50 + j * 10 + k * 5 + n - i - j - k] = True

	m[0] = False
	res[n] = sum(m.values())

if big_n <= N:
	print res[big_n]
else:
	print res[N] + (big_n - N) * 49