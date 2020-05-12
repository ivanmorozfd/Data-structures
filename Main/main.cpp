#include <iostream>
#include "Main/DoubleLinkedList.h"
#include <vector>
int main() {
	DoubleLinkedList<int> list = { 1,2,3,4,5 };
	list.replase(5, 1);
 
	for (auto& i : list)
		std::cout << i << " ";
	return 0;
}