n = input()
v = map(int, raw_input().split(' '))
v = [v[i] - 1 for i in range(2 * n)]

res = 0

for i in range(0, 2 * n, 2):
	cost = [0 for i in range(n)]

	for j in range(i, 2 * n):
		cost[v[j]] += j

	smallest, smallestindex = 10**9, 1
	for j in range(n):
		curr, currindex = cost[j], j

		if curr < smallest and cost[j] >= 2 * i:
			smallest, smallestindex = curr, currindex

	for j in range(i, 2 * n):
		element = 0
		if v[j] == smallestindex:
			print j, i + element
			for k in range(j, i + element, -1):
				v[k], v[k - 1] = v[k - 1], v[k]
				res += 1
			element += 1


print res