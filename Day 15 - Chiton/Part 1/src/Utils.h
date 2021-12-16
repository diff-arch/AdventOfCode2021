//
//  Utils.h
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 1)
//
//  Created by diff-arch on 15/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <map>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <utility>
#include <algorithm>
#include <stdexcept>

#include "PriorityQueue.h"
#include "Grid.h"

/// \brief Reads a text file line by line.
/// \returns the vector of individual lines
std::vector<std::string> readData(const char* filepath);

/// \brief Splits a string by a given delimiter.
/// \param s:         a string to split
/// \param delimiter: optional delimiter, by default whitespace
/// \returns the vector of individual strings
std::vector<std::string> split(std::string s, const std::string& delimiter=" ");

/// \brief Helper function for the dijkstra function which relaxes the cells. 
void relax(int from, int to, Grid& g, std::map<int, int>& dist_to, 
           std::map<int, int>& cell_to, PriorityQueue& pq);

/// \brief Given a weighted grid and a source, determines the shortest path 
///        to all other cells in terms of accumulated weights of edges.
/// \returns two structures: dist_to[i] which contains the length of the
///          shortest path by accumulated cell weights from source to i,
///          and cell_to[i] which contains the last edge j on the actual
///          shortst path from source to i
std::pair<std::map<int, int>, std::map<int, int>> dijkstra(Grid& g, int source);

/// \brief Helper function for the dijkstra function which recovers the actual
///        shortest path from source to target.
/// \return the recovered path as a vector of cell indices
std::vector<int> path_to(std::map<int, int>& cell_to, int source, int target);

#endif