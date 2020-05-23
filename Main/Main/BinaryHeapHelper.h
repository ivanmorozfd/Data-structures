#pragma once
#include "BinaryHeap.h"

class BinaryHeapHelper {
private:
	BinaryHeapHelper() = default;
	~BinaryHeapHelper() = default;
public:
	template<typename T>
	static void print_heap(BinaryHeap<T>* heap) {

	}
	template<typename T>
	static void writeToFile(BinaryHeap<T>* heap, std::ofstream& outputStream) {

	}
	template<typename T>
	static BinaryHeap<T>* readFromFile(std::ifstream& inputStream) {

	}
	template<typename T>
	static void heapSort(T* arr, size_t size) {

	}
};