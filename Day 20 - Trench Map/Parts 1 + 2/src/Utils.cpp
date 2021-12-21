//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 20 - Trench Map (Part 1 & 2)
//
//  Created by diff-arch on 20/12/2021.
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

	file.close();

	return lines;
}


std::vector<std::string> split(std::string s, const std::string& delimiter) {
	std::vector<std::string> words;
	int pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		std::string word = s.substr(0, pos);
		if (word.length() > 0)
			words.push_back(word);
		s.erase(0, pos + delimiter.length());
	}
	if (s.length() > 0)
		words.emplace_back(s);  // last word
	return words;
}


long int toDecimal(const std::string& binary) {
	long int val = 0;
	long int tmp = 1;
	for (int i = binary.length() - 1; i >= 0; i--) {
		if (binary[i] == '1')
			val += tmp;
		tmp *= 2; 
	}
	return val;
}
