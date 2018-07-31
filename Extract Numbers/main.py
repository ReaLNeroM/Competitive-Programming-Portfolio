s = raw_input().replace(';', ',')
s = s.split(',')


def number(x):
	if x == '' or (len(x) > 1 and x[0] == '0'):
		return False
	for i in x:
		if i < '0' or '9' < i:
			return False

	return True


a = []
b = []
for i in s:
	if number(i) is True:
		a.append(i)
	else:
		b.append(i)

if len(a) != 0:
	print '\"' + ','.join(a) + '\"'
else:
	print '-'
if len(b) != 0:
	print '\"' + ','.join(b) + '\"'
else:
	print '-'