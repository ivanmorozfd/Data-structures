#pragma once
#include "AvlTree.h"
class AvlTreeHelper {
private:
	AvlTreeHelper() = default;
	~AvlTreeHelper() = default;
public:
	template<typename T>
	static std::string getInOrderTraverse(AvlTree<T>* tree) {

	}
	template<typename T>
	static std::string getPreOrderTraverse(AvlTree<T>* tree) {

	}
	template<typename T>
	static std::string getPostOrderTraverse(AvlTree<T>* tree) {

	}
	template<typename T>
	static void printInOrder(AvlTree<T>* tree) {

	}
	template<typename T>
	static void printPreOrder(AvlTree<T>* tree) {

	}
	template<typename T>
	static void printPostOrder(AvlTree<T>* tree) {

	}
	template<typename T>
	static std::string serialize(AvlTree<T>* tree) {

	}
	template<typename T>
	static AvlTree<T>* deserialize(std::string serializedTree) {

	}
	template<typename T>
	static void writeToFile(AvlTree<T>* tree, std::ofstream& outputStream) {

	}
	template<typename T>
	static AvlTree<T>* readFromFile(std::ifstream& inputStream) {

	}
};