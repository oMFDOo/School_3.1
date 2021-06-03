#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoReshape(GLsizei width, GLsizei height);
void DoMenu(int value);
int Action = 1;
GLsizei lastWidth, lastHeight;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(DoReshape);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("전체 창 사용",1);
	glutAddMenuEntry("좌하단 사용",2);
	glutAddMenuEntry("우하단 사용",3);
	glutAddMenuEntry("절대 크기 사용",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	Action = value;
	DoReshape(lastWidth, lastHeight);
	glutPostRedisplay();
}

void DoReshape(GLsizei width, GLsizei height)
{
	lastWidth = width;
	lastHeight = height;

	switch(Action) {
	case 1:
		// 전체 창 사용
		glViewport(0,0,width, height);
		break;
	case 2:
		// 좌하단 사용
		glViewport(0,0,width/2, height/2);
		break;
	case 3:
		// 우하단 사용
		glViewport(width/2,0,width/2, height/2);
		break;
	case 4:
		// 절대 크기 사용
		glViewport(30,30,200,200);
		break;
	}
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glRectf(-1.0, 1.0, 1.0, -1.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
