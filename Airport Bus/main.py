n, c, k = map(int, raw_input().split(' '))

t = [0 for i in range(n)]

for i in range(n):
	t[i] = input()

t.sort()

lowest = 0
res = 1

for i in range(n):
	if i - lowest >= c:
		lowest = i
		res += 1
	elif t[i] - t[lowest] > k:
		lowest = i
		res += 1

print res