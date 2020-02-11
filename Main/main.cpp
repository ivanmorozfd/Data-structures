#include <iostream>
#include "Main/BinarySearchTree.h"
#include "Main/BinaryHeap.h"
#include "Main/Queue.h"
int main() {
	Queue<int> queue;

	queue.push(5);
	queue.push(6);
	queue.push(7);
	queue.pop();
	for (auto& i : queue)
	{
		std::cout << i;
	}
	return 0;
}