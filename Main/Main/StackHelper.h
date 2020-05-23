#pragma once
#include "Stack.h"
#include "HelperBase.h"
class StackHelper: virtual public HelperBase {
private:
	StackHelper() = default;
	~StackHelper() = default;
public:
	template<class T>
	static void print_stack(Stack<T>* stack) {
		_StackNode<T>* tmp = stack->_top;
		do {
			std::cout << tmp->data << " ";
		} while (tmp = tmp->prev);
		std::cout << std::endl;
	}
	template<class T>
	static void writeToFile(Stack<T>* stack,std::ofstream& outStream) {
		_StackNode<T>* tmp = stack->_top;
		do {
			outStream << tmp->data;
		} while (tmp = tmp->prev);
	}
	template<class T>
	static Stack<T>* readFromFile(std::ifstream& inputStream) {
		Stack<T>* stack = new Stack<T>();
		while (inputStream.eof()) {
			T a;
			inputStream >> a;
			stack->push(a);
		}
		return stack;
	}
};