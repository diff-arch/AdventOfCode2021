//
//  Utils.h
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 1)
//
//  Created by diff-arch on 22/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>


struct Interval {
	
	Interval();
	Interval(int _from, int _to);
	~Interval();
	
	friend std::ostream& operator <<(std::ostream& os, const Interval& i);
	
	int from, to;
	bool valid = false;

};


/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");


#endif