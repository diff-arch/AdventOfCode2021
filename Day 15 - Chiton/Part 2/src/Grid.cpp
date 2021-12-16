//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 2)
//
//  Created by diff-arch on 15/12/2021.
//

#include "Grid.h"


Grid::Grid() {}

Grid::Grid(const std::vector< std::vector<int> >& _rows_columns) 
: rows(_rows_columns.size()), columns(_rows_columns[0].size()) {
	cells.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cells.push_back(_rows_columns[i][j]);
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

std::vector<int> Grid::getRowData(int r) const {
	std::vector<int> row;
	row.reserve(columns);
	for (int i = 0; i < columns; i++) {
		row.push_back(cells[getIndex(i, r)]);
	}
	return row;
}

std::vector<int> Grid::getAdjacent(int idx) const {
	int x = getColumn(idx);
	int y = getRow(idx);
	int dx, dy;
	
	std::vector<int> adjacent;
	
	if (y - 1 >= 0) { // northern neighbour
		dy = y - 1;
		dx = x;
		adjacent.emplace_back(getIndex(dx, dy));
	}
	if (x + 1 < columns) { // eastern neighbour
		dx = x + 1;
		dy = y;
		adjacent.emplace_back(getIndex(dx, dy));
	} 
	if (y + 1 < rows) {  // southern neighbour
		dy = y + 1;
		dx = x;
		adjacent.emplace_back(getIndex(dx, dy));
	} 
	if (x - 1 >= 0) { // western neighbour
		dx = x - 1;
		dy = y;
		adjacent.emplace_back(getIndex(dx, dy));
	}
	
	return adjacent;
}

Grid Grid::scale(int sx, int sy) const {
	std::vector< std::vector<int> > rows_columns;
	rows_columns.reserve(columns * sx * rows * sy);
	
	for (int i = 0; i < rows; i++) {
		std::vector<int> prev_segment = getRowData(i);
		std::vector<int> new_row;
		new_row.reserve(columns * sx);
		new_row = prev_segment;
		
		for (int s = 1; s < sx; s++) {
			std::vector<int> curr_segment;
			curr_segment.reserve(prev_segment.size());
			
			for (int data : prev_segment) {
				int mod_data = (data + 1 <= 9) ? data + 1 : 1;
				curr_segment.push_back(mod_data);
				new_row.push_back(mod_data);
			}
			
			prev_segment = curr_segment;
			curr_segment.clear();
		}
		
		rows_columns.emplace_back(new_row);
	}
	
	std::vector< std::vector<int> > prev_block = rows_columns;
	
	for (int s = 1; s < sy; s++) {
		std::vector< std::vector<int> > curr_block;
		curr_block.reserve(prev_block.size());
		
		for (const std::vector<int>& row : prev_block) {
			std::vector<int> curr_row;
			curr_row.reserve(row.size());
			
			for (int data : row) {
				int mod_data = (data + 1 <= 9) ? data + 1 : 1;
				curr_row.push_back(mod_data);
			}
			
			curr_block.emplace_back(curr_row);
			rows_columns.emplace_back(curr_row);
		}
		
		prev_block = curr_block;
	}
	
	return Grid(rows_columns);
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << g.cells[i];
	}
	os << "\n)";
	return os;
}
