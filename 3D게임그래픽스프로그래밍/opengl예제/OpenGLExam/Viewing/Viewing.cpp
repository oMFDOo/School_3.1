#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
GLfloat xAngle, yAngle, zAngle;
GLfloat ex, ey, ez;

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

	case 'j':ex += 0.1;break;
	case 'l':ex -= 0.1;break;
	case 'i':ey -= 0.1;break;
	case 'k':ey += 0.1;break;
	case 'u':ez += 0.1;break;
	case 'o':ez -= 0.1;break;
	case 'm':ex = ey = ez = 0.0;break;
	}
	char info[128];
	sprintf(info, "ex=%.1f, ey=%.1f, ez=%.1f", ex, ey, ez);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DrawPyramid()
{
	// 아랫면 흰 바닥
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	// 위쪽 빨간 변
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
	glVertex3f(0.0, 0.0, -0.8);
	glColor3f(1,0,0);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);

	// 왼쪽 노란 변
	glColor3f(1,1,0);
	glVertex2f(-0.5, -0.5);

	// 아래쪽 초록 변
	glColor3f(0,1,0);
	glVertex2f(0.5, -0.5);

	// 오른쪽 파란 변
	glColor3f(0,0,1);
	glVertex2f(0.5, 0.5);
	glEnd();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	gluLookAt(
		ex, ey, ez,
		0.0, 0.0, -1.0, 
		0.0, 1.0, 0.0
		);

	DrawPyramid();

	glFlush();
}
