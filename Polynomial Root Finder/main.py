from random import uniform

def f(x):
	return x**5 - x + 1

def f_d(x):
	return 5 * x**4 - 1

def newtons_method(f, f_d):
	x = uniform(0, 100)

	for i in range(10000):
		x_new = x - f(x) / f_d(x)

		x = x_new

	return x

x = newtons_method(f, f_d)
print x
print f(x)