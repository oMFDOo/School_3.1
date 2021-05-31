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
bool	printSound1 = true;
bool	printSound2 = true;

void RenderScene(void) {

	
	if (levelup) {
		map = readMap(gameScore.setLevel(0));
		levelup = false;
		processStart = true;
	}
	if (gameScore.getChacha() == 0) {
		if (gameScore.setLevel(0) + 1 <= 6) {
			gameScore.setLevel(1);
			levelup = true;
		}
	}
	if (processStart) {
		ballSet();
	}
	glLoadIdentity();
	//���� ������ ��� �����ؾ� �ϴ°�?
	gluOrtho2D(0, 0 + width, 0, 0 + height);

	glClearColor(0.9, 0.9, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBackground(1);
	
	
	drawBlock(map);

	printScore();

	// �ٱ׸���
	drawBar();

	// �浹ó��
	collisionBar(getBarPosition(), getBarSize());
	collisionWindow();
	collisionBlock(map);

	// ���ӿ���
	if (gameScore.setLife(0) == 0 && printSound1 == true) {
		playSound(7);
		printSound1 = false;
	}
	// ����Ŭ����
	if (gameScore.setLevel(0) == 6 && gameScore.getChacha() == 0 && printSound2 == true) {
		playSound(8);
		printSound2 = false;
	}

	// ���̵�
	ballCenter.x += velocity.x;
	ballCenter.y += velocity.y;


	// ���׸���
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
		// ���� ��ư�� ������ � ���� �����ؾ� �ϴ°�?
		playSound(1);

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		// ������ ��ư�� ������ � ���� �����ؾ� �ϴ°�?
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



	glutDisplayFunc(RenderScene); 
	glutIdleFunc(RenderScene);

	glutMouseFunc(mouse1);
	//glutMotionFunc(motion);


	glutSpecialFunc(movingBar); // �� �׸���

	glutMainLoop();
}