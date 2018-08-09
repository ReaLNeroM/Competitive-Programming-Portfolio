n = input()

v = map(int, raw_input().split(' '))

dict = {}

sum = 0

for i in range(n):
	sum += v[i]
	if sum not in dict:
		dict[sum] = 0

	dict[sum] += 1

res = 0

sum = 0

if sum in dict:
	res += dict[sum]

sum += v[0]

for i in range(1, n):
	sum += v[i]
	dict[sum] -= 1
	res += dict[sum]

print res
