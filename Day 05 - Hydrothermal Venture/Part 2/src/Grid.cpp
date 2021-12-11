//
//  Grid.cpp
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 2)
//  
//  Created by diff-arch on 05/12/2021.
//

#include "Grid.h"


Node::Node() {}

Node::Node(int _x, int _y)
: x(_x), y(_y) {}

Node::~Node() = default;

bool Node::isMarked() const {
	return marks > 0;
}

//--------------------------------------------------------------

Grid::Grid() {}

Grid::Grid(int _rows, int _columns)
: rows(_rows), columns(_columns) {
	nodes.reserve(_rows * _columns);
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++) {
			nodes.emplace_back(i, j);
		}
	}
}

Grid::~Grid() = default;


int Grid::getSize() const {
	return rows * columns;
}

int Grid::getNodeIndex(int x, int y) const {
	return x + y * columns;
}

void Grid::markBetween(Node& start, Node& end) {
	// int si, ei;
	if (start.x != end.x && start.y != end.y) {  // diagonal
		Node *north, *south;
		if (start.y < end.y) {
			north = &start;
			south = &end;
		} else {
			north = &end;
			south = &start;
		} 

		int rid = 1;  // row increment or decrement
		if (north->x > south->x)
			rid = -1;
		
		int nx = north->x; // current node x
		for (int ny = north->y; ny <= south->y; ny++) {
			nodes[getNodeIndex(nx, ny)].marks++;
			nx += rid;
		}
		
	} else {
		int si, ei;
		if (start.x != end.x) {  // vertical
			si = std::min(start.x, end.x);
			ei = std::max(start.x, end.x);
			for (int i = si; i <= ei; i++)
				nodes[getNodeIndex(i, start.y)].marks++;
		} else {  // horizontal
			si = std::min(start.y, end.y);
			ei = std::max(start.y, end.y);
			for (int i = si; i <= ei; i++)
				nodes[getNodeIndex(start.x, i)].marks++;
		}
	}
		
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Node& n) {
	return os << "Node(" << n.x << ", " << n.y << ")";
}

std::ostream& operator <<(std::ostream& os, const Grid& g) {
	os << "Grid(\n";
	for (int i = 0; i < g.getSize(); i++) {
		if (i > 0 && i % g.columns == 0)
			os << "\n";
		os << " " << ((g.nodes[i].isMarked()) ? std::to_string(g.nodes[i].marks) : ".");
	}
	os << "\n)";
	return os;
}
