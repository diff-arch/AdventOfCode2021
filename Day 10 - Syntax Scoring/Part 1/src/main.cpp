//
//  main.cpp
//  ADVENT OF CODE 2021: Day 10 - Syntax Scoring (Part 1)
//
//  Created by diff-arch on 10/12/2021.
//
//  Goal:    Find the first illegal character in each corrupted line of the navigation subsystem. 
//           What is the total syntax error score for those errors?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <deque>
#include <map>

#include "Utils.h"


int main() {
 
	const char* fpath = "../bin/data/syntax-scoring.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
 
	std::map<char, char> brackets {
		{'(', ')'},
		{'[', ']'},
		{'{', '}'},
		{'<', '>'},
	};
	
	std::map<char, char> rbrackets;
	for (const std::pair<char, char>& p : brackets)
		rbrackets.emplace(p.second, p.first);
	
	std::map<char, int> score_table = {
		{')', 3    },
		{']', 57   },
		{'}', 1197 },
		{'>', 25137},
	};
	
	int score = 0;
	for (const std::string& line : lines) {
		
		std::deque<char> dq;
		
		for (const char& c : line) {
			if (brackets.find(c) != brackets.end()) {
				dq.push_back(c);
			} else if (rbrackets.find(c) != rbrackets.end()) {
				if (dq.back() != rbrackets[c]) {
					score += score_table[c];
					break;
				} else {
					dq.pop_back();
				}	
			}
		}
			
	}
	
	std::cout << "Total Syntax Error Score: " << score << "\n";
	
}
