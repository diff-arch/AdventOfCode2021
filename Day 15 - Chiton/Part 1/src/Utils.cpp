//
//  Utils.cpp
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 1)
//
//  Created by diff-arch on 15/12/2021.
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


void relax(int from, int to, Grid& g, std::map<int, int>& dist_to, 
           std::map<int, int>& cell_to, PriorityQueue& pq) {
	int weight = g.cells[to];
	if (dist_to[from] + weight < dist_to[to]) {
		dist_to[to] = dist_to[from] + weight;
		cell_to[to] = from;
		pq.decreasePriority(to, dist_to[to]);
	}
}


std::pair<std::map<int, int>, std::map<int, int>> dijkstra(Grid& g, int source) {
	std::map<int, int> dist_to;
	for (int i = 0; i < g.getSize(); i++)
		dist_to[i] = std::numeric_limits<int>::max();
	dist_to[source] = 0;
	
	PriorityQueue pq = {g.getSize()};
	pq.enqueue(source, dist_to[source]);
	for (int i = 0; i < g.getSize(); i++) {
		if (i != source)
			pq.enqueue(i, std::numeric_limits<int>::max());
	}
	
	std::map<int, int> cell_to;
	while (!pq.empty()) {
		int current = pq.peek();
		std::vector<int> adjacent = g.getAdjacent(current);
		for (int ia : adjacent) {
			if (ia != current)
				relax(current, ia, g, dist_to, cell_to, pq);
		}
		pq.dequeue();
	}
	return std::make_pair(dist_to, cell_to);
}


std::vector<int> path_to(std::map<int, int>& cell_to, int source, int target) {
	std::vector<int> path;
	if (cell_to.find(target) == cell_to.end()) {
		std::cout << "Unreachable.";
		return path;
	}
	int current = target;
	while (current != source) {
		path.push_back(current);
		current = cell_to[current];
	}
	path.push_back(source);
	std::reverse(path.begin(), path.end());
	return path;
}
