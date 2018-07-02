from math import sqrt, ceil

n = int(input())

v = []

i = 2
while i <= n:
	times = 0
	while n % i == 0:
		times += 1
		n /= i

	if times > 0:
		v.append([i, times])

	i += 1

if n != 1:
	v.append([n, 1])

v.sort()

s = ""
for i in range(len(v)):
	if(i != 0):
		s += "*"

	s += '('

	s += str(v[i][0])
	s += '^'
	s += str(v[i][1])

	s += ')'

print (s)	
