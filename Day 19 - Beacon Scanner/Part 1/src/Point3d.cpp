//
//  Point3d.cpp
//
//  ADVENT OF CODE 2021: Day 19 - Beacon Scanner (Part 1)
//
//  Created by diff-arch on 29/12/2021.
//

#include "Point3d.h"


Point3d::Point3d(int _x, int _y, int _z) 
: x(_x), y(_y), z(_z)	{ }

Point3d::~Point3d() = default;


bool Point3d::operator <(const Point3d& other) const {
	if (x == other.x) {
		if (y == other.y) {
			return z < other.z;
		}
		return y < other.y;
	}
	return x < other.x;
}

bool Point3d::operator ==(const Point3d& other) const {
	return (x == other.x && y == other.y && z == other.z);
}

Point3d Point3d::operator +(const Point3d& other) const {
	return {x + other.x, y + other.y, z + other.z};
}

Point3d Point3d::operator -(const Point3d& other) const {
	return {x - other.x, y - other.y, z - other.z};
}


Point3d Point3d::getRotation(int rindex) const {
	switch (rindex) {
		case 0:
			return Point3d( x,  y,  z);
		case 1:
			return Point3d(-x, -y,  z);
		case 2:
			return Point3d( x, -y, -z);
		case 3:
			return Point3d(-x,  y, -z);
		case 4:
			return Point3d(-x,  z,  y);
		case 5:
			return Point3d( x, -z,  y);
		case 6:
			return Point3d(-x, -z, -y);
		case 7:
			return Point3d( x,  z, -y);
		case 8:
			return Point3d(-y,  x,  z);
		case 9:
			return Point3d( y, -x,  z);
		case 10:
			return Point3d(-y, -x, -z);
		case 11:
			return Point3d( y,  x, -z);
		case 12:
			return Point3d( y,  z,  x);
		case 13:
			return Point3d(-y, -z,  x);
		case 14:
			return Point3d( y, -z, -x);
		case 15:
			return Point3d(-y,  z, -x);
		case 16:
			return Point3d( z,  x,  y);
		case 17:
			return Point3d(-z, -x,  y);
		case 18:
			return Point3d( z, -x, -y);
		case 19:
			return Point3d(-z,  x, -y);
		case 20:
			return Point3d(-z,  y,  x);
		case 21:
			return Point3d( z, -y,  x);
		case 22:
			return Point3d(-z, -y, -x);
		case 23:
			return Point3d( z,  y, -x);
		default:
			throw std::runtime_error("Rotation index out of bounds!");
	}
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Point3d& pt) {
	return os << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
}


std::map< Point3d, std::vector<Point3d> > groupBy(std::vector<Point3d> points) {
	std::map< Point3d, std::vector<Point3d> > point_groups;
	for (const Point3d& pt : points) {
		if (!point_groups.contains(pt))
			point_groups[pt] = {pt};
		else
			point_groups[pt].emplace_back(pt);
	}
	return point_groups;
}
