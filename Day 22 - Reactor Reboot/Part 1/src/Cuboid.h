//
//  Cuboid.h
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 1)
//
//  Created by diff-arch on 22/12/2021.
//

#ifndef Cuboid_h
#define Cuboid_h

#include <iostream>
#include <vector>

#include "Utils.h"


struct Cube {
	
	Cube();
	Cube(int _x, int _y, int _z);
	~Cube();
	
	friend std::ostream& operator <<(std::ostream& os, const Cube& c);
	bool operator <(const Cube& other) const;
	
	void toggle();
	
	int x, y, z;

};


struct Region {
	
	Region();
	Region(int _x1, int _x2, int _y1, int _y2, int _z1, int _z2, bool _on);
	Region(const Interval& _dx, const Interval& _dy, const Interval& _dz, bool _on);
	Region(const std::vector<Interval>& _xyz_domains, bool _on);
	~Region();
	
	friend std::ostream& operator <<(std::ostream& os, const Region& r);
	
	Interval dx, dy, dz;
	bool on;
	
};


#endif