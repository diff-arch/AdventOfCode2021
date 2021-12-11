//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 7 - The Treachery of Whales (Part 2)
//  
//  Created by diff-arch on 07/12/2021.
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
