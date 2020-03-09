	#pragma once
#include <vector>
#include "BinaryHeapExceptions.h"
using std::vector;

template<typename _T>
class BinaryHeap
{
public:
	vector<_T> data;
	int getSize() 
	{
		return data.size(); 
	}
	void addItem(_T item)
	{
		//push item to the value vector
		data.push_back(item);
		//get count and leaf parent
		int i = getSize() - 1;
		int parent = (i - 1) / 2;
		//the heap property may be violated
		//while its violated we swap element with parent
		while (i > 0 && data[parent] < data[i])	
		{
			int temp = data[i];
			data[i] = data[parent];
			data[parent] = temp;
			i = parent;
			parent = (i - 1) / 2;
		}
	}
	//This method is recover general property of heap
	void heapify(_T i)
	{
		int leftChild;
		int rightChild;
		int largestChild;

		for (; ; )
		{
			leftChild = 2 * i + 1; // left child have 2i + 1 position in array
			rightChild = 2 * i + 2; // right child have 2i + 2 position in array
			largestChild = i; // set the largest child

			if (leftChild < getSize() && data[leftChild] > data[largestChild])
			{
				largestChild = leftChild;
			}

			if (rightChild < getSize() && data[rightChild] > data[largestChild])
			{
				largestChild = rightChild;
			}

			if (largestChild == i)
			{
				break;
			}
			std::swap(data[largestChild],data[i]);
			i = largestChild;
		}
	}
	_T getmax()
	{
		_T item;
		item = data[0];
		data[0] = data[getSize() - 1];
		heapify(0);
		return item;
	}
	BinaryHeap() 
	{

	}
};