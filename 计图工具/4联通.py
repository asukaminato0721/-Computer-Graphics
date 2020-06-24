pts = [
    [1, 1], [1, 2], [1, 3], [1, 4],
    [2, 1], [2, 2], [2, 3], [2, 4],
    [3, 1], [3, 4], [3, 3],
    [4, 1], [4, 2], [4, 3]
]
step = [[0, 1], [0, -1], [-1, 0], [1, 0]]
S = [3, 2]
计数 = 0
stack, isvisited = [], []
stack.append(S)  # 种子像素入栈
while stack:
    temp = stack[-1]  # 栈顶像素出栈
    stack.pop()  # 栈顶像素出栈
    try:
        pts.remove(temp)  # 设置填充色
    except ValueError:
        break # 不需要填充就结束
    print(计数, temp)  # 设置填充色
    isvisited.append(temp)  # 设置填充色
    计数 += 1
    x, y = temp
    for _ in step:  # 检查四邻接点
        dx, dy = _
        x1, y1 = x+dx, y+dy
        if [x1, y1] in pts and [x1, y1] not in isvisited:  # 如果未设置多边形色
            stack.append([x1, y1])
            print(f'{[x1,y1]} 入栈')
