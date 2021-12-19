//
//  Geometry.cpp
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 1)
//
//  Created by diff-arch on 17/12/2021.
//

#include "Geometry.h"


Point2d::Point2d() {}

Point2d::Point2d(int _x, int _y)
: x(_x), y(_y) {}

Point2d::~Point2d() = default;


void Point2d::operator +=(const Vector2d& v) {
	x += v.x;
	y += v.y;
}


//--------------------------------------------------------------


Vector2d::Vector2d() {}

Vector2d::Vector2d(int _x, int _y)
: x(_x), y(_y) {}

Vector2d::~Vector2d() = default;


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Point2d& p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

std::ostream& operator <<(std::ostream& os, const Vector2d& v) {
	return os << "(" << v.x << ", " << v.y << ")";
}