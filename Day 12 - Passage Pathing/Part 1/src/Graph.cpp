//
//  Graph.cpp
//  ADVENT OF CODE 2021: Day 12 - Passage Pathing (Part 1)
//
//  Created by diff-arch on 12/12/2021.
//

#include "Graph.h"


Edge::Edge() = default;

Edge::Edge(const std::string& _from, const std::string& _to, bool _directed)
	: from(_from), to(_to), directed(_directed) { }

Edge::~Edge() = default;


// //--------------------------------------------------------------


Graph::Graph() = default;

Graph::~Graph() = default;


void Graph::addEdge(const std::string& _from_to) {
	std::vector<std::string> ft = split(_from_to, "-");
	edges[ft[0]].emplace_back(ft[0], ft[1], true);
	edges[ft[1]].emplace_back(ft[1], ft[0], true);
}

void Graph::addEdges(const std::vector<std::string>& _from_tos) {
	for (const std::string& sft : _from_tos)
		addEdge(sft);
}

std::vector<std::string> Graph::getIncidentNodes(const std::string& node) {
	std::vector<std::string> incident;
	for (const Edge& e : edges[node])
		incident.push_back(e.to);
	return incident;
}

int Graph::countPathsRec(const std::string& from, const std::string& to, 
												 std::vector<std::string>& visited, 
												 std::vector<std::string>& path) {
	path.push_back(from);
	
	if (from == to) {
		return 1;
	}
	
	int count = 0;
	for (const std::string& next : getIncidentNodes(from)) {
		std::vector<std::string> cvisited = visited;
		if (isLower(next)) {
			if (std::find(std::begin(cvisited), std::end(cvisited), next) != std::end(cvisited))
				continue;
			else
				cvisited.push_back(next);
		}
		count += countPathsRec(next, to, cvisited, path);
	}
	
	return count;
}


//--------------------------------------------------------------


std::ostream& operator <<(std::ostream& os, const Edge& e) {
	return os << "Edge(" << e.from << ", " << e.to << ", " << e.directed << ")";
}

std::ostream& operator <<(std::ostream& os, const Graph& g) {
	os << "Graph( ";
	int i = 0;
	for (const std::pair< std::string, std::vector<Edge> > n : g.edges) {
		if (i > 0)
			os << ", ";
		os << n.first << ": [";
		for (int j = 0; j < n.second.size(); j++) {
			if (j > 0)
				os << ", ";
			os << n.second[j].to;
		}
		os << "]";
		i++;
	}
	os << " )";
	return os;
}
