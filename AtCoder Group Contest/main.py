n = input()
v = map(int, raw_input().split(' '))

v.sort()

taken = 0
sum = 0

for i in range(len(v) - 2, -1, -2):
	sum += v[i]
	taken += 1

	if taken == n:
		break

print sum