#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);

GLfloat nx, ny;
BOOLEAN bScissor;
BOOLEAN bStencil;
BOOLEAN bEqual;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_STENCIL);
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Scissor ON",1);
	glutAddMenuEntry("Scissor OFF",2);
	glutAddMenuEntry("Stencil ON",3);
	glutAddMenuEntry("Stencil OFF",4);
	glutAddMenuEntry("Equal",5);
	glutAddMenuEntry("Not Equal",6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':nx -= 0.1;break;
	case 'd':nx += 0.1;break;
	case 'w':ny += 0.1;break;
	case 's':ny -= 0.1;break;
	}
	glutPostRedisplay();
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		bScissor=TRUE;
		break;
	case 2:
		bScissor=FALSE;
		break;
	case 3:
		bStencil=TRUE;
		break;
	case 4:
		bStencil=FALSE;
		break;
	case 5:
		bEqual=TRUE;
		break;
	case 6:
		bEqual=FALSE;
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// 가위 테스트
	if (bScissor) {
		glEnable(GL_SCISSOR_TEST);
	} else {
		glDisable(GL_SCISSOR_TEST);
	}
	glScissor(10,10,150,150);

	if (bStencil) {
		glEnable(GL_STENCIL_TEST);
	} else {
		glDisable(GL_STENCIL_TEST);
	}

	// 스탠실 버퍼에 마킹만 한다.
	glStencilFunc(GL_NEVER, 0x0, 0x0);
	glStencilOp(GL_INCR, GL_INCR, GL_INCR);

	// 수평 선 그음
	glColor3f(1,1,1);
	GLint arFac[] = { 1,     1,     1,     2,     3,     4,     2,     3,     2};
	GLushort arPat[]={0xaaaa,0x33ff,0x57ff,0xaaaa,0xaaaa,0xaaaa,0x33ff,0x33ff,0x57ff };
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(3);
	GLfloat y;
	GLint idx = 0;
	for (y = 0.8; y > -0.8;y -= 0.2) {
		glLineStipple(arFac[idx], arPat[idx]);
		glBegin(GL_LINES); {
			glVertex2f(-0.8, y);
			glVertex2f(0.8, y);
		}
		glEnd();
		idx++;
	}

	// 스텐실 값과 비교하여 특정 영역에만 출력한다.
	glStencilFunc(bEqual ? GL_EQUAL:GL_NOTEQUAL, 0x1, 0xff);

	// nx, ny 위치에 삼각형 그림
	glColor3f(0,0,1);
	glBegin(GL_TRIANGLES);
	glVertex2f(nx + 0.0, ny + 0.5);
	glVertex2f(nx -0.5, ny - 0.5);
	glVertex2f(nx + 0.5, ny - 0.5);
	glEnd();

	glFlush();
}
