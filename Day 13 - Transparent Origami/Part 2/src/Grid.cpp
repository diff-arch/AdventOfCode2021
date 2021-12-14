//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 13 - Transparent Origami (Part 2)
//
//  Created by diff-arch on 13/12/2021.
//

#include "Grid.h"


Grid::Grid() {}

Grid::Grid(int _rows, int _columns) 
: rows(_rows), columns(_columns) {
	cells.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cells.push_back(false);
		}
	}
}

Grid::Grid(const std::vector< std::vector<bool> >& _rows_columns) 
: rows(_rows_columns.size()), columns(_rows_columns[0].size()) {
	cells.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cells.push_back(_rows_columns[i][j]);
		}
	}
}

Grid::~Grid() = default;


Grid Grid::operator +(Grid& other) {
	Grid bigger;
	Grid* smaller;
	
	if (getSize() > other.getSize()) {
		bigger = *this;
		smaller = &other;
  } else {
		bigger = other;
		smaller = this;
	}
	
	int row_offset = bigger.rows - smaller->rows;
	int col_offset = bigger.columns - smaller->columns;
	for (int y = row_offset; y < bigger.rows; y++) {
		for (int x = col_offset; x < bigger.columns; x++) {
			int i = bigger.getIndex(x, y);
			int ii = smaller->getIndex(x - col_offset, y - row_offset);
			bigger.cells[i] = bigger.cells[i] || smaller->cells[ii];
		}
	}
	
	return bigger;
}


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

int Grid::getDots() const {
	int count = 0;
	for (const bool c : cells) {
		if (c) 
			count++;
	}
	return count;
}

std::vector<bool> Grid::getRowData(int r) {
	std::vector<bool> row;
	row.reserve(columns);
	for (int i = 0; i < columns; i++) {
		row.push_back(cells[getIndex(i, r)]);
	}
	return row;
}

std::vector<bool> Grid::getColumnData(int c) {
	std::vector<bool> column;
	column.reserve(rows);
	for (int i = 0; i < rows; i++) {
		column.push_back(cells[getIndex(c, i)]);
	}
	return column;
}

void Grid::toggleCell(int x, int y) {
	cells[getIndex(x, y)] = !cells[getIndex(x, y)];
}

void Grid::flipVertical() {
	for (int y = 0; y < rows; y++) {
		std::vector<bool> row = getRowData(y);
		std::reverse(row.begin(), row.end());
		for (int x = 0; x < columns; x++)
			cells[getIndex(x, y)] = row[x];
	}
}

void Grid::flipHorizontal() {
	for (int x = 0; x < columns; x++) {
		std::vector<bool> column = getColumnData(x);
		std::reverse(column.begin(), column.end());
		for (int y = 0; y < rows; y++) {
			cells[getIndex(x, y)] = column[y];
		}
	}
}

std::pair<Grid, Grid> Grid::split(char axis, int offset) {
	std::vector< std::vector <bool> > rowsa, rowsb;
	
	switch (axis) {
		case 'x':
			rowsa.reserve(rows);
			rowsb.reserve(rows);
			for (int y = 0; y < rows; y ++) {
				std::vector<bool> rowa, rowb;
				for (int x = 0; x < columns; x++) {
					if (x < offset)
						rowa.push_back(cells[getIndex(x, y)]);
					else if (x > offset)
						rowb.push_back(cells[getIndex(x, y)]);
				}
				rowsa.emplace_back(rowa);
				rowsb.emplace_back(rowb);
			}
			break;
		
		case 'y':
			for (int y = 0; y < rows; y ++) {
				std::vector<bool> row;
				row.reserve(columns);
				for (int x = 0; x < columns; x++)
					row.push_back(cells[getIndex(x, y)]);
				if (y < offset)
					rowsa.emplace_back(row);
				else if (y > offset)
					rowsb.emplace_back(row);
			}
			break;
		
		default:
		throw std::runtime_error(
			"Expected 'x' or 'y', got '" + std::string{1u, axis} + "' instead"
		);
	}
	
	return std::make_pair(rowsa, rowsb);
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << ((g.cells[i]) ? '#' : '.');
	}
	os << "\n)";
	return os;
}
