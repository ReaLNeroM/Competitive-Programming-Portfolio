t = input()

for test_case in range(1, t + 1):
	n = input()

	v = map(int, raw_input().split(' '))

	first_part = list(v[::2])
	second_part = list(v[1::2])

	v.sort()
	first_part.sort()
	second_part.sort()

	first_wrong = n
	for i in range(n):
		if i % 2 == 0 and v[i] != first_part[i / 2]:
			first_wrong = i
			break
		elif i % 2 == 1 and v[i] != second_part[i / 2]:
			first_wrong = i
			break

	print "Case #" + str(test_case) + ": ", 
	if first_wrong == n:
		print "OK"
	else:
		print first_wrong