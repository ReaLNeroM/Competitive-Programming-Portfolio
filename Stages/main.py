n, k = map(int, raw_input().split(' '))

v = raw_input()

v = ''.join(sorted(v))

k -= 1
last_character = v[0]
sum = ord(v[0]) - ord('a') + 1

for i in v:
	if ord(last_character) + 2 <= ord(i) and k > 0:
		k -= 1
		last_character = i
		sum += ord(last_character) - ord('a') + 1

if k > 0:
	print -1
else:
	print sum