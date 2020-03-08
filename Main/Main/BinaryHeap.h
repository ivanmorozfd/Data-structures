#pragma once
#include <vector>
#include "BinaryHeapExceptions.h"
using std::vector;

template<typename T>
class BinaryHeap
{
public:
	int heapSize;	
	vector<T> data;
	int getSize() { return data.size(); }
	void addItem(T item)
	{
		data.push_back(item);
		int i = getSize() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && data[parent] < data[i])
		{
			int temp = data[i];
			data[i] = data[parent];
			data[parent] = temp;

			i = parent;
			parent = (i - 1) / 2;
		}
	}
	void heapify(int i)
	{
		int leftChild;
		int rightChild;
		int largestChild;

		for (; ; )
		{
			leftChild = 2 * i + 1;
			rightChild = 2 * i + 2;
			largestChild = i;

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

			int temp = data[i];
			data[i] = data[largestChild];
			data[largestChild] = temp;
			i = largestChild;
		}
	}
	int getmax()
	{
		int item;
		item = data[0];
		data[0] = data[getSize() - 1];
		heapSize--;
		heapify(0);
		return(item);
	}
	BinaryHeap() {

	}
};