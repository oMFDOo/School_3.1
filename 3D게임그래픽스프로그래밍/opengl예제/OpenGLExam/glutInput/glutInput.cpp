#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoSpecial(int key, int x, int y);
void DoMouse(int button, int state, int x, int y);

const GLfloat size = 0.2;
const GLfloat step = 0.01;
GLfloat nx, ny;
GLboolean bGray = GL_FALSE;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutSpecialFunc(DoSpecial);
	glutMouseFunc(DoMouse);
	glutMainLoop();
	return 0;
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'r':
	case 'R':
		glClearColor(1.0, 0.0, 0.0, 1.0);
		break;
	case 'g':
	case 'G':
		glClearColor(0.0, 1.0, 0.0, 1.0);
		break;
	case 'b':
	case 'B':
		glClearColor(0.0, 0.0, 1.0, 1.0);
		break;
	}
	glutPostRedisplay();
}

void DoSpecial(int key, int x, int y)
{
	switch(key) {
	case GLUT_KEY_LEFT:
		nx -= step;
		break;
	case GLUT_KEY_RIGHT:
		nx += step;
		break;
	case GLUT_KEY_UP:
		ny += step;
		break;
	case GLUT_KEY_DOWN:
		ny -= step;
		break;
	}
	char info[128];
	sprintf(info, "x=%.2f, y=%.2f", nx, ny);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		bGray = !bGray;
		glutPostRedisplay();
	}
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (bGray) {
		glColor3f(0.5, 0.5, 0.5);
	} else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_POLYGON);
	glVertex2f(nx, ny + size);
	glVertex2f(nx - size, ny - size);
	glVertex2f(nx + size, ny - size);
	glEnd();
	glFlush();
}
