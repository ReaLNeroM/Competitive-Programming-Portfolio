n, m = map(int, raw_input().split(' '))

v = [[] for i in range(m)]

for i in range(n):
	a = map(int, raw_input().split(' '))
	v[a[0] - 1].append(a[1])

for i in range(m):
	v[i].sort()


res = 10**18
for i in range(0, max(len(i) for i in v) + 1):
	cost = 0
	need = i + 1 - len(v[0])
	for ind in range(m):
		if ind != 0 and len(v[ind]) > i:
			for k in range(len(v[ind]) - i):
				cost += v[ind][k]
				v[ind][k] *= -1
				need -= 1

	if need > 0:
		ll = []
		for j in range(1, m):
			ll += v[j]
		ll.sort()

		for j in ll:
			if need == 0:
				break
			if j < 0:
				continue

			cost += j
			need -= 1

	for j in range(m):
		for k in range(len(v[j])):
			v[j][k] = abs(v[j][k])

	res = min(res, cost)

print res
