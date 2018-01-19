s = raw_input()

res = 0

for i in s:
	if "aeiou13579".find(i) != -1:
		res += 1

print res