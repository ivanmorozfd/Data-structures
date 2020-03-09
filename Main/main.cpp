#include <iostream>
#include "Main/BinaryHeap.h"
int main() {
	BinaryHeap<int> heap;
	heap.addItem(5);
	heap.addItem(6);
	heap.addItem(4);
	heap.addItem(610);
	for (auto& i : heap.data)
		std::cout << i;
	return 0;
}