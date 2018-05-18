n = input()
w = map(int, raw_input().split(' '))
w = [[w[i], i + 1] for i in range(len(w))]
w.sort()

open = []

s = list(raw_input())

introvert_pos = 0

for i in s:
	if i == '0':
		open.append(w[introvert_pos][1])
		introvert_pos += 1
		print open[-1],
	else:
		print open[-1],
		del open[-1]