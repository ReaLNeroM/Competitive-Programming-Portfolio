s = raw_input()

def odd_count(v):
	return sum([v[i]%2 for i in range(26)])


v = [0 for i in range(26)]

for i in s:
	v[ord(i) - ord('a')] += 1

for i in range(25, 0, -1):
	if odd_count(v) >= 2 and v[i] % 2 == 1:
		for j in range(26):
			if v[j] % 2 == 1:
				v[j] += 1
				v[i] -= 1
				break

res = ''

for i in range(26):
	res += (chr(ord('a') + i) * (v[i] / 2))

for i in range(26):
	res += (chr(ord('a') + i) * (v[i] % 2))

for i in range(25, -1, -1):
	res += (chr(ord('a') + i) * (v[i] / 2))

print res