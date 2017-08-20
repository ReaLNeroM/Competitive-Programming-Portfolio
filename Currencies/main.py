n = int(raw_input())
money, start, end, operations = map(int, raw_input().split(' '))

mat = [[10 for j in range(n)] for i in range(n)]
old = [[0 for j in range(n)] for i in range(n)]
nnew = [[0 for j in range(n)] for i in range(n)]
res = [[0 for j in range(n)] for i in range(n)]
oldres = [[0 for j in range(n)] for i in range(n)]

for i in range(n):

	res[i][i] = 1
	old[i][i] = 1

for i in range(n):
	for j in range(n):
		for k in range(n):
			nnew[i][j] = max(nnew[i][j], old[i][k] * mat[k][j])


x = 1
while x <= operations:
	if x & operations:
		oldres = res
		res = [[0 for j in range(n)] for i in range(n)]

		for i in range(n):
			for j in range(n):
				for k in range(n):
					res[i][j] = max(res[i][j], oldres[i][k] * nnew[k][j])

	old = nnew
	nnew = [[0 for j in range(n)] for i in range(n)]

	for i in range(n):
		for j in range(n):
			for k in range(n):
				nnew[i][j] = max(nnew[i][j], old[i][k] * old[k][j])
	print x
	x *= 2

mod = int(1e9 + 7)
print (money * old[start][end]) % mod