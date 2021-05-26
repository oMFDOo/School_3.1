#pragma once
#include <glut.h>
#include <math.h>

#define	PI				3.1415
#define	polygon_num		30
#define ballRadius		30

typedef struct _Point {
	float	x;
	float	y;
} Point;

void Modeling_Circle(Point CC) {
	float	delta;

	glPointSize(3.0);
	delta = 2 * PI / polygon_num;

	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(CC.x + ballRadius * cos(delta * i), CC.y + ballRadius * sin(delta * i));
	glEnd();
}