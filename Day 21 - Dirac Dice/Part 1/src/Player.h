//
//  Player.h
//  ADVENT OF CODE 2021: Day 21 - Dirac Dice (Part 1)
//
//  Created by diff-arch on 21/12/2021.
//

#ifndef Player_h
#define Player_h

#include <iostream>
#include <compare>

struct Player {
	
	Player();
	Player(int _tag, int _position);
	~Player();
	
	friend std::ostream& operator <<(std::ostream& os, const Player& p);
	
	void move(int step);
	bool isWinner(int threshold) const;
	
	int tag, position, score, moves;
	bool won;

};


#endif