n = int(raw_input())
mod = 10**9 + 7
prime = [True for i in range(n + 1)]

res = 1
for i in range(2, n + 1):
	if prime[i]:
		curr = i * i
		while curr <= n:
			prime[curr] = False
			curr += i

		curr = i
		exponent = 0

		while curr <= n:
			exponent += n / curr
			curr *= i

		res *= (exponent + 1)
		res %= mod

print res	