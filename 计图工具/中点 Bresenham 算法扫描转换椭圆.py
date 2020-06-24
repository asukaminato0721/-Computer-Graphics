a, b = 8, 6
x, y = 0, b
d1 = b*b+a*a*(-b+0.25)
print(f' {x}  {y}  {d1}  ')
# print(f'{-x}  {-y}')
# print(f'{-x}  {y}')
# print(f'{x}   {-y}')
while b*b*(x+1) < a*a*(y-0.5):
    if d1 <= 0:
        d1 += b*b*(2*x+3)
        x += 1
    else:
        d1 += b*b*(2*x+3)+a*a*(-2*y+2)
        x += 1
        y -= 1
    print(f' {x}  {y}  {d1}  ')
    # print(f'{-x}  {-y}')
    # print(f'{-x}  {y}')
    # print(f'{x}   {-y}')
d2 = b*b*(x+0.5)**2+a*a*(y-1)**2-a**2*b**2
while y > 0:
    if d2 <= 0:
        d2 += b**2*(2*x+2)+a**2*(-2*y+3)
        x += 1
        y -= 1
    else:
        d2 += a**2*(-2*y+3)
        y -= 1
    print(f' {x}  {y}  {d2}  ')
    # print(f'{-x}  {-y}')
    # print(f'{-x}  {y}')
    # print(f'{x}   {-y}')
