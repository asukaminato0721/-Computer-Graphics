x0, y0 = 1, 2
x1, y1 = 5, 5
i = 0
if x0 > x1:
    x0, x1 = x1, x0
    y0, y1 = y1, y0
x, y = x0, y0
dx, dy = x1-x0, y1-y0
d = dx-2*dy
up, down = 2*dx-2*dy, -2*dy
print('i', '(xi,yi)', 'di')
while x <= x1:
    print(f'{i}  ({x},{y})  {d}')
    x += 1
    if d < 0:
        y += 1
        d += up
    else:
        d += down
    i += 1
