//
//  main.cpp
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 2)
//  
//  Created by diff-arch on 05/12/2021.
//
//  Goal:    Consider all of the lines. At how many points do at least two lines overlap?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>

#include "Submarine.h"


int main() {
	
	const char* fpath = "../bin/data/example-data.txt";  // insert your path

	Submarine sub = Submarine();
	sub.evaluateVents(fpath);
	
	std::cout << sub.grid << "\n\n";
	std::cout << "Number of Two or More Overlaps: " << sub.countVentOverlaps() << "\n";
	
}
