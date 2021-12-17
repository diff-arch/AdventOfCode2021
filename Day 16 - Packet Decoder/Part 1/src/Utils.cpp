//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 16 - Packet Decoder (Part 1)
//
//  Created by diff-arch on 16/12/2021.
//

#include "Utils.h"


std::string readLine(const char* filepath) {
	std::fstream file;
	file.open(filepath, std::ios::in);
	if (!file)
		throw std::runtime_error("No such file!");

	std::string line; 
	std::getline(file, line);
	file.close();
	return line;
}


std::vector<std::string> readData(const char* filepath) {
	std::fstream file;
	file.open(filepath, std::ios::in);

	if (!file)
		throw std::runtime_error("No such file!");

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)) {
		if (line.length() > 0)
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


std::string hexadecimalToBinary(const std::string& h) {
	std::string binary;
	for (const char& c : h) {
		switch (c) {
			case '0':
				binary += "0000";
				break;
			case '1':
				binary += "0001";
				break;
			case '2':
				binary += "0010";
				break;
			case '3':
				binary += "0011";
				break;
			case '4':
				binary += "0100";
				break;
			case '5':
				binary += "0101";
				break;
			case '6':
				binary += "0110";
				break;
			case '7':
				binary += "0111";
				break;
			case '8':
				binary += "1000";
				break;
			case '9':
				binary += "1001";
				break;
			case 'A':
				binary += "1010";
				break;
			case 'B':
				binary += "1011";
				break;
			case 'C':
				binary += "1100";
				break;
			case 'D':
				binary += "1101";
				break;
			case 'E':
				binary += "1110";
				break;
			case 'F':
				binary += "1111";
				break;
			default:
				break;
		}
	}
	return binary;
}


int toDecimal(const std::string& binary) {
	int val = 0;
	int tmp = 1;
	for (int i = binary.length() - 1; i >= 0; i--) {
		if (binary[i] == '1')
			val += tmp;
		tmp *= 2; 
	}
	return val;
}
