//
//  Region.cpp
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 2)
//
//  Created by diff-arch on 31/12/2021.
//

#include "Region.h"


Interval::Interval(int _from, int _to)
  : from(_from), to(_to) { }

Interval::~Interval() = default;


//--------------------------------------------------------------



Region3d::Region3d(bool _on, int _x1, int _x2, int _y1, int _y2, int _z1, int _z2)
: on(_on), dx(_x1, _x2), dy(_y1, _y2), dz(_z1, _z2) { }

Region3d::~Region3d() = default;


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Interval& i) {
  return os << "(" << i.from << ", " << i.to << ")";
}


std::ostream& operator <<(std::ostream& os, const Region3d& r) {
	return os << ((r.on) ? "ON" : "OFF") << " Region(\n  "
		        << r.dx << ",\n  " << r.dy << ",\n  " << r.dz << "\n)";
}
