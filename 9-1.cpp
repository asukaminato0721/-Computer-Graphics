//g++ -o 9-1 -Wall 9-1.cpp -mwindows glut32.lib -lopengl32 -lglu32
#include <windows.h>
#include <gl/glut.h>

void Initial()
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CW);
    glClearColor(1.0, 1.8, 1.8, 0.8);
}
// 启用深度测试
//设置多边形绕法顺时针为正面
void ChangeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-4.0f, 4.0f, -4.0f * h / w, 4.0f * h / w, -4.0f, 4.0f);
    else
        glOrtho(-4.0f * w / h, 4.0f * w / h, -4.0f, 4.0f, -4.0f, 4.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    /*第一个茶壶使用了剔除*/
    glEnable(GL_CULL_FACE);
    //开启多边形表面剔除功能 s
    glCullFace(GL_BACK);
    //剔除茶壶的后向面
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    GLdouble equ[4] = {-1.0f, 2.3f, 2.3f, 2.3f};
    // equ中保存平面方程的系数
    glClipPlane(GL_CLIP_PLANE0, equ);
    // glClipPlane定义裁剪平面
    glEnable(GL_CLIP_PLANE0);
    //开启裁剪平面
    //绘制茶壶
    glutSolidTeapot(1.0);
    glPopMatrix();
    /*第二个茶壶关闭了剔除操作*/
    // 关闭剔除功能
    glDisable(GL_CULL_FACE);
    glTranslatef(2.0f, 0.0f, 0.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glClipPlane(GL_CLIP_PLANE0, equ);
    glEnable(GL_CLIP_PLANE0);
    glutSolidTeapot(1.0);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE0);
    glFlush();
    //禁用裁剪平面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("the teapot tick out");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(Display);
    Initial();
    glutMainLoop();
    return 0;
}