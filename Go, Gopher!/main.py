from math import ceil
import sys

t = input()

for test_case in range(1, t + 1):
	cells = input()

	length_y = 3
	length_x = max(3, int(ceil(cells / float(3))))

	filled = [[False for j in range(length_x + 5)] for i in range(length_y + 5)]

	for i in range(1, length_y + 1):
		for j in range(1, length_x + 1):
			while filled[i][j] is False:
				query_y, query_x = max(2, min(length_y - 1, i)), max(2, min(length_x - 1, j))

				print query_y, query_x
				sys.stdout.flush()

				a, b = map(int, raw_input().split(' '))

				if a == -1 and b == -1:
					print "FUCK"
					sys.stdout.flush()
					sys.exit()
				elif a == 0 and b == 0:
					filled = [[True for j in range(length_x + 5)] for i in range(length_y + 5)]
					break

				filled[a][b] = True
