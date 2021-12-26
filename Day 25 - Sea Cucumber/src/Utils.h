//
//  Utils.h
//  ADVENT OF CODE 2021: Day 25 - Sea Cucumber (Part 1)
//
//  Created by diff-arch on 26/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>


/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);


#endif