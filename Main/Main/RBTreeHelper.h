#pragma once
#include "RBTree.h"
#include "HelperBase.h"
/*!
	Static class functions library
	\brief Use to work with RBTree
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class RBTreeHelper : public virtual HelperBase {
private:
	RBTreeHelper() = default;
	~RBTreeHelper() = default;
private:
	template<typename T>
	static void _serialize(_RBtreeNode<T>* node, std::stringstream& strStream) {
		if (!node) {
			strStream << "NULL" << " ";
			strStream << "NULLCOLOR" << " ";
			return;
		}
		strStream << node->key << " " <<  node->colorToString() << " ";// TODO
		_serialize(node->left, strStream);
		_serialize(node->right, strStream);

	}
public:
	template<typename T>
	static std::string getInOrderTraverse(RBTree<T>* tree) {
		std::stack<_RBtreeNode<T>*>* stack_node = new std::stack<_RBtreeNode<T>*>();
		std::string result = "";
		_RBtreeNode<T>* curr = tree->root;
		while (curr || !stack_node->empty()) {
			while (curr) {
				stack_node->push(curr);
				curr = curr->left;
			}
			curr = stack_node->top();
			stack_node->pop();

			result = result + std::to_string(curr->key) + " ";

			curr = curr->right;
		}
		return result;
	}
	template<typename T>
	static std::string getPreOrderTraverse(RBTree<T>* tree) {
		std::stack<_RBtreeNode<T>*>* nodeStack = new std::stack<_RBtreeNode<T>*>();
		nodeStack->push(tree->root);
		std::string result = "";
		while (nodeStack->empty() == false)
		{
			// Pop the top item from stack and print it
			_RBtreeNode<T>* node = nodeStack->top();
			result = result + std::to_string(node->key) + " ";
			nodeStack->pop();
			// Push right and left children to stack
			if (node->right)
				nodeStack->push(node->right);
			if (node->left)
				nodeStack->push(node->left);
		}
		return result;
	}
	template<typename T>
	static std::string getPostOrderTraverse(RBTree<T>* tree) {
		std::stack<_RBtreeNode<T>*>* stack_node = new std::stack<_RBtreeNode<T>*>();
		_RBtreeNode<T>* curr = tree->root;
		std::string result = "";
		while (curr || !stack_node->empty()) {
			while (curr) {
				stack_node->push(curr);
				curr = curr->right;
			}
			curr = stack_node->top();
			stack_node->pop();

			result = result + std::to_string(curr->key) + " ";

			curr = curr->left;
		}
		return result;
	}
	template<typename T>
	static void printInOrder(RBTree<T>* tree) {
		std::cout << getInOrderTraverse(tree);
	}
	template<typename T>
	static void printPreOrder(RBTree<T>* tree) {
		std::cout << getPreOrderTraverse(tree);
	}
	template<typename T>
	static void printPostOrder(RBTree<T>* tree) {
		std::cout << getPostOrderTraverse(tree);
	}
	template<typename T>
	static std::string serialize(RBTree<T>* tree) {
		std::stringstream strStream;
		_serialize(tree->root, strStream);
		return strStream.str();
	}
	template<typename T>
	static void deserialize(_RBtreeNode<T>* parent,_RBtreeNode<T>*& node, std::ifstream& inputStream) {
		std::string value = "";
		std::string color = "";
		inputStream >> value;
		if (value == "NULL" || value == " ")
			return;
		inputStream >> color;

		node = new _RBtreeNode<T>();
		node->key = std::stoi(value);
		node->parent = parent;
		color == "Black"
			? node->color = ELeafColor::BLACK
			: node->color = ELeafColor::RED;

		deserialize(node,node->left, inputStream);
		deserialize(node,node->right, inputStream);
	}
	//Data format in out file
	// [KEY COLOR PARENT]
	template<typename T>
	static void writeToFile(RBTree<T>* tree, std::ofstream& outputStream) {
		outputStream << serialize(tree);
		outputStream << std::endl;
		outputStream << "Прямой обход: " << getInOrderTraverse(tree) << std::endl;
		outputStream << "Обратный обход: " << getPostOrderTraverse(tree) << std::endl;
		outputStream << "Симметричный обохд: " << getPreOrderTraverse(tree) << std::endl;
	}
	template<typename T>
	static RBTree<T>* readFromFile(std::ifstream& inputStream) {
		RBTree<T>* tree = new RBTree<T>();
		deserialize<int>(nullptr,tree->root, inputStream);
		return tree;
	}
};