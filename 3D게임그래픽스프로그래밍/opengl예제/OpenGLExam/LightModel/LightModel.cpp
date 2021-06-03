#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
GLfloat xAngle, yAngle, zAngle;
GLfloat red=0.2, green=0.2, blue=0.2;

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

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	// 조명 모델 설정
	glEnable(GL_LIGHTING);
	GLfloat arLight[]={red, green, blue, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight);

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	glutSolidTeapot(0.5);

	glPopMatrix();
	glFlush();
}
