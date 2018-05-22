q = input()

for i in range(q):
	p, q, b = map(int, raw_input().split(' '))

	infinite = True
	for j in range(20):
		p = (p % q) * b

		if p == 0:
			infinite = False
			break

	if infinite is False:
		print "Finite"
	else:
		print "Infinite"