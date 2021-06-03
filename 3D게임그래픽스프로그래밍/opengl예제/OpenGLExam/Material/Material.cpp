#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);
GLfloat xAngle, yAngle, zAngle;
GLfloat red=0.5, green=0.5, blue=0.5;
GLboolean bColorTrack = GL_FALSE;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Color Tracking ON",1);
	glutAddMenuEntry("Color Tracking OFF",2);
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

	case 'u':red += 0.1;break;
	case 'j':red -= 0.1;break;
	case 'i':green += 0.1;break;
	case 'k':green -= 0.1;break;
	case 'o':blue += 0.1;break;
	case 'l':blue -= 0.1;break;
	case 'm':red=0.5, green=0.5, blue=0.5;break;
	}
	char info[128];
	sprintf(info, "(%.0f,%.0f,%.0f)"
		"(%.1f,%.1f,%.1f)", 
		xAngle, yAngle, zAngle,
		red, green, blue);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		bColorTrack = GL_TRUE;
		break;
	case 2:
		bColorTrack = GL_FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	// 주변광 설정
	glEnable(GL_LIGHTING);
	GLfloat arLight[]={red, green, blue, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);

	if (bColorTrack) {
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT,GL_AMBIENT);
	} else {
		glDisable(GL_COLOR_MATERIAL);
	}

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	// 아랫면 흰 바닥
	GLfloat arbottom[]={1.0, 1.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, arbottom);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	// 위쪽 빨간 변
	GLfloat arMat1[]={1.0, 0.0, 0.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, arMat1);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
	glVertex3f(0.0, 0.0, -0.8);
	glColor3f(1,0,0);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);

	// 왼쪽 노란 변
	GLfloat arMat2[]={0.0, 0.0, 0.5, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, arMat2);
	glColor3f(1,1,0);
	glVertex2f(-0.5, -0.5);

	// 아래쪽 초록 변
	GLfloat arMat3[]={0.0, 0.25, 0.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, arMat3);
	glColor3f(0,1,0);
	glVertex2f(0.5, -0.5);

	// 오른쪽 파란 변
	GLfloat arMat4[]={0.0, 0.0, 1.0, 1.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, arMat4);
	glColor3f(0,0,1);
	glVertex2f(0.5, 0.5);
	glEnd();

	glPopMatrix();
	glFlush();
}
