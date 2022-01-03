//
//  Cuboid.cpp
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 1)
//
//  Created by diff-arch on 22/12/2021.
//

#include "Cuboid.h"


Cube::Cube() {}
 
Cube::Cube(int _x, int _y, int _z)
: x(_x), y(_y), z(_z) { }

Cube::~Cube() = default;


bool Cube::operator <(const Cube& other) const {
	if (x == other.x) {
		if (y == other.y) {
			return z < other.z;
		}
		return y < other.y;
	}
	return x < other.x;
}


//--------------------------------------------------------------


Region::Region() {}

Region::Region(int _x1, int _x2, int _y1, int _y2, int _z1, int _z2, bool _on)
: dx(_x1, _x2), dy(_y1, _y2), dz(_z1, _z2), on(_on) { }

Region::Region(const Interval& _dx, const Interval& _dy, const Interval& _dz, bool _on)
: dx(_dx), dy(_dy), dz(_dz), on(_on) { }

Region::Region(const std::vector<Interval>& _xyz_domains, bool _on)
: dx(_xyz_domains[0]), dy(_xyz_domains[1]), dz(_xyz_domains[2]), on(_on) { }

Region::~Region() = default;


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Cube& c) {
	return os << "(" << c.x << ", " << c.y << ", " << c.z << ")";
}


std::ostream& operator <<(std::ostream& os, const Region& r) {
	return os << ((r.on) ? "ON" : "OFF") << " Region(\n  " 
		        << r.dx << ",\n  " << r.dy << ",\n  " << r.dz << "\n)";
}