//
//  Submarine.cpp
//  ADVENT OF CODE 2021: Day 2 - Dive! (Part 2)
//  
//  Created by diff-arch on 02/12/2021.
//

#include "Submarine.h"

Submarine::Submarine()
: x(0), y(0), aim(0) {}

Submarine::Submarine(int _x, int _y) 
: x(_x), y(_y), aim(0) {}

Submarine::~Submarine() = default;


void Submarine::moveAndAim(const std::string& direction, int step) {
	if (direction == "forward") {
		x += step;
		y += aim * step;
	} else if (direction == "down") {
		aim += step;
	} else if (direction == "up") {
		aim -= step;
	} else {
		std::cout << "Invalid command.\n";
	}
}

void Submarine::execute(const std::string& command) {
	std::vector<std::string> words = split(command);
	moveAndAim(words[0], std::stoi(words[1]));
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
