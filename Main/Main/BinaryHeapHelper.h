#pragma once
#include "BinaryHeap.h"
#include "HelperBase.h"
class BinaryHeapHelper:public virtual HelperBase {
private:
	BinaryHeapHelper() = default;
	~BinaryHeapHelper() = default;
public:
	template<typename T>
	static void print_heap(BinaryHeap<T>* heap) {
		for (auto& i : heap->data)
			std::cout << i << " ";
		std::cout << std::endl;
	}
	template<typename T>
	static void writeToFile(BinaryHeap<T>* heap, std::ofstream& outputStream) {
		for (auto& i : heap->data)
			outputStream << i << " ";
	}
	template<typename T>
	static BinaryHeap<T>* readFromFile(std::ifstream& inputStream) {
		BinaryHeap<T>* heap = new BinaryHeap<T>();
		vector<T> tmpdata;
		while (!inputStream.eof()) {
			T a;
			inputStream >> a;
			tmpdata.push_back(a);
		}
		heap->data = tmpdata;
		return heap;
	}
};