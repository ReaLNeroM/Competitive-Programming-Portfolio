def minunique(s):
    n = len(s)

    for i in range(n + 1):
        for j in range(n - i + 1):
            a = s[j:j+i]

            occur = 0
            for k in range(n - i + 1):
                b = s[k:k+i]

                # print(i, j, k, a, b)

                if a == b:
                    occur += 1

            if occur == 1:
                return i

def brutegen(n, k):
    for ind in range(2**n):
        s = format(ind, '0' + str(n) + 'b')

        if minunique(s) == k:
            return s
            # print(s)
    # return '0'

def smartgen(n, k):
    if n == k:
        return '0'*n

    l = (n - k) // 2

    ss = ('0' * l + '1')
    ks = (n + l - 1) // l
    s = (ss * ks)[:n]
    return s

for i in range(1, 50):
    start = i % 2
    if start == 0:
        start += 2

    for j in range(start, i + 1, 2):
        s = smartgen(i, j)

        if minunique(s) != j:
            print(i, j, s, minunique(s))
