import sys

def forward():
    print('+')
    sys.stdout.flush()
    v = int(input())
    if v == 1:
        zero_resolve()

def backward():
    print('-')
    sys.stdout.flush()
    v = int(input())
    if v == 1:
        zero_resolve()

def zero_resolve():
    print('+')
    sys.stdout.flush()
    v = int(input())

    print('-')
    sys.stdout.flush()
    v = int(input())
    if v == 1:
        print("! ugly")
        sys.exit(0)

    print('-')
    sys.stdout.flush()
    v = int(input())
    if v == 1:
        print("! good")
        sys.exit(0)
    else:
        print("! bad")
        sys.exit(0)

def f(k, direc=True):
    for i in range(k):
        if direc is True:
            forward()
        else:
            backward()
    for i in range(2 * k):
        if direc is True:
            backward()
        else:
            forward()

curr_k = 1
curr_dir = True
while True:
    f(curr_k, curr_dir)

    curr_k *= 4
    curr_dir = not curr_dir