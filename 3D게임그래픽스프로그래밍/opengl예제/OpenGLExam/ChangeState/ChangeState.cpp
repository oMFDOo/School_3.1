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
	glutAddMenuEntry("»¡°£»ö ¹è°æ",0);
	glutAddMenuEntry("»¡°£»ö »ï°¢Çü",1);
	glutAddMenuEntry("¿À°¢Çü ±×¸®±â",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	if (value < 100) {
		Action = value;
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glutPostRedisplay();
		return;
	}
}

void DoDisplay()
{
switch(Action) {
case 0:
	// »¡°£»ö ¹è°æ
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 1:
	// »¡°£»ö »ï°¢Çü
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
	break;
case 2:
	// ¿À°¢Çü ±×¸®±â
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0, 0.6);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.6, 0.0);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.4, -0.6);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.4, -0.6);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.6, 0.0);
	glEnd();
	glFlush();
	break;

}
}

