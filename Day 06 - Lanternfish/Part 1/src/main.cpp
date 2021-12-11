//
//  main.cpp
//  ADVENT OF CODE 2021: Day 6 - Lanternfish (Part 1)
//  
//  Created by diff-arch on 06/12/2021.
//
//  Goal:    Find a way to simulate lanternfish. 
//           How many lanternfish would there be after 80 days?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>

#include "Lanternfish.h"
#include "Utils.h"


int main() {
	
	const char* fpath = "../bin/data/lanternfish.txt";  // insert your path
	
	std::string school_data = readLine(fpath);
	
	const int days = 80;
	
	School school = {school_data};
	std::cout << "Initial state: " << school << "\n";
	
	for (int i = 1; i <= days; i++) {
		school.update();
		std::cout << "Afer  " << std::string(countDigits(days) - countDigits(i), ' ') 
			        << i <<  ((i > 1) ? "" : std::string(countDigits(i), ' ')) << " day" 
							<< ((i > 1) ? "s" : "") << ": " << school << "\n";
	}
	
	std::cout << "Total Population: " << school.getSize() << "\n";
	
}
