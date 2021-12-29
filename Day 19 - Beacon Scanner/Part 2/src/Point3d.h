//
//  Point3d.h
//  ADVENT OF CODE 2021: Day 19 - Beacon Scanner (Part 2)
//
//  Created by diff-arch on 29/12/2021.
//

#ifndef Point3d_h
#define Point3d_h

#include <stdexcept>
#include <iostream>
#include <string>
#include <map>

#include "Utils.h"


struct Point3d {
	Point3d();
	Point3d(int _x, int _y, int _z);
	~Point3d();
	
	friend std::ostream& operator <<(std::ostream& os, const Point3d& pt);
	bool operator <(const Point3d& other) const;
	bool operator ==(const Point3d& other) const;
	Point3d operator +(const Point3d& other) const;
	Point3d operator -(const Point3d& other) const;
	
	Point3d getRotation(int rindex) const;
	int manhattanDistanceTo(const Point3d& other) const;
	
	int x, y, z;
};


std::map< Point3d, std::vector<Point3d> > groupBy(std::vector<Point3d> points);


#endif