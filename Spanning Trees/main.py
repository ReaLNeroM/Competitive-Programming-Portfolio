import sys

n, k = map(int, raw_input().split(' '))

if k == 0 and (n == 2 or n == 3):
    print -1
    sys.exit()

print n - k - 1 + n - 1
for i in range(n - k - 1):
	print i + 1, i + 2, 1

biggest = 2
for i in range(2, min(n - k, n - 1), 2):
	print i, i + 2, 3
	biggest = i + 2

if biggest + k >= n:
	for i in range(n - k, n):
		print i, i + 1, 2
		biggest = i + 1
else:
	for i in range(n - k, n):
		print i, i + 1, 2

print biggest, 1, 3

for i in range(1, n - k - 1, 2):
	print i, i + 2, 3
