//
//  Grid.h
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 1)
//
//  Created by diff-arch on 09/12/2021.
//

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <vector>
#include <cmath>


struct Grid {
	
	Grid();
	Grid(const std::vector< std::vector<int> >& _rows_column);		
	~Grid();
	
	friend std::ostream& operator <<(std::ostream& os, const Grid& g);
	
	int getSize() const;
	int getIndex(int x, int y) const;
	int getRow(int idx) const;
	int getColumn(int idx) const;
	std::vector<int> getAdjacent(int idx) const;

	std::vector<int> nodes;
	int rows, columns;

};


#endif