#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define GL_POINT_SMOOTH

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void asu()
{
    glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}


void init(void){
  glClearColor(0, 0, 0, 0);
   glMatrixMode(GL_PROJECTION);
   glEnable(GL_DEPTH_TEST);
   is_depth=1;
   glMatrixMode(GL_MODELVIEW);
   glPointSize(5.0);
   glLineWidth(2.0f);
   }
const double PI = 3.141592653589793;
 int i;

void lingkaran(int jari2, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_LINE_STRIP);
 for (i=0;i<=360;i++){
 float sudut=i*(2*PI/jumlah_titik);
 float x=x_tengah+jari2*cos(sudut);
 float y=y_tengah+jari2*sin(sudut);
 glVertex3f(x,0.2,y);
 }
 glEnd();
 }

void renderScene(void) {
 glColor3ub(255,255,255);
 lingkaran(7,100,0,0);
 glFlush();
 }

void lapangan(void)
{
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex3f(-100,-0.3,70);
    glVertex3f(100,-0.3,70);
    glVertex3f(100,-0.3,-70);
    glVertex3f(-100,-0.3,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex3f(-55,0,40);
    glVertex3f(55,0,40);
    glVertex3f(55,0,-40);
    glVertex3f(-55,0,-40);
    glEnd();
    //ijobanget
    glBegin(GL_POLYGON);
    glColor3ub(0,153,0);
    glVertex3f(-37.5,0.1,40);
    glVertex3f(-25,0.1,40);
    glVertex3f(-25,0.1,-40);
    glVertex3f(-37.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-12.5,0.1,40);
    glVertex3f(-0,0.1,40);
    glVertex3f(-0,0.1,-40);
    glVertex3f(-12.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(12.5,0.1,40);
    glVertex3f(25,0.1,40);
    glVertex3f(25,0.1,-40);
    glVertex3f(12.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(37.5,0.1,40);
    glVertex3f(50,0.1,40);
    glVertex3f(50,0.1,-40);
    glVertex3f(37.5,0.1,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-50.5,0.1,40);
    glVertex3f(-55,0.1,40);
    glVertex3f(-55,0.1,-40);
    glVertex3f(-50,0.1,-40);
    glEnd();
}

void gawang (void)
{   //kanan
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(47,0.1,4);
    glVertex3f(47,4,4);
    glVertex3f(47,4,-4);
    glVertex3f(47,0.1,-4);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(47,4,4);
    glVertex3f(50,0,4);
    glVertex3f(47,4,-4);
    glVertex3f(50,0,-4);
    glEnd();
    //kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(-47,0.1,4);
    glVertex3f(-47,4,4);
    glVertex3f(-47,4,-4);
    glVertex3f(-47,0.1,-4);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-47,4,4);
    glVertex3f(-50,0,4);
    glVertex3f(-47,4,-4);
    glVertex3f(-50,0,-4);
    glEnd();
}

void garis_lapangan(void)
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(255,255,255);
    glVertex3f(-47,0.2,32);
    glVertex3f(47,0.2,32);
    glVertex3f(47,0.2,-32);
    glVertex3f(-47,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0,0.2,32);
    glVertex3f(0,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-47,0.2,-30);
    glVertex3f(-45,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(47,0.2,-30);
    glVertex3f(45,0.2,-32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-47,0.2,30);
    glVertex3f(-45,0.2,32);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(47,0.2,30);
    glVertex3f(45,0.2,32);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(-47, 0.2,-15);
    glVertex3f(-35, 0.2,-15);
    glVertex3f(-35, 0.2,15);
    glVertex3f(-47, 0.2,15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(47, 0.2,-15);
    glVertex3f(35, 0.2,-15);
    glVertex3f(35, 0.2,15);
    glVertex3f(47, 0.2,15);
    glEnd();
}

void tribun_depan(void)
{
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex3f(-55,0,40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(-55,5,40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,0,-40);
    glVertex3f(55,0,-40);
    glVertex3f(55,5,-40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,0,-40);
    glVertex3f(-55,0,40);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,0,-40);
    glVertex3f(55,0,40);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glEnd();
    //tribun kanan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(-55,5,-40);
    glVertex3f(-70,15,-40);
    glVertex3f(-70,15,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(55,5,40);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(70,15,40);
    glEnd();

    //antar tribun miring
    glBegin(GL_POLYGON);
    glColor3ub(120,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(-70,15,40);
    glVertex3f(-55,15,55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,5,-40);
    glVertex3f(70,15,-40);
    glVertex3f(55,15,-55);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(70,15,40);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-55,5,-40);
    glVertex3f(-55,15,-55);
    glVertex3f(-70,15,-40);
    glEnd();
    //tribun depan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,40);
    glVertex3f(55,5,40);
    glVertex3f(55,15,55);
    glVertex3f(-55,15,55);
    glEnd();
    //tribun belakang
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,5,-40);
    glVertex3f(55,5,-40);
    glVertex3f(55,15,-55);
    glVertex3f(-55,15,-55);
    glEnd();

    //tingkat
    //depan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,20,50);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glVertex3f(-55,40,70);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-55,20,-50);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glVertex3f(-55,40,-70);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-65,20,40);
    glVertex3f(-65,20,-40);
    glVertex3f(-80,40,-40);
    glVertex3f(-80,40,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(65,20,40);
    glVertex3f(65,20,-40);
    glVertex3f(80,40,-40);
    glVertex3f(80,40,40);
    glEnd();

    //antar tribun tingkat
    glBegin(GL_POLYGON);
    glColor3ub(120,0,0);
    glVertex3f(-80,40,-40);
    glVertex3f(-65,20,-40);
    glVertex3f(-55,20,-50);
    glVertex3f(-55,40,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(80,40,-40);
    glVertex3f(65,20,-40);
    glVertex3f(55,20,-50);
    glVertex3f(55,40,-70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(80,40,40);
    glVertex3f(65,20,40);
    glVertex3f(55,20,50);
    glVertex3f(55,40,70);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-80,40,40);
    glVertex3f(-65,20,40);
    glVertex3f(-55,20,50);
    glVertex3f(-55,40,70);
    glEnd();

    //tribun pemain
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(35,3,38);
    glVertex3f(15,3,38);
    glVertex3f(15,3,34);
    glVertex3f(35,3,34);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(35,3,34);
    glVertex3f(35,3,38);
    glVertex3f(35,0,38);
    glVertex3f(35,0,34);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(15,3,34);
    glVertex3f(15,3,38);
    glVertex3f(15,0,38);
    glVertex3f(15,0,34);
    glEnd();

    //tribun pemain 2
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-35,3,38);
    glVertex3f(-15,3,38);
    glVertex3f(-15,3,34);
    glVertex3f(-35,3,34);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(204,0,0);
    glVertex3f(-35,3,34);
    glVertex3f(-35,3,38);
    glVertex3f(-35,0,38);
    glVertex3f(-35,0,34);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-15,3,34);
    glVertex3f(-15,3,38);
    glVertex3f(-15,0,38);
    glVertex3f(-15,0,34);
    glEnd();

}

    void display(void)
   {
       if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
    lapangan();
    gawang();
    renderScene();
    garis_lapangan();
    tribun_depan();
    glPopMatrix();
    glutSwapBuffers();
   }

    void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;


}

void mouseMotion(int x, int y)
{
    asu();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }

}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi =1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslated(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);

}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'd':
        case 'D':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'a':
        case 'A':
            glTranslated(-3,0,0);
            break;
        case '7':
            glTranslated(0,3,0);
            break;
        case '9':
            glTranslated(0,-3,0);
            break;
        case '2':
            glRotated(2,1,0,0);
            break;
        case '8':
            glRotated(-2,1,0,0);
            break;
        case '6':
            glRotated(2,0,1,0);
            break;
        case '4':
            glRotated(-2,1,0,0);
            break;
        case '1':
            glRotated(2,0,0,1);
            break;
        case '3':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                glEnable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glDisable(GL_DEPTH_TEST);
            }
    }
    display();


}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("PENYU - 672018114_672018132");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();

    return 0;
}
