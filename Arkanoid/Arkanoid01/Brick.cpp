#include "Brick.h"

Brick::Brick() {
	width = 50;
	height = 50;
	hit = 1;
	active = false;
	range = 1;
}

Brick::Brick(short row_, short col_, float width_, float height_, short hit_){
	row = row_;
	col = col_;
	width = width_;
	height = height_;
	hit = hit_;
	active = false;
}

Brick::~Brick() {

}

void Brick::Draw(Brick &b) {
	
	glVertex2f(b.col * b.width + range, b.row * b.height + range);
	glVertex2f(b.col * b.width + b.width - range, b.row * b.height + range);
	glVertex2f(b.col * b.width + b.width - range, b.row * b.height + b.height - range);
	glVertex2f(b.col * b.width + range, b.row * b.height + b.height - range);
}
void Brick::Update() {

}