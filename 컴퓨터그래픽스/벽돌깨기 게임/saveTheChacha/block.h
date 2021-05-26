#pragma once
#include <glut.h>
#include <stdlib.h>
#include <time.h>

#define	blockBoxWidth 			400
#define	blockBoxHeigth			600
#define blockWidth				50
#define blockHeight				60

void drawBlock() {
	int cnt = 0;
	srand(time(NULL));
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 8 ; x++) {
			glColor3f((rand() % 10) / 10.0, (rand() % 10) / 10.0, (rand() % 10) / 10.0);
			glBegin(GL_POLYGON);

			glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * y)));
			glVertex2f(-1.0 + (0.5 * x) * 0.33, (1.0 - (0.1 * (y + 1))));
			glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * (y + 1))));
			glVertex2f(-1.0 + (0.5 * (x + 1)) * 0.33, (1.0 - (0.1 * y)));

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