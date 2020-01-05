#include "Main/Stack.h"
#include <iostream>
int main() {
	Stack<int> test(5);
	test.push(5);
	test.push(7);
	std::cout << test.pop() << std::endl;
	std::cout << test.pop() << std::endl;
	return 0;
}