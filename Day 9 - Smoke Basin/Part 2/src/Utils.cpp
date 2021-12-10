//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 9 - Smoke Basin (Part 2)
//
//  Created by diff-arch on 09/12/2021.
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
