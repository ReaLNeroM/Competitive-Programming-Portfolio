import random

def open_pack():
	pack = [0, 0, 0, 0, 1]
	for p in range(len(pack)):
		if pack[p] == 0 and random.uniform(0, 1) < 0.2:
			pack[p] = 1
		if pack[p] == 1 and random.uniform(0, 1) < 0.2:
			pack[p] = 2
		if pack[p] == 2 and random.uniform(0, 1) < 0.2:
			pack[p] = 3

	for p in range(len(pack)):
		if pack[p] == 0:
			pack[p] = random.randint(1, 80)
		elif pack[p] == 1:
			pack[p] = 80 + random.randint(1, 40)
		elif pack[p] == 2:
			pack[p] = 80 + 40 + random.randint(1, 20)
		elif pack[p] == 3:
			pack[p] = 80 + 40 + 20 + random.randint(1, 10)

	return pack

need = [
	7, 9, 12, 45, 61, 78, 80 + 3, 80 + 6, 80 + 20, 80 + 34, 120 + 5, 120 + 11, 120 + 19,
	7, 9, 12, 45, 61, 78, 80 + 3, 80 + 6, 80 + 20, 80 + 34, 120 + 5, 120 + 11, 120 + 19,
	140 + 1, 140 + 4, 140 + 8, 140 + 10
]

summ = 0.0
times = 0.0

for _ in range(100000):
	need2 = list(need)
	for k in range(100000):
		a = open_pack()
		for x in a:
			if x in need2:
				need2.remove(x)

		if len(need2) == 0:
			summ += k + 1
			times += 1
			break
	print summ / times
