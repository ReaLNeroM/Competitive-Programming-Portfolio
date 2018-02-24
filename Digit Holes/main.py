def count(x):
	holes = [1, 0, 0, 0, 0, 0, 1, 0, 2, 1]
	x = str(x)

	return sum(holes[ord(i) - ord('0')] for i in x)

a, b = map(int, raw_input().split(' '))
best = a

for i in range(a, b + 1):
	if count(i) > count(best):
		best = i

print best