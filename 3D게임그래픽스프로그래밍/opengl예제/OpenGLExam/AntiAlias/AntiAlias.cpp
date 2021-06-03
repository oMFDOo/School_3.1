#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoMenu(int value);
BOOLEAN bAlias;
BOOLEAN bHint;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Alias ON",1);
	glutAddMenuEntry("Alias OFF",2);
	glutAddMenuEntry("Hint ON",3);
	glutAddMenuEntry("Hint OFF",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		bAlias = TRUE;
		break;
	case 2:
		bAlias = FALSE;
		break;
	case 3:
		bHint = TRUE;
		break;
	case 4:
		bHint = FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// 블랜딩이 켜져 있어야 알리아싱이 제대로 된다.
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// 안티 알리아싱 on, off
	if (bAlias) {
		glEnable(GL_POINT_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POLYGON_SMOOTH);
	} else {
		glDisable(GL_POINT_SMOOTH);
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_POLYGON_SMOOTH);
	}

	// 고품질 출력을 위한 힌트
	glHint(GL_POINT_SMOOTH_HINT, bHint ? GL_NICEST:GL_FASTEST);
	glHint(GL_LINE_SMOOTH_HINT, bHint ? GL_NICEST:GL_FASTEST);
	glHint(GL_POLYGON_SMOOTH_HINT, bHint ? GL_NICEST:GL_FASTEST);

	glPointSize(10.0);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.8);
	glEnd();

	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.8, 0.7);
	glVertex2f(0.8, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2f(0.0, 0.4);
	glColor3f(0,1,0);
	glVertex2f(-0.4, 0.0);
	glColor3f(0,0,1);
	glVertex2f(0.0, -0.4);
	glColor3f(1,1,0);
	glVertex2f(0.4, 0.0);
	glEnd();

	glFlush();
}

