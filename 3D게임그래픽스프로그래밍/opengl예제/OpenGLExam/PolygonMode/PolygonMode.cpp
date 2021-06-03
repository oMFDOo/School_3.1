#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);

GLfloat xAngle, yAngle, zAngle;
GLenum PolygonMode = GL_FILL;
GLenum ShadeMode = GL_FLAT;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Polygon POINT",1);
	glutAddMenuEntry("Polygon LINE",2);
	glutAddMenuEntry("Polygon FILL",3);
	glutAddMenuEntry("Smooth Shade",4);
	glutAddMenuEntry("Flat Shade",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		PolygonMode = GL_POINT;
		break;
	case 2:
		PolygonMode = GL_LINE;
		break;
	case 3:
		PolygonMode = GL_FILL;
		break;
	case 4:
		ShadeMode = GL_SMOOTH;
		break;
	case 5:
		ShadeMode = GL_FLAT;
		break;
	}
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

	glPolygonMode(GL_FRONT_AND_BACK, PolygonMode);
	glShadeModel(ShadeMode);

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	DrawPyramid();

	glPopMatrix();
	glFlush();
}
