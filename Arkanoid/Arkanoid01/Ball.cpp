#include "Ball.h"
#include <cmath>

Ball::Ball(float radius_) {
	radius = radius_;
	active = false;
	direction_x = 7;
	direction_y = 7;
	life = 3;
	dead = false;
}

Ball::~Ball() {

}

void Ball::Draw() {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * 3.14; i += 3.14 / 4) {
		glVertex2f(x + radius * sin(i), y + radius * cos(i));
	}
	glEnd();
}

void Ball::Update() {

}

void Ball::Move(float player_x, float player_y, float player_width, float player_height) {
	x += direction_x;
	y += direction_y;

	if (x - radius <= 0) {
		x = radius;
		direction_x *= -1;
	}
	else if (y - radius <= 0) {
		y = radius;
		direction_y *= -1;
	}
	else if (x + radius >= 500) {
		x = 500 - radius;
		direction_x *= -1;
	}
	else if (y + radius >= player_y && y + radius <= player_y + player_height && x > player_x && x < player_x + player_width)
	{
		y = player_y - radius;
		direction_y *= -1;
	}
	else if (y + radius >= 600) {
		active = false;
		life--;
		if (life <= 0)
			dead = true;
	}
}

bool Ball::isCollision(Brick &brick) {
	float col = brick.col, row = brick.row, w = brick.width, h = brick.height;
	if (brick.active) {
		
		if (abs(x - col * w - w / 2 - 2) <= radius + w / 2 && abs(y - row * h - h / 2 - 2) <= radius + h / 2) {
			if (sqrt((col * w + w / 2 - x) * (col * w + w / 2 - x)
				+ (row * h + h / 2 - y) * (row * h + h / 2 - y))
				- (w / 2 - 1) * sqrt(2.0) - radius > radius * (sqrt(2.0) - 1))
				return 0;
			else
				return 1;
		}
	}
	return 0;
}

void Ball::Collision(Brick &brick) {
	float col = brick.col, row = brick.row, w = brick.width, h = brick.height;
	if (abs(x - col * w - w / 2) < abs(y - row * h - h / 2)) {
		direction_y *= -1;
	}
	else if (abs(x - col * w - w / 2) > abs(y - row * h - h / 2)) {
		direction_x *= -1;
	}
	else {
		if (direction_x > 0) {
			if (x < col * w + 1)
				direction_x *= -1;
		}
		else if (x > (col + 1) * w - 1)
			direction_x *= -1;

		if (direction_y > 0) {
			if (y < row*h + 1) 
				direction_y - 1;
		}
		else if (y > (row + 1)*h - 1) direction_y *= -1;
	}
	if (--brick.hit == 0) {
		brick.active = false;
	}
}