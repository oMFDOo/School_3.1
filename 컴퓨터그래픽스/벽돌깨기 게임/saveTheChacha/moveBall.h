#pragma once
#include <glut.h>
#include <math.h>
#include <stdio.h>

#define	PI				3.1415
#define	polygon_num		30
#define ballRadius		10



POINT ballCenter, velocity;


void Modeling_Circle(POINT CC) {
	float	delta;

	glPointSize(3.0);
	delta = 2 * PI / polygon_num;

	glColor3f(1.0, 0.0, 0.3);
	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(CC.x + ballRadius * cos(delta * i), CC.y + ballRadius * sin(delta * i));
	glEnd();
}

void ballSet() {
	POINT pos = getBarPosition();
	ballCenter.x = pos.x + (BarWidth / 2);
	ballCenter.y = 55 + BarHeight + ballRadius;
	velocity.x = 1;
	velocity.y = 1;
}

void collisionBar(POINT pos, SIZE s) {
	// 왼쪽 충돌
	if (ballCenter.x + ballRadius == pos.x &&
		ballCenter.y <= (pos.y + s.cy) &&
		ballCenter.y >= pos.y ) {
		printf("왼\n");
		velocity.x *= -1;
	}
	// 오른쪽
	if (ballCenter.x - ballRadius == pos.x + BarWidth &&
		ballCenter.y <= (pos.y + s.cy) &&
		ballCenter.y >= pos.y) {
		printf("오른\n");
		velocity.x *= -1;
	}
	// 위
	if (ballCenter.y - ballRadius == pos.y + BarHeight &&
		ballCenter.x <= (pos.x + s.cx) &&
		ballCenter.x >= pos.x) {
		printf("위\n");
		velocity.y *= -1;
	}
	// 아래
	if (ballCenter.y + ballRadius == pos.y &&
		ballCenter.x <= (pos.x + s.cx) &&
		ballCenter.x >= pos.x) {
		printf("아래\n");
		velocity.y *= -1;
	}
	// 모서리
	if ((ballCenter.x + ballRadius == pos.x && ballCenter.y - ballRadius == s.cy + BarHeight) ||
		(ballCenter.x + ballRadius == pos.x && ballCenter.y + ballRadius == s.cy) ||
		(ballCenter.x + ballRadius == pos.x + BarWidth&& ballCenter.y - ballRadius == s.cy + BarHeight) ||
		(ballCenter.x + ballRadius == pos.x + BarWidth && ballCenter.y + ballRadius == s.cy) ) {
		printf("모서리\n");
		velocity.x *= -1;
		velocity.y *= -1;
	}

}

void collisionWindow() {
	// 오른쪽 충돌
	if (ballCenter.x + ballRadius >= BarMaxWidth) {
		velocity.x *= -1;
	}
	// 왼쪽 충돌
	if (ballCenter.x - ballRadius <= 0) {
		velocity.x *= -1;
	}
	// 위쪽 충돌
	if (ballCenter.y + ballRadius >= BarMaxHeight) {
		velocity.y *= -1;
	}
	// 아래쪽 충돌
	if (ballCenter.y - ballRadius <= 0) {
		ballSet();
		// 점수 깎기, 리셋
	}
}

void collisionBlock(int* map, POINT blockCollision[8][10][4]) {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 8; k++) {
			for () {

			}
		}
	}
}