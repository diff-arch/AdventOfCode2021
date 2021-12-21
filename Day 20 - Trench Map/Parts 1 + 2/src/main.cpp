//
//  main.cpp
//  ADVENT OF CODE 2021: Day 20 - Trench Map (Part 1 & 2)
//
//  Created by diff-arch on 20/12/2021.
//
//  Goals:
//  Part 1:  Start with the original input image and apply the image enhancement 
//           algorithm twice, being careful to account for the infinite size of
//           the images. How many pixels are lit in the resulting image?
//
//	Part 2:  Start again with the original input image and apply the image enhancement 
//           algorithm 50 times. How many pixels are lit in the resulting image?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <set>

#include "Pixel.h"
#include "Utils.h"


std::pair<Pixel, Pixel> getBounds(const std::set<Pixel>& pixels) {
	int min_rows = std::numeric_limits<int>::max();
	int max_rows = std::numeric_limits<int>::min();;
	int min_cols = min_rows;
	int max_cols = max_rows;
	for (const Pixel& p : pixels) {
		if (p.x < min_rows) 
			min_rows = p.x;
		else if (p.x > max_rows) 
			max_rows = p.x;
		if (p.y < min_cols) 
			min_cols = p.y;
		else if (p.y > max_cols) 
			max_cols = p.y;
	}
	return std::make_pair(Pixel(min_rows, max_rows), Pixel(min_cols, max_cols));
}


void printPixels(const std::set<Pixel>& pixels) {
	std::pair<Pixel, Pixel> bounds = getBounds(pixels);
	for (int i = bounds.first.x - 2; i < bounds.first.y + 3; i++) {
		std::string row;
		for (int j = bounds.second.x - 2; j < bounds.second.y + 3; j++) {
			if (pixels.contains(Pixel(i, j)))
				row += '#';
			else
				row += '.';
		}
		std::cout << row << "\n";
	}
}


void enhance(std::set<Pixel>& pixels, const std::string& algorithm, bool hash) {
	std::set<Pixel> enhanced_pixels;
	std::pair<Pixel, Pixel> bounds = getBounds(pixels);

	for (int i = bounds.first.x - 2; i < bounds.first.y + 3; i++) {
		for (int j = bounds.second.x - 2; j < bounds.second.y + 3; j++) {
			std::string binary;
			for (int ai = -1; ai < 2; ai++) {
				for (int aj = -1; aj < 2; aj++) {
					if (hash)
						binary += (pixels.contains(Pixel(i + ai, j + aj))) ? '0' : '1';
					else
						binary += (pixels.contains(Pixel(i + ai, j + aj))) ? '1' : '0';
				}
			}
			if (hash && algorithm[toDecimal(binary)] == '#')
				enhanced_pixels.insert(Pixel(i, j));
			if (!hash && algorithm[toDecimal(binary)] == '.')
				enhanced_pixels.insert(Pixel(i, j));
		}
	}
	pixels = enhanced_pixels;
}


int main() {
   
	const char* fpath = "../bin/data/trench-map.txt";  // insert your path
	std::vector<std::string> lines = readData(fpath);

	std::string enhancement_algorithm = lines[0];
	std::vector<std::string> input_image(lines.begin() + 1, lines.begin() + lines.size());

	std::set<Pixel> lit_pixels;
	for (int i = 0; i < input_image.size(); i++){
		for (int j = 0; j < input_image[i].length(); j++){
			if (input_image[i][j] == '#')
				lit_pixels.insert(Pixel(i, j));
		}
	}
	
	for (int t = 0; t < 50; t++) {
		enhance(lit_pixels, enhancement_algorithm, t % 2);  // only works if enhancement_algorithm[0] = "#"
		
		if (t == 2)
			std::cout << "Lit Pixels After  " << t << " Iterations: " << lit_pixels.size() << "\n";
	}
	
	std::cout << "Lit Pixels After 50 Iterations: " << lit_pixels.size() << "\n";

}
