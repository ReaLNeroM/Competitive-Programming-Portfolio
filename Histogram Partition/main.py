n = int(raw_input())
v = map(int, raw_input().split(' '))
stack = []

res = 0
for i in v:
    while stack and i < stack[-1]:
        stack.pop()
    
    if not stack or stack[-1] < i:
        stack.append(i)
        res += 1
        
print res