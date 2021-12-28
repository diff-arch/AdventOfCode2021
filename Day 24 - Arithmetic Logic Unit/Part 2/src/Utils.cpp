//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 24 - Arithmetic Logic Unit (Part 2)
//
//  Created by diff-arch on 28/12/2021.
//

#include "Utils.h"


std::vector< std::vector<int> > cartesianProduct(
	const std::vector<int>& n1, 
	const std::vector<int>& n2
) {
	std::vector< std::vector<int> > product;
	product.reserve(n1.size() * n2.size());
	for (const int i1 : n1)
		for (const int i2 : n2)
			product.push_back({i1, i2});
	return product;
}

std::vector< std::vector<int> > cartesianProduct(
	const std::vector< std::vector<int> >& n1, 
	const std::vector<int>& n2
) {
	std::vector< std::vector<int> > product;
	product.reserve(n1.size() * n2.size());
	for (const std::vector<int>& v1 : n1) {
		for (const int i2 : n2) {
			std::vector<int> vc = v1;
			vc.push_back(i2);
			product.push_back(vc);
		}
	}
	return product;
}


std::vector< std::vector<int> > product(const std::vector<int>& n, int repeat) {
	std::vector< std::vector<int> > product = cartesianProduct(n, n);  // repeat 3
	repeat--; // repeat 2
	while (repeat > 1) {
		product = cartesianProduct(product, n);
		repeat--;
	}
	return product;
}