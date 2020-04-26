#include <iostream>
#include "Main/DoubleLinkedList.h"
int main() {
	DoubleLinkedList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	for (auto& i : list)
		i = 5;
	for (auto& i : list)
		std::cout << i;
	return 0;
}