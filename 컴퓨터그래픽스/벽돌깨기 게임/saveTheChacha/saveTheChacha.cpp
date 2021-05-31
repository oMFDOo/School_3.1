#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <math.h>

#include "moveBar.h"
#include "background.h"
#include "sound.h"
#include "moveBall.h"
#include "block.h"
#include "statusBox.h"

#define	width 			600
#define	height			600
 
int		left = 0;
int		bottom = 0;
bool	processStart = true;
bool	levelup = true;

void RenderScene(void) {
	if (processStart) {
		ballSet();
	}
	if (levelup) {
		map = readMap(gameScore.setLevel(0));
		levelup = false;
	}
	glLoadIdentity();
	//관측 공간을 어떻게 설정해야 하는가?
	gluOrtho2D(0, 0 + width, 0, 0 + height);

	glClearColor(0.9, 0.9, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground(1);
	
	
	drawBlock(map);

	printScore();

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

	
	glLoadIdentity();
	glFlush();


	if (processStart) {
		playSound(0);
		ballSet();
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

int main(int argc, char** argv) {
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Save the CHACHA");

	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(left, left + width, bottom, bottom + height); // mouse2()

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	if (gameScore.getChacha() == 0) {
		if (gameScore.setLevel(0) + 1 <= 6) {
			gameScore.setLevel(1);
			levelup = true;
		}
	}

	glutDisplayFunc(RenderScene); 
	glutIdleFunc(RenderScene);

	glutMouseFunc(mouse1);
	//glutMotionFunc(motion);


	glutSpecialFunc(movingBar); // 바 그리기

	glutMainLoop();
}