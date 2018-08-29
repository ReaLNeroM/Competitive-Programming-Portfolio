n, k = map(int, raw_input().split(' '))
s = raw_input()

res = ""
currsum = 0
size = 0
for i in s:
	if i == '(':
		if size < k:
			res += '('
			size += 2
			currsum += 1
	else:
		if currsum > 0:
			res += ')'
			currsum -= 1

print res