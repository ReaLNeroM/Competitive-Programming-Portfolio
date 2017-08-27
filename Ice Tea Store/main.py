A = []
A = map(int, raw_input().split(' '))
pow = [1, 2, 4, 8]

N = int(raw_input())
N *= 4

for i in range(len(A) - 1):
	A[i + 1] = min(A[i] * 2, A[i + 1])

res = 0
for i in range(len(A) - 1, -1, -1):
	floor = N / pow[i]
	res += floor * A[i]
	N %= pow[i]

print res