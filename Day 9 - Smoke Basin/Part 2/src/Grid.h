//
//  Grid.h
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 2)
//
//  Created by diff-arch on 09/12/2021.
//

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <vector>
#include <cmath>


struct Node {
	
	Node(int _id, int _value);
	~Node();
	
	friend std::ostream& operator <<(std::ostream& os, const Node& n);
	friend bool operator <(const Node& ni, const Node& nj);
	friend bool operator ==(const Node& ni, const Node& nj);
	int id, value;

};


struct Grid {
	
	Grid();
	Grid(const std::vector< std::vector<int> >& _rows_column);		
	~Grid();
	
	friend std::ostream& operator <<(std::ostream& os, const Grid& g);
	
	int getSize() const;
	int getIndex(int x, int y) const;
	int getRow(int idx) const;
	int getColumn(int idx) const;
	std::vector<Node> getAdjacent(const Node& n) const;
	void getAdjacentUpToRec(const Node& n, int value, std::vector<Node>& adjacent) const;
		
	std::vector<Node> nodes;
	int rows, columns;

};


#endif