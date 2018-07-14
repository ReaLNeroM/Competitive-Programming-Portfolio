import sys

def query(x, y, swap_values):
	if swap_values:
		x, y = y, x

	print x, y
	sys.stdout.flush()

	query_answer = input()
	if query_answer == 0:
		sys.exit()

	return query_answer



n = input()
l, r = 1, n

best = 0
return_value_at_best = False

while l <= r:
	mid = (l + r) / 2

	return_value = query(mid, mid, False)

	if return_value == 1 or return_value == 2:
		l = mid + 1
		best = mid
		return_value_at_best = (return_value == 2)
	elif return_value == 3:
		r = mid - 1

swap_values = return_value_at_best

l1, r1, l2, r2 = 1, best, best + 1, n

while l1 <= r1:
	mid1 = (l1 + r1) / 2
	return_value = query(mid1, best + 1, swap_values)

	if return_value == 1 or return_value == 2:
		l1 = mid1 + 1
	elif return_value == 3:
		r1 = mid1 - 1

while l2 <= r2:
	mid2 = (l2 + r2) / 2
	return_value = query(ans1, mid2, swap_values)

	if return_value == 1 or return_value == 2:
		l2 = mid + 1
	elif return_value == 3:
		r2 = mid - 1

print l1, l2