#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);
GLfloat lx, ly, lz = -1.0;
GLfloat xAngle, yAngle, zAngle;
GLboolean bAmbient;
GLboolean bAttach;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Ambient ON",1);
	glutAddMenuEntry("Ambient OFF",2);
	glutAddMenuEntry("Attach light",3);
	glutAddMenuEntry("Unattach light",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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

	case 'j':lx -= 0.1;break;
	case 'l':lx += 0.1;break;
	case 'i':ly += 0.1;break;
	case 'k':ly -= 0.1;break;
	case 'u':lz += 0.1;break;
	case 'o':lz -= 0.1;break;
	case 'm':lx = 0, ly = 0, lz = -1.0;break;
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
		bAmbient = GL_TRUE;
		break;
	case 2:
		bAmbient = GL_FALSE;
		break;
	case 3:
		bAttach = GL_TRUE;
		break;
	case 4:
		bAttach = GL_FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();

	if (bAttach) {
		glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
		glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
		glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
	}

	// 0번 광원 배치.
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat lightpos[] = {lx, ly, lz, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// 주변광을 초록색으로 설정
	if (bAmbient) {
		GLfloat ambient[4]={0,1,0,1};
		glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	} else {
		GLfloat ambient[4]={0,0,0,1};
		glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	}

	if (bAttach == false) {
		glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
		glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
		glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
	}

	glutSolidTeapot(0.5);

	glPopMatrix();
	glFlush();
}
