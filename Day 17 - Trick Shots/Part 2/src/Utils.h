//
//  Utils.h
//  ADVENT OF CODE 2021: Day 17 - Trick Shots (Part 2)
//
//  Created by diff-arch on 17/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


struct Interval {
	Interval();
	Interval(int _start, int _end);
	~Interval();
	
	friend std::ostream& operator <<(std::ostream& os, const Interval& i);
	bool contains(int value) const;
	int getMin() const;
	int getMax() const;
	
	int start, end;
};


/// \brief Reads the first line in a text file.
/// \returns the first line as a string
std::string readLine(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");


#endif