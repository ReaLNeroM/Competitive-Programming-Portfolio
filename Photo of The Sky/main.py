n = input()
v = map(int, raw_input().split(' '))

v.sort()

res = 10**18

for i in range(n):
	if i == 0:
		res = min(res, (v[i + n - 1] - v[i]) * (v[2 * n - 1] - v[i + n]))
	else:
		res = min(res, (v[i + n - 1] - v[i]) * (v[2 * n - 1] - v[0]))


print res