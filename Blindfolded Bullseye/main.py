import sys
import random

def ask(x, y):
    if not (-10**9 <= x <= 10**9 and -10**9 <= y <= 10**9):
        return "MISS"

    print(x, y)
    sys.stdout.flush()
    r = input()

    return r

def find_point_in_circle():
    while True:
        randx, randy = random.randint(-10**9, 10**9), random.randint(-10**9, 10**9)
        resp = ask(randx, randy)
        
        if resp != "MISS":
            return randx, randy, resp

test_cases, a, b = map(int, input().split(' '))

for test_case in range(test_cases):
    # First, find a point in the circle.
    random_point_x, random_point_y, resp = find_point_in_circle()
    
    if resp == "CENTER":
        continue
    
    p_x, p_y = random_point_x, random_point_y

    # Then, go as left as possible while staying in the circle.
    l, r = -10**9, p_x - 1

    while l <= r:
        mid = (l + r) // 2
        resp = ask(mid, p_y)

        if resp == "CENTER":
            break
        elif resp == "HIT":
            p_x = mid
            r = mid - 1
        else:
            l = mid + 1

    if resp == "CENTER":
        continue
    
    # Then, go as up as possible while staying in the circle.
    l, r = -10**9, p_y - 1

    while l <= r:
        mid = (l + r) // 2
        resp = ask(p_x, mid)

        if resp == "CENTER":
            break
        elif resp == "HIT":
            p_y = mid
            r = mid - 1
        else:
            l = mid + 1

    if resp == "CENTER":
        continue
    
    # Now that we have a point (call it p) that's on the top-left quarter-circle, 
    # we can find two other points:
    #   - Another point (call it q) with the same y-coordinate in the top-right quarter-circle.
    #   - Another point (call it r) with the same x-coordinate in the bottom-left quarter-circle.
    q_x, q_y = p_x, p_y
    l, r = q_x + 1, 10**9
    while l <= r:
        mid = (l + r) // 2
        resp = ask(mid, q_y)

        if resp == "CENTER":
            break
        elif resp == "HIT":
            q_x = mid
            l = mid + 1
        else:
            r = mid - 1

    if resp == "CENTER":
        continue
    
    r_x, r_y = p_x, p_y
    l, r = q_y + 1, 10**9
    while l <= r:
        mid = (l + r) // 2
        resp = ask(r_x, mid)

        if resp == "CENTER":
            break
        elif resp == "HIT":
            r_y = mid
            l = mid + 1
        else:
            r = mid - 1

    if resp == "CENTER":
        continue

    # The x-coordinate of the radius should be the average of p.x and q.x
    # The y-coordinate of the radius should be the average of p.y and r.y
    # The variables below may be incorrect due to rounding errors.
    center_x, center_y = (p_x + q_x) // 2, (p_y + r_y) // 2

    # We ask for all points in a neighborhood of (center_x, center_y)
    for i in range(-5, 5):
        for j in range(-5, 5):
            resp = ask(center_x + i, center_y + j)

            if resp == "CENTER":
                break

        if resp == "CENTER":
            break
