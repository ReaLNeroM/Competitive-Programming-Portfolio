# https://codeforces.com/gym/102920/problem/B

from math import gcd

a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))

t = 0
for i in a:
    for j in b:
        if i > j:
            t += 1
m = 36
t, m = t // gcd(t, m), m // gcd(t, m)

print(t, '/', m, sep = '')