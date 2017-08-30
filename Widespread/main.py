def good(x):
	VC = list(V)

	Breduce = B * x

	for i in range(N):
		VC[i] -= Breduce

	required = 0

	for i in range(N):
		if VC[i] > 0:
			required += (VC[i] + A - 1) / A

	if required <= x:
		return True
	else:
		return False

N, A, B = map(int, raw_input().split(' '))
A = A - B

V = [0 for i in range(N)]

for i in range(N):
	V[i] = int(raw_input())

l = 1
r = 1000000000000000000
best = 1000000000000000000


while l <= r:
	mid = (l + r) / 2
	if good(mid):
		r = mid - 1
		best = mid
	else:
		l = mid + 1

print best