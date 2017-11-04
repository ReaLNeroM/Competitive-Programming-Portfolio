n, x = map(int, raw_input().split(' '))
v = map(int, raw_input().split(' '))

sum = n - 1
for i in v:
	sum += i

if sum == x:
	print "YES"
else:
	print "NO"