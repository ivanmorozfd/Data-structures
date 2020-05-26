#pragma once
#include "core.h"
#include "Container.h"
#include <iostream>
#include "AvlTreeExceptions.h"
template<typename _T>

/*!
	Data representation in AvlTree
	Contain pointer to left child,to right child
	height and key
	\brief AvlTree element wrapper
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
struct _AvlTreeNode {
public:
	typedef _AvlTreeNode* NodePtr;//!< Node pointer type
	using valueType = _T;//!< Node value type
	using reference = valueType&;//!< Reference value type
public:
	valueType key;//!< Node value
	size_t height;//!< Node height in tree
	NodePtr left;//!< Pointer to left child
	NodePtr right;//!< Pointer to right child
public:
	_AvlTreeNode(const _AvlTreeNode&) = delete;
	_AvlTreeNode& operator=(const _AvlTreeNode&) = delete;
public:
	/*!
		Default _StackNode constructor
	*/
	_AvlTreeNode() = default;
	/*!
		Parameterized _AvlTreeNode constructor
		\param[in] valueType& item Node value
	*/
	_AvlTreeNode(valueType item) :
		key(item),
		height(0),
		left(nullptr),
		right(nullptr) {}
};


/*!
	AvlTree class
	\brief Use to store data in tree view	
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class AvlTree : public Container {
	friend class AvlTreeHelper;
private:
	using valueType = _T;//value type
	using reference = valueType&;//reference to value
	using const_reference = const reference;//const reference to value
	using NodePtr = _AvlTreeNode<_T>*;//Node pointer type
	using NodeRef = _AvlTreeNode<_T>;//Node reference type
	NodePtr _root;//Tree root
private:
	//Returns node height
	size_t height(NodePtr node) {
		return node
			?node->height
			:0;
	}
	// count balance factor for node
	size_t balanceFactor(NodePtr node) {
		return height(node->right) 
			- height(node->left);
	}
	// fix height for node
	void fixHeight(NodePtr node) {
		size_t heightLeft = height(node->left);
		size_t heightRight = height(node->right);

		node->height = 1 + (heightLeft > heightRight 
				? heightLeft 
				: heightRight) ;
	}
	// right turn relative to the vertex node
	NodePtr rotateRight(NodePtr	node) {
		NodePtr q = node->left;
		node->left = q->right;
		q->right = node;

		fixHeight(node);
		fixHeight(q);
		return q;
	}
	// left turn relative to the vertex
	NodePtr rotateLeft(NodePtr node) {
		NodePtr q = node->right;
		node->right = q->left;
		q->left = node;

		fixHeight(node);
		fixHeight(q);
		return q;
	}

	// balance tree with root in node
	NodePtr balance(NodePtr node) {
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
	NodePtr insert_(NodePtr node, const_reference key) {
		if (!node) {
			NodePtr nnode = new NodeRef(key);
			return nnode;
		}
		if (key < node->key)
			node->left = insert_(node->left, key);
		else
			node->right = insert_(node->right, key);
		return balance(node);
	}
	// returns minimal element in tree
	NodePtr findMin(NodePtr node){
		return node->left 
			? findMin(node->left) 
			: node;
	}
	// remove min element in subtree with root in node
	NodePtr removeMin(NodePtr node) {
		if (node->left == 0)
			return node->right;
		node->left = removeMin(node->left);
		return balance(node);
	}
	void removeRootMatch() {
		if (_root) {
			NodePtr delPtr = _root;
			valueType rootK = _root->key;
			valueType smallInRghtSubtr;
			// 0 children 
			// just delete _root
			if (!_root->left && !_root->right) {
				_root = nullptr;
				delete delPtr;
			}
			// 1 child
			// just remove right or left child
			else if (!_root->left && _root->right) {
				_root = _root->right;
				delPtr->right = nullptr;
				delete delPtr;
			}
			else if (_root->left && !_root->right) {
				_root = _root->left;
				delPtr->left = nullptr;
				delete delPtr;
			}
			// 2 child
			// need find smallest key in right subtree
			else {
				smallInRghtSubtr = findMin(_root->right)->key;
				remove(_root, smallInRghtSubtr);
				_root->key = smallInRghtSubtr;
			}
		}
		else
			throw AvlTreeException("Tree is empty");
	}
	// remove node from tree
	//default bst deletion with avl rotate rebalance
	NodePtr remove(NodePtr node, valueType key) {
		if (!node) {
			throw AvlTreeException("Key not exist");
		}
		if (key < node->key)
			node->left = remove(node->left, key);
		else if (key > node->key)
			node->right = remove(node->right, key);
		else {
			if (node == _root) {
				removeRootMatch();
				return balance(findMin(_root->right));
			}
			NodePtr lft = node->left;
			NodePtr rgt = node->right;
			delete node;
			if (!rgt) 
				return lft;

			NodePtr min = findMin(rgt);
				
			min->right = removeMin(rgt);
			min->left = rgt;
			return balance(min);
		}
		return balance(node);
	}
public:
	void clear() {
		while (!isEmpty())
			removeRootMatch();
	}
	/*!
		Returns root key
	*/
	valueType getRoot() const {
		if (!isEmpty())
			return this->_root->key;
		else
			throw AvlTreeException("Tree is empty");
	}
	/*!
		Insert value to the tree
		\param[in] const_reference Key
	*/
	void insert(valueType key) {
		_root = insert_(this->_root, key);
	}
	/*!
		Remove element from the tree by key
		\param[in] const_reference Key
	*/
	void remove(valueType key) {
		_root = remove(this->_root, key);
	}
	/*!
		Insert value to the tree
		\param[out] bool True,if tree contain any elements
	*/
	bool isEmpty() const override {
		return !_root;
	}
	_T getMin() {
		return findMin(_root)->key;
	}
public:
	/*!
		Default AvlTree constructor
	*/
	AvlTree() : _root(nullptr) {}
	/*!
		Parameterized AvlTree constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	AvlTree(std::initializer_list<valueType>& data) {
		for (auto i : data)
			this->insert(i);
	}
	/*!
		AvlTree destructor
	*/
	~AvlTree() { }
};