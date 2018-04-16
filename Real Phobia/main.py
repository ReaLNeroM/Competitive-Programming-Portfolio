from __future__ import division
from math import floor, ceil

def better_fraction(a, b, goal):
	if a[2] > b[2]:
		a, b = b, a

	if abs(a[0] - goal[0]) <= abs(b[0] - goal[0]):
		return a
	else:
		return b

def generate(a, b):
	l = [0, 0, 1]
	r = [1, 1, 1]

	iteration = 0
	while l[2] + r[2] < b:
		iteration += 1

		mid = [1, l[1] + r[1], l[2] + r[2]]
		mid[0] = mid[1] / mid[2]

		if mid[1] * b <= mid[2] * a:
			times_needed = floor(abs((a * l[2] - b * l[1]) / (b * r[1] - a * r[2]) - 0.00001))
			print "L", l, r, mid, times_needed,
			l = [1, l[1] + times_needed * r[1], l[2] + times_needed * r[2]]
			l[0] = l[1] / l[2]
			print l
		else:
			times_needed = ceil(abs((a * r[2] - b * r[1]) / (a * l[2] - b * l[1]) + 0.000001))
			print "R", l, r, mid, times_needed,
			r = [1, r[1] + times_needed * l[1], r[2] + times_needed * l[2]]
			r[0] = r[1] / r[2]
			print r

	
	return better_fraction(l, r, [a / b, a, b])

t = input()

for i in range(t):
	a, b = map(int, raw_input().split('/'))
	fraction = [a / b, a, b]

	best = [1, 1, 1]

	if a != 1:
		attempt1 = [0, 1, floor(b / a)]
		attempt1[0] = attempt1[1] / attempt1[2]
		best = better_fraction(best, attempt1, fraction)

		attempt2 = [0, 1, ceil (b / a)]
		attempt2[0] = attempt2[1] / attempt2[2]
		best = better_fraction(best, attempt2, fraction)

	attempt3 = [0, a - 1, b - 1]
	attempt3[0] = attempt3[1] / attempt3[2]
	best = better_fraction(best, attempt3, fraction)

	attempt4 = generate(a, b)
	best = better_fraction(best, attempt4, fraction)

	print str(int(best[1])) + '/' + str(int(best[2]))

