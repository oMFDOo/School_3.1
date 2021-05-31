#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <glut.h>

#define	BGMaxWidth 	400
#define	BGMaxHeight	600


GLubyte* LoadBmp(const char* Path, int* Width, int* Height) {

    HANDLE hFile;
    DWORD FileSize, dwRead;
    BITMAPFILEHEADER* fh = NULL;
    BITMAPINFOHEADER* ih;
    BYTE* pRaster;


    hFile = CreateFileA(Path, GENERIC_READ, 0, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        return NULL;
    }


    FileSize = GetFileSize(hFile, NULL);
    fh = (BITMAPFILEHEADER*)malloc(FileSize);
    ReadFile(hFile, fh, FileSize, &dwRead, NULL);
    CloseHandle(hFile);

    int len = FileSize - fh->bfOffBits;
    pRaster = (GLubyte*)malloc(len);
    memcpy(pRaster, (BYTE*)fh + fh->bfOffBits, len);


    // RGB로 순서를 바꾼다.
    for (BYTE* p = pRaster; p < pRaster + len - 3; p += 3) {
        BYTE b = *p;
        *p = *(p + 2);
        *(p + 2) = b;
    }

    ih = (BITMAPINFOHEADER*)((PBYTE)fh + sizeof(BITMAPFILEHEADER));
    *Width = ih->biWidth;
    *Height = ih->biHeight;

    free(fh);
    return pRaster;
}



void drawBackground(int num, int bw = 0, int bh = 0) {
    GLubyte* data;
    int w = BGMaxWidth, h = BGMaxHeight;

    if (num == 1) {
        data = LoadBmp("./image/test3.bmp", &w, &h);
        glDrawPixels(BGMaxWidth, BGMaxHeight, GL_RGB, GL_UNSIGNED_BYTE, data);
        free(data);
    }
    if (num == 2) {
        w = 51; h = 42;
        data = LoadBmp("./image/block.bmp", &w, &h);
        glDrawPixels(bw, bh, GL_RGB, GL_UNSIGNED_BYTE, data);
        free(data);
    }
}