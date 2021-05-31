#pragma once
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include "sound.h"
#include "score.h"

#define	PI				3.1415
#define	polygon_num		30
#define ballRadius		10
#define BWidth			50
#define BHeight			40


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
		gameScore.setLife(-1);
	}
}

void collisionBlock(int* map) {
	//printf("%d %d\n", ballCenter.x, ballCenter.y);
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 8; k++) {
			if (map[cnt] == 0) {
				cnt++;
				continue;
			}

			//printf("%d %d\n", ballCenter.x, ballCenter.y);
			
			if (ballCenter.x + ballRadius == BWidth * k && ballCenter.y - ballRadius == 600 - (BHeight * i)) {
				printf("블럭 좌상단 모서리\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			if (ballCenter.x + ballRadius == BWidth * k && ballCenter.y + ballRadius == 600 - (BHeight * i)) {
				printf("블럭 좌하단 모서리\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			//115 550
			if (ballCenter.x - ballRadius == BWidth * (k + 1) && ballCenter.y + ballRadius == 600 - (BHeight * i)) {
				printf("블럭 우하단 모서리\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			if (ballCenter.x - ballRadius == BWidth * (k + 1) && ballCenter.y - ballRadius == 600 - (BHeight * i)) {
				printf("블럭 우상단 모서리\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}

			if (ballCenter.y <= 600 - (BHeight * i) && ballCenter.y >= 600 - (BHeight * (i + 1))) {
				// 왼쪽
				if (ballCenter.x + ballRadius == BWidth * k) {
					printf("블럭 왼쪽\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200);}
					map[cnt] = 0; gameScore.setScore(100);
					velocity.x *= -1; return;
				}
				// 오른쪽
				if (ballCenter.x - ballRadius == BWidth * (k + 1)) {
					printf("블럭 오른쪽\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.x *= -1; return;
				}
			}
			
			if (ballCenter.x >= BWidth * k && ballCenter.x <= BWidth * (k + 1)) {
				// 위쪽
				if (ballCenter.y - ballRadius == 600 - (BHeight * i)) {
					printf("블럭 위쪽\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.y *= -1; return;
				}
				// 아래쪽
				if (ballCenter.y + ballRadius == 600 - (BHeight * (i + 1))) {
					printf("블럭 아래쪽\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.y *= -1; return;
				}
			}
			cnt++;
		}
	}
}