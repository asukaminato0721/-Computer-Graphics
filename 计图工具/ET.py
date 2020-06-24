class Line:
    def __init__(self, start: list, end: list):
        self.start = start
        self.end = end
        self.x1, self.y1 = self.start
        self.x2, self.y2 = self.end
        self.ymin = min(self.y1, self.y2)
        self.ymax = max(self.y1, self.y2)
        self.x = self.x1 if self.y1 < self.y2 else self.x2

    def scope(self):
        if (self.x2-self.x1) == 0:
            return 0
        else:
            return 1/((self.y2-self.y1)/(self.x2-self.x1))


line1 = Line([0, 2], [1, 4])
line2 = Line([1, 4], [3, 3])
line3 = Line([3, 3], [5, 4])
line4 = Line([5, 4], [4, 0])
line5 = Line([4, 0], [0, 2])

line = [line1, line2, line3, line4, line5]

ylist = [i.y1 for i in line]+[i.y2 for i in line]
ymin, ymax = min(ylist), max(ylist)
# print(ymin,ymax)
isvisited = []
def key(elem):
    'get x'
    return elem.x
for y in range(ymin, ymax+1):
    print(y, end="  ")
    temp = [] # hold to sort l
    for l in line:
        if l not in isvisited and l.ymin <= y <= l.ymax:
            """
            ymax  x  1/k  next
            """
            isvisited.append(l)
            temp.append(l)
    temp.sort(key=key,reverse=True)
    for l in temp:
        print(f'  ->  {l.ymax} {l.x} {l.scope()}', end='')
    print("")
    # AET 就是加一个增量判断，还有个配对的问题
