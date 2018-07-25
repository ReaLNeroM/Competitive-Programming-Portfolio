N = input()

v = map(int, raw_input().split(' '))

found = 0

i = 0
while i < N:
	j = i
	while j < N - 1 and v[i] == v[j + 1]:
		j += 1

	found += (j - i + 1) / 2

	i = j + 1

print found