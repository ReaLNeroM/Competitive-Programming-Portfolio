n = input()
v = map(int, raw_input().split(' '))
if sum([i % 2 for i in v]) % 2 == 0:
	print "YES"
else:
	print "NO"