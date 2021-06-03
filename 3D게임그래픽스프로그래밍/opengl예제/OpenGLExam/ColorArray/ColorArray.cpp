#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
GLfloat xAngle, yAngle, zAngle;

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
	}
	char info[128];
	sprintf(info, "x=%.1f, y=%.1f, z=%.1f", xAngle, yAngle, zAngle);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

/* ���� �迭�� ���� ����ϱ�
void DoDisplay()
{
	static GLfloat vert[] = {
		0, 0, -0.8,			// �߾�
		0.5, 0.5, 0,		// ���
		-0.5, 0.5, 0,		// �»�
		-0.5, -0.5, 0,		// ����
		0.5, -0.5, 0,		// ����
	};

	static GLfloat color[] = {
		1,1,1,				// �߾�
		0,0,1,				// ���
		1,0,0,				// �»�
		1,1,0,				// ����
		0,1,0,				// ����
	};

	static GLubyte index[] = {
		0, 1, 2,			//12��
		0, 2, 3,			// 9��
		0, 3, 4,			// 6��
		0, 4, 1,			// 3��
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	glColor3f(1,1,1);
	glRectf(-0.5, 0.5, 0.5, -0.5);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vert);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, color);

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);

	glPopMatrix();
	glFlush();
}
//*/

//* �� �迭 �ϳ��� ��ġ��
void DoDisplay()
{
	static GLfloat vertcolor[] = {
		1,1,1,	0, 0, -0.8, 		// �߾�
		0,0,1,	0.5, 0.5, 0, 	// ���
		1,0,0,	-0.5, 0.5, 0,	// �»�
		1,1,0,	-0.5, -0.5, 0,	// ����
		0,1,0,	0.5, -0.5, 0,	// ����
	};

	static GLubyte index[] = {
		0, 1, 2,			//12��
		0, 2, 3,			// 9��
		0, 3, 4,			// 6��
		0, 4, 1,			// 3��
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	glColor3f(1,1,1);
	glRectf(-0.5, 0.5, 0.5, -0.5);

	/* �� �迭 ��� ����ϱ�
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*6, &vertcolor[3]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, sizeof(GLfloat)*6, vertcolor);
	//*/

	//* ���͸��� �迭 ����ϱ�
	glInterleavedArrays(GL_C3F_V3F, 0, vertcolor);
	//*/
	
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);

	glPopMatrix();
	glFlush();
}
//*/

