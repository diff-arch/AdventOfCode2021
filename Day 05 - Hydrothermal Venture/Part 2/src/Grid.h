//
//  Grid.h
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 2)
//  
//  Created by diff-arch on 05/12/2021.
//

#ifndef Grid_h
#define Grid_h

#include <iostream>
#include <vector>


struct Node {

	Node();
	Node(int _x, int _y);
	~Node();

	friend std::ostream& operator <<(std::ostream& os, const Node& n);

	bool isMarked() const;

	int x, y;
	int marks = 0;

};


struct Grid {
	
	Grid();
	Grid(int _rows, int _columns);		
	~Grid();
	
	friend std::ostream& operator <<(std::ostream& os, const Grid& g);
	
	int getSize() const;
	int getNodeIndex(int x, int y) const;
	void markBetween(Node& start, Node& end);

	std::vector<Node> nodes;
	int rows, columns;

};


#endif