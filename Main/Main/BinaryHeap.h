#pragma once
#include "core.h"
#include "Container.h"
#include <vector>
#include "BinaryHeapExceptions.h"
using std::vector;
using std::initializer_list;

/*!
	BinaryHeap class
	\brief Use to store data and sorting arrays
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class BinaryHeap : public Container {
	friend class BinaryHeapHelper;
	using valueType = _T;// Element type
	using reference = valueType&;// Reference element type
	using const_reference = const valueType&;// Const reference
	using container = vector<_T>;
private:
	container data;//!< Contains values
public:
	/*!
		Checking the BinaryHeap for empty space
		\param[out] bool True,if BinaryHeap is empty,otherwise False
	*/
	bool isEmpty() const {
		return data.empty();
	}
	/*!
		Returns heap size
		\param[out] size_t heapSize
	*/
	size_t getSize() const {
		return data.size(); 
	}
	//add item to heap
	void addItem(const_reference item) {
		//push item to the value vector
		data.push_back(item);
		//get size and leaf parent
		size_t i = getSize() - 1;
		size_t parent = (i - 1) / 2;
		//the heap property may be violated
		//while its violated we swap element with parent
		while (i > 0 && data.at(parent) < data.at(i))	{
			std::swap(data[i],data[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}
	//This method is recover general property of heap
	void heapify(size_t i) {
		size_t leftChild;
		size_t rightChild;
		size_t largestChild;
		//iterate while general property of heap is not true
		for (;;) {
			leftChild = 2 * i + 1; // left child have 2i + 1 position in array
			rightChild = 2 * i + 2; // right child have 2i + 2 position in array
			largestChild = i; // set the largest child
			//searchind childs that greater than parent
			if (leftChild < getSize() 
				&& data.at(leftChild) > data.at(largestChild)) {
				largestChild = leftChild;
			}

			if (rightChild < getSize() 
				&& data.at(rightChild) > data.at(largestChild)) {
				largestChild = rightChild;
			}

			if (largestChild == i) 
				break;
	
			std::swap(data[largestChild],data[i]);
			i = largestChild;
		}
	}
	/*!
		get the max element of the heap and recover general purpose of the heap
		\param[out] valueType maxElement
	*/
	valueType getmax() {
		valueType item = data.at(0);
		data[0] = data.back();
		data.pop_back();
		heapify(0);
		return item;
	}
	/*!
		Peek BinaryHeap top
		\param[out] valueType value
	*/
	valueType peekMax() const {
		return data.at(0);
	}
	/*!
		Clear heap contents
	*/
	void clear()  {
		this->data.clear();	
	}
public:
	/*!
		Default BinaryHeap constructor
	*/
	BinaryHeap(): data() {}
	/*!
		Parameterized BinaryHeap constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	BinaryHeap(const initializer_list<_T>& data) {
		for (auto& i : data)
			this->addItem(i);
	}
	/*!
		BinaryHeap destructor
	*/
	~BinaryHeap() {
		this->clear();	
	}
};
