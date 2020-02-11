#include <iostream>
#include "Main/SingleLinkedList.h"
int main() {
	SingleLinkedList<int> list;
	list.push_back(1);
	list.push_front(5);
	list.push_front(6);
	list.push_back(5);
	list.push_back(7);
	for (auto& i : list) {
		std::cout << i;
	}
	return 0;
}