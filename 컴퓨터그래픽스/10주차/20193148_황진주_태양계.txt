#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <glut.h> // (or others, depending on the system in use)

#define PI 3.1415926

int Width = 800, Height = 800;
float radius1 = 50.0, radius2 = 10.0, radius3 = 5.0;
float sunEarth = 200.0, earthMoon = 30.0;
float earthR = 0.0, moonR = 0.0;
float delta_earthR = 0.02, delta_moonR = 0.2;

void init(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * Width / 2.0, Width / 2.0, -1.0 * Height / 2.0, Height /2.0);
}

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * Width / 2.0, Width / 2.0, -1.0 * Height / 2.0, Height / 2.0);
}

void Draw_Circle(float c_radius) {
	float delta;
	int num = 36;
	delta = 2 * PI / num;
	glBegin(GL_POLYGON);
	for (int i = 0; i < num; i++)
		glVertex2f(c_radius * cos(delta * i), c_radius * sin(delta * i));
	glEnd();
}
void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0); // Set display-window color to black.

	earthR += delta_earthR;
	moonR += delta_moonR;

	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();

	/***********코드 작성하기 ***************/
	// 태양 : 빨간색의 구 
	Draw_Circle(radius1);
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(earthR, 0.0, 0.0, 1.0);
	glTranslatef(sunEarth, 0, 0);

	// 지구 : 초록색의 구 
	Draw_Circle(radius2);
	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(moonR, 0.0, 0.0, 1.0);
	glTranslatef(earthMoon, 0, 0);

	// 달   : 노랑색의 구 
	Draw_Circle(radius3);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

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