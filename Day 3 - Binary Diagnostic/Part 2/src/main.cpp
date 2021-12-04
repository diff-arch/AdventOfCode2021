//
//  main.cpp
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 2)
//  
//  Created by diff-arch on 03/12/2021.
//
//  Goal:    What is the life support rating of the submarine?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>

#include "Submarine.h"


int main() {
	
	const char* fpath = "../bin/data/binary-diagnostic.txt";  // insert your path
	
	Submarine sub = Submarine();
	int life_support_rating = sub.computeLifeSupportRating(fpath);
	std::cout << "Life Support Rating: " << life_support_rating << "\n";
	
}
