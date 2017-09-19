N = int(raw_input())
V = map(int, raw_input().split(' '))

sorted_V = [N-i-1 for i in range(N)]

sorted_V.sort(reverse=True,key=lambda x: V[x])
lowest = N

uses = [0 for i in range(N)]

last = V[sorted_V[0]]

for ind, val in enumerate(sorted_V):
	if ind != N - 1 and V[sorted_V[ind]] == V[sorted_V[ind + 1]]:
		continue

	lowest = min(lowest, val)
	spots = ind + 1

	if ind == N - 1:
		individual_removals = last
		last = 0
	else:
		individual_removals = last - V[sorted_V[ind + 1]]
		last = V[sorted_V[ind + 1]]

	full_removals = individual_removals * spots
	uses[lowest] += full_removals

for i in uses:
	print i