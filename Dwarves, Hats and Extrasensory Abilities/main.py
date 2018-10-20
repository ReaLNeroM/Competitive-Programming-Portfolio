from sys import stdout
n = input()

def query(a, b):
	print a, b
	stdout.flush()
	s = raw_input()
	return (s == "black")

firstNode = query(0, 0)
l, r = 1, 10**9

for i in range(n - 1):
	mid = (l + r) / 2

	nextQuery = query(mid, mid)

	if nextQuery == firstNode:
		l = mid + 1
	else:
		r = mid - 1

print l, l - 1, l - 1, l