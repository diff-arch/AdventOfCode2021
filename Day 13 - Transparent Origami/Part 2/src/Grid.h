//
//  Grid.h
//  ADVENT OF CODE 2021: Day 13 - Transparent Origami (Part 2)
//
//  Created by diff-arch on 13/12/2021.
//

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <stdexcept>


struct Grid {
	
	Grid();
	Grid(int _rows, int _columns);
	Grid(const std::vector< std::vector<bool> >& _rows_columns);
	~Grid();
	
	friend std::ostream& operator <<(std::ostream& os, const Grid& g);
	Grid operator +(Grid& other);
	
	int getSize() const;
	int getIndex(int x, int y) const;
	int getRow(int idx) const;
	int getColumn(int idx) const;
	int getDots() const;
	
	std::vector<bool> getRowData(int r);
	std::vector<bool> getColumnData(int c);
	void toggleCell(int x, int y);
	void flipVertical();
	void flipHorizontal();
	std::pair<Grid, Grid> split(char axis, int offset);

	std::vector<bool> cells;
	int rows, columns;

};


#endif