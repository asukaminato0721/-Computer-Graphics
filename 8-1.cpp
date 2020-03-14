//g++ -o 8-1 -Wall 8-1.cpp -mwindows glut32.lib -lopengl32 -lglu32
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
class Pt3D
{
public:
    GLfloat x, y, z;
};
//计算多项式的系数
void GetCnk(GLint n, GLint *c)
{
    GLint i, k;
    for (k = 0; k <= n; k++)
    {
        c[k] = 1;
        for (i = n; i >= k + 1; i--)
            c[k] = c[k] * i;
        for (i = n - k; i >= 2; i--)
            c[k] = c[k] / i;
    }
}
//计算Bezier曲线上点的坐标
void GetPointPr(GLint *c, GLfloat t, Pt3D *Pt, int ControlN, Pt3D *ControlP)
{
    GLint k, n = ControlN - 1;
    GLfloat Bernstein;
    Pt->x = 0.0;
    Pt->y = 0.0;
    Pt->z = 0.0;
    for (k = 0; k < ControlN; k++)
    {
        Bernstein = c[k] * pow(t, k) * pow(1 - t, n - k);
        Pt->x += ControlP[k].x * Bernstein;
        Pt->y += ControlP[k].y * Bernstein;
        Pt->z += ControlP[k].z * Bernstein;
    }
}
//根据控制点,求曲线上的m个点
void BezierCurve(GLint m, GLint ControlN, Pt3D *ControlP)
{
    GLint *C, i;
    Pt3D CurvePt;
    C = new GLint[ControlN];
    GetCnk(ControlN - 1, C);
    glBegin(GL_POINTS);
    for (i = 0; i <= m; i++)
    {
        GetPointPr(C, (GLfloat)i / (GLfloat)m, &CurvePt, ControlN, ControlP);
        glVertex2f(CurvePt.x, CurvePt.y);
    }
    glEnd();
    delete[] C;
}
void initial(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLint ControlN = 4, m = 500;
    //指定有4个控制点,生成的Bezier曲线由500个点组成

    Pt3D ControlP[4] = {{-88.0, -40.0, 0.0}, {-10.0, 90.0, 0.8}, {10.0, -90.0, 0.0}, {80.0, 40.0, 0.0}};
    // 控制点坐标
    // 设置当前绘制点大小
    glPointSize(2);
    glColor3f(0.0, 0.0, 0.0);
    //绘制控制多边形
    BezierCurve(m, ControlN, ControlP); //绘制Bezier曲线
    glBegin(GL_LINE_STRIP);
    for (GLint i = 0; i < 4; i++)
        glVertex3f(ControlP[i].x, ControlP[i].y, ControlP[i].z);
    glEnd();
    glFlush();
}
void Reshape(GLint newwidth, GLint newHeight)
{
    glViewport(0, 0, newwidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bezier curve");
    initial();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}