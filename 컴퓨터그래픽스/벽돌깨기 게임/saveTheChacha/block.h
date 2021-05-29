#pragma once
#include <glut.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

#define	blockBoxWidth 			400
#define	blockBoxHeigth			600
#define blockWidth				50
#define blockHeight				60

int* map = NULL;
POINT blockCollision[10][8][4];

void drawBlock(int mapNum) {
	int cnt = 0;

	map = readMap(mapNum);

	for (int i = 0; map[i] != NULL; i++) {
		if (i % 5 == 0) printf("\n");
		printf("%d", map[i]);
	}

	srand(time(NULL));

	int index = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 8 ; x++) {
			glColor3f((rand() % 10) / 10.0, (rand() % 10) / 10.0, (rand() % 10) / 10.0);
			glBegin(GL_POLYGON);

			if (map[index] == 1) {
				glColor3f(1.0, 0.3, 0.6);
			}

			if (map[index] > 0) {
				blockCollision[y][x][0].x = -1.0 + (0.5 * x) * 0.33;
				blockCollision[y][x][0].y = 1.0 - (0.1 * y);
				blockCollision[y][x][1].x = -1.0 + (0.5 * x) * 0.33;
				blockCollision[y][x][1].y = 1.0 - (0.1 * (y + 1));
				blockCollision[y][x][2].x = -1.0 + (0.5 * (x + 1)) * 0.33;
				blockCollision[y][x][2].y = 1.0 - (0.1 * (y + 1));
				blockCollision[y][x][3].x = -1.0 + (0.5 * (x + 1)) * 0.33;
				blockCollision[y][x][3].y = 1.0 - (0.1 * y);

				glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * y)));
				glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * (y + 1))));
				glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * (y + 1))));
				glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * y)));

			}

			index++;
			glEnd();
		}
		cnt++;
	}
	// 테두리 그리기
	glColor3f(0.5, 0.3, 0.8);
	glLineWidth(12.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINES);
	glVertex2f(0.33, -1.0);
	glVertex2f(0.33, 1.0);
	glEnd();
}