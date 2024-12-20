#include <GL/glut.h>
#include <windows.h>
#include <math.h>

float xPos1 = -0.6f;
float yPos1 = 0.2f;

float xPos2 = -0.6f;
float yPos2 = -0.2f;

float xPos3 = 0.6f;
float yPos3 = 0.2f;

float xPos4 = 0.6f;
float yPos4 = -0.2f;

void drawObject(float x, float y) {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x - 0.2f, y - 0.2f);
    glVertex2f(x + 0.2f, y - 0.2f);
    glVertex2f(x + 0.2f, y + 0.2f);
    glVertex2f(x - 0.2f, y + 0.2f);
    glEnd();
}

void drawTriangle(float x, float y) {
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x, y + 0.2f);
    glVertex2f(x - 0.2f, y - 0.2f);
    glVertex2f(x + 0.2f, y - 0.2f);
    glEnd();
}

void drawCircle(float x, float y) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 15) {
        glVertex2f(x + 0.1f * cos(i * 3.14 / 180), y + 0.1f * sin(i * 3.14 / 180));
    }
    glEnd();
}

void drawEllipse(float x, float y) {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i <= 360; i += 15) {
        glVertex2f(x + 0.15f * cos(i * 3.14 / 180), y + 0.1f * sin(i * 3.14 / 180));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawObject(xPos1, yPos1);
    drawTriangle(xPos2, yPos2);
    drawCircle(xPos3, yPos3);
    drawEllipse(xPos4, yPos4);

    glutSwapBuffers();
}

void update(int value) {
    if (GetAsyncKeyState('W')) {
        yPos1 += 0.025f;
    }
    if (GetAsyncKeyState('A')) {
        xPos1 -= 0.025f;
    }
    if (GetAsyncKeyState('S')) {
        yPos1 -= 0.025f;
    }
    if (GetAsyncKeyState('D')) {
        xPos1 += 0.025f;
    }

    if (GetAsyncKeyState('I')) {
        yPos2 += 0.025f;
    }
    if (GetAsyncKeyState('J')) {
        xPos2 -= 0.025f;
    }
    if (GetAsyncKeyState('K')) {
        yPos2 -= 0.025f;
    }
    if (GetAsyncKeyState('L')) {
        xPos2 += 0.025f;
    }

    if (GetAsyncKeyState('T')) {
        yPos3 += 0.025f;
    }
    if (GetAsyncKeyState('F')) {
        xPos3 -= 0.025f;
    }
    if (GetAsyncKeyState('G')) {
        yPos3 -= 0.025f;
    }
    if (GetAsyncKeyState('H')) {
        xPos3 += 0.025f;
    }

    if (GetAsyncKeyState(VK_UP)) {
        yPos4 += 0.025f;
    }
    if (GetAsyncKeyState(VK_LEFT)) {
        xPos4 -= 0.025f;
    }
    if (GetAsyncKeyState(VK_DOWN)) {
        yPos4 -= 0.025f;
    }
    if (GetAsyncKeyState(VK_RIGHT)) {
        xPos4 += 0.025f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Move Objects with Keys");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();

    return 0;
}
