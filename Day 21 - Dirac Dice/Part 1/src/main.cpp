//
//  main.cpp
//  ADVENT OF CODE 2021: Day 21 - Dirac Dice (Part 1)
//
//  Created by diff-arch on 21/12/2021.
//
//  Goal:    Play a practice game using the deterministic 100-sided die. 
//           The moment either player wins, what do you get if you multiply 
//           the score of the losing player by the number of times the die 
//           was rolled during the game?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "Player.h"
#include "Utils.h"


int main() {
    
	const char* fpath = "../bin/data/dirac-dice.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
	std::vector<Player> players;
	players.reserve(lines.size());
	for (const std::string line : lines) {
		std::vector<std::string> split_line = split(line, ":");
		std::regex re("Player\\s*(\\d+)");
		std::smatch matches;
		if (std::regex_search(split_line[0], matches, re))
			players.emplace_back(std::stoi(matches[1].str()), std::stoi(split_line[1]));
	}
	
	int curr_index = 0;
	Player* winner = nullptr;
	
	int roll = 1;
	while (winner == nullptr) {
		std::cout << "Roll: " << roll << "\n";
		
		Player* curr_player = &players[curr_index];
		curr_player->move(roll);
		std::cout << *curr_player << "\n";
		
		if (curr_player->isWinner(1000)) {
			std::cout << "  ↳ Winner!\n\n";
			winner = curr_player;
			break;
		}
		
		if (roll % 3 == 0) {
			curr_index++;
			if (curr_index > players.size() - 1)
				curr_index = 0;
		}
		
		roll++;
	}
	
	std::sort(players.begin(), 
	          players.end(), 
						[](const Player& r, const Player& l) { return r.score < l.score; });
	
	Player* loser = &players[0];
	
	std::cout << "Die Rolls x Losing Player Score: " << roll * loser->score << "\n";
	
}
