//
//  Utils.h
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 2)
//  
//  Created by diff-arch on 04/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>

/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");

/// \brief Counts the digits in an integer number
/// \returns the count of digits
int countDigits(int n);

#endif