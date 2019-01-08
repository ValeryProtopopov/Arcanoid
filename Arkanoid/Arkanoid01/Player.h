#pragma once
#include <glut.h>

class Player {
public:
	float x, y, width, height;
	int score, live;
	Player();
	~Player();
	void FollowMouse(int x, int y);
	void Draw();
	void Update();
};