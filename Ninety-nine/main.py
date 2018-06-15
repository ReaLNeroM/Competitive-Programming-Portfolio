from __future__ import print_function

print(1)

sum = 1

while sum < 99:
	opponent_sum = input()
	sum = opponent_sum
	if sum == 99:
		break

	if sum % 3 == 0:
		sum += 2
	else:
		sum += 3 - sum % 3

	print(sum)
