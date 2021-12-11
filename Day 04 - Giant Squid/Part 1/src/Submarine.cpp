//
//  Submarine.cpp
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 1)
//  
//  Created by diff-arch on 04/12/2021.
//

#include "Submarine.h"

Submarine::Submarine() = default;
Submarine::~Submarine() = default;


std::pair< std::vector<int>, std::vector<Board> > Submarine::parseBingoReport(const char* filepath) const {
	std::vector<std::string> data = readData(filepath);
	
	// Parse the first line which specifies the draw order of numbers
	std::vector<std::string> split_digits = split(data[0], ",");
	
	std::vector<int> random_numbers;
	random_numbers.reserve(split_digits.size());
	for (std::string d : split_digits)
		random_numbers.emplace_back(std::stoi(d));
	
	// Parse the rest of the lines which specify the random boards
	std::vector<Board> boards;
	int bi = -1;  // current board index
	for (int i = 1; i < data.size(); i++) {
		std::string line = data[i];
		
		if (line.empty()) {
			boards.emplace_back(5, 5);
			bi++;
			continue;
		}
		
		std::vector<std::string> split_values = split(data[i]);
		
		std::vector<int> row_numbers;
		row_numbers.reserve(split_values.size());
		for (std::string v : split_values) {
			if (v[0] == ' ')  
				v = v[1];  // strip whitespace
			if (v.empty())
				continue;
			row_numbers.emplace_back(std::stoi(v));
		}

		boards[bi].addRow(row_numbers);
	}
	return std::make_pair(random_numbers, boards);
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Submarine& sub) {
	return os << "Submarine()";
}
