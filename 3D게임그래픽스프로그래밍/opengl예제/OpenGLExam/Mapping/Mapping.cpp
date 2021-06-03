#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

void DoDisplay();
void DoKeyboard(unsigned char key, int x, int y);
void DoMenu(int value);
GLfloat xAngle, yAngle, zAngle;
GLint EnvMode = GL_REPLACE;
GLint TexFilter = GL_LINEAR;

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	glutCreateWindow("OpenGL");
	glutDisplayFunc(DoDisplay);
	glutKeyboardFunc(DoKeyboard);
	glutCreateMenu(DoMenu);
	glutAddMenuEntry("Replace",1);
	glutAddMenuEntry("Modulate",2);
	glutAddMenuEntry("Add",3);
	glutAddMenuEntry("Nearest Filter",4);
	glutAddMenuEntry("Linear Filter",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

void DoKeyboard(unsigned char key, int x, int y)
{
	switch(key) {
	case 'a':yAngle += 2;break;
	case 'd':yAngle -= 2;break;
	case 'w':xAngle += 2;break;
	case 's':xAngle -= 2;break;
	case 'q':zAngle += 2;break;
	case 'e':zAngle -= 2;break;
	case 'z':xAngle = yAngle = zAngle = 0.0;break;
	}
	char info[128];
	sprintf(info, "x=%.1f, y=%.1f, z=%.1f", xAngle, yAngle, zAngle);
	glutSetWindowTitle(info);
	glutPostRedisplay();
}

void DoMenu(int value) 
{
	switch(value) {
	case 1:
		EnvMode = GL_REPLACE;
		break;
	case 2:
		EnvMode = GL_MODULATE;
		break;
	case 3:
		EnvMode = GL_ADD;
		break;
	case 4:
		TexFilter = GL_NEAREST;
		break;
	case 5:
		TexFilter = GL_LINEAR;
		break;
	}
	glutPostRedisplay();
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
	GLubyte *data;
	int Width, Height;

	// 텍스처 이미지 준비
	glEnable(GL_TEXTURE_2D);
	data = LoadBmp("marble64.bmp", &Width, &Height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 
		0, GL_RGB,  GL_UNSIGNED_BYTE, data);
	free(data);

	// 텍스처 환경 설정
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, EnvMode);

	// 텍스처 필터 설정
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TexFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TexFilter);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

	// 아랫면 흰 바닥
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-0.5, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(0.5, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(0.5, -0.5);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-0.5, -0.5);
	glEnd();

	// 위쪽 빨간 변
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,0,0);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0.0, 0.0, -0.8);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(0.5, 0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-0.5, 0.5);

	// 왼쪽 노란 변
	glColor3f(1,1,0);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-0.5, -0.5);

	// 아래쪽 초록 변
	glColor3f(0,1,0);
	glTexCoord2f(1.0, 0.0);
	glVertex2f(0.5, -0.5);

	// 오른쪽 파란 변
	glColor3f(0,0,1);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(0.5, 0.5);
	glEnd();

	glPopMatrix();
	glFlush();
}
