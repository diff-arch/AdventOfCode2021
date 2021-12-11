//
//  main.cpp
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 1)
//  
//  Created by diff-arch on 03/12/2021.
//
//  Goal:    What is the power consumption of the submarine?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>

#include "Submarine.h"


int main() {
	
	const char* fpath = "../bin/data/binary-diagnostic.txt";  // insert your path
	
	Submarine sub = Submarine();
	int power_consumption = sub.computePowerConsumption(fpath);
	std::cout << "Power Consumption: " << power_consumption << "\n";
	
}
