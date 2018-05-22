from copy import deepcopy

def multiply(A, B):
	new_a = [[0 for i in range(len(B[0]))] for j in range(len(A))]

	for i in range(len(A)):
		for j in range(len(B[0])):
			for k in range(len(A[i])):
				new_a[i][j] += A[i][k] * B[k][j]

	return new_a

def exponentiate(table, times):
	new_table = deepcopy(table)
	identity = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]

	curr_pow = 1
	while curr_pow <= times:
		if curr_pow & times:
			identity = multiply(new_table, identity)

		new_table = multiply(new_table, new_table)
		curr_pow *= 2

	return identity

a, b, c, k = map(int, raw_input().split(' '))
table = [[0, 1, 1], [1, 0, 1], [1, 1, 0]]

table_expand = exponentiate(table, min(k, 16384 + k % 2))
resultant_array = multiply(table_expand, [[a], [b], [c]])

if abs(resultant_array[0][0] - resultant_array[1][0]) > 10**18:
	print 'Unfair'
else:
	print resultant_array[0][0] - resultant_array[1][0]