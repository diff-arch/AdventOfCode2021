//
//  main.cpp
//  ADVENT OF CODE 2021: Day 24 - Arithmetic Logic Unit (Part 2)
//
//  Created by diff-arch on 28/12/2021.
//
//	Inspired by William Feng's solution that can be watched on YouTube:
//  https://www.youtube.com/watch?v=Eswmo7Y7C4U
//
//  Goal:    What is the smallest model number accepted by MONAD?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <vector>

#include "Utils.h"


bool evaluate(
	const std::vector<int>& digits, 
	const std::vector<int>& steps, 
	const std::vector<int>& required,
	std::vector<int>& result
) {
	int z = 0;
	int di = 0;
	
	for (int i = 0; i < 14; i++) {
		int increment = steps[i];
		int mod_req = required[i];
		
		if (increment == -1) {
			assert(mod_req != -1);
			result[i] = (z % 26) - mod_req;  //  z % 26 - m
			z /= 26;  // z // 26
			if (!(1 <= result[i] && result[i] <= 9))
				return false;
		} else {
			assert(increment != -1);
			z = z * 26 + digits[di] + increment;  // z * 26 + w + i
			result[i] = digits[di];
			di++;
		}	
		
	}
	return true;
}


int main() {

	// Manually chosen values from bin/data/arithmetic-logic-unit.txt, after figuring it out.
	// kRequired is to filled with each sixth value from each of the 14 input instructions,
	// if the value is negative, otherwise with a placeholder -1.
	const std::vector<int> kRequired = {-1, -1, -1, -1, -1, 11, -1, 16,  9, -1,  8,  8, 10,  9};
	// kSteps is to be filled with each third last value from each of the 14 input instructions,
	// if the corresponding value in kRequired is -1, otherwise with a placeholder -1.
	const std::vector<int> kSteps    = {13, 16,  2,  8, 11, -1, 12, -1, -1, 15, -1, -1, -1, -1};
	
	std::vector<int> range = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // only digits from 1 to 9 in MONAD input
	auto kInputSpace = product(range, 7);
	
	for (const auto& digits : kInputSpace) {
		std::vector<int> result(14, 0);
		bool valid = evaluate(digits, kSteps, kRequired, result);
		
		if (valid) {
			std::cout << "Smallest Accepted Model Number: ";
			for (int& n : result)
				std::cout << n;
			std::cout << "\n";
			break;
		}
	}

}
