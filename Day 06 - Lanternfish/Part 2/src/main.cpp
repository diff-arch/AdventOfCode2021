//
//  main.cpp
//  ADVENT OF CODE 2021: Day 6 - Lanternfish (Part 2)
//  
//  Created by diff-arch on 06/12/2021.
//
//  Goal:    How many lanternfish would there be after 256 days?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include "Utils.h"


int main() {
	
	const char* fpath = "/Users/marc/Desktop/Advent of Code 2021/Day 6 - Lanternfish/Part 2/bin/data/lanternfish.txt";  // insert your path
	
	std::string line = readLine(fpath);
	std::vector<std::string> split_data = split(line, ",");
	
	std::map<unsigned long int, unsigned long int> school;
	unsigned int key;
	for (const std::string& d : split_data) {
		key = std::stoul(d);
		if (school.find(key) == school.end())
			school.emplace(key, 0);
		school[key]++;
	}

	const unsigned int days = 256;
	
	for (int i = 0; i < days; i++) {
		std::map<unsigned long int, unsigned long int> next_school;
		for (const auto& fish : school) {
			if (fish.first == 0) {
				next_school[6] += fish.second;
				next_school[8] += fish.second;
			} else {
				next_school[fish.first-1] += fish.second;
			}
		}
		school = next_school;
	}
	
	unsigned long int total_population = 0;
	for (const std::pair<unsigned long int, unsigned long int>& fish: school) {
		total_population += fish.second;
	}
		
	std::cout << "Total Population: " << total_population << "\n";
	
}
