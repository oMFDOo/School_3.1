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

/* 색상 배열도 같이 사용하기
void DoDisplay()
{
	static GLfloat vert[] = {
		0, 0, -0.8,			// 중앙
		0.5, 0.5, 0,		// 우상
		-0.5, 0.5, 0,		// 좌상
		-0.5, -0.5, 0,		// 좌하
		0.5, -0.5, 0,		// 우하
	};

	static GLfloat color[] = {
		1,1,1,				// 중앙
		0,0,1,				// 우상
		1,0,0,				// 좌상
		1,1,0,				// 좌하
		0,1,0,				// 우하
	};

	static GLubyte index[] = {
		0, 1, 2,			//12시
		0, 2, 3,			// 9시
		0, 3, 4,			// 6시
		0, 4, 1,			// 3시
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

//* 두 배열 하나로 합치기
void DoDisplay()
{
	static GLfloat vertcolor[] = {
		1,1,1,	0, 0, -0.8, 		// 중앙
		0,0,1,	0.5, 0.5, 0, 	// 우상
		1,0,0,	-0.5, 0.5, 0,	// 좌상
		1,1,0,	-0.5, -0.5, 0,	// 좌하
		0,1,0,	0.5, -0.5, 0,	// 우하
	};

	static GLubyte index[] = {
		0, 1, 2,			//12시
		0, 2, 3,			// 9시
		0, 3, 4,			// 6시
		0, 4, 1,			// 3시
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

	/* 두 배열 섞어서 사용하기
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(GLfloat)*6, &vertcolor[3]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, sizeof(GLfloat)*6, vertcolor);
	//*/

	//* 인터리브 배열 사용하기
	glInterleavedArrays(GL_C3F_V3F, 0, vertcolor);
	//*/
	
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);

	glPopMatrix();
	glFlush();
}
//*/

