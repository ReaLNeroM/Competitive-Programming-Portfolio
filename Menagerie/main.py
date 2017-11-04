import sys

N = int(raw_input())
S = raw_input()

printed = False

for zero_is in range(2):
	for one_is in range(2):
		type = [0 for i in range(N)]
		type[0] = zero_is
		type[1] = one_is
		this_works = True

		for j in range(1, N):
			ind_prev = j - 1
			ind_next = (j + 1) % N

			if S[j] == 'o' and type[j] == 0 or S[j] == 'x' and type[j] == 1:
				type[ind_next] = type[ind_prev]
			else:
				type[ind_next] = not type[ind_prev]

		for j in range(0, N):
			ind_prev = (j + N - 1) % N
			ind_next = (j + 1) % N

			if S[j] == 'o' and type[j] == 0 or S[j] == 'x' and type[j] == 1:
				if type[ind_prev] != type[ind_next]:
					this_works = False
			else:
				if type[ind_prev] == type[ind_next]:
					this_works = False

		if this_works is True and printed is False:
			for i in type:
				if i == 0:
					sys.stdout.write('S')
				else:
					sys.stdout.write('W')
			printed = True

if printed is False:
	print -1
else:
	sys.stdout.write('\n')