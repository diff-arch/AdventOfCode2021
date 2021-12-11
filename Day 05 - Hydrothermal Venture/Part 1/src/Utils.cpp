//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 5 - Hydrothermal Venture (Part 1)
//  
//  Created by diff-arch on 05/12/2021.
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


std::vector<std::string> split(std::string s, const std::string& delimiter) {
	std::vector<std::string> words;
	int pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		words.emplace_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}
	words.emplace_back(s);  // last word
	return words;
}