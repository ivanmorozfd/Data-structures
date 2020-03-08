#pragma once
#include <initializer_list>
#include "RBTreeExceptions.h"
template<typename _T>
class RBTree
{
protected:
	enum class ELeafColor	
	{
		BLACK,
		RED
	};
	struct Node
	{
	public:
		Node* m_left;
		Node* m_right;
		Node* m_parent,
		_T data;
		ELeafColor m_color;
	public:
		Node(ELeafColor color,
			Node* left,
			Node* right,
			Node* parent;
			_T value, ) :m_color(color), data(value), m_left(lft), m_right(rgt),m_parent(parent) { }
	};
private:
	Node* m_root;
private:
	ELeafColor getColor(Node*& node)
	{
		if (!node)
			return BLACK;
		return node->m_color;
	}
	void setColor(Node*& node, ELeafColor& color) {
		if (!node)
			return;
		node->m_color = color;
	}
public:
	bool isEmpty()
	{
		return !m_root;
	}
	void fixInsertion(Node* node)
	{

	}	
	Node* grandparent(Node* node)
	{
		if ((node) && (node->parent))
			return node->parent->parent;
		else
			return nullptr;
	}
	Node* uncle(Node* node)
	{
		Node* grandpa = grandparent(n);
		if (!grandpa)
			return nullptr;
		if (node->parent == grandpa->left)
			return grandpa->right;
		else
			return grandpa->left;
	}
public:
	RBTree()
	{

	}
	RBTree(std::initializer_list<_T> data)
	{

	}
	RBTree(RBTree<_T>& other)
	{

	}
};