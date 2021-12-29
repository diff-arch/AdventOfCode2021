//
//  Scanner.cpp
//  ADVENT OF CODE 2021: Day 19 - Beacon Scanner (Part 2)
//
//  Created by diff-arch on 29/12/2021.
//

#include "Scanner.h"


Scanner::Scanner(int _id) 
: sid(_id) { }
	
Scanner::~Scanner() = default;


void Scanner::addBeacon(const std::string& coordinates) {
	std::vector<std::string> xyz = split(coordinates, ",");
	beacons.emplace_back(
		std::stoi(xyz[0]), 
		std::stoi(xyz[1]), 
		std::stoi(xyz[2])
	);
}

std::vector<Point3d> Scanner::getRotatedBeacons(int rindex) const {
	std::vector<Point3d> rbeacons;
	rbeacons.reserve(beacons.size());
	for (const Point3d& b : beacons) {
		rbeacons.emplace_back(b.getRotation(rindex));
	}
	return rbeacons;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Scanner& s) {
	os << "Scanner[" << s.sid <<  "]{\n";
	for (int i = 0; i < s.beacons.size(); i++) {
		if (i - 1 < s.beacons.size() - 1)
			os << ",\n";
		os << " " << s.beacons[i];
	}
	return os << "\n}";
}