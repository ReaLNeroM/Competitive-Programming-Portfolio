t = input()

for test_case in range(1, t + 1):
	destination, n = map(int, raw_input().split(' '))

	v = []
	for i in range(n):
		v.append(map(int, raw_input().split(' ')))

	most_time = 0.0000000000001

	for i in range(n):
		most_time = max(most_time, (destination - v[i][0]) / float(v[i][1]))

	print "Case #" + str(test_case) + ": " + '{0:.15f}'.format(destination / most_time)
