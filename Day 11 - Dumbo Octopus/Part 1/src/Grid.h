//
//  Grid.h
//  ADVENT OF CODE 2021: Day 11 - Dumbo Octopus (Part 1)
//
//  Created by diff-arch on 11/12/2021.
//

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <vector>
#include <cmath>


struct Grid;


struct Octopus {
	
	Octopus();
	Octopus(int _id, int _energy, Grid* _grid);
	~Octopus();
	
	void update();
	
	int id, energy, flashes;
	bool active;
	Grid* grid;
	
};


struct Grid {
	
	Grid();
	Grid(const std::vector< std::vector<int> >& _rows_column);		
	~Grid();
	
	friend std::ostream& operator <<(std::ostream& os, const Grid& g);
	
	void update();
	int getSize() const;
	int getIndex(int x, int y) const;
	int getRow(int idx) const;
	int getColumn(int idx) const;
	std::vector<Octopus*> getAdjacent(int idx);
	int getFlashes() const;
	
	std::vector<Octopus> octopi;
	int rows, columns;

};


#endif