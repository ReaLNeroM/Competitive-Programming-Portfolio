n, m = map(int, raw_input().split(' '))

v = map(int, raw_input().split(' '))

food = [0 for i in range(101)]

for i in v:
	food[i] += 1

l, r = 1, 10000
best = 0

while l <= r:
	mid = (l + r) / 2

	good = True
	found = 0

	for i in range(101):
		found += food[i] / mid

	if (found >= n):
		best = mid
		l = mid + 1
	else:
		r = mid - 1

print best