//
//  Submarine.h
//  ADVENT OF CODE 2021: Day 2 - Dive! (Part 1)
//  
//  Created by diff-arch on 02/12/2021.
//

#include "Submarine.h"

Submarine::Submarine()
: x(0), y(0) {}

Submarine::Submarine(int _x, int _y) 
: x(_x), y(_y) {}

Submarine::~Submarine() = default;


void Submarine::move(const std::string& direction, int step) {
	if (direction == "forward")
		x += step;
	else if (direction == "down")
		y += step;
	else if (direction == "up")
		y -= step;
	else
		std::cout << "Invalid command.\n";
}

void Submarine::execute(const std::string& command) {
	std::vector<std::string> words = split(command);
	move(words[0], std::stoi(words[1]));
}

void Submarine::batchExecute(const char* filepath) {
	std::vector<std::string> data = readData(filepath);
	for (const std::string& command : data) {
		execute(command);
	}
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Submarine& sub) {
	return os << "Submarine(" << sub.x << ", " << sub.y << ")";
}
