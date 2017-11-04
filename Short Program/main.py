n = int(raw_input())

one = 1023
zero = 0
for i in range(n):
	c, v = raw_input().split(' ')
	v = int(v)

	if c == '|':
		zero |= v
		one |= v
	elif c == '^':
		zero ^= v
		one ^= v
	elif c == '&':
		zero &= v
		one &= v

to_xor = 0
to_or = 0
to_and = 1023

i = 1
while i < 1024:
	if (zero & i) == 0 and (one & i) == 0:
		to_and ^= i
	if (zero & i) == i and (one & i) == 0:
		to_xor |= i
	if (zero & i) == i and (one & i) == i:
		to_or |= i

	i *= 2

print 3
print '|', to_or
print '^', to_xor
print '&', to_and
