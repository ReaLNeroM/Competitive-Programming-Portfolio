import sys
import math

for t1 in range(1, 50):
	for t2 in range(1, 50):
		for v1 in range(1, 50):
			for v2 in range(1, 50):
				for l in range(1, 50):
					for a1 in range(1, 50):
						for a2 in range(1, 50):
							for b1 in range(1, 50):
								for b2 in range(1, 50):
									if t1 != a1 and t2 != a2:
										izraz1 = float(v1 * t1 + v2 * t2 + l) / float(v1 + v2)
										izraz2 = float(a1 * b1 + a2 * b2 + l) / float(b1 + b2)
										if izraz1 != izraz2 and math.floor(izraz1) == math.floor(izraz2):
											print v1, t1, v2, t2, l
											print a1, b1, a2, b2, l
											print izraz1, izraz2
											# sys.exit()
