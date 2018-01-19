n = int(raw_input())

v = [raw_input().split(' ') for i in range(n)]
for i in range(len(v)):
	v[i][0] = int(v[i][0])

r_array = []
g_array = []
b_array = []

for i in v:
	if i[1] == "R":
		r_array.append(i[0])
	elif i[1] == "G":
		g_array.append(i[0])
	elif i[1] == "B":
		b_array.append(i[0])

res = 0

if g_array:
	g_index = -1

	r_found = False
	b_found = False
	for j in v:
		if j[1] == "G":
			break
		elif j[1] == "R" and r_found is False:
			res += g_array[0] - j[0]
			r_found = True
		elif j[1] == "B" and b_found is False:
			res += g_array[0] - j[0]
			b_found = True

	r_found = False
	b_found = False
	for j in reversed(v):
		if j[1] == "G":
			break
		elif j[1] == "R" and r_found is False:
			res += j[0] - g_array[-1]
			r_found = True
		elif j[1] == "B" and b_found is False:
			res += j[0] - g_array[-1]
			b_found = True

	first_approach = 0
	for i in v:
		if i[1] == "G":
			g_index += 1

			if g_index != 0:
				green_connection = g_array[g_index] - g_array[g_index - 1]
				res += min(3 * green_connection - red_cost - blue_cost, 2 * green_connection)

			red_cost = 0
			blue_cost = 0
		else:
			best_connection = 1e9

			if g_index != -1:
				best_connection = min(best_connection, i[0] - g_array[g_index])
			if g_index + 1 != len(g_array):
				best_connection = min(best_connection, g_array[g_index + 1] - i[0])

			first_approach += best_connection

else:
	for i in range(len(r_array) - 1):
		res += r_array[i + 1] - r_array[i]
	for i in range(len(b_array) - 1):
		res += b_array[i + 1] - b_array[i]

print res