#include <glut.h>
#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include <string>

Player player;
Ball ball(10);
Brick brick[5][10];

std::string score = "Score: ";
std::string life = "Life: ";
std::string gameOver = "Game Over";

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (ball.dead) {
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(200, 400);
		for (int i = 0; i < gameOver.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)gameOver[i]);
		}
	}

	player.Draw();
	ball.Draw();
	
	glBegin(GL_QUADS);
	for (int i = 0; i < 5; i++) {
		glColor3ub(i*50, i*10, 160);
		for (int j = 0; j < 10; j++) {
			Brick &b = brick[i][j];
			if (b.active) {
				b.Draw(b);
			}
		}
	}
	glEnd();

	glRasterPos2i(10, 20);
	for (int i = 0; i < score.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)score[i]);
	}

	std::string sc = std::to_string(player.score);
	for (int i = 0; i < sc.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)sc[i]);
	}

	glRasterPos2i(425, 20);
	for (int i = 0; i < life.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)life[i]);
	}

	std::string lf = std::to_string(ball.life);
	for (int i = 0; i < sc.size(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)lf[i]);
	}

	glutSwapBuffers();
}

void Update(int) {
	if (!ball.dead) {
		if (ball.active) {
			ball.Move(player.x, player.y, player.width, player.height);
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 10; j++) {
					Brick &b = brick[i][j];
					if (ball.isCollision(b)) {
						ball.Collision(b);
						player.score++;
						goto o;
					}
				}
			}
		}
	o:	Draw();
		glutTimerFunc(33, Update, 0);
	}
}

void Init() {
	glClearColor(1.0, 0.8, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 500, 600, 0, 1, 0);
}

void MousePress(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && !ball.active) {
		ball.active = true;
	}
}

void Mouse(int x, int y) {
	player.FollowMouse(x, y);
	if (!ball.active) {
		ball.x = player.x + player.width / 2;
		ball.y = player.y - ball.radius;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 600);
	glutInitWindowPosition(710, 240);
	glutCreateWindow("Arkanoid");
	glutDisplayFunc(Draw);
	glutTimerFunc(33, Update, 0);
	glutPassiveMotionFunc(Mouse);
	glutMouseFunc(MousePress);
	Init();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			brick[i][j].active = true;
			brick[i][j].col = j;
			brick[i][j].row = i+1;
		}
	}

	glutMainLoop();
	return 0;
}