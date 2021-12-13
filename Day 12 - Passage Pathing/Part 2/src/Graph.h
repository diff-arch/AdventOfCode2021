//
//  Graph.h
//  ADVENT OF CODE 2021: Day 12 - Passage Pathing (Part 2)
//
//  Created by diff-arch on 12/12/2021.
//

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Utils.h"


struct Edge {

	Edge();
	Edge(const std::string& _from, const std::string& _to, bool _directed);
	~Edge();

	friend std::ostream& operator <<(std::ostream& os, const Edge& e);

	std::string from, to;
	bool directed;

};


struct Graph {

	Graph();
	~Graph();
	
	friend std::ostream& operator <<(std::ostream& os, const Graph& g);
	
	void addEdge(const std::string& _from_to);
	void addEdges(const std::vector<std::string>& _from_tos);
	std::vector<std::string> getIncidentNodes(const std::string& node);
	int countPathsRec(const std::string& from, const std::string& to, 
										std::vector<std::string>& visited, std::vector<std::string>& path,
										int visit_small=1);
	
	std::map< std::string, std::vector<Edge> > edges;
	
};


#endif