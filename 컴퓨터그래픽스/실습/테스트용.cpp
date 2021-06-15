#include <GLUT.h>

static int Day = 0, Time = 0;

// ȭ���� ��¥�� �ð�
static int MDay = 0, MTime = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT
        | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW); // ���� matrix�� �����ϴ� ���

    /***����***/
    glLoadIdentity(); // ���� ��ǥ�� �ʱ�ȭ
    glTranslatef(0.0, 0.0, -2.0);
    glPushMatrix(); // ������ ǥ���ϴ� ���� ��ǥ�� �߰�
    //�����ǰ���
    glRotatef((float)Day, 0.0, 0.0, 1.0);
    glTranslatef(0.7, 0.0, 0.0);
    //����������
    glRotatef((float)Time, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0); // �Ķ�
    glutSolidSphere(0.1, 30, 8);

    /***��***/
    glPushMatrix(); // ���� ǥ���ϴ� ���� ��ǥ�� �߰�
    //���ǰ���
    glRotatef((float)Day, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0); // �ʷ�
    glutSolidSphere(0.04, 30, 8);

    glPopMatrix(); // ������ �� ���� ���� ��ǥ�踦 ���� ��
    glPopMatrix(); // ������ �� ������ ���� ��ǥ�踦 ���� ��

    /***ȭ��***/
    glPushMatrix(); // ȭ���� ǥ���ϴ� ���� ��ǥ�� �߰�
    //ȭ���ǰ���
    glRotatef((float)(MDay), 0.0, 0.0, 1.0); // ȭ���� ���� �ֱ�� �������� ��������� 2�� ������ ����
    glTranslatef(1.4, 0.0, 0.0);
    //ȭ��������
    glRotatef((float)(MTime), 0.0, 1.0, 0.0); // ȭ���� ����  �ֱ�� �������� ��������� 2�� ������ ����
    glColor3f(1.0, 0.0, 0.0); // ����
    glutSolidSphere(0.1, 30, 16); // ȭ���� ������ ũ��� �����ϰ� ����

    glPopMatrix(); // �����ص� ȭ���� ���� ��ǥ�踦 ���� ��

    /***�¾�***/
    glColor3f(1.0, 1.0, 0.0); // ���
    glutSolidSphere(0.2, 30, 16);


    glutSwapBuffers();
}

void MyTimer(int value) {
    Day = (Day + 10) % 360;
    Time = (Time + 15) % 360;

    MDay = (MDay + 5) % 360; // ȭ���� ���� �ֱ�� �������� ��������� 2�� ������ ����
    MTime = (MTime + 30) % 360; // ȭ���� ���� �ֱ�� �������� ��������� 2�� ������ ����

    glutTimerFunc(100, MyTimer, 1);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Solar system");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrtho�� view volume�� �����ϴ� �Լ�
    // �ΰ��� x, y, z�� ������ ǥ�� ��
    glOrtho(-3.0, 3.0, -3.0, 3.0, -2.0, 3.0); glutDisplayFunc(MyDisplay);
    glutTimerFunc(100, MyTimer, 1);
    glutMainLoop();
    return 0;
}