#include <windows.h>
#include <gl/glut.h>
#include <math.h>

void DoDisplay();
void DoMenu(int value);
int Action;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("�̵�",0);
	glutAddMenuEntry("Ȯ��",1);
	glutAddMenuEntry("ȸ��",2);
	glutAddMenuEntry("Ȯ�� �� �̵�",3);
	glutAddMenuEntry("Ȯ�� �� �̵� �̸� ���",4);
	glutAddMenuEntry("����̱�",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	if (value < 100) {
		Action = value;
		glutPostRedisplay();
		return;
	}
}

void DoDisplay()
{
switch(Action) {
case 0:
	{
	// �̵�
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat trans[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0, 
		0, 0, 1, 0,
		0.5, 0.5, 0, 1
	};
	glMultMatrixf(trans);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	}
	break;
case 1:
	{
	// Ȯ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat scale[16] = {
		1.5, 0, 0, 0,
		0, 1.5, 0, 0, 
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	glMultMatrixf(scale);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	}
	break;
case 2:
	{
	// ȸ��
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat rotate[16] = {
		cos(45.0*3.14/180), sin(45.0*3.14/180), 0, 0,
		-sin(45.0*3.14/180), cos(45.0*3.14/180), 0, 0, 
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	glMultMatrixf(rotate);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	}
	break;
case 3:
	{
	// Ȯ�� �� �̵�
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat trans[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0, 
		0, 0, 1, 0,
		0.5, 0.5, 0, 1
	};
	glMultMatrixf(trans);

	GLfloat scale[16] = {
		1.5, 0, 0, 0,
		0, 1.5, 0, 0, 
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	glMultMatrixf(scale);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	}
	break;
case 4:
	{
	// Ȯ�� �� �̵� �̸� ���
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat transscale[16] = {
		1.5, 0, 0, 0,
		0, 1.5, 0, 0, 
		0, 0, 1, 0,
		0.5, 0.5, 0, 1
	};
	glMultMatrixf(transscale);

	glutWireTeapot(0.2);

	glPopMatrix();
	glFlush();
	}
	break;
case 5:
	{
	// ����̱�
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	GLfloat sheer[16] = {
		1, 0, 0, 0,
		0.5, 1, 0, 0, 
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	glMultMatrixf(sheer);

	glutWireTeapot(0.5);

	glPopMatrix();
	glFlush();
	}
	break;
}
}

