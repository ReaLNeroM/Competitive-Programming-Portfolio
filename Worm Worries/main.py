from __future__ import print_function
import sys

n, m, k, q = map(int, raw_input().split(' '))

def query_single(y):
	print("? " + str(y + 1) + " 1 1")
	get = input()

	return get


def query_double(y, x):
	print("? " + str(y) + " " + str(x) + " 1")
	get = input()

	return get


def answer_double(y, x):
	print("! " + str(y) + " " + str(x) + " 1")


def split(y1, x1, y2, x2, most_y, most_x, most_val):
	if y1 == y2 and x1 == x2:
		answer_double(y1, x1)
		sys.exit()

	if y2 - y1 >= x2 - x1:
		mid_y = (y1 + y2) / 2
		most_pos, most_value = x1, 0

		for i in range(x1, x2 + 1):
			curr_value = query_double(mid_y, i)

			if curr_value > most_value:
				most_pos, most_value = i, curr_value

		a_value = 0
		b_value = 0
		if y1 <= mid_y - 1 <= y2:
			a_value = query_double(mid_y - 1, most_pos)
		if y1 <= mid_y + 1 <= y2:
			b_value = query_double(mid_y + 1, most_pos)

		if most_val > a_value and most_val > b_value and most_val > most_value:
			if most_y < mid_y:
				split(y1, x1, mid_y - 1, x2, most_y, most_x, most_val)
			elif most_y > mid_y:
				split(mid_y + 1, x1, y2, x2, most_y, most_x, most_val)
		elif most_value >= a_value and most_value >= b_value:
			answer_double(mid_y, most_pos)
			sys.exit()
		elif a_value >= most_value and a_value >= b_value:
			split(y1, x1, mid_y - 1, x2, mid_y - 1, most_pos, a_value)
		else:
			split(mid_y + 1, x1, y2, x2, mid_y + 1, most_pos, b_value)
	else:
		mid_x = (x1 + x2) / 2
		most_pos, most_value = y1, 0

		for i in range(y1, y2 + 1):
			curr_value = query_double(i, mid_x)

			if curr_value > most_value:
				most_pos, most_value = i, curr_value

		a_value = 0
		b_value = 0
		if x1 <= mid_x - 1 <= x2:
			a_value = query_double(most_pos, mid_x - 1)
		if x1 <= mid_x + 1 <= x2:
			b_value = query_double(most_pos, mid_x + 1)

		if most_val > a_value and most_val > b_value and most_val > most_value:
			if most_x < mid_x:
				split(y1, x1, y2, mid_x - 1, most_y, most_x, most_val)
			elif most_x > mid_x:
				split(y1, mid_x + 1, y2, x2, most_y, most_x, most_val)
		elif most_value >= a_value and most_value >= b_value:
			answer_double(most_pos, mid_x)
			sys.exit()
		elif a_value >= most_value and a_value >= b_value:
			split(y1, x1, y2, mid_x - 1, most_pos, mid_x - 1, a_value)
		else:
			split(y1, mid_x + 1, y2, x2, most_pos, mid_x + 1, b_value)


if n == 1000000 and m == 1 and k == 1 and q == 10000:
	best_location, best_value = 0, query_single(0)
	for i in range(1000, n, 1000):
		location, value = i, query_single(i)

		if value > best_value:
			best_location, best_value = location, value

	a = max(0, best_location - 3000)
	b = min(n - 1, best_location + 3000)

	for i in range(a, b + 1):
		location, value = i, query_single(i)

		if value > best_value:
			best_location, best_value = location, value

	print("! " + str(best_location + 1) + " 1 1")
# elif n == 1000000 and m == 1 and k == 1:
# 	#TODO
elif n > 1 and m > 1 and k == 1:
	split(1, 1, n, m, 1, 1, 0)