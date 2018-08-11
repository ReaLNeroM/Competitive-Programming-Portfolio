N = input()

i = 1
s = ""

while abs(i) <= abs(N):
	if (abs(N) & abs(i)) != 0:
		s += '1'
		N -= i
	else:
		s += '0'

	i *= -2

if s == "":
	s = "0"
s = s[::-1]
print s