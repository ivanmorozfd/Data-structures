#pragma once
#include "Stack.h"
#include "HelperBase.h"
/*!
	Static class functions library
	\brief Use to work with Stack
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
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
			outStream << tmp->data << " ";
		} while (tmp = tmp->prev);
	}
	template<class T>
	static Stack<T>* readFromFile(std::ifstream& inputStream) {
		Stack<T>* stack = new Stack<T>();
		while (inputStream.eof()) {
			std::string a;
			inputStream >> a;
			stack->push(std::stoi(a));
		}
		return stack;
	}
};