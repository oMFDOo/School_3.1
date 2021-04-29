#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <glut.h> // (or others, depending on the system in use)

#define		PI	3.1415926

int			Width = 800;
int			Height = 800;

float		radius1 = 50.0;
float		radius2 = 10.0;
float		radius3 = 5.0;

float		sunEarth = 200.0;
float		earthMoon = 30.0;

float		earthR = 0.0, moonR = 0.0;

float		delta_earthR = 0.0001;
float		delta_moonR = 0.1;

POINT		cur_position[3];
float		turnSun = 0;
float		turnEarth = 0;

void init(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * Width / 2.0, Width / 2.0, -1.0 * Height / 2.0, Height / 2.0);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * Width / 2.0, Width / 2.0, -1.0 * Height / 2.0, Height / 2.0);
}

void Draw_Circle(float c_radius, int type) {
	float	delta;
	int		num = 30;

	

	delta = 2 * PI / num;
	glBegin(GL_POLYGON);


	

	GLfloat x, y, x2 = 0, y2 = 0;

	if (type == 1) {
		x2 = sunEarth * sin(turnSun);
		y2 = sunEarth * cos(turnSun);
	}
	else if (type == 2) {
		x2 = (earthMoon + radius2) * sin(turnEarth) + cur_position[1].x;
		y2 = (earthMoon + radius2) * cos(turnEarth) + cur_position[1].y;
	}

	for (int i = 0; i < num; i++) {
		x = c_radius * cos(delta * i) + x2;
		y = c_radius * sin(delta * i) + y2;
		cur_position[type].x = x; cur_position[type].y = y;
		glVertex2f(x, y);
	}
	glEnd();
}



void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0); // Set display-window color to black.

	earthR += delta_earthR;
	moonR += delta_moonR;

	/***********코드 작성하기 ***************/
	// 태양 : 빨간색의 구 
	glColor3f(1.0, 0.0, 0.0);
	Draw_Circle(radius1, 0);


	// 지구 : 초록색의 구 
	glColor3f(0.0, 1.0, 0.0);
	Draw_Circle(radius2, 1);

	// 달   : 노랑색의 구 
	glColor3f(1.0, 1.0, 0.0);
	Draw_Circle(radius3, 2);

	turnSun += delta_moonR;
	turnEarth += delta_earthR;

	Sleep(100);

	glFlush();
	glutSwapBuffers();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Solar System");
	init();
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(RenderScene);
	glutMainLoop();
}

