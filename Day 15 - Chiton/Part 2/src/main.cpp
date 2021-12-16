//
//  main.cpp
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 2)
//
//  Created by diff-arch on 15/12/2021.
//
//  Goal:    Using the full map, what is the lowest total risk of 
//           any path from the top left to the bottom right?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <utility>
#include <string>
#include <vector>

#include "Grid.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/chiton.txt";  // insert your path
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
	
	Grid g(rows_columns);	
	// std::cout << g << "\n\n";
	
	Grid sg = g.scale(5, 5);
	// std::cout << sg << "\n\n";
	
	int source = 0;
	int target = sg.cells.size() - 1;

	std::pair<std::map<int, int>, std::map<int, int>> dk = dijkstra(sg, source);
	std::vector<int> path = path_to(dk.second, source, target);

	int total_risk = 0;
	for (const int i : path) {
		if (i != source)
			total_risk += sg.cells[i];
	}

	std::cout << "Lowest Risk: " << total_risk << "\n";

}
