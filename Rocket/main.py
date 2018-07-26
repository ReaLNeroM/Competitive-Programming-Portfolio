from sys import stdout, exit

n, m = map(int, raw_input().split(' '))

def query(x):
	print x
	stdout.flush()

	answer = input()
	return answer

def good_query(x, val, query_index):
	answer = query(x)

	if val[query_index] is False:
		answer *= -1

	return answer

given = [False for i in range(m)]

for i in range(m):
	answer = query(1)

	if answer == -1:
		given[i] = True
	elif answer == 0:
		exit()
	else:
		given[i] = False

l, r = 1, n
query_index = 0

while l <= r:
	mid = (l + r) / 2
	answer = good_query(mid, given, query_index)
	query_index += 1
	query_index %= m

	if answer == -1:
		l = mid + 1
	elif answer == 0:
		exit()
	else:
		r = mid - 1