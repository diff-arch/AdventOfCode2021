//
//  Submarine.h
//  ADVENT OF CODE 2021: Day 2 - Dive! (Part 2)
//  
//  Created by diff-arch on 02/12/2021.
//

#ifndef Submarine_h
#define Submarine_h

#include <iostream>
#include <string>

#include "Utils.h"

struct Submarine {
	Submarine();
	Submarine(int x, int y);
	~Submarine();
	
	friend std::ostream& operator <<(std::ostream& os, const Submarine& sub);
	
	void moveAndAim(const std::string& direction, int step);
	void execute(const std::string& command);
	void batchExecute(const char* fpath);
		
	int x, y, aim;
};

#endif
