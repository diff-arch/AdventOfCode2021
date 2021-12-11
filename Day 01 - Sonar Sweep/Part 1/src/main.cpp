//
//  main.cpp
//  ADVENT OF CODE 2021: Day 1 - Sonar Sweep (Part 1)
//  
//  Created by diff-arch on 01/12/2021.
//
//  Goal:    How many measurements are larger than the previous measurement?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/main.cpp
//  Run:     ./bin/a.out
//

#include <vector>
#include <fstream>
#include <iostream>

/// \brief Reads integers from a text file. 
/// \returns the vector of parsed intergers.
std::vector<int> readData(const char* filepath);

std::vector<int> readData(const char* filepath) {
	std::vector<int> parsed_data;
	std::ifstream stream(filepath);
	int num;
	while (stream >> num) {
		parsed_data.push_back(num);
	}
	stream.close();
	return parsed_data;
}

int main() {
	const char* fpath = "../bin/data/sonar-sweep.txt";  // insert your path
	std::vector<int> data = readData(fpath);
	
	int prev = data[0];
	int count = 0;
	
	for (int i = 1; i < data.size(); i++) {
		if (data[i] > prev)
			count++;
		prev = data[i];
	}
	
	std::cout << "Larger measurments: " << count << "\n";
}
