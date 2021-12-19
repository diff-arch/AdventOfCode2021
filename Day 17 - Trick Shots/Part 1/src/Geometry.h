//
//  Geometry.h
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 1)
//
//  Created by diff-arch on 17/12/2021.
//

#ifndef Geometry_h
#define Geometry_h

#include <iostream>


struct Vector2d;


struct Point2d {

	Point2d();
	Point2d(int _x, int _y);
	~Point2d();
	
	friend std::ostream& operator <<(std::ostream& os, const Point2d& p);
	void operator +=(const Vector2d& v);
	
	int x, y;

};


struct Vector2d {

	Vector2d();
	Vector2d(int _x, int _y);
	~Vector2d();
	
	friend std::ostream& operator <<(std::ostream& os, const Vector2d& v);
	
	int x, y;

};


#endif