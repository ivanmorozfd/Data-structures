#include <iostream>
#include "Main/SingleLinkedList.h"
int main() {
	SingleLinkedList<int> list({ 1,2,3,4 });
	for (auto& i : list) {
		std::cout << i;
	}
	return 0;
}