//
//  Probe.h
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 1)
//
//  Created by diff-arch on 17/12/2021.
//

#ifndef Probe_h
#define Probe_h

#include <iostream>
#include <vector>

#include "Geometry.h"


struct Probe {
	
	Probe();
	Probe(Point2d _position, Vector2d _velocity);
	~Probe();
	
	friend std::ostream& operator <<(std::ostream& os, const Probe& p);
	
	void step();
	void setPosition(int x, int y);
	void setVelocity(int x, int y);
	
	Point2d position;
	Vector2d velocity;
	int max_y = 0;
	
};


#endif