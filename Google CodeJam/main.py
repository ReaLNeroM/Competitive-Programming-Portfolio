test_cases = int(input())

for test_case in range(1, test_cases + 1):
    y, x = map(int, raw_input().split(' '))
    
    if x == 2 and y == 2:
        print "Case #" + str(test_case) + ": IMPOSSIBLE"
        #impposible
    elif x == 2 and y % 2 == 1:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for i in range(y):
            print i % 2 + 1, i + 1
        for i in range(y):
            print (i + 1) % 2 + 1, i + 1
    elif x == 2 and y % 2 == 0:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for i in range(y):
            print i % 2 + 1, i + 1
        for i in range(1, y):
            print (i + 1) % 2 + 1, i + 1
        print 2, 1
    elif y == 2 and x % 2 == 1:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for i in range(x):
            print i + 1, i % 2 + 1
        for i in range(x):
            print i + 1, (i + 1) % 2 + 1
    elif y == 2 and x % 2 == 0:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for i in range(x):
            print i + 1, i % 2 + 1
        for i in range(1, x):
            print i + 1, (i + 1) % 2 + 1
        print 1, 2
    elif y == 3 and x >= 4:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for ssum in range(1, x + y - 2):
            for i in range(ssum + 1):
                py, px = i, ssum - i
                if 0 <= py < y and 0 <= px < x:
                    print py + 1, px + 1
                if py == 0 and px == 2:
                    print y, x
                    print 1, 1
    elif x == 3 and y >= 4:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for ssum in range(1, x + y - 2):
            for i in range(ssum + 1):
                py, px = i, ssum - i
                if 0 <= py < y and 0 <= px < x:
                    print py + 1, px + 1
                if py == 1 and px == 1:
                    print 1, 1
                    print y, x
    elif x >= 4 and y >= 4:
        print "Case #" + str(test_case) + ": POSSIBLE"
        for ssum in range(1, x + y - 2):
            for i in range(ssum + 1):
                py, px = i, ssum - i
                if 0 <= py < y and 0 <= px < x:
                    print py + 1, px + 1
                if py == 1 and px == 2:
                    print 1, 1
                    print y, x
        # you just do the diagonal trick
    else:
        #should just be 3, 3
        print "Case #" + str(test_case) + ": IMPOSSIBLE"
