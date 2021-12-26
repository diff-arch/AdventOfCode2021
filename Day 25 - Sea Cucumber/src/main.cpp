//
//  main.cpp
//  ADVENT OF CODE 2021: Day 25 - Sea Cucumber (Part 1)
//
//  Created by diff-arch on 26/12/2021.
//
//  Goal:    Find somewhere safe to land your submarine. 
//           What is the first step on which no sea cucumbers move?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

#include "Utils.h"


void printFloor(std::map<std::tuple<int, int>, char>& seafloor, const int width, const int height) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::tuple<int, int> yx = std::make_tuple(y, x);
			if (seafloor.contains(yx))
				std::cout << seafloor[yx];
			else
				std::cout << '.';
		}
		std::cout << "\n";
	}
}


int main() {
    
	const char* fpath = "../bin/data/sea-cucumber.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	const int kWidth = lines[0].length();
	const int kHeight = lines.size();

	std::map<std::tuple<int, int>, char> seafloor;
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i].length(); j++) {
			char c = lines[i][j];
			if (c == '.')
				continue;
			else if (c == '>' || c == 'v')
				seafloor.emplace(std::make_tuple(i, j), c);
		}
	}
	
	bool moved = true;
	int steps = 0;
	
	while (moved) {
		// printFloor(seafloor, kWidth, kHeight);
		
		moved = false;
		std::map<std::tuple<int, int>, char> next_floor;
		
		for (auto& [yx, c] : seafloor) {
			auto [y, x] = yx;
			if (c == 'v' || seafloor.contains(std::make_tuple(y, (x + 1) % kWidth))) {
				next_floor.insert_or_assign(std::make_tuple(y, x), c);
			} else {
				next_floor.insert_or_assign(std::make_tuple(y, (x + 1) % kWidth), c);  // move east
				moved = true;
			} 
		}
		
		seafloor = next_floor;
		next_floor.clear();
		
		for (auto& [yx, c] : seafloor) {
			auto [y, x] = yx;
			if (c == '>' || seafloor.contains(std::make_tuple((y + 1) % kHeight, x))) {
				next_floor.insert_or_assign(std::make_tuple(y, x), c);
			} else {
				next_floor.insert_or_assign(std::make_tuple((y + 1) % kHeight, x), c);  // move south
				moved = true;
			}
		}
		
		seafloor = next_floor;
		steps++;
	
	}
	
	std::cout << "First Step With No Movement: " << steps << "\n";
	
}
