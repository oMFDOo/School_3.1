#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoTimer(int value);

const GLfloat size = 0.2;
GLfloat x;
GLfloat dx = 0.02;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutTimerFunc(30, DoTimer, 1);
	glutMainLoop();
	return 0;
}

void DoTimer(int value)
{
	x += dx;
	if (x + size > 1 || x - size < -1) {
		dx *= -1;
	}
	glutPostRedisplay();
	glutTimerFunc(30, DoTimer, 1);
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glVertex2f(x, size);
	glVertex2f(x - size, -size);
	glVertex2f(x + size, -size);
	glEnd();
	glutSwapBuffers();
}
