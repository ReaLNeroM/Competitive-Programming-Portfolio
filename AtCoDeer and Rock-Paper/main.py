s = raw_input()

res = 0

for i in s:
	if i == 'p':
		res -= 1

res += len(s) / 2

print res