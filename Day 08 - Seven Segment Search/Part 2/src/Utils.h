//
//  Utils.h
//  ADVENT OF CODE 2021: Day 8 - Seven Segment Search (Part 2)
//
//  Created by diff-arch on 08/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");

/// \brief Generates permutations of character combinations in a string.
///        The string should be presorted to get all possible permutations.
/// \returns the vector of found permuations
std::vector<std::string> getPermutations(const std::string& s);

/// \brief Joins the integers of a vector into an integer number.
/// \returns the integer number
int toInteger(const std::vector<int>& v);

#endif