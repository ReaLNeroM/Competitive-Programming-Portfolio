#!/bin/python

from __future__ import print_function

import os
import sys


#
# Complete the berthType function below.
#
def berthType(n):
    if n % 8 == 0:
        return "SUB"
    elif n % 8 == 7:
        return "SLB"
    elif n % 8 == 1 or n % 8 == 4:
        return "LB"
    elif n % 8 == 2 or n % 8 == 5:
        return "MB"
    elif n % 8 == 3 or n % 8 == 6:
        return "UB"
    # Return the type of berth as described in the output format section.


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    result = berthType(n)

    f.write(result + '\n')

    f.close()
