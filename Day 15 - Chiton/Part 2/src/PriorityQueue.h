//
//  PriorityQueue.h
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 2)
//
//  Created by diff-arch on 15/12/2021.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>


struct PriorityQueue {
	
	PriorityQueue(int _size);
	~PriorityQueue();
	
	void enqueue(int value, int priority);
	int dequeue();
	
	void swap(int i , int j);
	bool less(int i , int j) const;
	void swim(int child);
	void sink(int parent);
	int peek() const;
	void decreasePriority(int value, int lower_priority);
	bool empty() const;
	bool full() const;
	
	int size, si;
	std::vector<int> values;
	std::vector<int> priorities;
	std::map<int, int> location;
	
};


#endif