import sys

n, k = map(int, raw_input().split(' '))
s = raw_input()

empty = True
for i in s:
	if i != '0':
		empty = False

if empty:
	print k * len(s)
	sys.exit()

if k >= 2:
	s = s + s

longest = 0
curr = 0

for i in s:
	if i == '0':
		curr += 1
		longest = max(longest, curr)
	else:
		curr = 0

print longest