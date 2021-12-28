//
//  Utils.h
//  ADVENT OF CODE 2021: Day 24 - Arithmetic Logic Unit (Part 1)
//
//  Created by diff-arch on 28/12/2021.
//

#ifndef Utils_h
#define Utils_h

#include <vector>


std::vector< std::vector<int> > cartesianProduct(
	const std::vector<int>& n1, 
	const std::vector<int>& n2
);

std::vector< std::vector<int> > cartesianProduct(
	const std::vector< std::vector<int> >& n1, 
	const std::vector<int>& n2
);

std::vector< std::vector<int> > product(const std::vector<int>& n, int repeat);


#endif