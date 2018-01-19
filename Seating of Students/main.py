y, x = map(int, raw_input().split(' '))

start = [[i * x + j for j in range(x)] for i in range(y)]

res = [[0 for j in range(x)] for i in range(y)]

for i in range(y):
    if i % 2 == 0:
        curr_ind = 0
        for j in range(1, x, 2):
            res[i][curr_ind] = start[i][j]
            curr_ind += 1
        for j in range(0, x, 2):
            res[i][curr_ind] = start[i][j]
            curr_ind += 1
    else:
        curr_ind = 0
        for j in range(1, x, 2):
            res[i][curr_ind] = start[i][j]
            curr_ind += 1
        for j in range(0, x, 2):
            res[i][curr_ind] = start[i][j]
            curr_ind += 1

for i in range(y):
    for j in range(x):
        print res[i][j] + 1,
    print