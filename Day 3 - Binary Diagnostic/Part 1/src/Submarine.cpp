//
//  Submarine.cpp
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 1)
//  
//  Created by diff-arch on 03/12/2021.
//

#include "Submarine.h"

Submarine::Submarine() = default;
Submarine::~Submarine() = default;


std::pair<std::string, std::string> Submarine::decodeReport(const char* filepath) {
	std::vector<std::string> rows = readData(filepath);
	
	std::vector<std::string> columns;
	columns.reserve(rows[0].length());
	for (int i = 0; i < columns.capacity(); i++) {
		columns.emplace_back("");
		for (const std::string& row : rows) {
			columns[i] += row[i];
			continue;
		}
	}
	
	std::string gamma_rate = "";
	std::string epsilon_rate = "";
	for (const std::string& column : columns) {
		int column_total = sumIntegerDigits(column);
		if (column.length() / 2.0 <= column_total) {
			gamma_rate += '1';
		  epsilon_rate += '0';
			continue;
		}
		gamma_rate += '0';
		epsilon_rate += '1';
	}
	
	return std::make_pair(gamma_rate, epsilon_rate);
}

int Submarine::computePowerConsumption(const char* filepath) {
	std::pair<std::string, std::string> binary_values = decodeReport(filepath);
	return toDecimal(binary_values.first) * toDecimal(binary_values.second);
}

//--------------------------------------------------------------

std::ostream& operator <<(std::ostream& os, const Submarine& sub) {
	return os << "Submarine()";
}
