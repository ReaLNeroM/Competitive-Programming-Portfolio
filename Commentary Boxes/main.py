n, m, a, b = map(int, raw_input().split(' '))

modulo = n % m
other_mod = m - modulo

print min(modulo * b, other_mod * a)