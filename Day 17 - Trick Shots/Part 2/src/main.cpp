//
//  main.cpp
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 2)
//
//  Created by diff-arch on 17/12/2021.
//
//  Goal:    How many distinct initial velocity values cause the probe 
//           to be within the target area after any step?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Probe.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/trick-shots.txt";  // insert your path
	std::string line = readLine(fpath);
	
	const int offset = 13;
	std::string stripped_line = line.substr(offset, line.length() - offset);
	std::vector<std::string> split_line = split(stripped_line, ", ");
	
	std::map< char, Interval> target_area;
	for (const std::string s : split_line) {
		std::vector<std::string> range = split(s.substr(2, s.size() - 2), "..");
		target_area[s[0]] = {std::stoi(range[0]), std::stoi(range[1])};
	}

	Probe p;
	const int steps = 1000;
	
	int highest_y = 0;
	int distinct_vel_vals = 0;
	
	for (int x = 0; x <= target_area['x'].getMax(); x++) {
		for (int y = target_area['y'].getMin(); y <= 500; y++) {  // y-stop must be increased for even bigger examples
			p.setPosition(0, 0);
			p.setVelocity(x, y);
			
			bool hit = false;
			for (int s = 0; s < steps; s++) {
				p.step();
				
				if (target_area['x'].contains(p.position.x) && target_area['y'].contains(p.position.y))
					hit = true;
			}
			
			if (hit) {
				distinct_vel_vals++;
				if (p.max_y > highest_y)
					highest_y = p.max_y;
			}
	
		}
	}
	
	std::cout << "Distinct Initial Velocity Values: "<< distinct_vel_vals << "\n";
	
}
