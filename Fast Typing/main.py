s = raw_input()
v = map(int, raw_input().split(' '))

sum = 0

for i in s:
	sum += v[ord(i) - ord('a')]

print sum