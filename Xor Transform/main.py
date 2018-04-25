import random

def xorify(m):
	return_matrix = [[0 for i in range(len(m[j]))] for j in range(len(m))]

	for i in range(len(m)):
		for j in range(len(m[i])):
			return_matrix[i][j] ^= m[i][j]
			if i != len(m) - 1:
				return_matrix[i][j] ^= m[i + 1][j]
			if j != len(m[i]) - 1:
				return_matrix[i][j] ^= m[i][j + 1]
			if i != len(m) - 1 and j != len(m[i]) - 1:
				return_matrix[i][j] ^= m[i + 1][j + 1]

	return return_matrix

m = [[random.randint(1, 10000) for i in range(50)] for j in range(50)]

for i in range(1000):
	print m
	m = xorify(m)
