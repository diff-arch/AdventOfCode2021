//
//  Submarine.h
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 2)
//  
//  Created by diff-arch on 05/12/2021.
//

#ifndef Submarine_h
#define Submarine_h

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

#include "Grid.h"
#include "Utils.h"


struct Submarine {
	
	Submarine();
	~Submarine();
	
	friend std::ostream& operator <<(std::ostream& os, const Submarine& sub);
	
	std::vector< std::pair<Node, Node> > parseVentData(const char* filepath);
	void evaluateVents(const char* filepath);
	int countVentOverlaps(int min=2);
	
	int max_vent_x = 0;
	int max_vent_y = 0;
	
	Grid grid;
	
};


#endif
