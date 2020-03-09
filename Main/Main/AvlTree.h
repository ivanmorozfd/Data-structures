#pragma once
#include <iostream>
#include "AvlTreeExceptions.h"
template<typename _T>
class AvlTree
{
	class Node
	{
	public:
		_T key;
		int height;
		Node* left;
		Node* right;
	};
	Node* m_top;
	int height(Node* node)
	{
		return node?node->height:0;
	}
	int balanceFactor(Node* node)
	{
		return height(node->right) - height(node->left);
	}
	void fixHeight(Node* node)
	{
		int heightLeft = height(node->left);
		int heightRight = height(node->right);
		node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
	}
	Node* rotateRight(Node* node) // правый поворот вокруг p
	{
		Node* q = node->left;
		node->left = q->right;
		q->right = node;
		fixHeight(node);
		fixHeight(q);
		return q;
	}
	Node* rotateLeft(Node* node) // правый поворот вокруг p
	{
		Node* q = node->right;
		node->right = q->left;
		q->left = node;
		fixHeight(node);
		fixHeight(q);
		return q;
	}
	Node* balance(Node* node) // балансировка узла p
	{
		fixHeight(node);
		if (balanceFactor(node) == 2)
		{
			if (balanceFactor(node->right) < 0)
				node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
		if (balanceFactor(node) == -2)
		{
			if (balanceFactor(node->left) > 0)
				node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
		return node;
	}
	Node* insert_(Node* node, _T key) // вставка ключа k в дерево с корнем p
	{
		if (!node)
		{
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
	Node* findMin(Node* node) // поиск узла с минимальным ключом в дереве p 
	{
		return node->left ? findMin(node->left) : node;
	}
	Node* removeMin(Node* node) // удаление узла с минимальным ключом из дерева p
	{
		if (node->left == 0)
			return node->right;
		node->left = removeMin(node->left);
		return balance(node);
	}

	Node* remove(Node* node, _T key) // удаление ключа k из дерева p
	{
		if (!node) return 0;
		if (key < node->key)
			node->left = remove(node->left, key);
		else if (key > node->key)
			node->right = remove(node->right, key);
		else
		{
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
	void inOrder(Node* t)
	{
		if (!t)
			return;
		inOrder(t->left);
		std::cout << t->key << " ";
		inOrder(t->right);
	}
public:
	void insert(_T key)
	{
		m_top = insert_(this->m_top, key);
	}
	void display()
	{
		inOrder(m_top);
	}
public:
	AvlTree() :m_top(nullptr)
	{

	}
};