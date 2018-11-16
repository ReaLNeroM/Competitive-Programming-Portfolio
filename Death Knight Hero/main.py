t = input()

res = t

for i in range(t):
	s = raw_input()

	for j in range(len(s) - 1):
		if s[j] == 'C' and s[j + 1] == 'D':
			res -= 1
			break

print res