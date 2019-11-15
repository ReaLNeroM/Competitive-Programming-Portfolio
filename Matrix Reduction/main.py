def add(mat, augmented, a, b, c):
	n = len(mat)
	m = len(mat[0])
	a -= 1
	b -= 1
	for i in range(m):
		mat[b][i] += c * mat[a][i]
	for i in range(n):
		augmented[b][i] += augmented[a][i] * c

def swap(mat, augmented, a, b):
	n = len(mat)
	m = len(mat[0])
	a -= 1
	b -= 1
	for i in range(m):
		mat[a][i], mat[b][i] = mat[b][i], mat[a][i]
	for i in range(n):
		augmented[a][i], augmented[b][i] = augmented[b][i], augmented[a][i]

def multiply(mat, augmented, a, c):
	a -= 1
	n = len(mat)
	m = len(mat[0])
	for i in range(m):
		mat[a][i] *= c
	for i in range(n):
		augmented[a][i] *= c

def divide(mat, augmented, a, c):
	a -= 1
	c = float(c)
	n = len(mat)
	m = len(mat[0])
	for i in range(m):
		mat[a][i] /= c
	for i in range(n):
		augmented[a][i] /= c

def matrix_multiply(mat_a, mat_b):
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

mat = [
	[1, 0, -1],
	[2, 1, 3],
	[1, 1, 4]
]

augmented = [
	[1, 0, 0],
	[0, 1, 0],
	[0, 0, 1],
]

add(mat, augmented, 1, 2, -2)
add(mat, augmented, 1, 3, -1)

print mat

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
