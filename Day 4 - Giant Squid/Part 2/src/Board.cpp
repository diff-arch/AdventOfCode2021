//
//  Board.cpp
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 2)
//  
//  Created by diff-arch on 04/12/2021.
//

#include "Board.h"

//--------------------------------------------------------------

Cell::Cell() { } 

Cell::Cell(int _value) 
: value(_value), marked(false) { }

Cell::~Cell() = default;

//--------------------------------------------------------------

Board::Board(int _width, int _height)
: width(_width), height(_height) { 
	cells.reserve(_width * _height);
}
	
Board::~Board() = default;


void Board::addRow(const std::vector<int> values) {
	for (const int& v : values)
		cells.emplace_back(Cell(v));
}

std::vector<int> Board::getCellValues() const {
	std::vector<int> values;
	values.reserve(cells.size());
	for (const Cell& c : cells)
		values.emplace_back(c.value);
	return values;
} 

int Board::getIndex(int value) const {
	std::vector<int> cell_values = getCellValues();
	auto it = std::find(cell_values.begin(), cell_values.end(), value);
	int index = -1;
	if (it != cell_values.end())
		index = it - cell_values.begin();
	return index;
}

bool Board::markCell(int value) {
	int index = getIndex(value);
	if (index < 0)
		return false;  // value not in cells
	cells[index].marked = true;
	return true;
}

std::vector<Cell> Board::getUnmarked() const {
	std::vector<Cell> unmarked;
	for (const Cell& c : cells) {
		if (!c.marked)
			unmarked.push_back(c);
	}
	return unmarked;
}

int Board::sumUnmarked() const {
	std::vector<Cell> unmarked_cells = getUnmarked();
	int sum = 0;
	for (const Cell& c : unmarked_cells)
		sum += c.value;
	return sum;
}

int Board::getSize() const {
	return width * height;
}

int Board::checkRows() const {
	std::vector<int> counts(height, 0);
	int row_index = -1;
	for (int i = 0; i < getSize(); i++) {
		if (i % width == 0)
			row_index++;
		if (cells[i].marked)
			counts[row_index]++;
	}

	for (int i = 0; i < counts.size(); i++) {
		if (counts[i] == width)
			return i;
	}
	return -1;
}

int Board::checkColumns() const {
	std::vector<int> counts(width, 0);
	int column_index = 0;
	for (int i = 0; i < getSize(); i++) {
		if (i % width == 0)
			column_index = 0;
		if (cells[i].marked)
			counts[column_index]++;
		column_index++;
	}

	for (int i = 0; i < counts.size(); i++) {
		if (counts[i] == height)
			return i;
	}
	return -1;
}

bool Board::bingo() const {
	return (checkRows()  > -1 || checkColumns() > -1);
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Board& b) {
	os << "Board(\n";
	for (int i = 0; i < b.getSize(); i++) {
		if (i > 0 && i % b.width == 0)
			os << "\n";
		int val = b.cells[i].value;
		os << " " << ((countDigits(val) < 2) ? "  " : " ") << val;
	}
	os << "\n)";
	return os;
}

std::ostream& operator <<(std::ostream& os, const Cell& c) {
	return os << "Cell(" << c.value << ", " << ((c.marked) ? "marked" : "unmarked") << ")";
}
