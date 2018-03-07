N = input()

val = map(int, raw_input().split(' '))

pos = 1
ldist = val[0]
rdist = sum(val) - val[0]

res = [10**9, 0]

for i in range(N):
	while (pos + 1) % N != i and min(ldist, rdist) < min(ldist + val[pos % N], rdist - val[pos % N]):
		ldist += val[pos % N]
		rdist -= val[pos % N]
		pos += 1

	res = min(res, [min(ldist, rdist), i])
	ldist -= val[i]
	rdist += val[i]

print res[1] + 1