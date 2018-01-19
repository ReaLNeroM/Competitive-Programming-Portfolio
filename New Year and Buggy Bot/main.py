y, x = map(int, raw_input().split(' '))

v = ["" for i in range(y)]
for i in range(y):
	v[i] = raw_input()
	for j in range(x):
		if v[i][j] == "S":
			s = [i, j]
		elif v[i][j] == "E":
			e = [i, j]

path = raw_input()
decoded_path = [ord(c) - ord('0') for c in path]

general_directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

res = 0

for i in range(4):
	for j in range(4):
		for k in range(4):
			for l in range(4):
				if i != j and i != k and i != l and j != k and j != l and k != l:
					res += 1
					assigned = [general_directions[i], general_directions[j], general_directions[k], general_directions[l]]

					curr = list(s)
					for l in decoded_path:
						curr[0] += assigned[l][0]
						curr[1] += assigned[l][1]

						if curr[0] < 0 or curr[0] >= y or curr[1] < 0 or curr[1] >= x or v[curr[0]][curr[1]] == '#':
							curr = list(s)
							break
						elif curr == e:
							break

					if curr != e:
						res -= 1

print res