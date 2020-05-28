#pragma once
#include "Queue.h"
#include "HelperBase.h"
/*!
	Static class functions library
	\brief Use to work with Queue
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class QueueHelper:virtual public HelperBase {
private:
	QueueHelper() = default;
	~QueueHelper() = default;
public:
	template<class T>
	static void print_queue(Queue<T>* queue) {
		_QueueNode<T>* temp = queue->pFront;
		do {
			std::cout << temp->data << " ";
		} while (temp = temp->next);
		std::cout << std::endl;
	}
	template<class T>
	static void writeToFile(Queue<T>* queue, std::ofstream& os) {
		_QueueNode<T>* temp = queue->pFront;
		do {
			os << temp->data << " ";
		} while (temp = temp->next);
	}
	template<class T>
	static Queue<T>* readFromFile(std::ifstream& inputStream) {
		Queue<T>* queue = new Queue<T>();
		while (!inputStream.eof()) {
			T a;
			inputStream >> a;
			queue->push(a);
		}
		return queue;
	}
};
