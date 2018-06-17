n = input()

power_2 = 0

val = map(int, raw_input().split(' '))

for i in val:
	while i % 2 == 0:
		i /= 2
		power_2 += 1

print power_2