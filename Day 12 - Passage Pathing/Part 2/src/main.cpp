//
//  main.cpp
//  ADVENT OF CODE 2021: Day 12 - Passage Pathing (Part 2)
//
//  Created by diff-arch on 12/12/2021.
//
//  Goal:    Given these new rules, how many paths through this cave system are there?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/passage-pathing.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	Graph g;
	g.addEdges(lines);
	// std::cout << g << "\n";
		
	std::string from = "start";
	std::string to = "end";
	std::vector<std::string> visited;
	visited.push_back(from);
	std::vector<std::string> path;
	
	std::cout << "Paths Count: " << g.countPathsRec(from, to, visited, path) << "\n";
	
}
