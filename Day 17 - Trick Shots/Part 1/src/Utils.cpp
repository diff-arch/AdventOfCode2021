//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 1)
//
//  Created by diff-arch on 17/12/2021.
//

#include "Utils.h"


Interval::Interval() {}

Interval::Interval(int _start, int _end)
	: start(_start), end(_end) {
		if (getMin() < start) {
			start = getMin();
			end = getMax();
		}
	}

Interval::~Interval() = default;


bool Interval::contains(int value) const {
	return (value >= start && value <= end);
}

int Interval::getMin() const {
	return (start <= end) ? start : end;
}

int Interval::getMax() const {
	return (start >= end) ? start : end;
}


//--------------------------------------------------------------


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
		std::string word = s.substr(0, pos);
		if (word.length() > 0)
			words.push_back(word);
		s.erase(0, pos + delimiter.length());
	}
	if (s.length() > 0)
		words.emplace_back(s);  // last word
	return words;
}


std::ostream& operator <<(std::ostream& os, const Interval& i) {
	return os << "[" << i.start << ", " << i.end << "]";
}
