//
//  Pixel.cpp
//  ADVENT OF CODE 2021: Day 20 - Trench Map (Part 1 & 2)
//
//  Created by diff-arch on 20/12/2021.
//

#include "Pixel.h"


Pixel::Pixel() {}

Pixel::Pixel(int _x, int _y)
: x(_x), y(_y) {}

Pixel::~Pixel() = default;


bool Pixel::operator <(const Pixel& other) const {
	if (x == other.x)
			return y < other.y;
	return x < other.x;
}

//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Pixel& p) {
	return os << "(" << p.x << ", " << p.y << ")";
}