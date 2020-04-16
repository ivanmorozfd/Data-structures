#pragma once
#include <vector>
#include "BinaryHeapExceptions.h"
using std::vector;
using std::initializer_list;
template<typename _T>
class BinaryHeap
{
private:
	vector<_T> data;//contains values
public:
	bool isEmpty() const {
		return data.empty();
	}
	//returns size of the heap
	int getSize() const {
		return data.size(); 
	}
	//add item to heap
	void addItem(const _T& item) {
		//push item to the value vector
		data.push_back(item);
		//get counter and leaf parent
		int i = getSize() - 1;
		int parent = (i - 1) / 2;
		//the heap property may be violated
		//while its violated we swap element with parent
		while (i > 0 && data[parent] < data[i])	{
			std::swap(data[i],data[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}
	//This method is recover general property of heap
	void heapify(const _T& i)
	{
		int leftChild;
		int rightChild;
		int largestChild;
		//iterate while general property of heap is not true
		for (;;)
		{
			leftChild = 2 * i + 1; // left child have 2i + 1 position in array
			rightChild = 2 * i + 2; // right child have 2i + 2 position in array
			largestChild = i; // set the largest child
			//searchind childs that greater than parent
			if (leftChild < getSize() 
				&& data[leftChild] > data[largestChild]) {
				largestChild = leftChild;
			}

			if (rightChild < getSize() 
				&& data[rightChild] > data[largestChild]) {
				largestChild = rightChild;
			}

			if (largestChild == i) 
				break;
	
			std::swap(data[largestChild],data[i]);
			i = largestChild;
		}
	}
	//get the max element of the heap and recover general purpose of the heap
	_T getmax() {
		_T item = data.at(0);
		data[0] = data[getSize() - 1];
		heapify(0);
		return item;
	}
	_T peekMax() const {
		return data.at(0);
	}
	void clear()  {
		this->data.clear();	
	}
public:
	BinaryHeap(): 
	data() {}
	BinaryHeap(const BinaryHeap<_T>& other) { }
	BinaryHeap(const initializer_list<_T>& data) { }
	~BinaryHeap() {
		this->clear();	
	}
};
