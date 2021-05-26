#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <math.h>

#include "moveBar.h"
#include "background.h"
#include "sound.h"
#include "moveBall.h"
#include "block.h"

#define	width 			600
#define	height			600
 
int		left = 0;
int		bottom = 0;
bool processStart = true;

Point	circle_center, fix_center, shoot_center;

void RenderScene(void) {

	if (processStart) {
		playSound(0);
		processStart = false;
	}

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground();

	drawBlock();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//관측 공간을 어떻게 설정해야 하는가?
	gluOrtho2D(left, left + width, bottom, bottom + height);

	// 바그리기
	drawBar();

	glLoadIdentity();
	glFlush();
}

void main(int argc, char** argv) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Save the CHACHA");



	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutDisplayFunc(RenderScene); 

	//glutMouseFunc(mouse1);
	//glutMotionFunc(motion);

	glutSpecialFunc(movingBar); // 바 그리기

	glutMainLoop();
}