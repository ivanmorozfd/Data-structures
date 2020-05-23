#pragma once
#include "BinarySearchTree.h"
class BinarySearchTreeHelper {
private:
	BinarySearchTreeHelper() = default;
	~BinarySearchTreeHelper() = default;
public:
	template<typename T>
	static std::string getInOrderTraverse(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static std::string getPreOrderTraverse(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static std::string getPostOrderTraverse(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static void printInOrder(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static void printPreOrder(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static void printPostOrder(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static std::string serialize(BinarySearchTree<T>* tree) {

	}
	template<typename T>
	static BinarySearchTree<T>* deserialize(std::string serializedTree) {

	}
	template<typename T>
	static void writeToFile(BinarySearchTree<T>* tree,std::ofstream& outputStream) {
	
	}
	template<typename T>
	static BinarySearchTree<T>* readFromFile(std::ifstream& inputStream) {

	}
};