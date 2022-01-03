//
//  main.cpp
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 1)
//
//  Created by diff-arch on 22/12/2021.
//
//  Goal:    Execute the reboot steps. Afterward, considering only cubes in 
//           the region x=-50..50,y=-50..50,z=-50..50, how many cubes are on?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>

#include "Cuboid.h"
#include "Utils.h"


int main() {
    
	const char* fpath = "../bin/data/reactor-reboot.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	std::vector<Region> cuboids;
	cuboids.reserve(lines.size());
	
	std::regex pattern("(?:[xyz]=)(-*\\d+)(?:\\.{2,})(-*\\d+)");
	std::smatch matches;
	for (const std::string& line : lines) {
		std::vector<std::string> split_line = split(line);
		std::string state = split_line[0];
		
		std::vector<Interval> xyz_domains;
		xyz_domains.reserve(3);
		for (std::string s : split(split_line[1], ",")) {
			Interval d;
			if (std::regex_search(s, matches, pattern))
				d = {std::stoi(matches[1].str()), std::stoi(matches[2].str())};
			if (d.valid)
				xyz_domains.emplace_back(d);
		}
	
		cuboids.emplace_back(xyz_domains, (state == "on") ? true : false);
	}
	
	std::map<Cube, bool> cubes;
	for (const Region& r : cuboids) {
		for (int x = std::max(-50, r.dx.from); x <= std::min(50, r.dx.to); x++) {
			for (int y = std::max(-50, r.dy.from); y <= std::min(50, r.dy.to); y++) {
				for (int z = std::max(-50, r.dz.from); z <= std::min(50, r.dz.to); z++) {
					Cube c = {x, y, z};
					if (!cubes.contains(c)) {
						cubes.emplace(c, r.on);
					} else {
						if (cubes[c] != r.on)
							cubes[c] = r.on;
					}
				}
			}
		}
	}
	
	int on_count = 0;
	for (const auto& [cube, state] : cubes) {
		// std::cout << cube << ((state) ? ": On" : ": Off") << "\n";
		if (state)
			on_count++;
	}
	
	std::cout << "ON Cubes: " << on_count << "\n";
	
}
