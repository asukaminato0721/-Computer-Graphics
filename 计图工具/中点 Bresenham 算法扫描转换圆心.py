r = 8
x, y = 0, r
d = 1-r
print('i   (xi,yi)    d     2x+3     2(x-y)+5')
i = 0
while x <= y:
    print(f'{i}   {x,y}   {d}      {2*x+3}        {2*(x-y)+5}')
    if d < 0:
        d += 2*x+3
    else:
        d += 2*(x-y)+5
        y -= 1
    x += 1
    i += 1
print(f'{i}   {x,y}   {d}      {2*x+3}        {2*(x-y)+5}')
