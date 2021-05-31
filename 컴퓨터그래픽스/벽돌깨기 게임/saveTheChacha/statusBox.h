#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <stdlib.h>

#define MAX_DIGITS 10
#include "score.h"


void textOutput(int x, int y, float r, float g, float b, char* string) {
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
    glRasterPos2f(0, 0);
}

void printScore() {
    char a[] = "score";
    textOutput(450, 500, 0.2, 0.2, 0.2, a);
    char b[10];
    _itoa_s(gameScore.setScore(0), b, 10);
    textOutput(450, 480, 0.2, 0.2, 0.2, b);

    char c[] = "remain";
    textOutput(450, 400, 0.2, 0.2, 0.2, c);
    char d[10];
    _itoa_s(gameScore.getChacha(), d, 10);
    textOutput(450, 380, 0.2, 0.2, 0.2, d);

    char e[] = "life";
    textOutput(450, 300, 0.2, 0.2, 0.2, e);
    char f[10];
    _itoa_s(gameScore.setLife(0), f, 10);
    textOutput(450, 280, 0.2, 0.2, 0.2, f);

    char g[] = "level";
    textOutput(450, 200, 0.2, 0.2, 0.2, g);
    char h[10];
    _itoa_s(gameScore.setLevel(0), h, 10);
    textOutput(450, 180, 0.2, 0.2, 0.2, h);
}

//
//GLUT_BITMAP_8_BY_13
//GLUT_BITMAP_9_BY_15
//GLUT_BITMAP_TIMES_ROMAN_10
//GLUT_BITMAP_TIMES_ROMAN_24
//GLUT_BITMAP_HELVETICA_10
//GLUT_BITMAP_HELVETICA_12
//GLUT_BITMAP_HELVETICA_18