from __future__ import print_function
from decimal import *
getcontext().prec = 50

a, b, c = map(int, raw_input().split(' '))

res = Decimal(Decimal(a) * b) / Decimal(c)
print(res)