import sys

test_cases = int(input())

for test_case in range(test_cases):
    n, b, f = map(int, raw_input().split(' '))

    response = []

    span = 1

    while span <= 16:
        query = '0' * span + '1' * span
        query = query * (2048 / len(query))
        
        print query[0:n]
        sys.stdout.flush()

        response.append(raw_input())

        span *= 2

    broken_machines = []

    currPos = 0

    for i in range(n):
        while currPos < len(response[0]) and i % 16 == 0 and \
                bool(i / 16 % 2) != bool(response[-1][currPos] == '1'):
            currPos += 1
        if currPos >= len(response[0]):
            broken_machines.append(i)
            continue

        isBroken = False

        currBitChecked = 1
        currQueryChecked = 0
        while currQueryChecked < len(response):
            if bool((currBitChecked & i) != 0) != bool(response[currQueryChecked][currPos] == '1'):
                isBroken = True
                break
            currBitChecked *= 2
            currQueryChecked += 1

        if isBroken is True:
            broken_machines.append(i)
        else:
            currPos += 1

    for i in broken_machines:
        print i,
    print

    sys.stdout.flush()

    verdict = raw_input()
