//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 1)
//
//  Created by diff-arch on 09/12/2021.
//

#include "Grid.h"


Grid::Grid() {}

Grid::Grid(const std::vector< std::vector<int> >& _rows_columns) 
: rows(_rows_columns.size()), columns(_rows_columns[0].size()) {
	nodes.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			nodes.emplace_back(_rows_columns[i][j]);
		}
	}
}

Grid::~Grid() = default;


int Grid::getSize() const {
	return rows * columns;
}

int Grid::getIndex(int x, int y) const {
	return x + y * columns;
}

int Grid::getRow(int idx) const {
	return idx / columns;
}

int Grid::getColumn(int idx) const {
	return std::floor(idx % columns);
}

std::vector<int> Grid::getAdjacent(int idx) const {
	int x = getColumn(idx);
	int y = getRow(idx);
	int dx, dy;
	
	std::vector<int> adjacent;
	
	if (y - 1 >= 0) { // northern neighbour
		dy = y - 1;
		dx = x;
		adjacent.emplace_back(nodes[getIndex(dx, dy)]);
	}
	if (x + 1 < columns) { // eastern neighbour
		dx = x + 1;
		dy = y;
		adjacent.emplace_back(nodes[getIndex(dx, dy)]);
	} 
	if (y + 1 < rows) {  // southern neighbour
		dy = y + 1;
		dx = x;
		adjacent.emplace_back(nodes[getIndex(dx, dy)]);
	} 
	if (x - 1 >= 0) { // western neighbour
		dx = x - 1;
		dy = y;
		adjacent.emplace_back(nodes[getIndex(dx, dy)]);
	}
	
	return adjacent;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << g.nodes[i];
	}
	os << "\n)";
	return os;
}
