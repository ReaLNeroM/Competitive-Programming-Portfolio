cubes = int(raw_input())
v = [[0 for j in range(7)] for i in range(cubes)]

for i in range(cubes):
	v[i] = map(int, raw_input().split(' '))

def able(make, used, made):
	if make == made:
		return True

	for i in range(cubes):
		if (1 << i) & used:
			for j in range(6):
				if able(make, used ^ (1<<i), made * 10 + v[i][j]):
					return True

	return False

for i in range(1000):
	if able(i, (1 << cubes) - 1, 0) is False:
		print i - 1
		break	