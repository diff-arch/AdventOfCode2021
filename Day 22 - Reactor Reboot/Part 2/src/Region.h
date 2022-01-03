//
//  Region.h
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 2)
//
//  Created by diff-arch on 31/12/2021.
//

#ifndef Region_h
#define Region_h

#include <iostream>
#include <vector>

#include "Utils.h"


struct Interval {
  
  Interval(int _from, int _to);
  ~Interval();
  
  friend std::ostream& operator <<(std::ostream& os, const Interval& i);
  
  int from, to;
  
};


struct Region3d {
  
	Region3d(bool _on, int _x1, int _x2, int _y1, int _y2, int _z1, int _z2);
	~Region3d();
	
	friend std::ostream& operator <<(std::ostream& os, const Region3d& r);
  
	Interval dx, dy, dz;
	bool on;
  
};


#endif
