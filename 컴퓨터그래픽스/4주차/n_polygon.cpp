#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glut.h> // (or others, depending on the system in use)

#define		PI				3.1415926
#define		Window_Width	500
#define		Window_Height	500

int			model_type=GL_POINTS;

int			num = 10;
float		radius = 30;
float		start_angle = 0.0;

void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	//glViewport(0, h/2, w/2, h/2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250, 250, -250, 250);
	//glOrtho(-250, 250, -250, 250, -1, 1);
}

void Modeling_Circle(void) {
	float	delta;

	glColor3f(1.0, 1.0, 0.0);
	glPointSize(3.0);
	delta = 2 * PI / num;
	glBegin(model_type);
	for (int i = 0; i < num; i++)
		glVertex2f(radius * cos(start_angle+delta*i), radius * sin(start_angle+delta*i));
	glEnd();
}

void Modeling_Axis(void) {
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-250.0, 0.0);
		glVertex2f(250.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, -250.0);
		glVertex2f(0, 250.0);
	glEnd();
}

void Modeling_Rectangle(void){
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2i(100, 100);
		glVertex2i(150, 100);
		glVertex2i(150, 150);
		glVertex2i(100, 150);
	glEnd();
}

void Modeling_Ground(void) {
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2i( 250,  250);
		glVertex2i(-250,  250);
		glVertex2i(-250, -250);
		glVertex2i( 250, -250);
	glEnd();
}

void RenderScene(void) {
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	

	//Modeling_Ground();
	
	
	Modeling_Rectangle();	// 1사분면에 있는 정사각형 
	Modeling_Axis();		// x축과 y축 
	Modeling_Circle();		// 반지름의 크기가 30인 원
	
	glFlush();
}


void MyKey(unsigned char key, int x, int y) {

	switch (key) {
		case 'n':	num += 1;		
					break;
		case 'm':	num -= 1; 		
					if (num < 3) 	num = 3;
					break;
		case 'a':	radius += 1.0;	
					break;
		case 's':	radius -= 1.0;	
					break;
		case 'r':	start_angle += 0.1;	
					break;
		case 't':	start_angle -= 0.1;	
					break;

		default:	break;
	}
	glutPostRedisplay();
}

void SpecialKey(int key, int x, int y) {
	
	switch (key) {
		case GLUT_KEY_F1:	model_type = GL_POINTS ;	break;
		case GLUT_KEY_F2:	model_type = GL_LINES;		break;
		case GLUT_KEY_F3:	model_type = GL_TRIANGLES;	break;
		case GLUT_KEY_F4:	model_type = GL_QUADS;		break;
		case GLUT_KEY_F5:	model_type = GL_LINE_STRIP;	break;
		case GLUT_KEY_F6:	model_type = GL_LINE_LOOP;	break;
		case GLUT_KEY_F7:	model_type = GL_POLYGON;	break;
		default:	break;
	}
	glutPostRedisplay();
}


void main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(Window_Width, Window_Height);
	glutCreateWindow("N-Polygon & Keyboard Event");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKey);
	glutSpecialFunc(SpecialKey);
	glutMainLoop();
}