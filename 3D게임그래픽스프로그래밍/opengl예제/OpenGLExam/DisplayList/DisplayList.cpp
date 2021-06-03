#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
int dl;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");

	dl = glGenLists(1);
	glNewList(dl, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.2);
	glVertex2f(-0.2, -0.2);
	glVertex2f(0.2, -0.2);
	glEnd();
	glEndList();

	glutDisplayFunc(DoDisplay);
	glutMainLoop();
	return 0;
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0);
	glCallList(dl);
	
	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(0,1,0);
	glCallList(dl);

	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(0,0,1);
	glCallList(dl);

	glFlush();
}
