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

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, left + width, bottom, bottom + height); // mouse2()
}


void RenderScene(void) {
	if (processStart) {
		ballSet();
	}

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground();

	drawBlock(1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//관측 공간을 어떻게 설정해야 하는가?
	gluOrtho2D(left, left + width, bottom, bottom + height);

	// 바그리기
	drawBar();

	// 충돌처리
	collisionBar(getBarPosition(), getBarSize());
	collisionWindow();
	collisionBlock(map);

	// 공이동
	ballCenter.x += velocity.x;
	ballCenter.y += velocity.y;


	// 공그리기
	Modeling_Circle(ballCenter);

	//glutSwapBuffers();
	glLoadIdentity();
	glFlush();


	if (processStart) {
		playSound(0);
		ballSet();
		readMap(1);
		processStart = false;
	}
}

void mouse1(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// 왼쪽 버튼을 누르면 어떤 일을 수행해야 하는가?
		playSound(1);

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		// 오른쪽 버튼을 누르면 어떤 일을 수행해야 하는가?


	}
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Save the CHACHA");


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);


	glutReshapeFunc(MyReshape);
	glutDisplayFunc(RenderScene); 
	glutIdleFunc(RenderScene);

	glutMouseFunc(mouse1);
	//glutMotionFunc(motion);

	glutSpecialFunc(movingBar); // 바 그리기




	glutMainLoop();
}