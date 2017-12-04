n = int(raw_input())

t = map(int, raw_input().split(' '))

exist = [0 for i in range(n + 1)]

exist[0] = True
res = 1
for i in range(1, n + 1):
	if exist[t[i - 1]] is True:
		exist[t[i - 1]] = False
		exist[i] = True
	else:
		res += 1
		exist[i] = True

print res