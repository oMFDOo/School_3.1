#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
GLfloat xAngle, yAngle, zAngle;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutMainLoop();
	return 0;
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':yAngle += 2;break;
	case 'd':yAngle -= 2;break;
	case 'w':xAngle += 2;break;
	case 's':xAngle -= 2;break;
	case 'q':zAngle += 2;break;
	case 'e':zAngle -= 2;break;
	case 'z':xAngle = yAngle = zAngle = 0.0;break;
	}
	char info[128];
	sprintf(info, "x=%.1f, y=%.1f, z=%.1f", xAngle, yAngle, zAngle);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	GLUquadricObj *pQuad;
	pQuad = gluNewQuadric();
	gluQuadricDrawStyle(pQuad, GLU_LINE);

	gluSphere(pQuad, 0.3, 20, 20);

	glPushMatrix();
	glTranslatef(-0.6, 0.6, 0.0);
	gluCylinder(pQuad, 0.2, 0.2, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, -0.6, 0.0);
	gluCylinder(pQuad, 0.2, 0.0, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.6, 0.0);
	gluDisk(pQuad, 0.1, 0.3, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.6, 0.0);
	gluDisk(pQuad, 0.0, 0.3, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(pQuad);
	glPopMatrix();
	glFlush();
}
