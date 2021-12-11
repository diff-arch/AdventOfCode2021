//
//  Submarine.h
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 2)
//  
//  Created by diff-arch on 03/12/2021.
//

#ifndef Submarine_h
#define Submarine_h

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Utils.h"

struct Submarine {
	Submarine();
	~Submarine();
	
	friend std::ostream& operator <<(std::ostream& os, const Submarine& sub);
	
	std::vector<std::string> decodeRec(const std::vector<std::string>& rows, int mode, int ri=0);
	std::pair<std::string, std::string> decodeReport(const char* filepath);
	int computeLifeSupportRating(const char* filepath);
};

#endif
