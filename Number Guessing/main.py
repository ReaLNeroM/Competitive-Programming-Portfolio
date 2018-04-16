import sys

t = input()

for i in range(t):
	a, b = map(int, raw_input().split(' '))
	a += 1
	n = input()

	while a <= b:
		mid = (a + b) / 2
		print mid
		sys.stdout.flush()

		s = raw_input()
		if s == "CORRECT":
			a = b = mid
			break
		elif s == "TOO_SMALL":
			a = mid + 1
		elif s == "TOO_BIG":
			b = mid - 1
		else:
			sys.exit()
