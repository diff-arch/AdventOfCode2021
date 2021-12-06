//
//  Lanternfish.h
//  ADVENT OF CODE 2021: Day 6 - Lanternfish (Part 1)
//  
//  Created by diff-arch on 06/12/2021.
//

#ifndef Lanternfish_h
#define Lanternfish_h

#include <vector>
#include <string>
#include <iostream>

#include "Utils.h"


struct School;


struct Lanternfish {

	Lanternfish();
	Lanternfish(int _internal_timer, School* _school);
	~Lanternfish();
	
	friend std::ostream& operator <<(std::ostream& os, const Lanternfish& f);
	
	void update();
	
	int reproduction_rate = 6;
	int internal_timer;
	School* school;
	
};


struct School {
	
	School();
	School(const std::string& _timer_data);
	~School();
	
	friend std::ostream& operator <<(std::ostream& os, const School& s);
	
	void addFish();
	void update();
	int getSize() const;
	
	std::vector<Lanternfish> population;
	
};

#endif