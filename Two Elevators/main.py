n, u, d = map(int, raw_input().split(' '))

if u > d:
    u, d = d, u

res = 0

for i in range(n):
    a, b = map(int, raw_input().split(' '))
    
    if a > b and d >= a:
        res += 1
    elif a < b and u <= a:
        res += 1
        
print res