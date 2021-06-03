#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoMenu(int value);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");

	// 서브 메뉴 미리 준비
	GLint SubMenu = glutCreateMenu(DoMenu);
	glutAddMenuEntry("Red",4);
	glutAddMenuEntry("Green",5);
	glutAddMenuEntry("Blue",6);

	// 메인 메뉴 생성
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("White",1);
	glutAddMenuEntry("Black",2);
	glutAddMenuEntry("Gray",3);

	// 서브 메뉴를 메인 메뉴에 붙인다.
	glutAddSubMenu("Triangle Color",SubMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(DoDisplay);
	glColor3f(1.0, 0.0, 0.0);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		glClearColor(1.0, 1.0, 1.0, 1.0);
		break;
	case 2:
		glClearColor(0.0, 0.0, 0.0, 1.0);
		break;
	case 3:
		glClearColor(0.5, 0.5, 0.5, 1.0);
		break;
	case 4:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case 5:
		glColor3f(0.0, 1.0, 0.0);
		break;
	case 6:
		glColor3f(0.0, 0.0, 1.0);
		break;
	}
	glutPostRedisplay();
}

void DoDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}
