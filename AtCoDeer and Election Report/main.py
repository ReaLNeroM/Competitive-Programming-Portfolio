n = input()

v = [[0, 0] for i in range(n)]
for i in range(n):
	v[i] = map(int, raw_input().split(' '))

a, b = 1, 1

for i in range(n):
	change = v[i][0] * b - a * v[i][1]
	while change != 0:
		if change < 0:
			additions = (-change + v[i][0] - 1) / v[i][0]
			change += additions * v[i][0]
			b += additions
		if change > 0:
			additions = (change + v[i][1] - 1) / v[i][1]
			change -= additions * v[i][1]
			a += additions

print a + b
