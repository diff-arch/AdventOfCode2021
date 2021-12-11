//
//  main.cpp
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 1)
//
//  Created by diff-arch on 09/12/2021.
//
//  Goal:    Find all of the low points on your heightmap. 
//           What is the sum of the risk levels of all low points on your heightmap?
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
    
  const char* fpath = "../bin/data/smoke-basin.txt";  // insert your path
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
	std::cout << g << "\n\n";
	
	std::vector<int> low_nodes;
	for (int i = 0; i < g.getSize(); i++) {
		std::vector<int> neighbours = g.getAdjacent(i);
		std::sort(neighbours.begin(), neighbours.end());
		int current = g.nodes[i];
		if (current < neighbours[0])
			low_nodes.emplace_back(current);
	}

	std::cout << "Low Nodes: ";
	int risk_level = 0;
	for (int i = 0; i < low_nodes.size(); i++) {
		risk_level += low_nodes[i] + 1;
		if (i > 0)
			std::cout << ", ";
		std::cout << low_nodes[i];
		 
	}
	std::cout << " -> Risk Level: " << risk_level << "\n";	
	
}
