import random

def quickSelect(numbers, l, r, k):
    pivot = random.randint(l, r)
    rStartPoint = l
    numbers[pivot], numbers[r] = numbers[r], numbers[pivot]
    
    for i in range(l, r):
        if numbers[i] <= numbers[r]:
            numbers[i], numbers[rStartPoint] = numbers[rStartPoint], numbers[i]
            rStartPoint += 1
    
    if k < rStartPoint - l:
        return quickSelect(numbers, l, rStartPoint - 1, k)
    elif k == rStartPoint - l:
        return numbers[r]
    else:
        return quickSelect(numbers, rStartPoint, r - 1, k - (rStartPoint - l + 1))

def solution(numbers, k):
    if k >= len(numbers):
        return 0
    
    return quickSelect(numbers, 0, len(numbers) - 1, len(numbers) - k)

print solution([6, 5, 4, 3, 2, 1], 4)