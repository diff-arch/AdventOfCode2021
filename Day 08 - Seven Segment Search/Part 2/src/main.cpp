//
//  main.cpp
//  ADVENT OF CODE 2021: Day 8 - Seven Segment Search (Part 2)
//
//  Created by diff-arch on 08/12/2021.
//
//  Goal:    For each entry, determine all of the wire/segment connections and decode the four-digit output values.
//           What do you get if you add up all of the output values?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/seven-segment-search.txt";  // insert your path
	
	std::vector<std::string> lines = readData(fpath);
	
	const std::string key_chars = "abcdefg";
	std::map<std::string, int> digit_keys = {
		{"abcefg" , 0},
		{"cf"     , 1},
		{"acdeg"  , 2},
		{"acdfg"  , 3},
		{"bcdf"   , 4},
		{"abdfg"  , 5},
		{"abdefg" , 6},
		{"acf"    , 7},
		{"abcdefg", 8},
		{"abcdfg" , 9},
	};
	
	std::vector<std::string> digits;
	digits.reserve(digit_keys.size());
	for (const std::pair<std::string, int>& dk : digit_keys)
		digits.emplace_back(dk.first);
	std::sort(digits.begin(), digits.end());
	
	std::vector<std::string> permutations = getPermutations(key_chars);
	
	int line_count = 0;
	int output_sum = 0;
	
	for (const std::string line : lines) {
		std::vector<std::string> split_line = split(line, "|");
		std::vector<std::string> unique_signal_patterns = split(split_line[0]);
		std::vector<std::string> digit_output_values = split(split_line[1]);
	
		std::vector<int> output_ints;
		output_ints.reserve(4);
	
		for (const std::string& p : permutations) {
			// Map key chars to matching permutation chars
			std::map<char, char> keys;
			for (const char& c : key_chars) {
				keys[c] = p[key_chars.find(c)];
			}
			
			// Compile the new signal patterns
			std::vector<std::string> new_patterns;
			new_patterns.reserve(unique_signal_patterns.size());

			for (const std::string& signal_pattern : unique_signal_patterns) {
				std::string pattern;
				for (const char& c : signal_pattern)
					pattern += keys[c];
				std::sort(pattern.begin(), pattern.end());
				new_patterns.emplace_back(pattern);
			}
		
			std::sort(new_patterns.begin(), new_patterns.end());
			
			// Decode the digit output values
			if (new_patterns == digits) {
				for (const std::string digit_value : digit_output_values) {
					std::string decoded_value;
					for (const char& c : digit_value)
						decoded_value += keys[c];
					std::sort(decoded_value.begin(), decoded_value.end());
					output_ints.emplace_back(digit_keys[decoded_value]);
				}
			}
		
		}
		
		int output_num = toInteger(output_ints);
		output_sum += output_num;
		line_count++;

		std::cout << "Line " << line_count << " Output Value: " << output_num << "\n"; 

	}
	
	std::cout << "Total: " << output_sum << "\n";

}
