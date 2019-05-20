import sys
import random

testCases = 250
# testCases = int(input())

for testCase in range(1, testCases + 1):
    a = random.randint(1, 20)
    b = random.randint(1, 20)

    while a == b:
        b = random.randint(1, 20)

    randomPerm = range(1, 21)
    randomPerm.remove(a)
    randomPerm.remove(b)
    random.shuffle(randomPerm)

    for i in range(1, 101):
        # read_day = input()
        # if read_day == -1:
        #     print "FUCK"
        #     sys.exit()
        
        if i <= 19:
            print i, 100
        elif i == 100:
            print 20, 100
        else:
            print randomPerm[i % 18], i / 18
        sys.stdout.flush()