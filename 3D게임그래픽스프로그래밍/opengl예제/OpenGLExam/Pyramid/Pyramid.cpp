#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);

GLfloat xAngle, yAngle, zAngle;
GLboolean bDepthTest = GL_TRUE;
GLboolean bCullFace = GL_FALSE;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Depth Test ON",1);
	glutAddMenuEntry("Depth Test OFF",2);
	glutAddMenuEntry("Cull Face ON",3);
	glutAddMenuEntry("Cull Face OFF",4);
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
		bDepthTest = GL_TRUE;
		break;
	case 2:
		bDepthTest = GL_FALSE;
		break;
	case 3:
		bCullFace = GL_TRUE;
		break;
	case 4:
		bCullFace = GL_FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);

	if (bDepthTest) {
		glEnable(GL_DEPTH_TEST);
	} else {
		glDisable(GL_DEPTH_TEST);
	}

	if (bCullFace) {
		glEnable(GL_CULL_FACE);
	} else {
		glDisable(GL_CULL_FACE);
	}

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	// �Ʒ��� �� �ٴ�
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	// ���� ���� ��
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
	glVertex3f(0.0, 0.0, -0.8);
	glColor3f(1,0,0);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);

	// ���� ��� ��
	glColor3f(1,1,0);
	glVertex2f(-0.5, -0.5);

	// �Ʒ��� �ʷ� ��
	glColor3f(0,1,0);
	glVertex2f(0.5, -0.5);

	// ������ �Ķ� ��
	glColor3f(0,0,1);
	glVertex2f(0.5, 0.5);
	glEnd();

	glPopMatrix();
	glFlush();
}
