#include <iostream>
#include <glut.h>
using namespace std;

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Initialize() {
	glClearColor(0.8, 1.0, 0.6, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0, 200.0, -200.0, 200.0, -5.0, 5.0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("Arkanoid");
	glutDisplayFunc(Display);
	Initialize();
	glutMainLoop();

	return 0;
}