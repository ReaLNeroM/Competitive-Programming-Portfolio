testCases = input()

for testCase in range(1, testCases + 1):
	n, k = map(int, raw_input().split(' '))

	res = -k
	edgeList = []
	currNum = k - 1
	edgeList.append([1, n, k])
	for i in range(1, n):
		if currNum > 1:
			res += currNum
			edgeList.append([i, i + 1, currNum])
		else:
			res += currNum
			edgeList.append([i, n, 1])
			break
		currNum -= 1

	print "Case #{}:".format(testCase),
	if k == 1 or n == 2 or res <= 0:
		print 0
		print 1
		print "1 {} 1".format(n)
	else:
		print res
		print len(edgeList)
		for edge in edgeList:
			print edge[0], edge[1], edge[2]
