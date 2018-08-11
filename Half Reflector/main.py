def simulate(s):
	direction = 1
	pos = 0
	while pos != -1 and pos != len(s):
		if s[pos] == 'A':
			s[pos] = 'B'
			direction *= -1
			pos += direction
		elif s[pos] == 'B':
			s[pos] = 'A'
			pos += direction	

for n in range(1, 20):
	# n, k = map(int, raw_input().split(' '))
	# s = list(raw_input())
	s = list('A'*n)

	ideal = list()
	if n % 2 == 0:
		ideal = list('BA'*(n/2)+'B'*(n%2))
	else:
		ideal = list('AB'*(n/2)+'A')
	# print ideal
	iterations = 0

	while s != ideal:
		simulate(s)
		if iterations == 8:
			print ''.join(s)
		iterations += 1

	print n, iterations
