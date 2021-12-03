//
//  main.cpp
//  ADVENT OF CODE 2021: Day 2 - Dive! (Part 1)
//  
//  Created by diff-arch on 02/12/2021.
//
//  Goal:    What do you get if you multiply your final horizontal position by your final depth?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <vector>
#include <iostream>
#include <string>

#include "Submarine.h"
#include "Utils.h"

int main() {
	
	const char* fpath = "../bin/data/dive.txt";  // insert your path
	
	Submarine sub = Submarine();
	sub.batchExecute(fpath);
	
	std::cout << sub << ": " << (sub.x * sub.y) << "\n";

}
