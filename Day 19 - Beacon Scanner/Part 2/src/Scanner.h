//
//  Scanner.h
//  ADVENT OF CODE 2021: Day 19 - Beacon Scanner (Part 2)
//
//  Created by diff-arch on 29/12/2021.
//

#ifndef Scanner_h
#define Scanner_h

#include <vector>
#include <string>
#include <cmath>

#include "Point3d.h"
#include "Utils.h"


struct Scanner {
	Scanner(int _id);
	~Scanner();
	
	friend std::ostream& operator <<(std::ostream& os, const Scanner& s);
	
	void addBeacon(const std::string& coordinates);
	std::vector<Point3d> getRotatedBeacons(int rindex) const;
	
	int sid;
	std::vector<Point3d> beacons;
};


#endif