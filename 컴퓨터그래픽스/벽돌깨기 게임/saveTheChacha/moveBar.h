#pragma once
#include <stdio.h>

#define BarWidth		100
#define BarHeight		20
#define	BarMaxWidth 	400
#define	BarMaxHeight	600
#define BarY            50
#define BarSpeed        9.0

float BarX = (BarMaxWidth) / 2 - (BarWidth / 2);

void RenderScene();
void drawBar();
void movingBar(int key, int x, int y);
Point getBarPosition();
SIZE getBarSize();

typedef struct _Point {
    float	x;
    float	y;
} Point;

void drawBar() {
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f(BarX, BarY);
    glVertex2f(BarX, BarY + BarHeight);
    glVertex2f(BarX + BarWidth, BarY + BarHeight);
    glVertex2f(BarX + BarWidth, BarY);
    glEnd();
    glFinish();
}

//glutSpecialFunc(movingBar);
void movingBar(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        if((BarMaxWidth - BarWidth) >= (BarX + BarSpeed)) BarX += BarSpeed;
    }
    else if (key == GLUT_KEY_LEFT) {
        if (0 <= (BarX - BarSpeed)) BarX -= BarSpeed;
    }
    RenderScene();
}

Point getBarPosition() {
    Point pos;
    pos.x = BarX;
    pos.y = BarY;
    return pos;
}

SIZE getBarSize() {
    SIZE s;
    s.cx = BarMaxWidth;
    s.cy = BarMaxHeight;
}




