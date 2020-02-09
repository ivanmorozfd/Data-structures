#include <iostream>
#include "Main/DoubleLinkedList.h"
int main() {
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_back(7);
	list.push_back(8);
	DoubleLinkedList<int>::iterator it1 = list.begin();
	for (auto& i : list) {
		std::cout << i;
	}
	return 0;
}