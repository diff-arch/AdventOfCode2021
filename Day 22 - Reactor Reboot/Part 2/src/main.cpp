//
//  main.cpp
//  ADVENT OF CODE 2021: Day 22 - Reactor Reboot (Part 2)
//
//  Created by diff-arch on 31/12/2021.
//
//  Inspired by Neal Wu's solution from YouTube:
//  https://www.youtube.com/watch?v=YKpViLcTp64
//
//  Goal:    Starting again with all cubes off, execute all reboot steps.
//           Afterward, considering all cubes, how many cubes are on?
//
//  Compile: g++ -std=c++20 -o bin/a.out src/*.cpp
//  Run:     ./bin/a.out
//


#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <regex>


#include "Region.h"
#include "Utils.h"


int main() {
    
  const char* fpath = "../bin/data/reactor-reboot.txt";  // insert your path
  std::vector<std::string> lines = readData(fpath);
  
  std::vector<int> x_coords, y_coords, z_coords;
  x_coords.reserve(lines.size() * 2);
  y_coords.reserve(lines.size() * 2);
  z_coords.reserve(lines.size() * 2);
  
  std::vector<Region3d> regions;
  regions.reserve(lines.size());
  
  std::regex pattern("^(on|off) x=(-?\\d+)..(-?\\d+),y=(-?\\d+)..(-?\\d+),z=(-?\\d+)..(-?\\d+)$");
  std::smatch match;
  for (const std::string& line : lines) {
    if (!std::regex_search(line, match, pattern))
      throw std::runtime_error("No matches found for line: " + line);
    
    regions.emplace_back(
      (match[1] == "on") ? true : false,
      std::stoi(match[2]), std::stoi(match[3]) + 1,
      std::stoi(match[4]), std::stoi(match[5]) + 1,
      std::stoi(match[6]), std::stoi(match[7]) + 1
    );
    
    Region3d& current = regions.back();
    x_coords.emplace_back(current.dx.from);
    x_coords.emplace_back(current.dx.to);
    y_coords.emplace_back(current.dy.from);
    y_coords.emplace_back(current.dy.to);
    z_coords.emplace_back(current.dz.from);
    z_coords.emplace_back(current.dz.to);
  }
  
  std::sort(x_coords.begin(), x_coords.end());
  std::sort(y_coords.begin(), y_coords.end());
  std::sort(z_coords.begin(), z_coords.end());
  int len = (int)(x_coords.size());
  
  auto get_index = [](std::vector<int>& coords, int c) {
    return (int)(std::lower_bound(coords.begin(), coords.end(), c) - coords.begin());
  };
  
  std::vector< std::vector< std::vector<bool> > > grid(
    len, std::vector< std::vector<bool> >(len, std::vector<bool>(len, false))
  );
  
  for (const Region3d& r : regions) {
    int x1 = get_index(x_coords, r.dx.from);
    int x2 = get_index(x_coords, r.dx.to);
    int y1 = get_index(y_coords, r.dy.from);
    int y2 = get_index(y_coords, r.dy.to);
    int z1 = get_index(z_coords, r.dz.from);
    int z2 = get_index(z_coords, r.dz.to);
    
    for (int x = x1; x < x2; x++)
      for (int y = y1; y < y2; y++)
        for (int z = z1; z < z2; z++)
          grid[x][y][z] = r.on;
  }
  
  long int count = 0;
  
  for (int x = 0; x < len - 1; x++) {
    for (int y = 0; y < len - 1; y++) {
      for (int z = 0; z < len - 1; z++) {
        int ix = x_coords[x + 1] - x_coords[x];
        int iy = y_coords[y + 1] - y_coords[y];
        int iz = z_coords[z + 1] - z_coords[z];
        count += (long int)(grid[x][y][z]) * ix * iy * iz;
      }
    }
  }
  
  std::cout << "ON Cubes: " << count << "\n";
}
