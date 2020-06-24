"""
左边是种子
"""

pts = [[2, j]for j in range(2, 10)] +\
    [[3, j] for j in range(2, 10)] +\
    [[4, j]for j in range(2, 10)] +\
    [[5, 2], [5, 3], [5, 7]] +\
    [[6, 2], [6, 3], [6, 7]] +\
    [[7, 2], [7, 3], [7, 7]] +\
    [[8, 2], [8, 3], [8, 4], [8, 7]] +\
    [[9, 2], [9, 3], [9, 4], [9, 5], [9, 7]] +\
    [[10, j]for j in range(3, 10)] +\
    [[11, j]for j in range(4, 10)]

stack, isvisited = [], []

S = [6, 3]

stack.append(S)

计数 = 1

while stack:
    temp = stack[-1]  # 出栈
    stack.pop()  # 出栈
    isvisited.append(temp)
    xl, yl, xr, yr = temp*2
    while [xl-1, yl] in pts:
        isvisited.append([xl-1, yl])
        pts.remove([xl-1, yl])
        xl -= 1
    # 循环完成，左边推到一个值
    while [xr+1, yr] in pts:
        isvisited.append([xr+1, yr])
        pts.remove([xr+1, yr])
        xr += 1
    # 循环完成，右边推到一个值

    上 = yl-1

    for pt in pts:
        if pt[-1] == 上 and xl <= pt[0] <= xr:
            if ([pt[0]-1, 上] not in pts or pt[0] == xl) and pt not in isvisited:  # 判断上面一行的种子
                stack.append(pt)
                isvisited.append(pt)
                print(计数, pt)
                计数 += 1
    下 = yr+1
    for pt in pts:
        if pt[-1] == 下 and xl <= pt[0] <= xr:
            if ([pt[0]-1, 下] not in pts or pt[0] == xl) and pt not in isvisited:  # 判断下面一行的种子
                stack.append(pt)
                isvisited.append(pt)
                print(计数, pt)
                计数 += 1
