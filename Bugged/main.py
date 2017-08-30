import sys

N = int(raw_input())

A = [0 for i in range(N)]

sum = 0
for i in range(N):
	A[i] = int(raw_input())
	sum += A[i]

A.sort()

if sum % 10 == 0:
	for i in A:
		if i % 10 != 0:
			print sum - i
			sys.exit()
	print 0
else:
	print sum