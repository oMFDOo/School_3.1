//#include <freeglut.h>
//#include <math.h>
//
//#define radius 0.5
//#define startX 0.0
//#define startY 0.0
//#define polygonSize 80
//// polygonSize 변경을 통해 다각형의 각의 수 변경 가능
//
//
//void DrawGlTriangleFan() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glShadeModel(GL_FLAT);
//	glBegin(GL_TRIANGLE_FAN);
//
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2f(startX, startY);	// 초기 점
//
//	float delta = 2 * 3.14 / polygonSize;
//
//	for (int i = 0; i <= polygonSize; i++) {
//		if (i % 2) { glColor3f(1.0, 1.0, 0.0); }	// 색상변경
//		float x = startX + radius * cos(delta * i);	// x, y 좌표설정
//		float y = startY + radius * sin(delta * i);
//		glVertex2f(x, y);
//		glColor3f(1.0, 0.5, 0.5);
//	}
//
//	glEnd();
//	glFlush();
//
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutCreateWindow("20193148_황진주");
//	glutDisplayFunc(DrawGlTriangleFan);
//	glutMainLoop();
//}