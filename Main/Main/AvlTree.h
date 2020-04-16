#pragma once
#include <iostream>
#include "AvlTreeExceptions.h"
template<typename _T>
class AvlTree {
	class Node {
	public:
		_T key;
		int height;
		Node* left;
		Node* right;
	};
	Node* m_top;
	int height(Node* node) {
		return node
			?node->height
			:0;
	}
	// count balance factor of nodes
	int balanceFactor(Node* node) {
		return height(node->right) 
			- height(node->left);
	}
	void fixHeight(Node* node) {
		int heightLeft = height(node->left);
		int heightRight = height(node->right);
		node->height = 1 + (heightLeft > heightRight 
				? heightLeft 
				: heightRight) ;
	}
	// right turn relative to the vertex node
	Node* rotateRight(Node*	 node) { 
		Node* q = node->left;
		node->left = q->right;
		q->right = node;
		fixHeight(node);
		fixHeight(q);
		return q;
	}
	// left turn relative to the vertex
	Node* rotateLeft(Node* node) {
		Node* q = node->right;
		node->right = q->left;
		q->left = node;
		fixHeight(node);
		fixHeight(q);
		return q;
	}
	// balance tree with root in node
	Node* balance(Node* node) {
		fixHeight(node);
		if (balanceFactor(node) == 2) {
			if (balanceFactor(node->right) < 0)
				node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
		if (balanceFactor(node) == -2) {
			if (balanceFactor(node->left) > 0)
				node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
		return node;
	}
	// insert to the tree with the root in node
	Node* insert_(Node* node,
		      const _T& key) {
		if (!node) {
			Node* nnode = new Node();
			nnode->key = key;
			return nnode;
		}
		if (key < node->key)
			node->left = insert_(node->left, key);
		else
			node->right = insert_(node->right, key);
		return balance(node);
	}
	// returns minimal element in tree
	Node* findMin(Node* node){
		return node->left 
			? findMin(node->left) 
			: node;
	}
	// remove min element in subtree with root in node
	Node* removeMin(Node* node) {
		if (node->left == 0)
			return node->right;
		node->left = removeMin(node->left);
		return balance(node);
	}
	// remove node from tree
	Node* remove(Node* node,
		     const _T& key) {
		if (!node) return 0;
		if (key < node->key)
			node->left = remove(node->left, key);
		else if (key > node->key)
			node->right = remove(node->right, key);
		else {
			Node* lft = node->left;
			Node* rgt = node->right;
			delete node;
			if (!rgt) return lft;
			Node* min = findMin(rgt);
			min->right = removeMin(rgt);
			min->left = rgt;
			return balance(min);
		}
		return balance(node);
	}
	// print tree in order
	void inOrder(Node* t) {
		if (!t)
			return;
		inOrder(t->left);
		std::cout << t->key << " ";
		inOrder(t->right);
	}
public:
	void insert(const _T& key) {
		m_top = insert_(this->m_top, key);
	}
	void display() {
		inOrder(m_top);
	}
public:
	AvlTree() :
	m_top(nullptr) {}
	AvlTree(const std::initializer_list<_T>& data) { }
	AvlTree(const AvlTree<_T>& other) {}
	~AvlTree() { }
};
