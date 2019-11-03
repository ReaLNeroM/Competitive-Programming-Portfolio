from collections import defaultdict
from math import factorial

def next_permutation(v):
	nondecreasing_suffix_index = 0
	for i in range(len(v) - 2, -1, -1):
		if v[i] < v[i + 1]:
			nondecreasing_suffix_index = i + 1
			break

	if nondecreasing_suffix_index == 0:
		print "Last permutation!"
		return []

	v[nondecreasing_suffix_index:] = v[-1:-(len(v)-nondecreasing_suffix_index+1):-1]

	removal_element = -1
	for i in range(nondecreasing_suffix_index, len(v)):
		if (
			v[i] > v[nondecreasing_suffix_index - 1] and 
			(removal_element == -1 or v[removal_element] > v[i])
		):
			removal_element = i

	v[removal_element], v[nondecreasing_suffix_index - 1] = v[nondecreasing_suffix_index - 1], v[removal_element]

	return v

def count_permutations(v):
	number_of_permutations = factorial(len(v))

	number_frequency = defaultdict(int)

	for i in v:
		number_frequency[i] += 1

	for key, value in number_frequency.items():
		number_of_permutations /= factorial(value)

	return number_of_permutations

v = [2, 2, 4, 4]
number_of_permutations = count_permutations(v)

for _ in range(number_of_permutations):
	print v
	v = next_permutation(v)
