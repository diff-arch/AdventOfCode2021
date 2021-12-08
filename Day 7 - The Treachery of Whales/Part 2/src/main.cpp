//
//  main.cpp
//  ADVENT OF CODE 2021: Day 7 - The Treachery of Whales (Part 2)
//  
//  Created by diff-arch on 07/12/2021.
//
//  Goal:    Determine the horizontal position that the crabs can align to 
//	         using the least fuel possible so they can make you an escape route! 
//           How much fuel must they spend to align to that position?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <cmath>
#include <limits>

#include "Utils.h"


int main() {
	
	const char* fpath = "../bin/data/treachery-of-whales.txt";  // insert your path

	std::string line = readLine(fpath);
	std::vector<std::string> split_line = split(line, ",");
	
	std::vector<int> crab_positions;
	crab_positions.reserve(split_line.size());
	for (const std::string& segment : split_line)
		crab_positions.emplace_back(std::stoi(segment));
	
	std::set<int> positions_set;
	for (int& p : crab_positions) {
		positions_set.insert(p);
	}
	
	std::vector<int> unique_positions;
	std::set<int>::iterator itr;
	unique_positions.reserve(positions_set.size());
	for (itr = positions_set.begin(); itr != positions_set.end(); itr++)
		unique_positions.emplace_back(*itr);
	
	std::vector<int> horizontal_positions;
	for (int i = unique_positions[0]; i <= unique_positions[unique_positions.size()-1]; i++)
		horizontal_positions.push_back(i);
		
	std::map< int, std::map<int, int> > distances_to;
	int distance;
	for (int i = 0; i < horizontal_positions.size(); i++) {
		for (int j = 0; j < unique_positions.size(); j++) {
			int steps = std::abs(unique_positions[j] - horizontal_positions[i]);
			distance = steps * (steps + 1) / 2;
			distances_to[horizontal_positions[i]].emplace(unique_positions[j], distance);
		}
	}

	int closest_distance = std::numeric_limits<int>::max();
	int closest_position;

	for (int& position : horizontal_positions) {
		distance = 0;
		for (int& crab : crab_positions) {
			distance += distances_to[position][crab];
		}
		if (distance < closest_distance) {
			closest_distance = distance;
			closest_position = position;
		}
	}

	std::cout << "Cheapest Position: " << closest_position << " -> Fuel Spent: " << closest_distance << "\n";

}
