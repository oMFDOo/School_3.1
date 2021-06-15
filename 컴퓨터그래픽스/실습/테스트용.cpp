#include <GLUT.h>

static int Day = 0, Time = 0;

// 화성의 날짜와 시간
static int MDay = 0, MTime = 0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT
        | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW); // 모델의 matrix를 조작하는 모드

    /***지구***/
    glLoadIdentity(); // 전역 좌표계 초기화
    glTranslatef(0.0, 0.0, -2.0);
    glPushMatrix(); // 지구을 표현하는 지역 좌표계 추가
    //지구의공전
    glRotatef((float)Day, 0.0, 0.0, 1.0);
    glTranslatef(0.7, 0.0, 0.0);
    //지구의자전
    glRotatef((float)Time, 0.0, 0.0, 1.0);
    glColor3f(0.0, 0.0, 1.0); // 파랑
    glutSolidSphere(0.1, 30, 8);

    /***달***/
    glPushMatrix(); // 달을 표현하는 지역 좌표계 추가
    //달의공전
    glRotatef((float)Day, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0); // 초록
    glutSolidSphere(0.04, 30, 8);

    glPopMatrix(); // 저장해 둔 달의 지역 좌표계를 제거 함
    glPopMatrix(); // 저장해 둔 지구의 지역 좌표계를 제거 함

    /***화성***/
    glPushMatrix(); // 화성을 표현하는 지역 좌표계 추가
    //화성의공전
    glRotatef((float)(MDay), 0.0, 0.0, 1.0); // 화성의 공전 주기는 지구보다 상대적으로 2배 느리게 설정
    glTranslatef(1.4, 0.0, 0.0);
    //화성의자전
    glRotatef((float)(MTime), 0.0, 1.0, 0.0); // 화성의 자전  주기는 지구보다 상대적으로 2배 빠르게 설정
    glColor3f(1.0, 0.0, 0.0); // 빨강
    glutSolidSphere(0.1, 30, 16); // 화성과 지구의 크기는 동일하게 설정

    glPopMatrix(); // 저장해둔 화성의 지역 좌표계를 제거 함

    /***태양***/
    glColor3f(1.0, 1.0, 0.0); // 노랑
    glutSolidSphere(0.2, 30, 16);


    glutSwapBuffers();
}

void MyTimer(int value) {
    Day = (Day + 10) % 360;
    Time = (Time + 15) % 360;

    MDay = (MDay + 5) % 360; // 화성의 공전 주기는 지구보다 상대적으로 2배 느리게 설정
    MTime = (MTime + 30) % 360; // 화성의 자전 주기는 지구보다 상대적으로 2배 빠르게 설정

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

    // glOrtho는 view volume을 설정하는 함수
    // 두개씩 x, y, z의 범위를 표현 함
    glOrtho(-3.0, 3.0, -3.0, 3.0, -2.0, 3.0); glutDisplayFunc(MyDisplay);
    glutTimerFunc(100, MyTimer, 1);
    glutMainLoop();
    return 0;
}