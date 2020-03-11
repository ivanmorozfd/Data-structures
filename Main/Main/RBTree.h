#pragma once
#include <initializer_list>
#include "RBTreeExceptions.h"
template<typename _T>
class RBTree
{
	enum class ELeafColor
	{
		BLACK,
		RED
	};
	struct Node
	{
	public:
		Node* left;
		Node* right;
		Node* parent;
		_T data;
		ELeafColor color;
		std::string colorToString()
		{
			return this->color == ELeafColor::BLACK
				? "Black"
				: "Red";
		}
	public:
		Node(ELeafColor color,
			Node* left,
			Node* right,
			Node* parent,
			_T value): 
				color(color),
				data(value), 
				left(left),
				right(right),
				parent(parent) 
		{

		}
	};
private:
	Node* m_root;
private:

	void rotateLeft(Node*& ptr) {
		Node* right_child = ptr->right;
		ptr->right = right_child->left;

		if (ptr->right != nullptr)
			ptr->right->parent = ptr;

		right_child->parent = ptr->parent;

		if (ptr->parent == nullptr)
			m_root = right_child;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = right_child;
		else
			ptr->parent->right = right_child;

		right_child->left = ptr;
		ptr->parent = right_child;
	}

	void rotateRight(Node*& ptr) {
		Node* left_child = ptr->left;
		ptr->left = left_child->right;

		if (ptr->left != nullptr)
			ptr->left->parent = ptr;

		left_child->parent = ptr->parent;

		if (ptr->parent == nullptr)
			m_root = left_child;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = left_child;
		else
			ptr->parent->right = left_child;

		left_child->right = ptr;
		ptr->parent = left_child;
	}

	void fixInsertion(Node*& ptr) {
		Node* parent = nullptr;
		Node* grandparent = nullptr;
		while (ptr != m_root && ptr->color == ELeafColor::RED && ptr->parent->color == ELeafColor::RED) {
			parent = ptr->parent;
			grandparent = parent->parent;
			if (parent == grandparent->left) {
				Node* uncle = grandparent->right;
				if (uncle->color == ELeafColor::RED) {
					uncle->ELeafColor::BLACK;
					parent->color = ELeafColor::BLACK;
					grandparent->color = ELeafColor::RED;
					ptr = grandparent;
				}
				else {
					if (ptr == parent->right) {
						rotateLeft(parent);
						ptr = parent;
						parent = ptr->parent;
					}
					rotateRight(grandparent);
					std::swap(parent->color, grandparent->color);
					ptr = parent;
				}
			}
			else {
				Node* uncle = grandparent->left;
				if (uncle->color == ELeafColor::RED) {
					uncle->color = ELeafColor::BLACK;
					parent->color = ELeafColor::BLACK;
					grandparent->color = ELeafColor::RED;
					ptr = grandparent;
				}
				else {
					if (ptr == parent->left) {
						rotateRight(parent);
						ptr = parent;
						parent = ptr->parent;
					}
					rotateLeft(grandparent);
					std::swap(parent->color, grandparent->color);
					ptr = parent;
				}
			}
		}
		m_root->color = ELeafColor::BLACK;
	}
	Node* insert_(Node*& root, Node*& ptr)
	{
		if (root == nullptr)
			return ptr;

		if (ptr->data < root->data) 
		{
			root->left = insert_(root->left, ptr);
			root->left->parent = root;
		}
		else if (ptr->data > root->data) 
		{
			root->right = insert_(root->right, ptr);
			root->right->parent = root;
		}
		return root;
	}
	void inorderBST(Node*& ptr) {
		if (ptr == nullptr)
			return;

		inorderBST(ptr->left);
		std::cout << ptr->data << " " << ptr->colorToString()<< std::endl;
		inorderBST(ptr->right);
	}
public:
	bool isEmpty()
	{
		return !m_root;
	}
public:
	void addItem(_T item)
	{
		Node* node = new Node(ELeafColor::RED,
			nullptr,
			nullptr,
			nullptr,
			item);
		m_root = insert_(m_root, node);
		fixInsertion(node);
	}
	void inorder()
	{
		inorderBST(m_root);
	}
public:
	RBTree() :m_root(nullptr)
	{

	}
	RBTree(std::initializer_list<_T> data)
	{

	}
	RBTree(RBTree<_T>& other)
	{

	}
};