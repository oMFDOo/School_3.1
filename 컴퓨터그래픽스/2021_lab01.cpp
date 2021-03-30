#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <math.h>


void RenderScene(void) {
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Modeling Objects -------- 


	glFlush();
}

void main(void) {
	glutInitWindowPosition(50, 150);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Welcome to Computer Graphics");
	glutDisplayFunc(RenderScene);
	glutMainLoop();
}