//
//  Utils.h
//  ADVENT OF CODE 2021: Day 7 - The Treachery of Whales (Part 1)
//  
//  Created by diff-arch on 07/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


/// \brief Reads the first line in a text file.
/// \returns the first line as a string
std::string readLine(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");


#endif