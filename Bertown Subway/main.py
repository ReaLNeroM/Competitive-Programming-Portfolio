n = int(raw_input())
v = map(lambda x:x - 1, map(int, raw_input().split(' ')))
used = [False] * n

loops = []

for i in range(n):
	size = 0

	pos = i
	while used[pos] is False:
		used[pos] = True
		size += 1
		pos = v[pos]

	if size > 0:
		loops.append(size)

loops.sort()

if len(loops) >= 2:
	loops[-2] += loops[-1]
	loops[-1] = 0

sum = 0

for i in loops:
	sum += i**2

print sum