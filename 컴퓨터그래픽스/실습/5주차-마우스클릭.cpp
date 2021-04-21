//#include <windows.h>
//#include <freeglut.h>
//#include <math.h>
//
//#define	width 			400
//#define	height			600
//#define	PI				3.1415
//#define	polygon_num		30
//
//enum      actions { MOVE_OBJECT, ROTATE_OBJECT, ZOOM_OBJECT, DO_NONE };
//GLsizei   action;
//GLsizei   xini = 0, yini = 0;
//GLfloat   xmov = 0.0, ymov = 0.0;
//double ez, xAngle, yAngle, zAngle;
//
//int		left = 0;
//int		bottom = 0;
//
//int		mouse_motion = 0;
//
//float	radius = 10.0;
//float	point[1000][2];
//int		point_num = 0;
//
//
//double Far = 100.0;
//double Near = 0.1;
//
//typedef struct _Point {
//	float	x;
//	float	y;
//} Point;
//
//Point	circle_center;
//
//void Modeling_Axis(void) {
//	glLineWidth(2.0);
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2i(0, 0);
//	glVertex2i(1.0 * width, 0);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex2f(0.0, 0.0);
//	glVertex2f(0.0, 1.0 * height);
//	glEnd();
//}
//
//void	Modeling_Circle(Point CC) {
//	float	delta;
//
//	glPointSize(3.0);
//	delta = 2 * PI / polygon_num;
//
//	glBegin(GL_POLYGON);
//	for (int i = 0; i < polygon_num; i++)
//		glVertex2f(CC.x + radius * cos(delta * i), CC.y + radius * sin(delta * i));
//	glEnd();
//}
//
////void drawSq() {
////	glBegin(GL_QUADS);
////	glVertex2f(-0.5f, -0.5f);
////	glVertex2f(0.5f, -0.5f);
////	glVertex2f(0.5f, 0.5f);
////	glVertex2f(-0.5f, 0.5f);
////	glEnd();
////	glFinish();
////}
//
//
//void	Modeling_Points_from_Screen(void) {
//	glPointSize(5.0);
//	glColor3f(0.0, 0.0, 0.0);
//
//	glBegin(GL_POINTS);
//	for (int k = 0; k < point_num; k++)
//		glVertex2f(point[k][0], point[k][1]);
//	glEnd();
//}
//
//void RenderScene(void) {
//
//	glClearColor(1.0, 1.0, 0.0, 0.0); // Set display-window color to Yellow
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	//���� ������ ��� �����ؾ� �ϴ°�?
//	gluOrtho2D(left, left + width, bottom, bottom + height);
//
//
//	Modeling_Axis(); // �� �׸��ⷡ!
//
//	// ���� ���������� �Էµ� ���� �߽����� �ϴ� �� �����ϱ�
//	Modeling_Circle(circle_center);
//
//	// ���콺 ���� ��ư Ŭ���� ���� ����� �� �����ϱ�
//	Modeling_Points_from_Screen();
//	glLoadIdentity();
//	glFlush();
//}
//
//// ����̽� ��ǥ�� ����
//void mouse1(int button, int state, int x, int y) {
//	Point pos;
//	pos.x = x;
//	pos.y = y;
//	circle_center.x = x;
//	circle_center.y = height - y;
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		// ���� ��ư�� ������ � ���� �����ؾ� �ϴ°�?
//		point[point_num][0] = x;
//		point[point_num][1] = height - y;
//		point_num++;
//		Modeling_Circle(pos);
//		Modeling_Points_from_Screen();
//		RenderScene();
//
//	}
//	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//		// ������ ��ư�� ������ � ���� �����ؾ� �ϴ°�?
//		glutInitWindowPosition(100, 100);
//		glutInitWindowSize(width, height);
//		glutDisplayFunc(RenderScene);
//
//	}
//	glutPostRedisplay();
//}
//
//void  motion(int x, int y)
//{
//	// this will only be true when the left button is down
//	if (action == MOVE_OBJECT) { // update dx, dy
//		xmov += (GLfloat)(x - xini) * 0.025f;
//		ymov += (GLfloat)(yini - y) * 0.025f;
//		Point pos;
//		pos.x = x;
//		pos.y = y;
//		circle_center.x = x;
//		circle_center.y = height - y;
//		Modeling_Circle(pos);
//		Modeling_Points_from_Screen();
//		RenderScene();
//	}
//
//	/* Update the stored mouse position for later use */
//	xini = x;
//	yini = y;
//
//
//
//	glutPostRedisplay();
//}
//
//
//// ī�޶� ���� ����
//void MySpecial(int key, int x, int y) {
//	switch (key) {
//	case GLUT_KEY_LEFT:		left += 1.0; break;
//	case GLUT_KEY_RIGHT:	left -= 1.0; break;
//	case GLUT_KEY_DOWN:		bottom += 1.0; break;
//	case GLUT_KEY_UP:		bottom -= 1.0; break;
//	case GLUT_KEY_ALT_L:	ez -= 10.0; break;
//	case GLUT_KEY_CTRL_L:	ez += 10.0; break;
//	default:	break;
//	}
//}
//
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(width, height);
//	glutCreateWindow("Draw Points by Mouse Input");
//	glutDisplayFunc(RenderScene);
//	//glutDisplayFunc(drawSq);
//	glutMouseFunc(mouse1);
//	glutMotionFunc(motion);
//	glutSpecialFunc(MySpecial);
//	glutMainLoop();
//}