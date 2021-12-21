//
//  Pixel.h
//  ADVENT OF CODE 2021: Day 20 - Trench Map (Part 1 & 2)
//
//  Created by diff-arch on 20/12/2021.
//

#ifndef Pixel_h
#define Pixel_h

#include <iostream>


struct Pixel {
	
	Pixel();
	Pixel(int _x, int _y);
	~Pixel();
	
	friend std::ostream& operator <<(std::ostream& os, const Pixel& p);
	bool operator <(const Pixel& other) const;
	
	int x;
	int y;

};


#endif