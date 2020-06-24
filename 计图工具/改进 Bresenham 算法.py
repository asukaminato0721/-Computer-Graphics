x0, y0 = 0, 0
x1, y1 = 8, 6
dx, dy = x1-x0, y1-y0
e = -dx
x, y = x0, y0
i = 0
print('i  (xi,yi)    e    e+2dy  e-2dx')
while x <= x1:
    print(f'{i}    ({x},{y})    {e}     {e+2*dy}     {e-2*dx}')
    x += 1
    e += 2*dy
    if e > 0:
        y += 1
        e -= 2*dx
    i += 1
