//
//  Submarine.cpp
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 1)
//  
//  Created by diff-arch on 05/12/2021.
//

#include "Submarine.h"

Submarine::Submarine() = default;
Submarine::~Submarine() = default;


std::vector< std::pair<Node, Node> > Submarine::parseVentData(const char* filepath) {
	std::vector<std::string> lines = readData(filepath);
	
	std::vector< std::pair<Node, Node> > connected_nodes;
	connected_nodes.reserve(lines.size() * 2);
	
	for (const std::string ln : lines) {
		std::vector<std::string> split_line = split(ln);
		
		int x, y;
		
		std::vector<Node> line_nodes;
		line_nodes.reserve(2);
		
		for (const std::string& segment : split_line) {
				std::vector<std::string> coordinates = split(segment, ",");
				if (coordinates.size() < 2)
					continue;
				
				x = std::stoi(coordinates[0]);
				y = std::stoi(coordinates[1]);

				if (x > max_vent_x)
					max_vent_x = y;
				if (y > max_vent_y)
					max_vent_y = y; 
				
				line_nodes.emplace_back(x, y);
		}

		if (line_nodes.size() > 0)
			connected_nodes.emplace_back(line_nodes[0], line_nodes[1]);
	}
	
	return connected_nodes;
}

void Submarine::evaluateVents(const char* filepath) {
	std::vector< std::pair<Node, Node> > connected_vents = parseVentData(filepath);
	
	grid = Grid(max_vent_y + 1, max_vent_x + 1);
	
	for (const std::pair<Node, Node>& ln : connected_vents) {
		grid.markBetween(ln.first, ln.second);
	}
}

int Submarine::countVentOverlaps(int min) {
	return std::count_if(grid.nodes.begin(), grid.nodes.end(), 
									     [min] (const Node& n) { return n.marks >= min; });
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Submarine& sub) {
	return os << "Submarine()";
}
