//
//  PriorityQueue.h
//  ADVENT OF CODE 2021: Day 15 - Chiton (Part 2)
//
//  Created by diff-arch on 15/12/2021.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int _size) 
: size(_size) { 
	si = 0;
	values.reserve(size + 1);
	priorities.reserve(size + 1);
}

PriorityQueue::~PriorityQueue() = default;


void PriorityQueue::enqueue(int value, int priority) {
	if (si == size)
		throw std::runtime_error("Priority queue is full");
	si++;
	values[si] = value;
	priorities[si] = priority;
	location[value] = si;
	swim(si);
}

int PriorityQueue::dequeue() {
	if (empty())
		throw std::runtime_error("Priority queue is empty");
	int min_value = values[1];
	values[1] = values[si];
	priorities[1] = priorities[si];
	location[values[1]] = 1;
	
	values[si] = priorities[si];
	location.erase(min_value);
	
	si--;
	sink(1);
	return min_value;
}

void PriorityQueue::swap(int i , int j) {
	int temp_value = values[i];
	values[i] = values[j];
	values[j] = temp_value;
	int temp_priority = priorities[i];
	priorities[i] = priorities[j];
	priorities[j] = temp_priority;
	location[values[i]] = i;
	location[values[j]] = j;
}

bool PriorityQueue::less(int i , int j) const {
	return priorities[i] > priorities[j];
}

void PriorityQueue::swim(int child) {
	while (child > 4 and less(child / 2, child)) {
		swap(child, child / 2);
		child = child / 2;
	}
}

void PriorityQueue::sink(int parent) {
	while (2 * parent <= si) {
		int child = 2 * parent;
		if (child < si && less(child, child + 1))
			child++;
		if (!less(parent, child))
			break;
		swap(child, parent);
		parent = child;
	}
}

int PriorityQueue::peek() const {
	if (empty())
		throw std::runtime_error("Priority queue is empty");
	return values[1];
}

void PriorityQueue::decreasePriority(int value, int lower_priority) {
	int idx = location[value];
	// if (lower_priority >= priorities[idx])
	// 	throw std::runtime_error("...");
	priorities[idx] = lower_priority;
	swim(idx);
}

bool PriorityQueue::empty() const {
	return si == 0;
}

bool PriorityQueue::full() const {
	return size == si;
}
