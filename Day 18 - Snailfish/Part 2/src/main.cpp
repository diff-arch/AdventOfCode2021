//
//  main.cpp
//  ADVENT OF CODE 2021: Day 18 - Snailfish (Part 2)
//
//  Created by diff-arch on 30/12/2021.
//
//  Goal:    What is the largest magnitude of any sum of two different 
//           snailfish numbers from the homework assignment?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <regex>

#include "Utils.h"


std::pair<bool, std::string> explode(const std::string& s) {
	std::string result = s;
	int bracket_count = 0;
	bool found = false;
	int si;
	
	for (si = 0; si < s.length(); si++) {
		if (s[si] == '[') {
			bracket_count++;
			if (bracket_count == 5) {
				found = true;
				break;
			}
		} else if (s[si] == ']')
			bracket_count--;
	}
	if (!found) {
		return std::make_pair(false, s);
	}
 	
	std::string exploded = s.substr(si, s.find_first_of("]", si) - si + 1);
	std::smatch match;
	if (!std::regex_match(exploded, match, std::regex("^\\[(\\d+),(\\d+)\\]$")))
		throw std::runtime_error("Unable to match group of integers to explode.");
		
	int num1 = std::stoi(match[1]);
	int num2 = std::stoi(match[2]);
	std::string left_fragment  = s.substr(0, si);
	std::string right_fragment = s.substr(si + exploded.length(), s.length());
	
	if (std::regex_search(right_fragment, match, std::regex("^[\\[\\],]*(\\d+)"))) {
		int right_num = std::stoi(match[1]);
		int right_sum = right_num + num2;
		result.replace(
			si + exploded.length() + match.position(1), 
		    match[1].length(),
			std::to_string(right_sum)
		);
	}
    
  result.replace(si, exploded.length(), "0");
    
	if (std::regex_search(left_fragment, match, std::regex("(\\d+)[\\[\\],]*$"))) {
		int left_num = std::stoi(match[1]);
		int left_sum = left_num + num1;
		std::string left_str_sum = std::to_string(left_sum);
		result.replace(
			match.position(1), 
		    match[1].length(),
            std::to_string(left_sum)
		);
	}
	
	return std::make_pair(true, result);
}


void debugExplode() {
	std::vector < std::pair <std::string, std::string> > test_data {
		{"[[[[[4,3],4],4],[7,[[8,4],9]]],[1,1]]", "[[[[0,7],4],[7,[[8,4],9]]],[1,1]]"},
		{"[[[[0,7],4],[7,[[8,4],9]]],[1,1]]"    , "[[[[0,7],4],[15,[0,13]]],[1,1]]"},
		{"[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]", "[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"},
		{"[[[[[9,8],1],2],3],4]"                , "[[[[0,9],2],3],4]"},
		{"[7,[6,[5,[4,[3,2]]]]]"                , "[7,[6,[5,[7,0]]]]"},
		{"[[6,[5,[4,[3,2]]]],1]"                , "[[6,[5,[7,0]]],3]"},
		{"[[3,[2,[1,[7,3]]]],[6,[5,[4,[3,2]]]]]", "[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]"},
		{"[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]"    , "[[3,[2,[8,0]]],[9,[5,[7,0]]]]"}
	};
	
	std::cout << "TESTING EXPLODE FUNCTION\n";
	for (const auto& [test, answer] : test_data) {
		std::cout << "Explode: " << test << "\n";
		auto [success, result] = explode(test);
		if (!success)
			std::cout << " !  Parsing failed!";
		else {
			std::cout << " --> " << result << "\n";
			std::cout << ((result != answer) ? " =/= " : " === ") << result << "\n";
		}
		std::cout << "\n";
	}
}


std::pair<bool, std::string> split(const std::string& s) {
	std::string result = s;
	std::smatch match;
	if (std::regex_search(s, match, std::regex("(\\d{2,})"))) {
		double half = std::stod(match[0]) * 0.5;
		int left_num = std::floor(half);
		int right_num = std::ceil(half);
		std::string split_up = "[" + std::to_string(left_num) + "," + std::to_string(right_num) + "]";
		result.replace(match.position(0), match[0].length(), split_up);
        return std::make_pair(true, result);
	}
  return std::make_pair(false, result);
}


void debugSplit() {
	std::vector < std::pair <std::string, std::string> > test_data {
		{"[[[[0,7],4],[15,[0,13]]],[1,1]]"       , "[[[[0,7],4],[[7,8],[0,13]]],[1,1]]"},
		{"[[[[0,7],4],[[7,8],[0,13]]],[1,1]]"    , "[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]"},
		{"[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]" , "[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"},
	};
	
	std::cout << "TESTING SPLIT FUNCTION\n";
	for (const auto& [test, answer] : test_data) {
		std::cout << "Split: " << test << "\n";
		auto [success, result] = split(test);
		if (!success)
			std::cout << " !  Parsing failed!";
		else {
			std::cout << " --> " << result << "\n";
			std::cout << ((result != answer) ? " =/= " : " === ") << result << "\n";
		}
		std::cout << "\n";
	}
}


std::pair<bool, std::string> reduce(const std::string& s, bool verbose=false) {
	std::string result = s;
	bool success = false;

	while (true) {
		std::tie(success, result) = explode(result);
		if (success) {
			if (verbose) std::cout << "After Explosion: " << result << "\n";
			continue;
		}

		std::tie(success, result) = split(result);
		if (success) {
      if (verbose) std::cout << "After Split    : " << result << "\n";
			continue;
		}
		
		break;
	}
	
	if (result != s)
		success = true;
	return std::make_pair(success, result);
}


