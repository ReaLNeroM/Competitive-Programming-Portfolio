def damage(string):
	res = 0
	curr_power = 1

	for i in string:
		if i == 'C':
			curr_power *= 2
		else:
			res += curr_power

	return res

t = input()

for test_case in range(1, t + 1):
	hp, string = raw_input().split(' ')
	hp = int(hp)
	string = list(string)

	swaps = 0
	while damage(string) > hp:
		swap_successful = False 
		for [ind, i] in enumerate(string):
			if i == 'C' and (ind + 1 != len(string) and string[ind + 1] == 'S'):
				string[ind], string[ind + 1] = string[ind + 1], string[ind]
				swaps += 1
				swap_successful = True
				break

		if swap_successful is False:
			break

	print "Case #" + str(test_case) + ": ", 
	if damage(string) <= hp:
		print swaps
	else:
		print "IMPOSSIBLE"