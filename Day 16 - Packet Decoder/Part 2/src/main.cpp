//
//  main.cpp
//  ADVENT OF CODE 2021: Day 16 - Packet Decoder (Part 2)
//
//  Created by diff-arch on 16/12/2021.
//
//  Inspired by William Feng's Pythonic solution that he showed here:
//  https://www.youtube.com/watch?v=qYMFGESBOLE
//
//  Goal:    What do you get if you evaluate the expression represented
//           by your hexadecimal-encoded BITS transmission?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "Utils.h"


long int operate(int type_id, std::vector<long int> values) {
	long int val = -1;
	switch(type_id) {
		case 0:
			val = 0;
			for (long int v : values)
				val += v;
			break;
		case 1:
			val = 1;
			for (long int v : values)
				val *= v;
			break;
		case 2:
			std::sort(values.begin(), values.end());
			val = values[0];
			break;
		case 3:
			std::sort(values.begin(), values.end());
			val = values.back();
			break;
		case 5:
			val = (values[0] > values[1]) ? 1 : 0;
			break;
		case 6:
			val = (values[0] < values[1]) ? 1 : 0;
			break;
		case 7:
			val = (values[0] == values[1]) ? 1 : 0;
			break;
	}
	return val;
}


std::pair<long int, int> parseBinary(const std::string& b, long int si) {
	int version = toDecimal(b.substr(si, 3));
	int type_id = toDecimal(b.substr(si + 3, 3));
	
	if (type_id == 4) {  // literal value
		si += 6;
		long int literal_val = 0;
		while (true) {
			literal_val = literal_val * 16 + toDecimal(b.substr(si + 1, 4));
			si += 5;
			if (b[si-5] == '0')
				return std::make_pair(literal_val, si);
		}
	}
	
	else {  // Operator
		int length_type = b[si+6] - '0';
		std::vector<long int> sub_values;
		
		if (length_type == 0) {  // 15 bit field (indicating total length of bits of sub-packets)
			int num_bits = toDecimal(b.substr(si + 7, 15));
			int start_i = si + 7 + 15;
			si = start_i;
			while (true) {
				std::pair<long int, int> p = parseBinary(b, si);
				sub_values.push_back(p.first);
				int next_i = p.second;
				si = next_i;
				if (next_i - start_i == num_bits)
					break;
			}
		
		} else {  // 11 bit field (sub-packets immediately contained)
			int num_packets = toDecimal(b.substr(si + 7, 11));
			si += 7 + 11;
			for (int i = 0; i < num_packets; i++) {
				std::pair<long int, int> p = parseBinary(b, si);
				sub_values.push_back(p.first);
				si = p.second;
			}
		}
		
		return std::make_pair(operate(type_id, sub_values), si);
	}
}


int main() {
    
  const char* fpath = "../bin/data/packet-decoder.txt";  // insert your path
	std::string line; 
	line = readLine(fpath);
	
	// More examples;
	// line = "C200B40A82";  // 3
	// line = "04005AC33890";  // 54
	// line = "880086C3E88112";  // 7
	// line = "CE00C43D881120";  // 9
	// line = "D8005AC2A8F0";  // 1
	// line = "F600BC2D8F";  // 0
	// line = "9C005AC2F8F0";  // 0
	// line = "9C0141080250320F1802104A08"; // 1
	
	std::string binary = hexadecimalToBinary(line);
	// std::cout << "Binary Represenation: " << binary_rep << "\n";

	std::pair<long int, int> p = parseBinary(binary, 0);
	
	std::cout << "Result: " << p.first << "\n";
	
}
