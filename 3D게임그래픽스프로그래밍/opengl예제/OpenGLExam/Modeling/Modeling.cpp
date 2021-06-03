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
	glutAddMenuEntry("��ȯ ����",0);
	glutAddMenuEntry("�̵�",1);
	glutAddMenuEntry("������ ��ġ�� ��Ÿ���� �̵�",2);
	glutAddMenuEntry("���� ��ķ� ����",3);
	glutAddMenuEntry("���ÿ� ���� �� ����",4);
	glutAddMenuEntry("Ȯ��",5);
	glutAddMenuEntry("������",6);
	glutAddMenuEntry("x�� ���� ȸ��",7);
	glutAddMenuEntry("y�� ���� ȸ��",8);
	glutAddMenuEntry("z�� ���� ȸ��",9);
	glutAddMenuEntry("Ȯ�� �� �̵�",10);
	glutAddMenuEntry("�̵� �� Ȯ��",11);
	glutAddMenuEntry("���� ���� ȸ��",12);
	glutAddMenuEntry("���ڸ� ȸ��",13);
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
	// ��ȯ ����
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glFlush();
	break;
case 1:
	// �̵�
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);

	glFlush();
	break;
case 2:
	// ������ ��ġ�� ��Ÿ���� �̵�
	glClear(GL_COLOR_BUFFER_BIT);

	glutWireTeapot(0.2);

	glTranslatef(0.6, 0.0, 0.0);
	glutWireTeapot(0.2);

	glTranslatef(0.0, 0.6, 0.0);
	glutWireTeapot(0.2);

	glFlush();
	break;
case 3:
	// ���� ��ķ� ����
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
	// ���ÿ� ���� �� ����
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
	// Ȯ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(2.0, 3.0, 1.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 6:
	// ������
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(-2.0, 3.0, 1.0);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	break;
case 7:
	// x�� ���� ȸ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 1.0, 0.0, 0.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 8:
	// y�� ���� ȸ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 0.0, 1.0, 0.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 9:
	// z�� ���� ȸ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 0.0, 0.0, 1.0);

	glutWireTeapot(0.4);

	glPopMatrix();
	glFlush();
	break;
case 10:
	// Ȯ�� �� �̵�
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
	// �̵� �� Ȯ��
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
	// ���� ���� ȸ��
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
	// ���ڸ� ȸ��
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



