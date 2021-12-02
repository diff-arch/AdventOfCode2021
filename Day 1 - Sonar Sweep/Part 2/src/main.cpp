//
//  main.cpp
//  ADVENT OF CODE 2021: Day 1 - Sonar Sweep (Part 2)
//
//  Created by diff-arch on 01/12/2021.
//
//  Goal:    Consider sums of a three-measurement sliding window. 
//           How many sums are larger than the previous sum?
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
	
	int prev_sum;
	int count = 0;
	
	for (int i = 0; i < data.size() - 2; i++) {
		int curr_sum = 0;
		
		for (int j = i; j < i + 3; j++) {
			curr_sum += data[j];
		}
		
		if (i > 0 && curr_sum > prev_sum)
				count++;
		
		prev_sum = curr_sum;
	}
	
	std::cout << "Larger measurments: " << count << "\n";
}