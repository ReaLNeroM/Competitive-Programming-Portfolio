testCases = input()

for testcase in range(testCases):
	n = raw_input()
	n = input()
	A = map(int, raw_input().split(' '))

	for i in range(n):
		printcurr = 1
		if i != n - 1:
			while printcurr * 10 <= A[i]:
				printcurr *= 10
		print printcurr,
	print
