//
//  Submarine.cpp
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 2)
//  
//  Created by diff-arch on 03/12/2021.
//

#include "Submarine.h"

Submarine::Submarine() = default;
Submarine::~Submarine() = default;

std::vector<std::string> Submarine::decodeRec(const std::vector<std::string>& rows, int mode, int ri) {
	if (rows.size() < 2)
		return rows;
	
	std::string column;
	for (const std::string& row : rows) {
		column += row[ri];
	}
	int column_sum = sumIntegerDigits(column);
	
	char ob = (mode == 0) ? '0' : '1';
	if (column.length() / 2.0f <= column_sum)
		ob = (mode == 0) ? '1' : '0';
	
	std::vector<std::string> selected_rows;
	for (const std::string& row : rows) {
		if (row[ri] == ob)
			selected_rows.push_back(row);
	}
	
	return decodeRec(selected_rows, mode, ++ri);
}

std::pair<std::string, std::string> Submarine::decodeReport(const char* filepath) {
	std::vector<std::string> rows = readData(filepath);
	std::string oxygen_generator_rating = decodeRec(rows, 0)[0];
	std::string co2_scrubber_rating = decodeRec(rows, 1)[0];
	return std::make_pair(oxygen_generator_rating, co2_scrubber_rating);
}

int Submarine::computeLifeSupportRating(const char* filepath) {
	std::pair<std::string, std::string> binary_values = decodeReport(filepath);
	return toDecimal(binary_values.first) * toDecimal(binary_values.second);
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Submarine& sub) {
	return os << "Submarine()";
}
