//
//  Utils.h
//  ADVENT OF CODE 2021: Day 3 - Binary Diagnostic (Part 1)
//  
//  Created by diff-arch on 03/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);

/// \brief Adds all integer digits in a string of integers.
/// \returns the resulting integer sum
int sumIntegerDigits(const std::string& s);

/// \brief Converts binary strings to decimal.
/// \returns the corresponding decimal number
int toDecimal(const std::string& binary);

#endif