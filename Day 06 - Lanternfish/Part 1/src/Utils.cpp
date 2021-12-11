//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 6 - Lanternfish (Part 1)
//  
//  Created by diff-arch on 06/12/2021.
//

#include "Utils.h"


std::string readLine(const char* filepath) {
	std::fstream file;
	file.open(filepath, std::ios::in);
	if (!file)
		throw std::runtime_error("No such file!");

	std::string line; 
	std::getline(file, line);
	file.close();
	return line;
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


int countDigits(unsigned int num) {
	if (num > 0)
		return 1 + static_cast<std::size_t>(std::log10(num));
	return 1;
}