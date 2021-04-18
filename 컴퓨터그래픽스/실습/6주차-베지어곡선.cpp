#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <glut.h> // (or others, depending on the system in use)

#define		Window_Width	800
#define		Window_Height	800

int			point[100][2];
int			num = 0;

int Factorial(int num) {
	int fac = 1;
	for (int i = 1; i <= num; i++) {
		fac *= i;
	}
	return fac;
}

int Combination(int n, int r) {
	int result = (Factorial(n) / Factorial(r)) / Factorial(n-r);
	return result;
}

// Bernstein Polynomial : nCk * (1-t)^(n-k) * t^k
double Bernstein(int num, double k, double t) {
	return Combination(num, k) * pow((1 - t), num - k) * pow(t, k);
}

void Draw_Bezier_Curve(void) {

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);

	double part = 1.0 / 80;
	double sumx, sumy;  
	double high;  // 가중치 값
	int px, py; // P0, P1, P2, ... Pn

	// 초기 점 지정
	px = point[0][0];
	py = point[0][1];
	glVertex2d(px, py);

	// 시간(t)의 흐름
	for (double t = part; t <= 1.0; t += part) {
		sumx = sumy = 0;
		// Pi를 곱해주는 과정 : 1=0 Σ n
		for (int i = 0; i < num; i++) {
			high = Bernstein(num -1, i, t);
			sumx += high * point[i][0];
			sumy += high * point[i][1];
		}
		glVertex2d(sumx, sumy);
	}
	glEnd();

}

void Draw_Control_Points(void) {

	glPointSize(3.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int k = 0; k < num; k++) {
		glVertex2f(point[k][0], point[k][1]);
	}
	glEnd();

}

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);

	if (num >= 1)
		Draw_Control_Points();
	if (num >= 2)
		Draw_Bezier_Curve();

	glFlush();
	glutSwapBuffers();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION); // Set projection parameters.
	glLoadIdentity();
	gluOrtho2D(0, Window_Width, 0, Window_Height);
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		point[num][0] = x;
		point[num][1] = Window_Height - y;
		num++;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		num = 0;
	}
	glutPostRedisplay();
	RenderScene();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Window_Width, Window_Height); 
	glutCreateWindow("Bezier Curve");
	init();
	glutDisplayFunc(RenderScene);
	glutMouseFunc(mouse);
	glutMainLoop();
}