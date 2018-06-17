a, b = map(int, raw_input().split(' '))

curr_number = 0

for i in range(1, 10**7):
	if i % (100**a) == 0 and i % (100**(a+1)) != 0:
		curr_number += 1

		if curr_number == b:
			print i
			break
