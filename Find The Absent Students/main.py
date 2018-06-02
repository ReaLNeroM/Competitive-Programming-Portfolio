#!/bin/python

import os
import sys

# Complete the findTheAbsentStudents function below.
def findTheAbsentStudents(n, a):
    v = []
    for i in range(1, n + 1):
        found = False
        for j in a:
            if i == j:
                found = True

        if found is False:
            v.append(i)
            
    return v

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    a = map(int, raw_input().rstrip().split())

    result = findTheAbsentStudents(n, a)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
