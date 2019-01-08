#pragma once 
#include<glut.h>

class Brick {
public:
	bool active;
	short row, col, hit;
	float width, height;
	int range;
	Brick();
	Brick(short row_, short col_, float width_, float height_, short hit_);
	~Brick();

	void Draw(Brick &b);
	void Update();
};