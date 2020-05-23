#pragma once
#include "RBTree.h"
class RBTreeHelper {
private:
	RBTreeHelper() = default;
	~RBTreeHelper() = default;
public:
	template<typename T>
	static std::string getInOrderTraverse(RBTree<T>* tree) {

	}
	template<typename T>
	static std::string getPreOrderTraverse(RBTree<T>* tree) {

	}
	template<typename T>
	static std::string getPostOrderTraverse(RBTree<T>* tree) {

	}
	template<typename T>
	static void printInOrder(RBTree<T>* tree) {

	}
	template<typename T>
	static void printPreOrder(RBTree<T>* tree) {

	}
	template<typename T>
	static void printPostOrder(RBTree<T>* tree) {

	}
	template<typename T>
	static std::string serialize(RBTree<T>* tree) {

	}
	template<typename T>
	static RBTree<T>* deserialize(std::string serializedTree) {

	}
	template<typename T>
	static void writeToFile(RBTree<T>* tree, std::ofstream& outputStream) {

	}
	template<typename T>
	static RBTree<T>* readFromFile(std::ifstream& inputStream) {

	}
};