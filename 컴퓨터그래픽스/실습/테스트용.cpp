#include <windows.h>
#include <freeglut.h>
#include <math.h>

#define	width 			400
#define	height			600
#define	PI				3.1415
#define	polygon_num		30

enum      actions { MOVE_OBJECT, ROTATE_OBJECT, ZOOM_OBJECT, DO_NONE };
GLsizei   action;
GLfloat	  endX = 200, endY = 100;

double ez, xAngle, yAngle, zAngle;

int		left = 0;
int		bottom = 0;

int		mouse_motion = 0;

float	radius = 10.0;
float	point[1000][2];
int		point_num = 0;


double Far = 100.0;
double Near = 0.1;

float shootX, shootY;
float speed = 100;

typedef struct _Point {
	float	x;
	float	y;
} Point;

Point	circle_center, fix_center, shoot_center;



void Modeling_Axis(void) {
	fix_center.x = 200;
	fix_center.y = 100;
	glLineWidth(8.0);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(fix_center.x, fix_center.y);
	glVertex2i(endX, endY);
	glEnd();
}

void	Modeling_Circle(Point CC) {
	float	delta;

	glPointSize(3.0);
	delta = 2 * PI / polygon_num;

	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(CC.x + radius * cos(delta * i), CC.y + radius * sin(delta * i));
	glEnd();
}

void	Modeling_Points_from_Screen(void) {
	glPointSize(5.0);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_POINTS);
	for (int k = 0; k < point_num; k++)
		glVertex2f(point[k][0], point[k][1]);
	glEnd();
}

void RenderScene(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to Yellow
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//관측 공간을 어떻게 설정해야 하는가?
	gluOrtho2D(left, left + width, bottom, bottom + height);


	Modeling_Axis(); // 축 그리기래!

	// 제일 마지막으로 입력된 점을 중심으로 하는 원 생성하기
	Modeling_Circle(circle_center);
	Modeling_Circle(fix_center);

	// 마우스 왼쪽 버튼 클릭을 통해 얻어진 점 생성하기
	Modeling_Points_from_Screen();
	glLoadIdentity();
	glFlush();
}

// 디바이스 좌표계 기준
void mouse1(int button, int state, int x, int y) {
	Point pos;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// 왼쪽 버튼을 누르면 어떤 일을 수행해야 하는가?
		endX = x;
		endY = height - y;
		point[point_num][0] = x;
		point[point_num][1] = height - y;
		point_num++;
		pos.x = x;
		pos.y = y;
		Modeling_Circle(pos);
		Modeling_Points_from_Screen();
		RenderScene();

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		// 왼쪽 버튼을 누르면 어떤 일을 수행해야 하는가?
		endX = 200;
		endY = 100;
		circle_center.x = 200;
		circle_center.y = 100;
		pos.x = 200;
		pos.y = 100;
		Modeling_Circle(pos);
		Modeling_Points_from_Screen();
		RenderScene();

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		// 오른쪽 버튼을 누르면 어떤 일을 수행해야 하는가?
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(width, height);
		glutDisplayFunc(RenderScene);

	}
	glutPostRedisplay();
}

void  motion(int x, int y)
{
	// this will only be true when the left button is down
	if (action == MOVE_OBJECT) { // update dx, dy
		Point pos;
		pos.x = x;
		pos.y = y;
		circle_center.x = x;
		circle_center.y = height - y;
		endX = x;
		endY = height - y;
		Modeling_Circle(pos);
		Modeling_Points_from_Screen();
		RenderScene();
	}

	/* Update the stored mouse position for later use */

	glutPostRedisplay();
}


// 카메라 관측 변경
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:		left += 1.0; break;
	case GLUT_KEY_RIGHT:	left -= 1.0; break;
	case GLUT_KEY_DOWN:		bottom += 1.0; break;
	case GLUT_KEY_UP:		bottom -= 1.0; break;
	case GLUT_KEY_ALT_L:	ez -= 10.0; break;
	case GLUT_KEY_CTRL_L:	ez += 10.0; break;
	default:	break;
	}
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Draw Points by Mouse Input");
	glutDisplayFunc(RenderScene);
	glutMouseFunc(mouse1);
	glutMotionFunc(motion);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
}