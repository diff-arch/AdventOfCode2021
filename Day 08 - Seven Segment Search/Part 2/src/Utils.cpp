//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 8 - Seven Segment Search (Part 2)
//
//  Created by diff-arch on 08/12/2021.
//

#include "Utils.h"


std::vector<std::string> readData(const char* filepath) {
	std::fstream file;
	file.open(filepath, std::ios::in);

	if (!file)
		throw std::runtime_error("No such file!");

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)) {
		lines.emplace_back(line);
	}

	file.close();

	return lines;
}


std::vector<std::string> split(std::string s, const std::string& delimiter) {
	std::vector<std::string> words;
	int pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		std::string word = s.substr(0, pos);
		if (word.length() > 0)
			words.push_back(word);
		s.erase(0, pos + delimiter.length());
	}
	if (s.length() > 0)
		words.emplace_back(s);  // last word
	return words;
}


std::vector<std::string> getPermutations(const std::string& s) {
	std::vector<std::string> permutations;
	std::string sc = s;
	do {
		permutations.push_back(sc);
	} while (std::next_permutation(sc.begin(), sc.end()));
	return permutations;
}


int toInteger(const std::vector<int>& v) {
	std::vector<int> vc = v;
	std::reverse(vc.begin(), vc.end());
	int decim = 1;
	int total = 0;
	for (int& i : vc) {
		total += i * decim;
		decim *= 10;
	}
	return total;
}
