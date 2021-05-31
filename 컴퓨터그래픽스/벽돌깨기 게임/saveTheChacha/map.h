#pragma once
#include <stdio.h>
#include <string>
#include "score.h"

bool mapRead = true;

int* readMap(int mapNum) {
    static int map[10][8] = { 0 };
    FILE* fp = NULL;

    if (mapNum == 1) fopen_s(&fp, "./map/baby.txt", "r");
    else if (mapNum == 2) { fopen_s(&fp, "./map/heart.txt", "r");   gameScore.setChacha(2);}
    else if (mapNum == 3) { fopen_s(&fp, "./map/x.txt", "r");       gameScore.setChacha(4);}
    else if (mapNum == 4) { fopen_s(&fp, "./map/zigzag.txt", "r");  gameScore.setChacha(6);}
    else if (mapNum == 5) { fopen_s(&fp, "./map/candy.txt", "r");   gameScore.setChacha(16);}
    else if (mapNum == 6) { fopen_s(&fp, "./map/good.txt", "r");    gameScore.setChacha(777);}
    else { fopen_s(&fp, "./map/good.txt", "r"); }

    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 8; k++) {
            int num;
            fscanf_s(fp, "%1d", &num);
            if (num == 2) {
                cnt++;
            }
            map[i][k] = num;
        }
    }

    if (mapRead == true) {
        gameScore.setChacha(cnt - 1);
        mapRead = false;
    }
    fclose(fp);    // 파일 포인터 닫기

    return (int*)map;
}