n = input()

a = [0 for i in range(n)]
b = [0 for i in range(n)]

for i in range(n):
	a[i], b[i] = map(int, raw_input().split(' '))

increases = 0

for i in range(n - 1, -1, -1):
	increases += (b[i] - (a[i] + increases)) % b[i]

print increases