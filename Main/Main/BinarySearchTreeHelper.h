#pragma once
#include "HelperBase.h"
#include "BinarySearchTree.h"
class BinarySearchTreeHelper:public virtual HelperBase {
private:
	BinarySearchTreeHelper() = default;
	~BinarySearchTreeHelper() = default;
private:
	template<typename T>
	static void _serialize(_BstNode<T>* node,std::stringstream& strStream) {
		if (!node){
			strStream <<"NULL" << " ";
				return;
		}
		strStream << node->key << " ";
		_serialize(node->left,strStream);
		_serialize(node->right,strStream);

	}
public:
	template<typename T>
	static std::string getInOrderTraverse(BinarySearchTree<T>* tree) {
		std::stack<_BstNode<T>*>* stack_node = new std::stack<_BstNode<T>*>();
		std::string result = "";
		_BstNode<T>* curr = tree->root;
		while (curr || !stack_node->empty()){
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
	static std::string getPreOrderTraverse(BinarySearchTree<T>* tree) {
		std::stack<_BstNode<T>*>* nodeStack = new std::stack<_BstNode<T>*>();
		nodeStack->push(tree->root);
		std::string result = "";
		while (nodeStack->empty() == false)
		{
			// Pop the top item from stack and print it
			_BstNode<T>* node = nodeStack->top();
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
	static std::string getPostOrderTraverse(BinarySearchTree<T>* tree) {
		std::stack<_BstNode<T>*>* stack_node = new std::stack<_BstNode<T>*>();
		_BstNode<T>* curr = tree->root;
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
	static void printInOrder(BinarySearchTree<T>* tree) {
		std::cout << getInOrderTraverse(tree);
	}
	template<typename T>
	static void printPreOrder(BinarySearchTree<T>* tree) {
		std::cout << getPreOrderTraverse(tree);
	}
	template<typename T>
	static void printPostOrder(BinarySearchTree<T>* tree) {
		std::cout << getPostOrderTraverse(tree);
	}
	template<typename T>
	static std::string serialize(BinarySearchTree<T>* tree) {
		std::stringstream strStream;
		_serialize(tree->root,strStream);
		return strStream.str();
	}
	template<typename T>
	static void deserialize(_BstNode<T>*& node,std::ifstream& inputStream) {
		std::string value = "";

		inputStream >> value;

		if (value == "NULL" || value == " ")
			return;

		node = new _BstNode<T>();
		node->key = std::stoi(value);

		deserialize(node->left, inputStream);
		deserialize(node->right, inputStream);
	}
	template<typename T>
	static void writeToFile(BinarySearchTree<T>* tree, std::ofstream& outputStream) {
		outputStream << serialize(tree);
		outputStream << std::endl;
		outputStream << "Прямой обход: " << getInOrderTraverse(tree) << std::endl;
		outputStream << "Обратный обход: " << getPostOrderTraverse(tree) << std::endl;
		outputStream << "Симметричный обохд: " << getPreOrderTraverse(tree) << std::endl;
	}
	template<typename T>
	static BinarySearchTree<T>* readFromFile(std::ifstream& inputStream) {
		BinarySearchTree<T>* tree = new BinarySearchTree<T>();
		deserialize<int>(tree->root, inputStream);
		return tree;
	}
};