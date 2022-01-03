//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 1)
//
//  Created by diff-arch on 22/12/2021.
//

#include "Utils.h"


Interval::Interval() { }

Interval::Interval(int _from, int _to) 
	: from(_from), to(_to), valid(true) { }

Interval::~Interval() = default;


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Interval& i) {
	return os << "(" << i.from << ", " << i.to << ")";
}


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
