t = input()

for i in range(t):
	n = input()
	v = map(int, raw_input().split(' '))

	sorted_v = list(v)
	sorted_v.sort(reverse=True)

	s = ""

	if len(v) >= 2:
		while sorted_v[0] != sorted_v[1]:
			ind = v.index(sorted_v[0])
			v[ind] -= 1
			sorted_v[0] -= 1

			s += chr(ord('A') + ind) + ' '

			sorted_v.sort(reverse=True)

	if len(v) >= 3:
		while sorted_v[2] > 0:
			ind = v.index(sorted_v[2])
			v[ind] -= 1
			sorted_v[2] -= 1

			s += chr(ord('A') + ind) + ' '

			sorted_v.sort(reverse=True)

	if len(v) >= 2:
		while sorted_v[0] > 0:
			ind1 = v.index(sorted_v[0])
			v[ind1] -= 1
			sorted_v[0] -= 1

			ind2 = v.index(sorted_v[1])
			v[ind2] -= 1
			sorted_v[1] -= 1

			s += chr(ord('A') + ind1) + chr(ord('A') + ind2) + ' '

			sorted_v.sort(reverse=True)

	while sorted_v[0] > 0:
		ind = v.index(sorted_v[0])
		v[ind] -= 1
		sorted_v[0] -= 1

		s += chr(ord('A') + ind) + ' '
		
		sorted_v.sort(reverse=True)

	print "Case #" + str(i + 1) + ": " + s