//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 2)
//
//  Created by diff-arch on 09/12/2021.
//

#include "Grid.h"


Node::Node(int _id, int _value)
: id(_id), value(_value) {}

Node::~Node() = default;


//--------------------------------------------------------------


Grid::Grid() {}

Grid::Grid(const std::vector< std::vector<int> >& _rows_columns) 
: rows(_rows_columns.size()), columns(_rows_columns[0].size()) {
	nodes.reserve(rows * columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			nodes.emplace_back(j + i * columns, _rows_columns[i][j]);
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

std::vector<Node> Grid::getAdjacent(const Node& n) const {
	int x = getColumn(n.id);
	int y = getRow(n.id);
	int dx, dy;
	
	std::vector<Node> adjacent;
	
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


void Grid::getAdjacentUpToRec(const Node& n, int value, std::vector<Node>& adjacent) const {
	adjacent.push_back(n);
	std::vector<Node> neighbours = getAdjacent(n);

	for (const Node& nn : neighbours) {
		if (nn.value < value && std::find(adjacent.begin(), adjacent.end(), nn) == adjacent.end())
			getAdjacentUpToRec(nn, value, adjacent);
	}
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Node& n) {
	return os << "Node(" << n.id << ", " << n.value << ")";
}

bool operator <(const Node& ni, const Node& nj) {
	return ni.value < nj.value;
}

bool operator ==(const Node& ni, const Node& nj) {
	return ni.id == nj.id;
}


std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << g.nodes[i].value;
	}
	os << "\n)";
	return os;
}
