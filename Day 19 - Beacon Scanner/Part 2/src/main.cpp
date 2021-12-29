//
//  main.cpp
//  ADVENT OF CODE 2021: Day 19 - Beacon Scanner (Part 2)
//
//  Created by diff-arch on 29/12/2021.
//
//  Goal:    What is the largest Manhattan distance between any two scanners?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "Scanner.h"
#include "Point3d.h"
#include "Utils.h"


int main() {
	
	const char* filename = "../bin/data/beacon-scanner.txt";  // insert your path
	std::vector<std::string> lines = readData(filename);
	
	std::vector<Scanner> scanners;
	int si = 0;
	for (const auto& line : lines) {
		if (line.substr(0, 2) == "--") {
			scanners.emplace_back(si);
			si++;
			continue;
		}
		scanners[scanners.size()-1].addBeacon(line);
	}
	
	const int kRotations = 24;
	const bool kDebug = false;
	
	std::set<Point3d> ref_beacons;
	for (const Point3d& beacon : scanners[0].beacons)
		ref_beacons.insert(beacon);
	
	std::vector<Scanner> targets(scanners.begin() + 1, scanners.end());
	std::vector<Point3d> scanner_matches;  // beacons identified as scanners
		
	int ti = 0;
	
	while (!targets.empty()) {
		Scanner target = targets[ti];
		if (kDebug) std::cout << "Looking for match for: " << target.sid << "\n";
		
		for (int rotation = 0; rotation < kRotations; rotation++) {
			std::vector<Point3d> target_rbeacons = target.getRotatedBeacons(rotation);		
			std::vector<Point3d> diffs;

			for (const Point3d ref_beacon : ref_beacons) {
				for (const Point3d target_beacon : target_rbeacons) {
					diffs.emplace_back(ref_beacon - target_beacon);
				}
			}
		
			std::vector< std::pair< Point3d, std::vector<Point3d> > > grouped;
			for (auto [pt, group] : groupBy(diffs)) {
				if (group.size() >= 12)
					grouped.emplace_back(pt, group);
			}
		
			if (grouped.empty())
				continue;
			if (grouped.size() > 1)
				throw std::runtime_error("Multiple overlapping matches found!");
			Point3d scanner_match = grouped[0].second[0];
			if (kDebug) std::cout << "Found match for: " << target.sid << "\n";
			
			for (const Point3d& target_rbeacon : target_rbeacons) {
				ref_beacons.insert(target_rbeacon + scanner_match);
			}
			
			scanner_matches.emplace_back(scanner_match);
			targets.erase(targets.begin()+ti);
			ti--;
			break;
		}
		
		ti++;
		if (ti == targets.size())
			ti = 0;
	}
	
	int max_distance = 0;
	for (int i = 0; i < scanner_matches.size(); i++) {
		for (int j = i + 1; j < scanner_matches.size(); j++) {
			int dist = scanner_matches[i].manhattanDistanceTo(scanner_matches[j]);
			if (dist > max_distance)
				max_distance = dist;
		}
	}
	
	std::cout << "Largest Manhattan Distance Between 2 Scanners: " << max_distance << "\n";

}
