from __future__ import print_function
import random
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

def query_triple(v):
	print("? " + str(v[0]) + " " + str(v[1]) + " " + str(v[2]))
	get = input()
	return get


def answer_single(y):
	print("! " + str(y + 1) + " 1 1")

def answer_double(y, x):
	print("! " + str(y) + " " + str(x) + " 1")

def answer_triple(v):
	print("! " + str(v[1][0]) + " " + str(v[1][1]) + " " + str(v[1][2]))


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

	answer_single(best_location)
elif n > 1 and m > 1 and k == 1:
	split(1, 1, n, m, 1, 1, 0)
elif n > 1 and m > 1 and k > 1:
	best = [0, [1, 1, 1]]

	for i in range(q / 2):
		queried_coords = [random.randint(1, n), random.randint(1, m), random.randint(1, k)]
		query_array = [query_triple(queried_coords), queried_coords]

		best = max(best, query_array)

	for i in range(5, q / 2, 6):
		best_temporary = list(best)

		for j in range(-1, 2, 2):
			for l in range(3):
				new_query_coords = list(best_temporary[1])
				new_query_coords[l] += j

				if 1 <= new_query_coords[0] <= n and 1 <= new_query_coords[1] <= m and 1 <= new_query_coords[2] <= k:
					curr = [query_triple(new_query_coords), new_query_coords]
					best = max(best, curr)

	answer_triple(best)