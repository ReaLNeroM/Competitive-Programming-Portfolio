import time

start_time = time.time()
val = []

x = raw_input()
val = list(map(int, x.split(' ')))
n = val[0]

del val[0]
    
val.sort()

res = ""
for i in xrange(0, n):
	res += str(val[i]) + ' '

end_time = time.time()
while end_time - start_time < 1.1:
	end_time = time.time()

print res
