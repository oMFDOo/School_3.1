#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoMenu(int value);
int Action;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("점 찍기",0);
	glutAddMenuEntry("10픽셀로 점 확대",1);
	glutAddMenuEntry("선그리기",2);
	glutAddMenuEntry("선 연결하기",3);
	glutAddMenuEntry("여러 개의 선 긋기",4);
	glutAddMenuEntry("선 굵기 변경",5);
	glutAddMenuEntry("선 모양 변경",6);
	glutAddMenuEntry("삼각형",7);
	glutAddMenuEntry("삼각형 이어 그리기",8);
	glutAddMenuEntry("삼각형 팬",9);
	glutAddMenuEntry("사각형",10);
	glutAddMenuEntry("마름모",11);
	glutAddMenuEntry("다각형",12);
	glutAddMenuEntry("분할한 다각형",13);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	if (value < 100) {
		Action = value;
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glPointSize(1.0);
		glLineWidth(1);
		glDisable(GL_LINE_STIPPLE);
		glutPostRedisplay();
		return;
	}
}

void DoDisplay()
{
switch(Action) {
case 0:
	// 점 찍기
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 1:
	// 10픽셀로 점 확대
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 2:
	// 선그리기
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 3:
	// 선 연결하기
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 4:
	{
	// 여러 개의 선 긋기
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINES);
	GLfloat x = -0.8;
	GLfloat y = 0.4;
	for (int i = 0; i < 6; i++) {
		glVertex2f(x, y);
		x += 0.3;
		y *= -1;
	}
	glEnd();
	glFlush();
	}
	break;
case 5:
	{
	// 선 굵기 변경
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat y;
	GLfloat w = 1;
	for (y = 0.8; y > -0.8;y -= 0.2) {
		glLineWidth(w++);
		glBegin(GL_LINES);
		glVertex2f(-0.8, y);
		glVertex2f(0.8, y);
		glEnd();
	}
	glFlush();
	}
	break;
case 6:
	{
	// 선 모양 변경
	GLushort arPat[]={0xaaaa,0xaaaa,0xaaaa,0xaaaa,0x33ff,0x33ff,0x33ff,0x57ff,0x57ff };
	GLint arFac[] = { 1,     2,     3,     4,     1,     2,     3,     1,     2};

	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_STIPPLE);
	GLfloat y;
	GLint idx = 0;
	for (y = 0.8; y > -0.8;y -= 0.2) {
		glLineStipple(arFac[idx], arPat[idx]);
		glBegin(GL_LINES);
		glVertex2f(-0.8, y);
		glVertex2f(0.8, y);
		glEnd();
		idx++;
	}
	glFlush();
	}
	break;
case 7:
	{
	// 삼각형
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	GLfloat x = -0.8;
	GLfloat y = 0.4;
	for (int i = 0; i < 6; i++) {
		glVertex2f(x, y);
		x += 0.3;
		y *= -1;
	}
	glEnd();
	glFlush();
	}
	break;
case 8:
	{
	// 삼각형 이어 그리기
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_STRIP);
	GLfloat x = -0.8;
	GLfloat y = 0.4;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			glColor3f(1.0, 0.0, 0.0);
		} else {
			glColor3f(0.0, 1.0, 0.0);
		}
		glVertex2f(x, y);
		x += 0.3;
		y *= -1;
	}
	glEnd();
	glFlush();
	}
	break;
case 9:
	// 삼각형 팬
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.35, 0.35);

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5, 0.0);
	
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.35, -0.35);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.0, -0.5);
	glEnd();
	glFlush();
	break;
case 10:
	// 사각형
	glClear(GL_COLOR_BUFFER_BIT);

	glRectf(-0.8, 0.8, 0.8, -0.8);
	glFlush();
	break;
case 11:
	// 마름모
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glVertex2f(0.5, 0.0);
	glEnd();
	glFlush();
	break;
case 12:
	// 다각형
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glEnd();
	glFlush();
	break;
case 13:
	// 분할한 다각형
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.0, 0.0);

	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.0, -0.5);
	glEnd();
	glFlush();
	break;
}
}

