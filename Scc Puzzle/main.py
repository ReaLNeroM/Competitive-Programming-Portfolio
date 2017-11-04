S, C = map(int, raw_input().split(' '))

X = min(S, C / 2)

res = X

C -= 2 * X

res += C / 4

print res