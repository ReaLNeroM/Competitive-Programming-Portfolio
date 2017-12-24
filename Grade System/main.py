n = int(raw_input())
v = map(int, raw_input().split(' '))
v.sort()
v = v[1:n - 1]
print sum(v) / (n - 2)