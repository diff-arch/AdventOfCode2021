//
//  main.cpp
//  ADVENT OF CODE 2021: Day 8 - Seven Segment Search (Part 1)
//
//  Created by diff-arch on 08/12/2021.
//
//  Goal:    In the output values, how many times do digits 1, 4, 7, or 8 appear?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Utils.h"


int main() {
    
    const char* fpath = "../bin/data/seven-segment-search.txt";  // insert your path
		std::vector<std::string> lines = readData(fpath);
		
		std::map<int, int> digits = { {7, 8}, {3, 7}, {4, 4}, {2, 1}, };
		int count = 0;
		
		for (const std::string& ln : lines) {
			std::vector<std::string> split_line = split(ln, "|");
			std::vector<std::string> output_values = split(split_line[1]);
			
			for (const std::string& value : output_values) {
				if (digits.find(value.length()) != digits.end())
					count++;
			}
		}
		
		std::cout << "Occurances of 1, 4, 7, or 8: " << count << "\n";

}
