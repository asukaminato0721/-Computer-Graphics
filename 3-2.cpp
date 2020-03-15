//g++ -o 3-2 -Wall 3-2.cpp -mwindows glut32.lib -lopengl32 -lglu32
#include <windows.h>
#include <gl/glut.h>
void Key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'p':
        if (iPointNum == 0 || iPointNum == 2)
        {
            iPointNum = 1;
            x1 = x;
            y1 = winHeight - y;
        }
        else
        {
            iPointNum = 2;
            x2 = x;
            y2 = winHeight - y;
            glutPostRedisplay();
        }
        break;

    default:
        break;
    }
}