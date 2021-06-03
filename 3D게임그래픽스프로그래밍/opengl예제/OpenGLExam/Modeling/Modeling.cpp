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
	glutAddMenuEntry("변환 없음",0);
	glutAddMenuEntry("이동",1);
	glutAddMenuEntry("엉뚱한 위치에 나타나는 이동",2);
	glutAddMenuEntry("단위 행렬로 리셋",3);
	glutAddMenuEntry("스택에 저장 및 복구",4);
	glutAddMenuEntry("확대",5);
	glutAddMenuEntry("뒤집기",6);
	glutAddMenuEntry("x축 기준 회전",7);
	glutAddMenuEntry("y축 기준 회전",8);
	glutAddMenuEntry("z축 기준 회전",9);
	glutAddMenuEntry("확대 후 이동",10);
	glutAddMenuEntry("이동 후 확대",11);
	glutAddMenuEntry("원점 기준 회전",12);
	glutAddMenuEntry("제자리 회전",13);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	if (value < 100) {
		Action = value;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glColor3f(1,1,1);
		glutPostRedisplay();
		return;
	}
}

void DoDisplay()
{
switch(Action) {
case 0:
	// 변환 없음
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glFlush();
	break;
case 1:
	// 이동
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);

	glFlush();
	break;
case 2:
	// 엉뚱한 위치에 나타나는 이동
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);

	glTranslatef(0.0, 0.6, 0.0);
	glutWireTeapot(0.2);

	glFlush();
	break;
case 3:
	// 단위 행렬로 리셋
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutWireTeapot(0.2);

	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);

	glLoadIdentity();
	glTranslatef(0.0, 0.6, 0.0);
	glutWireTeapot(0.2);

	glFlush();
	break;
case 4:
	// 스택에 저장 및 복구
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glutWireTeapot(0.2);

	glPushMatrix();
	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);
	glPopMatrix();

	glTranslatef(0.0, 0.6, 0.0);
	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 5:
	// 확대
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(2.0, 3.0, 1.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 6:
	// 뒤집기
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(-2.0, 3.0, 1.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 7:
	// x축 기준 회전
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 8:
	// y축 기준 회전
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 0.0, 1.0, 0.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 9:
	// z축 기준 회전
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 10:
	// 확대 후 이동
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(0.5, 0.5, 0.0);
	glScalef(1.5, 1.5, 1.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 11:
	// 이동 후 확대
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(1.5, 1.5, 1.0);
	glTranslatef(0.5, 0.5, 0.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 12:
	// 원점 기준 회전
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.8, 0.2);
	glEnd();

	glRotatef(45.0, 0.0, 0.0, 1.0);

	glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.8, 0.2);
	glEnd();

	glPopMatrix();
	glFlush();
	break;
case 13:
	// 제자리 회전
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.8, 0.2);
	glEnd();

	glTranslatef(0.5, 0.5, 0.0);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, -0.5, 0.0);

	glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.2, 0.2);
	glVertex2f(0.8, 0.2);
	glEnd();

	glPopMatrix();
	glFlush();
	break;
}
}



