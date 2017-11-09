n, a, b = map(int, raw_input().split(' '))
v = map(int, raw_input().split(' '))

res = 0
for i in range(0, n - 1):
	if (v[i + 1] - v[i]) * a > b:
		res += b
	else:
		res += (v[i + 1] - v[i]) * a

print res