//g++ -o 3-3 -Wall 3-3.cpp -mwindows glut32.lib -lopengl32 -lglu32
#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>
const GLint pickSize = 32; //拾取缓冲区的大小
int winWidth = 400, winHeight = 300;
void Initial(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
} //按照指定的模式绘制矩形对象
void DrawRect(GLenum mode)
{
    if (mode == GL_SELECT)
        glPushName(1); //将名字1压入堆栈
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(60.0f, 50.0f, 150.0f, 150.0f); //绘制红色矩形

    if (mode == GL_SELECT)
        glPushName(2); //将名字2压入堆栈
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(230.0f, 50.0f, 330.0f, 150.0f); //绘制绿色矩形
    if (mode == GL_SELECT)
        glPushName(3); //将名字3压入堆栈
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(140.0f, 140.0f, 240.0f, 240.0f); //绘制蓝色矩形
}
void ProcessPicks(GLint nPicks, GLuint pickBuffer[])
{
    GLint i;
    GLuint name, *ptr;
    printf("选中的数目为%d个\n", nPicks);
    ptr = pickBuffer;
    for (i = 0; i < nPicks; i++)
    {
        name = *ptr;
        //选中图元在堆栈中的位置
        ptr += 3;
        // 跳过名字和深度信息
        ptr += name - 1;
        //根据位置信息获得选中的图元名字
        if (*ptr == 1)
            printf("你选择了红色图元\n");
        if (*ptr == 2)
            printf("你选择了绿色图元\n");
        if (*ptr == 3)
            printf("你选择了蓝色图元\n");
        ptr++;
    }
    printf("\n\n");
}
void ChangeSize(int w, int h)
{
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h); //指定视区,即指定窗口中用于图形显示的区域
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    DrawRect(GL_RENDER); //用渲染模式绘制图形
    glFlush();
}
void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    GLuint pickBuffer[pickSize];
    GLint nPicks, vp[4];
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
    {
        glSelectBuffer(pickSize, pickBuffer);
        //设置选择缓冲区
        glRenderMode(GL_SELECT);
        //激活选择模式.
        glInitNames();
        //初始化名字堆栈
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        //将当前的投影矩阵复制一个并压入堆
        glLoadIdentity();
        glGetIntegerv(GL_VIEWPORT, vp); //获得当前窗口显示区域的参数
        //定义一个10x10的选择区域
        gluPickMatrix(GLdouble(xMouse), GLdouble(vp[3] - yMouse), 10.0, 10.0, vp);
        gluOrtho2D(0.0, winWidth, 0.0, winHeight);
        DrawRect(GL_SELECT);
        //用选择模式绘制图形
        //恢复投影变换
        glMatrixMode(GL_PROJECTION);
        glPopMatrix(); //将投影矩阵堆栈中的栈顶元素删除
        glFlush();
        //获得选择集并输出
        nPicks = glRenderMode(GL_RENDER);
        ProcessPicks(nPicks, pickBuffer); //输出选择结果
        glutPostRedisplay();
        }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("pick");
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize);
    glutMouseFunc(MousePlot);
    Initial();
    glutMainLoop();
    return 0;
}