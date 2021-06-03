#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);

GLfloat Alpha = 0.5f;
GLenum Src = GL_SRC_ALPHA;
GLenum Dest = GL_ONE_MINUS_SRC_ALPHA;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Opaque",1);
	glutAddMenuEntry("Traslucent",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'q':
		Alpha += 0.1;
		break;
	case 'a':
		Alpha -= 0.1;
		break;
	}
	glutPostRedisplay();
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		Src = GL_ONE;
		Dest = GL_ZERO;
		break;
	case 2:
		Src = GL_SRC_ALPHA;
		Dest = GL_ONE_MINUS_SRC_ALPHA;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(Src, Dest);

	glColor3f(0, 0, 1);
	glRectf(-0.5, 0.8, 0.5, 0.0);

	glColor4f(1, 0, 0, Alpha);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}