//
//  Player.cpp
//  ADVENT OF CODE 2021: Day 21 - Dirac Dice (Part 1)
//
//  Created by diff-arch on 21/12/2021.
//

#include "Player.h"


Player::Player() {}

Player::Player(int _tag, int _position)
: tag(_tag), position(_position) {
	score = 0;
	won = false;
	moves = 0;
}

Player::~Player() = default;


void Player::move(int step) {
	position += step;
	position = (position % 10 == 0) ? 10 : position % 10;
	moves++;
	
	if (moves == 3) {
		score += position;
		moves = 0;
	}
}

bool Player::isWinner(int threshold) const {
	return score >= threshold;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Player& p) {
	return os << "Player " << p.tag << " (" << p.position 
		        << "," << " score: " << p.score << ")";
}