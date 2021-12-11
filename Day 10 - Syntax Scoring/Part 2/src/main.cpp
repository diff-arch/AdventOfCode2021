//
//  main.cpp
//  ADVENT OF CODE 2021: Day 10 - Syntax Scoring (Part 2)
//
//  Created by diff-arch on 10/12/2021.
//
//  Goal:    Find the completion string for each incomplete line, 
//           score the completion strings, and sort the scores.
//           What is the middle score?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <utility>

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
		{'(', 1},
		{'[', 2},
		{'{', 3},
		{'<', 4},
	};
	
	std::vector<unsigned long int> scores;
	
	for (const std::string& line : lines) {
		
		std::deque<char> dq;
		bool corrupt = false;
		
		for (const char& c : line) {
			if (brackets.find(c) != brackets.end()) {
				dq.push_back(c);
			} else if (rbrackets.find(c) != rbrackets.end()) {
				if (dq.back() != rbrackets[c]) {
					corrupt = true;
					break;
				} else {
					dq.pop_back();
				}	
			}
		}
		
		if (!corrupt) {
			unsigned long int score = 0;
			std::deque<char>::reverse_iterator itr = dq.rbegin();
			for (itr = dq.rbegin(); itr != dq.rend(); ++itr) {
				score = score * 5 + score_table[*itr];
			}
			scores.push_back(score);
		}
	
	}
		
	std::sort(scores.begin(), scores.end());

	std::cout << "Middle Score: " << scores[(int)(scores.size()) / 2] << "\n";
	
}
