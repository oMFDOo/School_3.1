#include <windows.h>
#include <gl/gl.h>
#include <glut.h>
#include <math.h>

#define	width 			400
#define	height			600
#define	PI				3.1415
#define	polygon_num		50

int		left = 0;
int		bottom = 0;

int		collision_count = 0;

float	radius1, moving_ball_radius;

typedef struct _Point {
	float	x;
	float	y;
} Point;

Point	fixed_ball, moving_ball, velocity;


void init(void) {
	radius1 = 20.0;
	fixed_ball.x = width / 2;
	fixed_ball.y = height / 2;

	moving_ball_radius = 10.0;
	moving_ball.x = width / 2;
	moving_ball.y = height / 4;

	velocity.x = 0.0;
	velocity.y = 0.05;

	collision_count = 1;
}


void MyReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, left + width, bottom, bottom + height); // mouse2()
}


void Modeling_Circle(float radius, Point CC) {
	float	delta;

	delta = 2 * PI / polygon_num;
	glBegin(GL_POLYGON);
	for (int i = 0; i < polygon_num; i++)
		glVertex2f(CC.x + radius * cos(delta * i), CC.y + radius * sin(delta * i));
	glEnd();
}

void Collision_Detection_Between_Balls(void) {
	float	distance;
	// ************** ����� �ڵ� 

	// �� ������ �Ÿ�
	distance = sqrt(pow(moving_ball.x - fixed_ball.x, 2.0) +
					pow(moving_ball.y - fixed_ball.y, 2.0));

	// �浹
	if (distance <= radius1 + moving_ball_radius) {
		velocity.y *= -1;
		velocity.x *= -1;
		collision_count++;
	}
}

void Collision_Detection_to_Walls(void) {

	// ************** ����� �ڵ� 

	// ������ �浹
	if (moving_ball.x + moving_ball_radius >= width + left) {
		velocity.x *= -1;
		collision_count++;
	}
	// ���� �浹
	if (moving_ball.x - moving_ball_radius <= left) {
		velocity.x *= -1;
		collision_count++;
	}
	// ���� �浹
	if (moving_ball.y + moving_ball_radius >= height + bottom) {
		velocity.y *= -1;
		collision_count++;
	}
	// �Ʒ��� �浹
	if (moving_ball.y - moving_ball_radius <= bottom) {
		velocity.y *= -1;
		collision_count++;
	}
}

void RenderScene(void) {

	glClearColor(1.0, 1.0, 0.0, 0.0); // Set display-window color to Yellow
	glClear(GL_COLOR_BUFFER_BIT);

	// ������ �߽��� ��ġ�� ������ �� �׸��� 
	glColor3f(1.0, 0.0, 0.0);
	if (collision_count % 2)
		Modeling_Circle(radius1, fixed_ball);

	// �浹 ó�� �κ�
	Collision_Detection_Between_Balls();		// ���� ���� �浹 �Լ� 
	Collision_Detection_to_Walls();			// ���� ���� �浹 �Լ� 

	// �����̴� ���� ��ġ ��ȭ 
	 moving_ball.x += velocity.x;
	 moving_ball.y += velocity.y;

	// �����̴� �� �׸��� 
	glColor3f(0.0, 0.0, 1.0);
	Modeling_Circle(moving_ball_radius, moving_ball);

	glutSwapBuffers();
	glFlush();
}


void main(int argc, char** argv) {
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(width, height);
	glutCreateWindow("Bouncing Ball & Wall");
	init();
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);
	glutMainLoop();
}