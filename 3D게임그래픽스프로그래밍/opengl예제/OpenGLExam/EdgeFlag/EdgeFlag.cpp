#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoMenu(int value);
GLboolean bEdge = GL_FALSE;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Edeg ON",1);
	glutAddMenuEntry("Edeg OFF",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		bEdge = GL_TRUE;
		break;
	case 2:
		bEdge = GL_FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEdgeFlag(TRUE);

	glBegin(GL_TRIANGLES);
	if (bEdge) glEdgeFlag(TRUE);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.5, 0.5);
	if (bEdge) glEdgeFlag(FALSE);
	glVertex2f(-0.5, -0.5);

	glVertex2f(0.0, 0.0);
	if (bEdge) glEdgeFlag(TRUE);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);

	if (bEdge) glEdgeFlag(FALSE);
	glVertex2f(0.0, 0.0);
	if (bEdge) glEdgeFlag(TRUE);
	glVertex2f(-0.5, -0.5);
	if (bEdge) glEdgeFlag(FALSE);
	glVertex2f(0.5, -0.5);

	glEnd();
	glFlush();
}
