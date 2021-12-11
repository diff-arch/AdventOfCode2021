//
//  main.cpp
//  ADVENT OF CODE 2021: Day 4 - Giant Squid (Part 1)
//  
//  Created by diff-arch on 04/12/2021.
//
//  Goal:    To guarantee victory against the giant squid, figure out which board will win first. 
//		  		 What will your final score be if you choose that board?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <vector>
#include <utility>

#include "Submarine.h"
#include "Board.h"


int main() {
	
	const char* fpath = "../bin/data/giant-squid.txt";  // insert your path
	
	Submarine sub = Submarine();
	
	std::pair< std::vector<int>, std::vector<Board> > parsed_report = sub.parseBingoReport(fpath);
	
	int board_index = -1;
	int final_score = 0;
	
	for (int num : parsed_report.first) {
		bool won = false;
		for (int i = 0; i < parsed_report.second.size(); i++) {
			Board* b = &parsed_report.second[i];
			b->markCell(num);
			
			if (b->bingo()) {
				board_index = i;
				final_score = b->sumUnmarked() * num;
				won = true;
				break;
			}
			
		}
		if (won)
			break;
	}
	
	std::cout << "Winning Board: " << ((board_index >= 0) ? board_index + 1 : board_index) << ", Final Score: " << final_score << "\n";
	
}
