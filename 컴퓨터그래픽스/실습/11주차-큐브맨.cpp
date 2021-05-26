//#include <glut.h> 
//#include <stdio.h>
//#include <math.h>
//
//#define PI 3.1415926
//float theta = 0.5;
//float phi = 0.3;
//float radius = 2.0;
//float x, y, z;
//
//GLfloat vertices[][3] = {
//{ -1.0, -1.0, 1.0 }, // 0 
//{ -1.0, 1.0, 1.0 }, // 1
//{ 1.0, 1.0, 1.0 }, // 2
//{ 1.0, -1.0, 1.0 }, // 3
//{ -1.0, -1.0, -1.0 }, // 4
//{ -1.0, 1.0, -1.0 }, // 5
//{ 1.0, 1.0, -1.0 }, // 6
//{ 1.0, -1.0, -1.0 }  // 7
//};
//
//GLfloat colors[][3] = {
//{ 1.0, 1.0, 0.0 }, // yellow
//{ 1.0, 1.0, 1.0 }, // white
//{ 1.0, 0.0, 1.0 }, // magenta
//{ 1.0, 0.0, 0.0 }, // red
//{ 0.0, 0.0, 1.0 }, // blue
//{ 0.0, 1.0, 0.0 }  // green
//}; 
//
//void polygon(int a, int b, int c, int d) {
//	glColor3fv(colors[a]);
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[a]);
//	glVertex3fv(vertices[b]);
//	glVertex3fv(vertices[c]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void cube(void) {
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(3, 0, 4, 7);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(1, 2, 6, 5);
//	polygon(5, 4, 0, 1);
//}
//
//void init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//		
//	glColor3f(1.0, 1.0, 0.0);
//	radius = 10.0;
//	theta = 0.0;
//	phi = 0.0;
//	glEnable(GL_DEPTH_TEST);
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-5.0, 5.0, -5.0, 5.0, 0.1, 20.0);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	x = radius * cos(theta) * cos(phi);
//	y = radius * sin(theta) * cos(phi);
//	z = radius * sin(phi);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(x, y, z, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0); // x축 
//	glVertex3f(0.0, 0.0, 0.0);
//	glVertex3f(10.0, 0.0, 0.0);
//	glColor3f(0.0, 1.0, 0.0); // y축 
//	glVertex3f(0.0, 0.0, 0.0);
//	glVertex3f(0.0, 10.0, 0.0);
//	glColor3f(0.0, 0.0, 1.0); // z축 
//	glVertex3f(0.0, 0.0, 0.0);
//	glVertex3f(0.0, 0.0, 10.0);
//	glEnd();
//	glTranslatef(0.0, 0.0, 1.0);
//	cube(); //Torso
//
//
//	glPushMatrix(); // Head
//	glTranslatef(0.0, 0.0, 1.8);
//	glScalef(0.7, 0.7, 0.7);
//	cube();
//
//
//	glPopMatrix();
//
//
//	glPushMatrix(); // Right Arm
//	glTranslatef(0.0, 1.9, 1.5);
//	glRotatef(60.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//	glPushMatrix(); // Right Lower Arm
//	glTranslatef(0.0, 2.2, 0.0);
//	cube();
//
//
//	glPopMatrix();
//	glPopMatrix();
//
//	 
//	glPushMatrix(); // Left Arm
//	glTranslatef(0.0, -1.6, 0.0);
//	glRotatef(-20.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.5, 0.4);
//	cube();
//
//	glPushMatrix(); // Right Lower Arm
//	glTranslatef(0.0, -2.2, 0.0);
//	cube();
//
//
//	glPopMatrix();
//	glPopMatrix();
//
//
//	glPushMatrix(); // Upper Right Right Leg
//	glTranslatef(0.0, 1.0, -2.0);
//	glRotatef(-70.0f, 1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//
//	glPopMatrix();
//
//
//	glPushMatrix(); // Lower Right Leg
//	glTranslatef(0.0, 1.7, -0.5);
//	glRotatef(-25.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//	glPopMatrix();
//
//	glPushMatrix(); // Lower Right foot
//	glTranslatef(0.0, 3.0, -0.5);
//	glRotatef(-90.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//
//	glPopMatrix();
//	glPopMatrix();
//
//
//	glPushMatrix(); // Left Right Right Leg
//	glTranslatef(0.0, -1.0, -2.0);
//	glRotatef(30.0f, 1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//
//	glPopMatrix();
//
//
//	glPushMatrix(); // Left Lower Leg
//	glTranslatef(0.0, -1.7, -0.5);
//	glRotatef(25.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//
//	glPopMatrix();
//
//	glPushMatrix(); // Left Lower foot
//	glTranslatef(0.0, -3.2, -0.5);
//	glRotatef(115.0f, 1.0, 0.0, 0.0);
//	glScalef(0.4, 0.8, 0.4);
//	cube();
//
//	glPopMatrix();
//	glPopMatrix(); 
//
//
//	glFlush();
//	glutSwapBuffers();
//}
//void special_key(int key, int x, int y)
//{
//	switch (key) {
//	case GLUT_KEY_LEFT: theta += 0.01;
//		break;
//	case GLUT_KEY_RIGHT: theta -= 0.01;
//		break;
//	case GLUT_KEY_UP: phi += 0.01;
//		break;
//	case GLUT_KEY_DOWN: phi -= 0.01;
//		break;
//	default: break;
//	}
//	glutPostRedisplay();
//}
//
//void Mykey(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 'a': radius += 0.1; break;
//	case 's': radius -= 0.1; break;
//	default: break;
//	}
//	glutPostRedisplay();
//}
//
//void main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("이얏호오~!");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutSpecialFunc(special_key);
//	glutKeyboardFunc(Mykey);
//	glutIdleFunc(display);
//	glutMainLoop();
//}