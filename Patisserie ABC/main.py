n, m = map(int, raw_input().split(' '))

x = [0 for i in range(n)]
y = [0 for i in range(n)]
z = [0 for i in range(n)]

for i in range(n):
	x[i], y[i], z[i] = map(int, raw_input().split(' '))

max_v = 0

for __counter_a in range(2):
	for __counter_b in range(2):
		for __counter_c in range(2):
			v = [0 for i in range(n)]
			for i in range(n):
				v[i] = x[i] + y[i] + z[i]
			v.sort(reverse=True)

			curr_v_sum = 0
			for i in range(m):
				curr_v_sum += v[i]

			max_v = max(max_v, curr_v_sum)
			
			for i in range(n):
				z[i] *= -1

		for i in range(n):
			y[i] *= -1

	for i in range(n):
		x[i] *= -1;

print max_v