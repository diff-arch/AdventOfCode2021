//
//  main.cpp
//  ADVENT OF CODE 2021: Day 13 - Transparent Origami (Part 2)
//
//  Created by diff-arch on 13/12/2021.
//
//  Goal:    What code do you use to activate the infrared thermal imaging camera system?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <utility>

#include "Grid.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/transparent-origami.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	int max_row, max_column = 0;
	std::vector< std::pair<int, int> > coordinates;
	std::vector< std::pair<char, int> > fold_instructions;
	for (const std::string line : lines) {
		if (std::isdigit(line[0])){
			std::vector<std::string> split_line = split(line, ",");
			int x = std::stoi(split_line[0]);
			int y = std::stoi(split_line[1]);
			if (x > max_column)
				max_column = x;
			if (y > max_row)
				max_row = y;
			coordinates.emplace_back(x, y);
		} else {
			std::vector<std::string> split_line = split(line);
			std::vector<std::string> instruction = split(split_line.back(), "=");
			fold_instructions.emplace_back(instruction[0][0], std::stoi(instruction[1]));
		}	
	}
	
	Grid g = {max_row + 1, max_column + 1};
	for (const std::pair<int, int> coords : coordinates)
		g.toggleCell(coords.first, coords.second);
	std::cout << g << "\n\n";
	
	for (const std::pair<char, int>& fi : fold_instructions) {
		std::pair<Grid, Grid> temp_grids = g.split(fi.first, fi.second);
		
		switch (fi.first) {
			case 'x':
				temp_grids.second.flipVertical();
				break;
			case 'y':
				temp_grids.second.flipHorizontal();
				break;
			default:
				break;
		}
		
		g = temp_grids.first + temp_grids.second;
		std::cout << g << "\n\n";
	}
	
}
