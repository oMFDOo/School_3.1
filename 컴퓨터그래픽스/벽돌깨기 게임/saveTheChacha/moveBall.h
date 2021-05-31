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
	// ���� �浹
	if (ballCenter.x + ballRadius == pos.x &&
		ballCenter.y <= (pos.y + s.cy) &&
		ballCenter.y >= pos.y ) {
		printf("��\n");
		velocity.x *= -1;
	}
	// ������
	if (ballCenter.x - ballRadius == pos.x + BarWidth &&
		ballCenter.y <= (pos.y + s.cy) &&
		ballCenter.y >= pos.y) {
		printf("����\n");
		velocity.x *= -1;
	}
	// ��
	if (ballCenter.y - ballRadius == pos.y + BarHeight &&
		ballCenter.x <= (pos.x + s.cx) &&
		ballCenter.x >= pos.x) {
		printf("��\n");
		velocity.y *= -1;
	}
	// �Ʒ�
	if (ballCenter.y + ballRadius == pos.y &&
		ballCenter.x <= (pos.x + s.cx) &&
		ballCenter.x >= pos.x) {
		printf("�Ʒ�\n");
		velocity.y *= -1;
	}
	// �𼭸�
	if ((ballCenter.x + ballRadius == pos.x && ballCenter.y - ballRadius == s.cy + BarHeight) ||
		(ballCenter.x + ballRadius == pos.x && ballCenter.y + ballRadius == s.cy) ||
		(ballCenter.x + ballRadius == pos.x + BarWidth&& ballCenter.y - ballRadius == s.cy + BarHeight) ||
		(ballCenter.x + ballRadius == pos.x + BarWidth && ballCenter.y + ballRadius == s.cy) ) {
		printf("�𼭸�\n");
		velocity.x *= -1;
		velocity.y *= -1;
	}

}

void collisionWindow() {
	// ������ �浹
	if (ballCenter.x + ballRadius >= BarMaxWidth) {
		velocity.x *= -1;
	}
	// ���� �浹
	if (ballCenter.x - ballRadius <= 0) {
		velocity.x *= -1;
	}
	// ���� �浹
	if (ballCenter.y + ballRadius >= BarMaxHeight) {
		velocity.y *= -1;
	}
	// �Ʒ��� �浹
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
				printf("�� �»�� �𼭸�\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			if (ballCenter.x + ballRadius == BWidth * k && ballCenter.y + ballRadius == 600 - (BHeight * i)) {
				printf("�� ���ϴ� �𼭸�\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			//115 550
			if (ballCenter.x - ballRadius == BWidth * (k + 1) && ballCenter.y + ballRadius == 600 - (BHeight * i)) {
				printf("�� ���ϴ� �𼭸�\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}
			if (ballCenter.x - ballRadius == BWidth * (k + 1) && ballCenter.y - ballRadius == 600 - (BHeight * i)) {
				printf("�� ���� �𼭸�\n");
				if (map[cnt] == 2) playSound(1);
				map[cnt] = 0;
				velocity.x *= -1; velocity.y *= -1; return;
			}

			if (ballCenter.y <= 600 - (BHeight * i) && ballCenter.y >= 600 - (BHeight * (i + 1))) {
				// ����
				if (ballCenter.x + ballRadius == BWidth * k) {
					printf("�� ����\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200);}
					map[cnt] = 0; gameScore.setScore(100);
					velocity.x *= -1; return;
				}
				// ������
				if (ballCenter.x - ballRadius == BWidth * (k + 1)) {
					printf("�� ������\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.x *= -1; return;
				}
			}
			
			if (ballCenter.x >= BWidth * k && ballCenter.x <= BWidth * (k + 1)) {
				// ����
				if (ballCenter.y - ballRadius == 600 - (BHeight * i)) {
					printf("�� ����\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.y *= -1; return;
				}
				// �Ʒ���
				if (ballCenter.y + ballRadius == 600 - (BHeight * (i + 1))) {
					printf("�� �Ʒ���\n");
					if (map[cnt] == 2) { playSound(1); gameScore.setChacha(-1); gameScore.setScore(200); }
					map[cnt] = 0;  gameScore.setScore(100);
					velocity.y *= -1; return;
				}
			}
			cnt++;
		}
	}
}