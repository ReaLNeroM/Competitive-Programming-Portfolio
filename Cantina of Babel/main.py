n = int(input())
for i in range(n):
    s = input().split(' ')[1:]
    speak, listen = s[0], s[1:]
    print(speak, listen)
