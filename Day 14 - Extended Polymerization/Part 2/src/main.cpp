//
//  main.cpp
//  ADVENT OF CODE 2021: Day 14 - Extended Polymerization (Part 2)
//
//  Created by diff-arch on 14/12/2021.
//
//  Inspired by Jonathan Paulson Pythonic solution that can be found here:
//  https://github.com/jonathanpaulson/AdventOfCode/blob/master/2021/14.py
//
//  Goal:    Apply 40 steps of pair insertion to the polymer template and 
//           find the most and least common elements in the result. 
//           What do you get if you take the quantity of the most common element 
//           and subtract the quantity of the least common element?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>

#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/extended-polymerization.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	std::string polymer_template = lines[0];
	std::map<std::string, char> insertion_rules;
	
	for (int i = 1; i < lines.size(); i++) {
		std::vector<std::string> split_line = split(lines[i], " -> ");
		insertion_rules.emplace(split_line[0], split_line[1][0]);
	}
	
	std::map<std::string, long int> polymer_counter;
	for (int i = 0; i < polymer_template.size() - 1; i++)
		polymer_counter[{polymer_template[i], polymer_template[i+1]}] += 1;
	
	const int steps = 40;
	
	for (int i = 0; i <= steps; i++) {
		
		if (i == steps) {
			std::map<char, long int> char_counter;
			for (const std::pair<std::string, char> p : polymer_counter)
				char_counter[p.first[0]] += polymer_counter[p.first];
			char_counter[polymer_template.back()] += 1;
			
			std::vector<long int> counts;
			counts.reserve(char_counter.size());
			for (const std::pair<char, long int>& p : char_counter)
				counts.push_back(p.second);
			
			std::sort(counts.begin(), counts.end());
			long int diff = counts.back() - counts[0];
			std::cout << counts.back() << " - " << counts[0] << " = " << diff << "\n";
		}
		
		std::map<std::string, long int> curr_counter;
		for (const std::pair<std::string, char> p : polymer_counter) {
			curr_counter[{p.first[0], insertion_rules[p.first]}] += polymer_counter[p.first];
			curr_counter[{insertion_rules[p.first], p.first.back()}] += polymer_counter[p.first];
		}
			
		polymer_counter = curr_counter;
	}
	
}
