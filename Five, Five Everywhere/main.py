table = [True for i in range(1, 100000)]

def generate():
	global table
	for i in range(2, len(table)):
		if table[i] == True:
			for j in range(i * i, len(table), i):
				table[j] = False

	table[1] = False
	
def prime(x):
	if table[1] == True:
		generate()

	return table[x]

v = []
for i in range(11, 55556, 10):
	if prime(i):
		v.append(i)

n = int(raw_input())

for i in range(n):
	print v[i],
