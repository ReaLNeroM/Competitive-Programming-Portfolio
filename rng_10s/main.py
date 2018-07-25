test_cases = input()

for test_case in range(test_cases):
	A, B, C, D = map(int, raw_input().split(' '))

	last_take = max(1, (A - C + B - 1) // B)
	A -= last_take * B

	if A < 0 or B > D:
		print "No"
	elif B == D or B <= C: 
		print "Yes"
	else:
		printed = False

		for i in range(10000):
			x = (C - A) // (D - B) + 1
			A += (D - B) * x
			last_take = max(1, (A - C + B - 1) // B)
			A -= last_take * B

			if A < 0:
				print "No"
				printed = True
				break
			
		if printed is False:
			print "Yes"
