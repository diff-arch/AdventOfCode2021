//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 1)
//  
//  Created by diff-arch on 03/12/2021.
//

#include "Utils.h"


std::vector<std::string> readData(const char* filepath) {
	std::fstream file;
	file.open(filepath, std::ios::in);

	if (!file)
		throw std::runtime_error("No such file!");

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)) {
		lines.emplace_back(line);
	}

	file.close();

	return lines;
}


int sumIntegerDigits(const std::string& s) {
	int sum = 0;
	for (const char& c : s) {
		sum += (int)(c - '0');
	}
	return sum;
}


int toDecimal(const std::string& binary) {
	int val = 0;
	int tmp = 1;
	for (int i = binary.length() - 1; i >= 0; i--) {
		if (binary[i] == '1')
			val += tmp;
		tmp *= 2; 
	}
	return val;
}
