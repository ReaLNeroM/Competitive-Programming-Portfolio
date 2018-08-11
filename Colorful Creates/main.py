n = input()
v = map(int, raw_input().split(' '))
v.sort()

def good(mid, v):
	sum = v[mid]
	for i in range(n):
		if i != mid:
			if v[i] > 2 * sum:
				return False

			sum += v[i]

	return True


l, r = 0, n - 1
best = n - 1

while l <= r:
	mid = (l + r) / 2

	if good(mid, v):
		best = mid
		r = mid - 1
	else:
		l = mid + 1

print n - best