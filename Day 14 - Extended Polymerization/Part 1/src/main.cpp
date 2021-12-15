//
//  main.cpp
//  ADVENT OF CODE 2021: Day 14 - Extended Polymerization (Part 1)
//
//  Created by diff-arch on 14/12/2021.
//
//  Goal:    Apply 10 steps of pair insertion to the polymer template
//           and find the most and least common elements in the result. 
//           What do you get if you take the quantity of the most common element 
//           and subtract the quantity of the least common element?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <limits>
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
	
	std::cout << "Template    : " << polymer_template << "\n";
	
	int steps = 10;
	int init_steps = steps;
	
	while (steps > 0) {
		std::string mod_template;
		mod_template.reserve(polymer_template.length() + polymer_template.length() - 1);
		mod_template.push_back(polymer_template.front());
		
		for (int i = 0; i < polymer_template.size() - 1; i++) {
			std::string rule = polymer_template.substr(i, 2);
			rule[0] = insertion_rules[rule];
			mod_template += rule;
		}
		
		polymer_template = mod_template;
		steps--;
		
		std::cout << "After Step " << init_steps - steps << ": " << mod_template << "\n";
	}
	std::cout << "\n";
	
	std::map<char, int> frequencies;
	for (char c : polymer_template)
		frequencies[c] += 1;
	
	int max_count = 0;
	int min_count = std::numeric_limits<int>::max();
	for (const std::pair<char, int>& p : frequencies) {
		if (p.second > max_count)
			max_count = p.second;
		if (p.second < min_count)
			min_count = p.second;
	}
	
	int difference = max_count - min_count;
	std::cout << max_count << " - " << min_count << " = " << difference << "\n";
	
}
