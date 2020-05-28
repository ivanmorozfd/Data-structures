#pragma once
#include "HelperBase.h"
#include "AvlTree.h"
/*!
	Static class functions library
	\brief Use to work with AvlTree
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class AvlTreeHelper : public virtual HelperBase {
private:
	AvlTreeHelper() = default;
	~AvlTreeHelper() = default;
private:
	template<typename T>
	static void _serialize(_AvlTreeNode<T>* node, std::stringstream& strStream) {
		if (!node) {
			strStream << "NULL" << " ";
			return;
		}
		strStream << node->key << " " << node->height << " "; // TODO
		_serialize(node->left, strStream);
		_serialize(node->right, strStream);

	}
public:
	template<typename T>
	static std::string getInOrderTraverse(AvlTree<T>* tree) {
		std::stack<_AvlTreeNode<T>*>* stack_node = new std::stack<_AvlTreeNode<T>*>();
		std::string result = "";
		_AvlTreeNode<T>* curr = tree->_root;
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
	static std::string getPreOrderTraverse(AvlTree<T>* tree) {
		std::stack<_AvlTreeNode<T>*>* nodeStack = new std::stack<_AvlTreeNode<T>*>();
		nodeStack->push(tree->_root);
		std::string result = "";
		while (nodeStack->empty() == false)
		{
			// Pop the top item from stack and print it
			_AvlTreeNode<T>* node = nodeStack->top();
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
	static std::string getPostOrderTraverse(AvlTree<T>* tree) {
		std::stack<_AvlTreeNode<T>*>* stack_node = new std::stack<_AvlTreeNode<T>*>();
		_AvlTreeNode<T>* curr = tree->_root;
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
	static void printInOrder(AvlTree<T>* tree) {
		std::cout << getInOrderTraverse(tree);
	}
	template<typename T>
	static void printPreOrder(AvlTree<T>* tree) {
		std::cout << getPreOrderTraverse(tree);
	}
	template<typename T>
	static void printPostOrder(AvlTree<T>* tree) {
		std::cout << getPostOrderTraverse(tree);
	}
	template<typename T>
	static std::string serialize(AvlTree<T>* tree) {
		std::stringstream strStream;
		_serialize(tree->_root, strStream);
		return strStream.str();
	}
	template<typename T>
	static void deserialize(_AvlTreeNode<T>*& node, std::ifstream& inputStream) {
		std::string value = "";
		std::string nodeHeight = "";
		inputStream >> value;
		
		if (value == "NULL" || value == " ")
			return;
		inputStream >> nodeHeight;

		node = new _AvlTreeNode<T>();
		node->key = std::stoi(value);
		node->height = std::stoi(nodeHeight);

		deserialize(node->left, inputStream);
		deserialize(node->right, inputStream);
	}
	// data store in KEY HEIGHT Format
	template<typename T>
	static void writeToFile(AvlTree<T>* tree, std::ofstream& outputStream) {
		outputStream << serialize(tree);
		outputStream << std::endl;
		outputStream << "Прямой обход: " << getInOrderTraverse(tree) << std::endl;
		outputStream << "Обратный обход: " << getPostOrderTraverse(tree) << std::endl;
		outputStream << "Симметричный обохд: " << getPreOrderTraverse(tree) << std::endl;
	}
	template<typename T>
	static AvlTree<T>* readFromFile(std::ifstream& inputStream) {
		AvlTree<T>* tree = new AvlTree<T>();
		deserialize<int>(tree->_root, inputStream);
		return tree;
	}
};