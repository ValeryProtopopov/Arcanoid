#pragma once
#include <glut.h>
#include <math.h>
#include "Brick.h"

class Ball {
public:
	float x, y, direction_x, direction_y, radius;
	bool active, dead;
	int life;
	Ball(float radius_);
	~Ball();
	void Draw();
	void Update();
	void Move(float player_x, float player_y, float player_width, float player_height);

	bool isCollision(Brick &brick);
	void Collision(Brick &brick);
};