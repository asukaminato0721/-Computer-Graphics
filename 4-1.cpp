//g++ -o 4-1 -Wall 4-1.cpp -mwindows glut32.lib -lopengl32 -lglu32
#include <windows.h>
#include <gl/glut.h>

static GLsizei iMode = 1;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

GLUquadricObj *obj;

void Initial(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_LINE);
}

void ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5f, 1.5f, -1.5f, 1.5f);
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    switch (iMode)
    {
    case 1:
        glutWireTetrahedron();
        break;
    case 2:
        glutSolidTetrahedron();
        break;
    case 3:
        glutWireOctahedron();
        break;
    case 4:
        glutSolidOctahedron();
        break;
    case 5:
        glutWireSphere(1.0f, 15, 15);
        break;
    case 6:
        glutSolidSphere(1.0f, 15, 15);
        break;
    case 7:
        glutWireTeapot(1.0f);
        break;
    case 8:
        glutSolidTeapot(1.0f);
        break;
    case 9:
        gluSphere(obj, 1.0f, 15, 15);
        break;
    case 10:
        gluCylinder(obj, 1.0f, 0.0f, 1.0f, 15, 15);
        break;
    case 11:
        gluPartialDisk(obj, 0.3f, 0.8f, 15, 15, 30.0f, 260.0f);
        break;
    default:
        break;
    }
    glFlush();
}

void ProcessMenu(int value)
{
    iMode = value;
    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
        xRot -= 5.0f;
    if (key == GLUT_KEY_DOWN)
        xRot += 5.0f;
    if (key == GLUT_KEY_LEFT)
        yRot -= 5.0f;
    if (key == GLUT_KEY_RIGHT)
        yRot += 5.0f;
    if (xRot > 356.0f)
        xRot = 0.0f;
    if (xRot < -1.0f)
        xRot = 355.0f;
    if (yRot > 356.0f)
        yRot = 0.0f;
    if (yRot < -1.0f)
        yRot = 355.0f;
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("opengl draw example");

    int nGlutPolyMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("4", 1);
    glutAddMenuEntry("4", 2);
    glutAddMenuEntry("8", 3);
    glutAddMenuEntry("8", 4);

    int nGlutCurveMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("qiu", 5);
    glutAddMenuEntry("qiu", 6);
    glutAddMenuEntry("tea", 7);
    glutAddMenuEntry("tea", 8);

    int nGluCurveMenu = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("qiu", 9);
    glutAddMenuEntry("qiu", 10);
    glutAddMenuEntry("tea", 11);

    int nMainMenu = glutCreateMenu(ProcessMenu); //这行不知道有啥用
    //   glutAddSubMenu("all", nMainMenu);
    glutAddSubMenu("g", nGlutPolyMenu);
    glutAddSubMenu("qu", nGlutCurveMenu);
    glutAddSubMenu("qu", nGluCurveMenu);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    Initial();
    glutMainLoop();
    return 0;
}