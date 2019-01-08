#include "Player.h"

Player::Player() {
	x = 210.0;
	y = 550.0;
	width = 100.0;
	height = 10.0;
	score = 0;
	live = 3;
}

Player::~Player() {

}

void Player::FollowMouse(int ax, int ay) {
	x = ax - width / 2;
}

void Player::Draw() {
	glColor3f(0.2, 0.8, 0.1);
	glRectf(x, y, x + width, y + height);
}

void Player::Update() {
	Draw();
}