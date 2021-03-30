#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glut.h>



void RenderScene(void) {
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Modeling Objects -------- 


	glFlush();
}

void main(int argc, char** argv) {
	glutInitWindowPosition(50, 150);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Welcome to Computer Graphics");
	glutDisplayFunc(RenderScene);
	glutMainLoop();
}

