#pragma once
#include <stdio.h>
#include <string>


int* readMap(int mapNum) {
    static int map[10][8] = { 0 };
    FILE* fp = NULL;
    fopen_s(&fp, "./map/test.txt", "r");


    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 8; k++) {
            int num;
            fscanf_s(fp, "%1d", &num);
            map[i][k] = num;
        }
    }
    fclose(fp);    // 파일 포인터 닫기

    return (int*)map;
}