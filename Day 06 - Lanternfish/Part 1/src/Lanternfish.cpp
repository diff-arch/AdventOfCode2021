//
//  Lanternfish.cpp
//  ADVENT OF CODE 2021: Day 6 - Lanternfish (Part 1)
//  
//  Created by diff-arch on 06/12/2021.
//

#include "Lanternfish.h"


Lanternfish::Lanternfish() = default;

Lanternfish::Lanternfish(int _internal_timer, School* _school) 
: internal_timer(_internal_timer), school(_school)	{ }

Lanternfish::~Lanternfish() = default;


void Lanternfish::update() {
	if (internal_timer == 0) {
		internal_timer = reproduction_rate;
		school->addFish();
	} else {
		internal_timer--;
	}
}


//--------------------------------------------------------------


School::School() = default;

School::School(const std::string& _timer_data) { 
	std::vector<std::string> split_data = split(_timer_data, ",");
	population.reserve(split_data.size());
	for (const std::string& f : split_data)
		population.emplace_back(std::stoi(f), this);
}

School::~School() = default;


void School::addFish() {
	population.push_back(Lanternfish(8, this));
}

void School::update() {
	for (int i = population.size() - 1; i >= 0; i--) {
		population[i].update();
	}
}

int School::getSize() const {
	return population.size();
}

//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Lanternfish& f) {
	return os << f.internal_timer;
}

std::ostream& operator <<(std::ostream& os, const School& s) {
	os << "(";
	for (int i = 0; i < s.population.size(); i++) {
		os << s.population[i];
		if (i < s.population.size() - 1)
			os << ", ";
	}
	os << ")\n";
	return os;
}
