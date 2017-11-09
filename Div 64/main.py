s = raw_input()

zeroes = -100000
for i in range(len(s)):
	if s[i] == '1' and zeroes < 0:
		zeroes = 0
	if s[i] == '0':
		zeroes += 1

if zeroes >= 6:
	print "yes"
else:
	print "no"