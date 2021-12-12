//
//  main.cpp
//  ADVENT OF CODE 2021: Day 11 - Dumbo Octopus (Part 2)
//
//  Created by diff-arch on 11/12/2021.
//
//  Goal:    What is the first step during which all octopuses flash? 
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
	
	int step = 0;
	while (true) {
		step++;
		g.update();
		if (g.allFlashed())
			break;
	}

	std::cout << "After All Octopi Flashed For the First Time at Step " << step << ":\n";
	std::cout << g << "\n\n";
	
}
