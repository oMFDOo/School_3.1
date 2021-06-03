#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoReshape(GLsizei width, GLsizei height);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(DoReshape);
	glutMainLoop();
	return 0;
}

void DoReshape(GLsizei width, GLsizei height)
{
	/* 뷰포트 변환으로 종횡비 유지
	if (width > height) {
		glViewport((width - height)/2, 0, height, height);
	} else {
		glViewport(0, (height - width)/2, width, width);
	}
	//*/

	//* 직교 투영 영역을 조정하여 종횡비 유지
	glViewport(0,0,width,height);

	if (height == 0) return;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	if (width > height) {
		glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, 1.0, -1.0);
	} else {
		glOrtho(-1.0, 1.0, -1.0/aspect, 1.0/aspect, 1.0, -1.0);
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//*/
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glRectf(-1.0, 1.0, 1.0, -1.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
