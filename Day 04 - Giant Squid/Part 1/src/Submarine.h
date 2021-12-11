//
//  Submarine.h
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 1)
//  
//  Created by diff-arch on 04/12/2021.
//

#ifndef Submarine_h
#define Submarine_h

#include <iostream>
#include <vector>
#include <utility>

#include "Board.h"
#include "Utils.h"

struct Submarine {
	Submarine();
	~Submarine();
	
	friend std::ostream& operator <<(std::ostream& os, const Submarine& sub);
	
	std::pair< std::vector<int>, std::vector<Board> > parseBingoReport(const char* filepath) const;

};

#endif
