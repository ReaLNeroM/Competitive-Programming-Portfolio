import math
x = raw_input()

count = [0 for i in range(11)]

res = 0

def calc(v):
	sum = 0
	for i in v:
		sum += i

	ans = math.factorial(sum)
	for i in v:
		ans /= math.factorial(i)

	return ans - count[10]


count[10] += 1

for i in x:
	count[ord(i) - ord('0')] += 1

for i in range(1, 10):
	if count[i] >= 1:
		count[i] -= 1

		res += calc(count)
		print count, calc(count),
		count[10] -= 1
		print calc(count)
		res -= calc(count)
		count[10] += 1
		count[i] += 1


print res
