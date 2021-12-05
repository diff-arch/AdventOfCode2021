//
//  Board.h
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 2)
//  
//  Created by diff-arch on 04/12/2021.
//

#ifndef Board_h
#define Board_h

#include <iostream>
#include <vector>

#include "Utils.h"

struct Cell {
	
  Cell();
	Cell(int _value);
	~Cell();
	
	friend std::ostream& operator <<(std::ostream& os, const Cell& c);
	
	int value;
	bool marked;

};


struct Board {
	
	Board(int _width, int _height);
	~Board();
	
	friend std::ostream& operator <<(std::ostream& os, const Board& b);
	
	void addRow(const std::vector<int> values);
	std::vector<int> getCellValues() const;
	int getIndex(int value) const;
	bool markCell(int value);
	std::vector<Cell> getUnmarked() const;
	int sumUnmarked() const;
	int getSize() const;
	int checkRows() const;
	int checkColumns() const;
	bool bingo() const;
	
	int width, height;
	std::vector<Cell> cells;

};


#endif
