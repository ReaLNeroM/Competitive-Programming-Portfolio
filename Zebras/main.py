s = raw_input()

res = []

start = -1
possible = True

for i in range(len(s)):
	if s[i] == '1':
		if start == -1 or s[i - 1] == '1':
			possible = False
	else:
		if start == -1:
			start = i
		elif s[i - 1] == '0':
			res.append([start + 1, i])
			start = i

if possible:
	print len(res)
	for i in res:
		print i[0], i[1]
else:
	print -1