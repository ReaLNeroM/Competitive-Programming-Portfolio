square = [False for i in range(100)]
i = 1
while i**2 < 100:
	square[i**2] = True
	i += 1

def f(pos, array, used):
	if pos == 15:
		print array
		return

	for i in range(1, 16):
		if used[i] is False and square[array[pos] + i] is True:
			array[pos + 1] = i
			used[i] = True
			f(pos + 1, array, used)
			used[i] = False
			array[pos + 1] = 0

array = [0 for i in range(16)]
used = [False for i in range(16)]

for i in range(1, 16):
	array[0] = i
	used[i] = True
	f(0, array, used)
	used[i] = False
