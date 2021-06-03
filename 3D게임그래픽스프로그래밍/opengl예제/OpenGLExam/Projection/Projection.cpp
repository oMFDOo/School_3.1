#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoReshape(GLsizei width, GLsizei height);
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);
GLfloat xAngle, yAngle, zAngle;
GLfloat left=-1, right=1, bottom=-1, top=1, Near=-1, Far=1;
GLfloat fov = 45;
int Projection;
int Object;
GLsizei lastWidth, lastHeight;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutReshapeFunc(DoReshape);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Orthographic",1);
	glutAddMenuEntry("Frustrum",2);
	glutAddMenuEntry("Perspective",3);
	glutAddMenuEntry("Pyramid",4);
	glutAddMenuEntry("Cylinder",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glEnable(GL_DEPTH_TEST);
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

	case 'r':left += 0.1;break;
	case 'f':left -= 0.1;break;
	case 't':right += 0.1;break;
	case 'g':right -= 0.1;break;
	case 'y':bottom -= 0.1;break;
	case 'h':bottom += 0.1;break;
	case 'u':top -= 0.1;break;
	case 'j':top += 0.1;break;
	case 'i':Near -= 0.1;break;
	case 'k':Near += 0.1;break;
	case 'o':Far -= 0.1;break;
	case 'l':Far += 0.1;break;
	case 'p':fov -= 1;break;
	case ';':fov += 1;break;
	case 'v':left=-1, right=1, bottom=-1, top=1;
		if (Projection == 0) {
			Near=-1, Far=1;
		} else {
			Near=1, Far=10;
		}
		break;
	}
	char info[128];
	sprintf(info, "(%.0f,%.0f,%.0f)"
		"(%.1f,%.1f,%.1f,%.1f,%.1f,%.1f)", 
		xAngle, yAngle, zAngle,
		left, right, bottom, top, Near, Far);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		Projection = 0;
		Near = -1;
		Far = 1;
		break;
	case 2:
		Projection = 1;
		Near = 1;
		Far = 10;
		break;
	case 3:
		Projection = 2;
		Near = 1;
		Far = 10;
		break;
	case 4:
		Object = 0;
		break;
	case 5:
		Object = 1;
		break;
	}
	glutPostRedisplay();
}

void DoReshape(GLsizei width, GLsizei height)
{
	glViewport(0,0,width,height);

	lastWidth = width;
	lastHeight = height;
}

void DrawPyramid()
{
	// 아랫면 흰 바닥
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	// 위쪽 빨간 변
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,1,1);
	glVertex3f(0.0, 0.0, 0.8);
	glColor3f(1,0,0);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);

	// 왼쪽 노란 변
	glColor3f(1,1,0);
	glVertex2f(-0.5, -0.5);

	// 아래쪽 초록 변
	glColor3f(0,1,0);
	glVertex2f(0.5, -0.5);

	// 오른쪽 파란 변
	glColor3f(0,0,1);
	glVertex2f(0.5, 0.5);
	glEnd();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch (Projection) {
	case 0:
		glOrtho(left, right, bottom, top, Near, Far);
		break;
	case 1:
		glFrustum(left, right, bottom, top,Near,Far);
		break;
	case 2:
		GLfloat aspect = (GLfloat)lastWidth / (GLfloat)lastHeight;
		gluPerspective(fov, aspect, Near, Far);
		break;
	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// 원근투영일 때는 약간 더 뒤쪽에서 보아야 한다.
	if (Projection != 0) {
		glTranslatef(0,0,-2);
	}
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	if (Object == 0) {
		DrawPyramid();
	} else {
		GLUquadricObj *pQuad;
		pQuad = gluNewQuadric();
		gluQuadricDrawStyle(pQuad, GLU_LINE);
		glTranslatef(0.0, 0.0, -0.6);
		glColor3f(1,1,1);
		gluCylinder(pQuad, 0.3, 0.3, 1.2, 20, 20);
	}

	glPopMatrix();
	glFlush();
}
