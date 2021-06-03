#include <windows.h>
#include <gl/glut.h>

void DoDisplay();
void DoMenu(int value);
int Action;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("비트맵 출력",0);
	glutAddMenuEntry("노란색 픽셀맵 출력",1);
	glutAddMenuEntry("이미지 파일 출력",2);
	glutAddMenuEntry("이미지 일부를 화면으로 복사",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoMenu(int value) 
{
	if (value < 100) {
		Action = value;
		glColor3f(1,1,1);
		glutPostRedisplay();
		return;
	}
}

GLubyte *LoadBmp(const char *Path, int *Width, int *Height)
{
	HANDLE hFile;
	DWORD FileSize, dwRead;
	BITMAPFILEHEADER *fh=NULL;
	BITMAPINFOHEADER *ih;
	BYTE *pRaster;

	hFile=CreateFileA(Path,GENERIC_READ,0,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if (hFile==INVALID_HANDLE_VALUE) {
		return NULL;
	}

	FileSize=GetFileSize(hFile,NULL);
	fh=(BITMAPFILEHEADER *)malloc(FileSize);
	ReadFile(hFile,fh,FileSize,&dwRead,NULL);
	CloseHandle(hFile);

	int len = FileSize - fh->bfOffBits;
	pRaster=(GLubyte *)malloc(len);
	memcpy(pRaster, (BYTE *)fh+fh->bfOffBits, len);

	// RGB로 순서를 바꾼다.
	for (BYTE *p=pRaster;p < pRaster + len - 3;p+=3) {
		BYTE b = *p;
		*p = *(p+2);
		*(p+2) = b;
	}

	ih=(BITMAPINFOHEADER *)((PBYTE)fh+sizeof(BITMAPFILEHEADER));
	*Width=ih->biWidth;
	*Height=ih->biHeight;

	free(fh);
	return pRaster;
}

void DoDisplay()
{
switch(Action) {
case 0:
	// 비트맵 출력
	{
	static GLubyte bitmap[] = {
		0x07, 0xe0, 0x18, 0x18, 0x20, 0x04, 0x43, 0xc2,
		0x44, 0x22, 0x88, 0x11, 0x81, 0x81, 0x81, 0x81,
		0x80, 0x01, 0x80, 0x01, 0x92, 0x49, 0x4c, 0x32,
		0x40, 0x02, 0x20, 0x04, 0x18, 0x18, 0x07, 0xe0,
	};
	glClear(GL_COLOR_BUFFER_BIT);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
	glColor3f(1,1,0);
	glRasterPos2f(0.5,0.5);
	glBitmap(16,16,0,0,20,0,bitmap);
	glBitmap(16,16,0,0,20,0,bitmap);
	glBitmap(16,16,0,10,20,0,bitmap);

	glFlush();
	}
	break;
case 1:
	{
	// 노란색 픽셀맵 출력
	GLubyte data[32*32*3];

	for (int y=0;y<32;y++) {
		for (int x=0;x<32;x++) {
			data[y*32*3+x*3+0] = 0xff;
			data[y*32*3+x*3+1] = 0xff;
			data[y*32*3+x*3+2] = 0x00;
		}
	}

	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2f(0.0,0.0);
	glDrawPixels(32, 32, GL_RGB, GL_UNSIGNED_BYTE, data);

	glFlush();
	}
	break;
case 2:
	{
	// 이미지 파일 출력
	GLubyte *data;
	int Width, Height;

	glClear(GL_COLOR_BUFFER_BIT);

	data = LoadBmp("chestnut.bmp", &Width, &Height);
	if (data != NULL) {
		glRasterPos2f(-0.5,-0.5);
		glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, data);
		free(data);
	}

	glFlush();
	}
	break;
case 3:
	{
	// 이미지 일부를 화면으로 복사
	GLubyte *data;
	int Width, Height;

	glClear(GL_COLOR_BUFFER_BIT);

	data = LoadBmp("chestnut.bmp", &Width, &Height);
	if (data != NULL) {
		glRasterPos2f(-0.5,-0.5);
		glDrawPixels(Width, Height, GL_RGB, GL_UNSIGNED_BYTE, data);
		free(data);
	}

	glRasterPos2f(-1.0,-1.0);
	glCopyPixels(100,100,80,50,GL_COLOR);

	glFlush();
	}
	break;
}
}
