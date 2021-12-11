//
//  main.cpp
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 2)
//  
//  Created by diff-arch on 04/12/2021.
//
//  Goal:    Figure out which board will won last. Once it wons, what would its final score be?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <vector>

#include "Submarine.h"
#include "Board.h"


int main() {
	
	const char* fpath = "../bin/data/giant-squid.txt";  // insert your path
	
	Submarine sub = Submarine();
	
	std::pair< std::vector<int>, std::vector<Board> > parsed_report = sub.parseBingoReport(fpath);
	
	int num_boards = parsed_report.second.size();
	std::vector<bool> already_won(num_boards, false);
	
	int board_index = -1;
	int final_score = 0;
	
	for (int num : parsed_report.first) {
		bool won = false;
		
		for (int i = 0; i < num_boards; i++) {
			if (already_won[i])
				continue;
			
			Board* b = &parsed_report.second[i];
			b->markCell(num);
			
			if (b->bingo()) {
				already_won[i] = true;
				if (std::all_of(already_won.begin(), already_won.end(), [](bool w) { return w; })) {
					board_index = i;
					final_score = b->sumUnmarked() * num;
					won = true;
					break;
				}	
			}
			
		}
		
		if (won)
			break;
	}
	
	std::cout << "Winning Board: " << board_index << ", Final Score: " << final_score << "\n";
	
}
