//
//  main.cpp
//  ADVENT OF CODE 2021: Day 11 - Dumbo Octopus (Part 1)
//
//  Created by diff-arch on 11/12/2021.
//
//  Goal:    Given the starting energy levels of the dumbo octopuses in your cavern, 
//           simulate 100 steps. How many total flashes are there after 100 steps?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Grid.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/dumbo-octopus.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	std::vector< std::vector<int> > rows_columns;
	rows_columns.reserve(lines.size());
	for (const std::string& line : lines) {
		std::vector<int> columns;
		columns.reserve(line.length());
		for (const char& c : line) {
			columns.emplace_back((int)c - (int)'0');
		}
		rows_columns.emplace_back(columns);
	}
	
	Grid g = {rows_columns};
	std::cout << "Before Any Steps:\n";
	std::cout << g << "\n\n";
	
	const unsigned int total_time = 100;
	
	for (int i = 0; i < total_time; i++) {
		g.update();
	}
	
	std::cout << "After Step " << total_time << ":\n";
	std::cout << g << "\n\n";
	
	std::cout << "Total Flashes: " << g.getFlashes() << "\n";
	
}
