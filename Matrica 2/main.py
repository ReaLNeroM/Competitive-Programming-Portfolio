y, x = map(int, input().split(' '))

res = 0

for i in range(y):
	v = map(int, input().split(' '))

	get_sum = sum(v)

	res += max(get_sum, -get_sum)

print (res)