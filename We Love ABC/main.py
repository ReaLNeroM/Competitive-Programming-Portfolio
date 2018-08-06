s = input()
n = len(s)

make = [[0 for i in range(4)] for j in range(n + 1)]

make[n][3] = 1

mod = 10**9 + 7

for i in range(n - 1, -1, -1):
	if s[i] == '?':
		make[i][0] += make[i + 1][0] * 3 + make[i + 1][1]
		make[i][1] += make[i + 1][1] * 3 + make[i + 1][2]
		make[i][2] += make[i + 1][2] * 3 + make[i + 1][3]
		make[i][3] += make[i + 1][3] * 3
	elif s[i] == 'A':
		make[i][0] += make[i + 1][0] + make[i + 1][1]
		make[i][1] += make[i + 1][1]
		make[i][2] += make[i + 1][2]
		make[i][3] += make[i + 1][3]
	elif s[i] == 'B':
		make[i][0] += make[i + 1][0]
		make[i][1] += make[i + 1][1] + make[i + 1][2]
		make[i][2] += make[i + 1][2]
		make[i][3] += make[i + 1][3]
	elif s[i] == 'C':
		make[i][0] += make[i + 1][0]
		make[i][1] += make[i + 1][1]
		make[i][2] += make[i + 1][2] + make[i + 1][3]
		make[i][3] += make[i + 1][3]

	make[i][0] %= mod
	make[i][1] %= mod
	make[i][2] %= mod
	make[i][3] %= mod

print(make[0][0])