//
//  Probe.cpp
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 2)
//
//  Created by diff-arch on 17/12/2021.
//

#include "Probe.h"


Probe::Probe()
: position({0, 0}), velocity({0, 0}), max_y(0) {}

Probe::Probe(Point2d _position, Vector2d _velocity)
: position(_position), velocity(_velocity), max_y(0) {}

Probe::~Probe() = default;


void Probe::step() {
	position += velocity;
	max_y = (position.y > max_y) ? position.y : max_y;
	// Drag
	if (velocity.x > 0)
		velocity.x--;
	else if (velocity.x < 0)
		velocity.x++;
	// Gravity
	velocity.y--;
}

void Probe::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
	max_y = 0;
}

void Probe::setVelocity(int x, int y) {
	velocity.x = x;
	velocity.y = y;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Probe& p) {
	return os << "Probe(\n" << "  position: " << p.position << ",\n"
		        << "  velocity: " << p.velocity << "\n)";
}
