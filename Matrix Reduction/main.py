def add(mat, augmented, a, b, c):
	"""Adds c*mat[a] to row mat[a]."""
	n = len(mat)
	m = len(mat[0])
	a -= 1
	b -= 1
	for i in range(m):
		mat[b][i] += c * mat[a][i]
	for i in range(n):
		augmented[b][i] += augmented[a][i] * c


def swap(mat, augmented, a, b):
	"""Swaps two rows of a matrix."""
	n = len(mat)
	m = len(mat[0])
	a -= 1
	b -= 1
	for i in range(m):
		mat[a][i], mat[b][i] = mat[b][i], mat[a][i]
	for i in range(n):
		augmented[a][i], augmented[b][i] = augmented[b][i], augmented[a][i]


def multiply(mat, augmented, a, c):
	"""Multiplies a row of a matrix by c."""
	a -= 1
	n = len(mat)
	m = len(mat[0])
	for i in range(m):
		mat[a][i] *= c
	for i in range(n):
		augmented[a][i] *= c


def divide(mat, augmented, a, c):
	"""Divides a row of a matrix by c."""
	a -= 1
	c = float(c)
	n = len(mat)
	m = len(mat[0])
	for i in range(m):
		mat[a][i] /= c
	for i in range(n):
		augmented[a][i] /= c


def is_nonzero_float(x):
	"""Helper function which returns True if a number is non-zero."""
	return abs(x) > 0.00001


def matrix_inverse(mat, augmented):
	"""Computes the inverse of the given matrix, stored in augmented. Uses Gaussian elimination."""
	r = len(mat)
	c = len(mat[0])
	is_leading_one_column = []

	for i in range(r):
		for j in range(c):
			if is_nonzero_float(mat[i][j]):
				divide(mat, augmented, i + 1, mat[i][j])
				for k in range(r):
					if k != i and is_nonzero_float(mat[k][j]):
						add(mat, augmented, i + 1, k + 1, -mat[k][j])
				is_leading_one_column.append(j)
				break

	is_leading_one_column.sort()

	for i, column_index in enumerate(is_leading_one_column):
		for j in range(r):
			if is_nonzero_float(mat[j][column_index]):
				mat[j], mat[i] = mat[i], mat[j]
				break


def matrix_multiply(mat_a, mat_b):
	"""Computes the matrix product of the two given matrices naively i.e. with no optimizations."""
	mat_a_n = len(mat_a)
	mat_a_m = len(mat_a[0])
	mat_b_n = len(mat_b)
	mat_b_m = len(mat_b[0])
	mat_c = [[0 for i in range(mat_b_m)] for j in range(mat_a_n)]

	for i in range(mat_a_n):
		for j in range(mat_b_m):
			for k in range(mat_a_m):
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j]

	return mat_c


def matrix_fast_multiply(mat_a, mat_b):
	"""Computes the matrix product of the two given matrices with less cache misses."""
	mat_a_n = len(mat_a)
	mat_a_m = len(mat_a[0])
	mat_b_n = len(mat_b)
	mat_b_m = len(mat_b[0])
	mat_c = [[0 for i in range(mat_b_m)] for j in range(mat_a_n)]

	for i in range(mat_a_n):
		for k in range(mat_a_m):
			for j in range(mat_b_n):
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j]

	return mat_c


def matrix_sub(mat_a, mat_b):
	"""Computes A - B for the two given matrices."""
	mat_a_n = len(mat_a)
	mat_a_m = len(mat_a[0])
	mat_c = [[0 for i in range(mat_a_m)] for j in range(mat_a_n)]

	for i in range(mat_a_n):
		for j in range(mat_a_m):
			mat_c[i][j] = mat_a[i][j] - mat_b[i][j]

	return mat_c


mat_a = [
	[0, 0, 0, 0, 0],
	[0, 0, 0, 0, 1],
	[0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0],
	[0, 1, 0, 0, 0],
]
mat_b = [
	[0, 0, 0, 0, 0],
	[0, 0, 0, 0, 1],
	[0, 0, 0, 0, 0],
	[0, 0, 0, 0, 0],
	[0, 2, 0, 0, 0],
]

print matrix_sub(matrix_multiply(mat_a, mat_b), matrix_multiply(mat_b, mat_a))
print matrix_sub(matrix_fast_multiply(mat_a, mat_b), matrix_fast_multiply(mat_b, mat_a))

# r = len(mat)
# c = len(mat[0])

# augmented = [
# 	[
# 		1 if i == j else 0 
# 		for j in range(c)
# 	] 
# 	for i in range(r)
# ]
# # add(mat, augmented, 1, 2, -2)
# # add(mat, augmented, 1, 3, -1)

# # matrix_inverse(mat, augmented)
# print mat, augmented

# divide(mat, augmented, 1, 3)

# add(mat, augmented, 1, 2, -1)
# add(mat, augmented, 1, 3, -2)
# add(mat, augmented, 1, 4, -6)

# multiply(mat, augmented, 2, -1)

# add(mat, augmented, 2, 4, 1)

# add(mat, augmented, 3, 4, -1)

# for matrow, augmentedrow in zip(mat, augmented):
# 	printed = 0
# 	print '[',
# 	printed += 2
# 	for entry in matrow:
# 		print ' ' * (3 - len(str(entry))) + str(entry) + ',',
# 		printed += 8
# 	print ']'
# 	printed += 2

# 	# for entry in augmentedrow:
# 	# 	print ' ' * (3 - len(str(entry))) + str(entry) + ',',
# 	# 	printed += 8
# 	# print ']'
