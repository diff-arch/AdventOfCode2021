//
//  main.cpp
//  ADVENT OF CODE 2021: Day 21 - Dirac Dice (Part 2)
//
//  Created by diff-arch on 21/12/2021.
//
//  Inspired by Jonathan Paulson Pythonic solution which can be found here:
//  https://github.com/jonathanpaulson/AdventOfCode/blob/master/2021/21.py
//
//  Goal:    Using your given starting positions, determine every possible outcome. 
//           Find the player that wins in more universes; in how many universes
//           does that player win?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

#include "Utils.h"


std::tuple<long int, long int> evaluate_winners(long int p1, long int p2, long int s1, long int s2, int threshold, 
                                                std::map< std::tuple<long int, long int, long int, long int>, 
                                                std::tuple<long int, long int> >& dim_map) {
	if (s1 >= threshold)
		return std::make_tuple(0, 1);
	if (s2 >= threshold)
		return std::make_tuple(0, 1);
	
	std::tuple<long int, long int, long int, long int> ppss = std::make_tuple(p1, p2, s1, s2);
	if (dim_map.find(ppss) != dim_map.end())
		return dim_map[ppss];
	
	std::tuple<long int, long int> winner = std::make_tuple(0, 0);
	for (int d1 = 1; d1 < 4; d1++) {
		for (int d2 = 1; d2 < 4; d2++) {
			for (int d3 = 1; d3 < 4; d3++) {
				long int new_p1 = (p1 + d1 + d2 + d3) % 10;
				long int new_s1 = s1 + new_p1 + 1;
				
				auto [xx, yx] = evaluate_winners(p2, new_p1, s2, new_s1, threshold, dim_map);
				winner = std::make_tuple(std::get<0>(winner) + yx, std::get<1>(winner) + xx);
			}
		}
	}
	
	dim_map[ppss] = winner;
	return winner;
}


int main() {
    
	const char* fpath = "../bin/data/dirac-dice.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	std::vector< std::tuple<int, int> > players;
	players.reserve(lines.size());
	for (const std::string line : lines) {
		std::vector<std::string> split_line = split(line, ":");
		players.emplace_back(std::stoi(split_line[1]) - 1, 0);
	}
	
	auto [p1, s1] = players[0];
	auto [p2, s2] = players[1];
	std::map< std::tuple<long int, long int, long int, long int>, std::tuple<long int, long int> > dim_map;
	std::tuple<long int, long int> winner = evaluate_winners(p1, p2, s1, s2, 21, dim_map);

	std::cout << "Number of Universes: " << std::max(std::get<0>(winner), std::get<1>(winner)) << "\n";
	
}