void debugReduce() {
	std::vector < std::pair <std::string, std::string> > test_data {
		{"[[[[[4,3],4],4],[7,[[8,4],9]]],[1,1]]"    , "[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"},
    {"[[[0,[4,5]],[0,0]],[[[4,5],[2,6]],[9,5]]]", "[[[[4,2],2],6],[8,7]]"},
	};
	
	std::cout << "TESTING REDUCE FUNCTION\n";
	for (const auto& [test, answer] : test_data) {
		std::cout << "Reduce: " << test << "\n";
		auto [success, result] = reduce(test, true);
		std::cout << " --> " << result << "\n";
		std::cout << ((result != answer) ? " =/= " : " === ") << result << "\n\n";
	}
}


std::pair<bool, std::string> add(const std::string& s1, const std::string& s2, bool verbose=false) {
	return reduce("[" + s1 + "," + s2 + "]", verbose);
}


void debugAdd() {
	std::vector< std::pair<std::string, std::string> > test_data = {
		{"[1,1], [2,2], [3,3], [4,4]"              , "[[[[1,1],[2,2]],[3,3]],[4,4]]"},
		{"[1,1], [2,2], [3,3], [4,4], [5,5]"       , "[[[[3,0],[5,3]],[4,4]],[5,5]]"},
		{"[1,1], [2,2], [3,3], [4,4], [5,5], [6,6]", "[[[[5,0],[7,4]],[5,5]],[6,6]]"},
		{"[1,1], [2,2], [3,3], [4,4], [5,5], [6,6]", "[[[[5,0],[7,4]],[5,5]],[6,6]]"},
    {"[[[0,[4,5]],[0,0]],[[[4,5],[2,6]],[9,5]]], "
     "[7,[[[3,7],[4,3]],[[6,3],[8,8]]]], "
     "[[2,[[0,8],[3,4]]],[[[6,7],1],[7,[1,6]]]], "
     "[[[[2,4],7],[6,[0,5]]],[[[6,8],[2,8]],[[2,1],[4,5]]]], "
     "[7,[5,[[3,8],[1,4]]]], [[2,[2,2]],[8,[8,1]]], "
     "[2,9], [1,[[[9,3],9],[[9,0],[0,7]]]], "
     "[[[5,[7,4]],7],1], [[[[4,2],2],6],[8,7]]", "[[[[8,7],[7,7]],[[8,6],[7,7]]],[[[0,7],[6,6]],[8,7]]]"}
	};

	std::cout << "TESTING ADD FUNCTION\n";
	
	std::string result;
	bool success;
	for (const auto& [data, answer] : test_data) {
		std::cout << "Add: " << data << "\n";
		std::vector<std::string> split_data = splitString(data, ", ");
		result = split_data[0];
		success = false;
		for (int i = 1; i < split_data.size(); i++) {
			std::tie(success, result) = add(result, split_data[i], true);
		}
		std::cout << " --> " << result << "\n";
		std::cout << ((result != answer) ? " =/= " : " === ") << answer << "\n\n";
	}
}


int getMagnitude(const std::string& s) {
  std::string result = s;
  
  auto evaluate = [](const std::string& s1, const std::string& s2)
    { return std::to_string(3 * std::stoi(s1) + 2 * std::stoi(s2)); };
  
  while (result[0] == '[') {
    std::smatch match;
    if (std::regex_search(result, match, std::regex("\\[(\\d+),(\\d+)\\]")))
      result.replace(match.position(0), match[0].length(), evaluate(match[1], match[2]));
  }
  return std::stoi(result);
}


void debugGetMagnitude() {
  std::vector < std::pair <std::string, int> > test_data {
    {"[[1,2],[[3,4],5]]"                                    , 143},
    {"[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"                    , 1384},
    {"[[[[1,1],[2,2]],[3,3]],[4,4]]"                        , 445},
    {"[[[[3,0],[5,3]],[4,4]],[5,5]]"                        , 719},
    {"[[[[5,0],[7,4]],[5,5]],[6,6]]"                        , 1137},
    {"[[[[8,7],[7,7]],[[8,6],[7,7]]],[[[0,7],[6,6]],[8,7]]]", 3488},
  };
  
  std::cout << "TESTING GETMAGNITUDE FUNCTION\n";
  
  int result;
  for (const auto& [data, answer] : test_data) {
    std::cout << "Calculate: " << data << "\n";
    result = getMagnitude(data);
    std::cout << " --> " << result;
    std::cout << ((result != answer) ? " =/= " : " === ") << answer << "\n\n";
  }
  
}


int main() {
    
  const char* fpath = "../bin/data/snailfish.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);
	
//  debugExplode();
//  debugSplit();
//  debugReduce();
//  debugAdd();
//  debugGetMagnitude();
  
  int max_magnitude = 0;
  std::string result;
  bool success;
  
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines.size(); j++) {
      if (i == j)
        continue;
      std:tie(success, result) = add(lines[i], lines[j]);
      int magnitude = getMagnitude(result);
      if (magnitude > max_magnitude)
        max_magnitude = magnitude;
    }
  }
  
  std::cout << "Largest Magnitude: " << max_magnitude << "\n";

}
