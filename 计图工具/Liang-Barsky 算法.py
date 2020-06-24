# https://blog.csdn.net/liam_dapaitou/article/details/87550813


def Liang_Barsky_clipper(xmin, ymin, xmax, ymax,
                         x1,  y1,  x2,  y2):
    """
    Liang_Barsky_clipper(xmin, ymin, xmax, ymax, x1,  y1,  x2,  y2)
    """
    p = [0]*10
    q = [0]*10
    dx = x2 - x1
    dy = y2 - y1
    p[1] = -dx
    p[2] = -p[1]
    p[3] = -dy
    p[4] = -p[3]
    q[1] = x1 - xmin
    q[2] = xmax - x1
    q[3] = y1 - ymin
    q[4] = ymax - y1
    u1 = 0
    u2 = 1
    for i in range(1, 5):
        r = q[i]/p[i]
        if (p[i] < 0):
            if (r > u2):
                return False
            if (r > u1):
                u1 = r
        elif (p[i] > 0):
            if (r < u1):
                return False
            if (r < u2):
                u2 = r
        elif (q[i] < 0):
            return False

    # // do x2 y2 first
    x2 = x1 + u2*dx
    y2 = y1 + u2*dy
    x1 = x1 + u1*dx
    y1 = y1 + u1*dy
    print(f'{x1,y1},{x2,y2}')
    return True


Liang_Barsky_clipper(0, 0, 2, 2, -1, -2, 3, 3)
