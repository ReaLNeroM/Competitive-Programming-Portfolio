res = 0

for i in range(0, 6):
	for j in range(i, 6):
		for k in range(j, 6):
			for l in range(k, 6):
				for m in range(l, 6):
					for n in range(m, 6):
						for o in range(n, 6):
							for p in range(o, 6):
								for q in range(p, 6):
									for r in range(q, 6):
										res += 1

print res