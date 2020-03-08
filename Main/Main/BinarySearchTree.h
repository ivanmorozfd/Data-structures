#pragma once
#include "BinarySearchTreeExceptions.h"
template<typename T>
class BinarySearchTree 
{
private:
	struct Node 
	{
		T key;
		Node* left;
		Node* right;
	};
	Node* root;

	void addLeaf_(T key, Node* ptr) 
	{
		if (!root)
			root = createLeaf(key);
		else if (key < ptr->key)
		{
			if (ptr->left)
				addLeaf_(key, ptr->left);
			else
				ptr->left = createLeaf(key);
		}
		else if (key > ptr->key)
		{
			if (ptr->right)
				addLeaf_(key, ptr->right);
			else
				ptr->right = createLeaf(key);
		}
		else
			throw BinarySearchTreeException("This key just avialable");
	}
	void printInOrder_(Node* ptr)
	{
		if (root) 
		{
			if (ptr->left)
				printInOrder_(ptr->left);
			std::cout << ptr->key;
			if (ptr->right)
				printInOrder_(ptr->right);
		}
		else
			throw BinarySearchTreeException("Tree is empty");
		
	}
	Node* returnNode_(T key, BinarySearchTree::Node* ptr) 
	{
		if (ptr) 
		{
			if (ptr->key == key)
				return ptr;
			else if (key < ptr->key) 
				return(returnNode_(key, ptr->left));
			else 
				return(returnNode_(key, ptr->right));
		}
		else 
			return nullptr;
	}
	T findSmallestK_(BinarySearchTree::N	ode* ptr) 
	{
		if (!root) 
			throw BinarySearchTreeException("Tree is empty");
		else 
		{
			if (ptr->left) 
				return findSmallestK_(ptr->left);
			else 
				return ptr->key;

		}
	}
	void removeNode_(T key, BinarySearchTree::Node* parent) 
	{
		if (root)
		{
			if (root->key == key)
				removeRootMatch();
			else 
			{
				if (key < parent->key && parent->left)
				{
					parent->left->key == key
					?removeMatch(parent, parent->left, true)
					:removeNode_(key, parent->left);
				}
				else if (key > parent->key&& parent->right)
				{
					parent->right->key == key
					?removeMatch(parent, parent->right, false)
					:removeNode_(key, parent->right);
				}
				else 
					std::cout << "Not found this key" << std::endl;
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
	void removeRootMatch() 
	{
		if (root)
		{
			Node* delPtr = root;
			T rootK = root->key;
			T smallInRghtSubtr;
			// 0 children
			if (!root->left && !root->left)
			{
				root = nullptr;
				delete delPtr;
			}
			// 1 child
			else if (!root->left && root->right)
			{
				root = root->right;
				delPtr->right = nullptr;
				delete delPtr;
			}
			else if (root->left && !root->right)
			{
				root = root->left;
				delPtr->left = nullptr;
				delete delPtr;
			}
			else
			{
				T = findSmallestK_(root->right);
				removeNode_(smallInRghtSubtr, root);
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
	void removeMatch(Node* parent, Node* match, bool isLeft) 
	{
		if (root) 
		{
			Node* delPtr;
			int matchK = match->key;
			int smallestInRightSub;
			// zero child
			if (!match->right && match->left)
			{
				delPtr = match;
				
				isLeft == true
				?parent->left = nullptr
				:parent->right = nullptr;

				delete delPtr;
			}
			// 1 child
			else if (match->left && !match->right)
			{
				delPtr = match;

				isLeft == true
				?parent->left = match->right
				:parent->right = match->right;
				
				match->right = nullptr;
				delete delPtr;
			}
			else if (match->left && !match->right)
			{
				delPtr = match;

				isLeft == true
				?parent->left = match->left
				:parent->right = match->left;

				match->left = nullptr;
				delete delPtr;
			}
			// 2 child
			else
			{
				smallestInRightSub = findSmallestK_(match->right);
				removeNode_(smallestInRightSub, match);
				match->key = smallestInRightSub;
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
public:
	Node* createLeaf(T key) 
	{
		Node* leaf = new Node();
		leaf->key = key;
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	}
	void  addLeaf(T key) 
	{
		addLeaf_(key, root);
	}
	void  printInOrder() 
	{
		printInOrder_(root);
	}
	Node* returnNode(T key) 
	{
		return returnNode_(key, root);
	}
	T returnRootK()
	{
		if (root)
			return root->key;
		else 
			return -1;
	}
	T findSmallestK() 
	{
		findSmallestK_(root);
	}
	void removeNode(T key) 
	{
		removeNode_(key, root);
	}
public:
	BinarySearchTree() :root(nullptr)
	{

	}
	BinarySearchTree(const BinarySearchTree<T>& other)
	{

	}
	~BinarySearchTree()
	{

	}
};