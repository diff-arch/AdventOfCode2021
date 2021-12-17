//
//  main.cpp
//  ADVENT OF CODE 2021: Day 16 - Packet Decoder (Part 1)
//
//  Created by diff-arch on 16/12/2021.
//
//  Goal:    Decode the structure of your hexadecimal-encoded BITS transmission; 
//           what do you get if you add up the version numbers in all packets?
//
//  Compile: g++ -std=c++11 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"


bool isValidBinary(const std::string& b) {
	if (b.length() == 0)
		return false;
	for (const char& c : b) {
		if ((int)(c - '0') != 0)
			return true;
	}
	return false;
}


int addVersionsRec(const std::string& binary, int count=-1) {
	
	if (!isValidBinary(binary))
		return 0;
	
	if (count == 0)
		return addVersionsRec(binary, -1);
	
	int version = toDecimal(binary.substr(0, 3));
	int type_id = toDecimal(binary.substr(3, 3));
	// std::cout << "Version: " << version << ", Type ID: " << type_id << "\n";
	
	if (type_id == 4) {  // literal value
		int idx = 6;
		std::string literal_binary;
		while (true) {
			int prefix = binary[idx] - '0';  // 0 = last
			literal_binary += binary.substr(idx + 1, 4);
			idx += 5;
			if (prefix == 0)
				break;
		}
		int literal_val = toDecimal(literal_binary);
		return version + addVersionsRec(binary.substr(idx, binary.length() - idx), --count);
	}
	
	else {  // operator
		int length_type = binary[6] - '0';
		if (length_type == 0) {  // 15 bit field (indicating total length of bits of sub-packets)
			int num_bits = toDecimal(binary.substr(7, 15));
			return version 
						 + addVersionsRec(binary.substr(22, num_bits), -1)
						 + addVersionsRec(binary.substr(22 + num_bits, binary.length() - 22 + num_bits), --count);
		} else {  // 11 bit field (sub-packets immediately contained)
			int num_subpacks = toDecimal(binary.substr(7, 11));
			return version + addVersionsRec(binary.substr(18, binary.length() - 18), num_subpacks);
		}
	}

}


int main() {
    
  const char* fpath = "/Users/marc/Desktop/Advent of Code 2021/Day 16 - Packet Decoder/Part 1/bin/data/packet-decoder.txt";  // insert your path
	std::string line;
	line = readLine(fpath);
	
	// More examples;
	// line = "8A004A801A8002F478";  // 16
	// line = "620080001611562C8802118E34";  // 12
	// line = "C0015000016115A2E0802F182340";  // 23
	// line = "A0016C880162017C3686B18A3D4780";  // 31
	
	std::string binary_rep = hexadecimalToBinary(line);
	// std::cout << "Binary Represenation: " << binary_rep << "\n";
	
	std::cout << "Summed Version Numbers: " << addVersionsRec(binary_rep) << "\n";
	
}
