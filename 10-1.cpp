//g++ -o 10-1 -Wall 10-1.cpp -mwindows glut32.lib -lopengl32 -lglu32
//书上代码是 void main, 改为 int main
#include <windows.h>
#include <gl/glut.h>
void Initial(void)
{
    GLfloat mat_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat mat_shininess[] = {50.0f};
    GLfloat light0_diffuse[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat light0_position[] = {1.0f, 1.0f, 1.0f, 0.0f};
    GLfloat light1_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat light1_diffuse[] = {1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light1_specular[] = {1.0f, 0.6f, 0.6f, 1.0f};
    GLfloat light1_position[] = {-3.0f, -3.0f, 3.0f, 1.0f};
    GLfloat spot_direction[] = {1.0f, 1.0f, -1.0f};

    //定义材质属性
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);     //指定材质的环境反射光反射系数
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);     //指定材质的漫反射光反射系数
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   //指定材质的镜面反射光反射系数
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); //指定材质的镜面反射指数值
    //light0为漫反射的蓝色点光源
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);   //指定漫反射光成分
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position); //设置光源的位置
    //light1为红色聚光光源
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);        //指定环境光成分
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);        //指定漫反射光成分
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);      //指定镜面光成分
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);      //指定光源的位置
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);               //指定聚光截止角
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction); //指定聚光灯的方向
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //启用光源1/启用光源
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
    //启用光源
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
};
void Changesize(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.5f, 5.5f, -5.5f * h / w, 5.5f * h / w, -10.0f, 10.0f);
    else
        glOrtho(-5.5f * w / h, 5.5f * w / h, -5.5f, 5.5f, -10.0f, 10.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslated(-3.0f, -3.0f, 3.0f);
    glPopMatrix();
    glutSolidSphere(2.0f, 50, 50);
    glFlush();
}
int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("多光源球");
    glutDisplayFunc(Display);
    glutReshapeFunc(Changesize);
    Initial();
    glutMainLoop();
    return 0;
}
