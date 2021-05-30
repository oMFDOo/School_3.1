#pragma once
#include <glut.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "ballTpye.h"

#define	blockBoxWidth 			400
#define	blockBoxHeigth			600
#define blockWidth				50
#define blockHeight				40

int* map = NULL;


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

			if (map[index] > 0) {
				glBegin(GL_POLYGON);

				if (map[index] == 1) {
					glColor3f(1.0, 0.3, 0.6);
				}
				printf("%d %d %d %d\n", x * blockWidth, blockBoxHeigth - y * blockHeight, (x + 1) * blockWidth, blockBoxHeigth - (y + 1) * blockHeight);
				glVertex2i(x * blockWidth, blockBoxHeigth - y * blockHeight);				// 좌상단
				glVertex2i(x * blockWidth, blockBoxHeigth - (y + 1) * blockHeight);			// 좌하단
				glVertex2i((x + 1) * blockWidth, blockBoxHeigth - (y + 1) * blockHeight);	// 우하단
				glVertex2i((x + 1) * blockWidth, blockBoxHeigth - y * blockHeight);			// 우상단
				glEnd();

				//glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * y)));				// 좌상단
				//glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * (y + 1))));		// 좌하단
				//glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * (y + 1))));	// 우하단
				//glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * y)));		// 우상단
			}

			index++;
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