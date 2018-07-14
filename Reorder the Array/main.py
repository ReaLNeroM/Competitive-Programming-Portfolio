n = input()
v = map(int, raw_input().split(' '))

v.sort()

l, r = 0, 0
while r < n and v[l] == v[r]:
	r += 1

found = 0
while r < n:
	if v[l] != v[r]:
		found += 1
		l += 1
		r += 1

	while r < n and v[l] == v[r]:
		r += 1

print found