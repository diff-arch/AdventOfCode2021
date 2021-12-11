//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 10 - Syntax Scoring (Part 2)
//
//  Created by diff-arch on 10/12/2021.
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
		if (line.length() > 0)
			lines.emplace_back(line);
	}
	if (line.length() > 0)
		file.close();

	return lines;
}
