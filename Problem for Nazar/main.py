l, r = map(int, raw_input().split(' '))


def getSumOdd(l, seq_len):
	return (l + seq_len)**2 - l**2

def getSumEven(l, seq_len):
	return (l + seq_len) * (l + seq_len - 1) - l * (l - 1)

def getAns(r):
	res = 0

	currNum = 0
	currPos = [0, 1]
	currSize = 1
	currSide = 0

	while currNum < r:
		currEnd = currNum + currSize

		if currEnd >= r:
			if currSide == 0:
				res += getSumOdd(currPos[currSide], r - currNum)
			else:
				res += getSumEven(currPos[currSide], r - currNum)
			currNum = r
		else:
			if currSide == 0:
				res += getSumOdd(currPos[currSide], currSize)
			else:
				res += getSumEven(currPos[currSide], currSize)
			currNum = currEnd

		currPos[currSide] += currSize
		currSize *= 2
		currSide = not currSide

	return res

print (getAns(r) - getAns(l - 1)) % (10**9+7)