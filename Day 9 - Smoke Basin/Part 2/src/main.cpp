//
//  main.cpp
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 2)
//
//  Created by diff-arch on 09/12/2021.
//
//  Goal:    Find the three largest basins and multiply their sizes together. 
//           What do you get if you multiply together the sizes of the three largest basins?
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
	// std::cout << g << "\n\n";
	
	std::vector<Node> low_nodes;
	for (const Node& n : g.nodes) {
		std::vector<Node> neighbours = g.getAdjacent(n);

		std::sort(neighbours.begin(), neighbours.end(), 
						  [](const Node& ni, const Node& nj) { return ni.value < nj.value; });

		if (n.value < neighbours[0].value)
			low_nodes.emplace_back(n);
	}

	std::vector< std::vector<Node> > basins;
	basins.reserve(low_nodes.size());
	
	for (const Node& n : low_nodes) {
		std::vector<Node> basin;
		g.getAdjacentUpToRec(n, 9, basin);
		std::cout << "Basin: ";
		for (int i = 0; i < basin.size(); i++) {
			if (i > 0)
				std::cout << ", ";
			std::cout << basin[i].value;
		}
		std::cout << "; Size: " << basin.size() << "\n";
		basins.emplace_back(basin);
	}
	
	std::sort(basins.begin(), basins.end(), 
	          [](const std::vector<Node>& vi, const std::vector<Node>& vj) 
							{ return vi.size() > vj.size(); });
	
	int basin_product = 1;
	for (int i = 0; i < 3; i++) {  // three largest only
		basin_product *= basins[i].size();
	}

	std::cout << "Three Largest Basins -> Size Product: " << basin_product << "\n";
	
}
