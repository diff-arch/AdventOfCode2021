//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 11 - Dumbo Octopus (Part 1)
//
//  Created by diff-arch on 11/12/2021.
//

#include "Grid.h"


Octopus::Octopus() = default;

Octopus::Octopus(int _id, int _energy, Grid* _grid)
: id(_id), energy(_energy), grid(_grid), active(true), flashes(0) {}

Octopus::~Octopus() = default;


void Octopus::update() {
	if (active) {
		energy++;
		if (energy > 9) {
			energy = 0;
			active = false;
			flashes++;
			std::vector<Octopus*> neighbours = grid->getAdjacent(id);
			for (Octopus* n : neighbours)
				n->update();
		}
	}
}


//--------------------------------------------------------------


Grid::Grid() {}

Grid::Grid(const std::vector< std::vector<int> >& _rows_columns) 
: rows(_rows_columns.size()), columns(_rows_columns[0].size()) {
	octopi.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			octopi.emplace_back(j + i * columns, _rows_columns[i][j], this);
		}
	}
}

Grid::~Grid() = default;


void Grid::update() {
	for (Octopus& o : octopi) {
		o.update();
	}
	for (Octopus& o : octopi)
		o.active = true;
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

std::vector<Octopus*> Grid::getAdjacent(int idx) {
	int x = getColumn(idx);
	int y = getRow(idx);
	int dx, dy;
	
	std::vector<Octopus*> adjacent;
	
	if (y - 1 >= 0) { // northern neighbour
		dx = x;
		dy = y - 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (x + 1 < columns && y - 1 >= 0) {  // north eastern neighbour
		dx = x + 1;
		dy = y - 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (x + 1 < columns) { // eastern neighbour
		dx = x + 1;
		dy = y;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (x + 1 < columns && y + 1 < rows) {  // south eastern neighbour
		dx = x + 1;
		dy = y + 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (y + 1 < rows) {  // southern neighbour
		dx = x;
		dy = y + 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	} 
	if (x - 1 >= 0 && y + 1 < rows) {  // south western neighbour
		dx = x - 1;
		dy = y + 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (x - 1 >= 0) { // western neighbour
		dx = x - 1;
		dy = y;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	if (x - 1 >= 0 && y - 1 >= 0) {  // north western neighbour
		dx = x - 1;
		dy = y - 1;
		adjacent.push_back(&(octopi[getIndex(dx, dy)]));
	}
	
	return adjacent;
}

int Grid::getFlashes() const {
	int flashes = 0;
	for (const Octopus& o : octopi)
		flashes += o.flashes;
	return flashes;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << g.octopi[i].energy;
	}
	os << "\n)";
	return os;
}
