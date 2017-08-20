#!/bin/python

import sys

def buyMaximumProducts(n, k, v):
    v = [(x, i + 1) for i, x in enumerate(v)]

    v.sort()

    res = 0

    for i in v:
        if i[0] * i[1] <= k:
            k -= i[0] * i[1]
            res += i[1]
        else:
            now = k / i[0]
            k -= now * i[0]
            res += now
            
    return res

if __name__ == "__main__":
    n = int(raw_input().strip())
    arr = map(int, raw_input().strip().split(' '))
    k = long(raw_input().strip())
    result = buyMaximumProducts(n, k, arr)
    print result
