n = int(raw_input())
v = map(int, raw_input().split(' '))

res = sum(v)

i = len(v) - 1
while i >= 0:
	sum = 0

	j = i
	while j < len(v):
		sum += v[j]
		j += (i + 1)

	if sum <= 0:
		res -= sum

		j = i
		while j < len(v):
			v[j] = 0
			j += (i + 1)

	i -= 1

print res