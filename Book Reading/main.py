n, t = map(int, raw_input().split(' '))
v = map(int, raw_input().split(' '))

for ite, val in enumerate(v):
	t -= 86400 - val

	if t <= 0:
		print ite + 1
		break
