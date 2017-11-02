n, k = map(int, raw_input().split(' '))
val = map(int, raw_input().split(' '))
val.sort()
partial = 0

for i in range(min(n, k)):
	partial += val[i]

partial += (100 - (partial % 100)) % 100
partial /= 100

print partial