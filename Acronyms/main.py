n = int(raw_input())
val = ["" for i in range(n)]
for i in range(n):
	val[i] = raw_input()

app = [0 for i in range(26)]

for i in range(n):
	app[ord(val[i][0]) - ord('a')] += 1

res = 0


for i in range(n):
	app[ord(val[i][0]) - ord('a')] -= 1

	good = True

	temp_app = [0 for x in range(26)]
	for j in val[i]:
		temp_app[ord(j) - ord('a')] += 1

	for j in range(26):
		if temp_app[j] > app[j]:
			good = False

	if good is True:
		res += 1

	app[ord(val[i][0]) - ord('a')] += 1

print res