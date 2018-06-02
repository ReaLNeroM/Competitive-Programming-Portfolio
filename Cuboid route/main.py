import math

def test(M):
	res = 0

	for i in range(1, M + 1):
		for j in range(1, i + 1):
			for k in range(1, j + 1):
				dist_a = i**2 + (j + k)**2
				dist_b = j**2 + (i + k)**2
				dist_c = k**2 + (i + j)**2

				dist_min = math.sqrt(min(dist_a, dist_b, dist_c))

				if dist_min - int(dist_min) < 0.00001:
					res += 1

	return res

print test(500)