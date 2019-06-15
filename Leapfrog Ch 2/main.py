t = input()

for testCase in range(1, t + 1):
	good = False

	s = raw_input()

	count = 0
	for i in s:
		if i == 'B':
			count += 1

	if len(s) == 2 or count >= len(s) - 1:
		good = False
	elif len(s) / 2 <= count <= len(s) - 2:
		good = True
	elif len(s) >= 6 and count >= 2:
		good = True
		# now jump left

	if good is True:
		print "Case #{}: Y".format(testCase)
	else:
		print "Case #{}: N".format(testCase)