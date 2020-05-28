#pragma once
#include "core.h"
#include "Container.h"
#include "BinarySearchTreeExceptions.h"
template<typename _T>

/*!
	Data representation in BinarySearchTree
	Contain pointer to next and right child,node key
	\brief Stack element wrapper
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
struct _BstNode {
	typedef _BstNode* NodePtr;//!< Node  pointer type
	using valueType = _T;//!< Element type
	using reference = valueType&;//Reference type
public:
	valueType key;//!< Node key 
	NodePtr left;//!< Pointer  to left child
	NodePtr right;//!< Pointer to right child
public:
	_BstNode(const _BstNode&) = delete;
	_BstNode& operator=(const _BstNode&) = delete;
public:
	/*!
		Default _BstNode constructor
	*/
	_BstNode() = default;
	/*!
		Parameterized _BstNode constructor
		\param[in] valueType& Node data
	*/
	_BstNode(valueType key) : key(key),
		left(nullptr),
		right(nullptr) {}
};


/*!
	BinarySearchTree class
	\brief Use to store data in tree view
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>	
class BinarySearchTree : public Container {
	friend class BinarySearchTreeHelper;
private:
	using valueType = _T;//Element type
	using reference = valueType&;//Reference element type
	using const_reference = const valueType&;//Const reference element type
	using NodePtr = _BstNode<_T>*;//Pointer node type
	using NodeRef = _BstNode<_T>;//Reference node type
private:
	NodePtr root;//!< tree root
	//add value to the tree recursively
	void addLeaf_(const_reference key, NodePtr ptr) {
		if (!root)
			root = createLeaf(key);
		else if (key < ptr->key) {
			if (ptr->left)
				addLeaf_(key, ptr->left);
			else
				ptr->left = createLeaf(key);
		}
		else if (key >= ptr->key) {
			if (ptr->right)
				addLeaf_(key, ptr->right);
			else
				ptr->right = createLeaf(key);
		}
		else
			throw BinarySearchTreeException("This key just avialable");
	}
	//Return node by key
	NodePtr returnNode_(const_reference key, NodePtr ptr) {
		if (ptr) {
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
	//Find min element in tree
	valueType findMin_(NodePtr ptr) {
		if (!root) 
			throw BinarySearchTreeException("Tree is empty");
		else {
			if (ptr->left) 
				return findMin_(ptr->left);
			else 
				return ptr->key;

		}
	}
	//Remove node from tree recursively
	void removeNode_(const_reference key, NodePtr parent) {
		if (root){
			if (root->key == key)
				removeRootMatch();
			else {
				if (key < parent->key 
				    && parent->left) {
					parent->left->key == key
					?removeMatch(parent, parent->left, true)
					:removeNode_(key, parent->left);
				}
				else if (key > parent->key 
					 && parent->right) {
					parent->right->key == key
					?removeMatch(parent, parent->right, false)
					:removeNode_(key, parent->right);
				}
				else 
					throw BinarySearchTreeException("This key is not exist");
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
	//if we need remove tree root
	void removeRootMatch() {
		if (root) {
			NodePtr delPtr = root;
			valueType rootK = root->key;
			valueType smallInRghtSubtr;
			// 0 children 
			// just delete root
			if (!root->left && !root->right) {
				root = nullptr;
				delete delPtr;
			}
			// 1 child
			// just remove right or left child
			else if (!root->left && root->right) {
				root = root->right;
				delPtr->right = nullptr;
				delete delPtr;
			}
			else if (root->left && !root->right) {
				root = root->left;
				delPtr->left = nullptr;
				delete delPtr;
			}
			// 2 child
			// need find smallest key in right subtree
			else {
				smallInRghtSubtr = findMin_(root->right);
				removeNode_(smallInRghtSubtr, root);
				root->key = smallInRghtSubtr;
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
	//Remove node match 
	void removeMatch(NodePtr parent,
			 NodePtr match,
			 const bool& isLeft) {
		if (root) {
			NodePtr delPtr = nullptr;
			valueType matchK = match->key;
			valueType smallestInRightSub = valueType();
			// zero child
			// just delete pointers
			if (!match->right 
			    && !match->left) {
				delPtr = match;
				
				isLeft == true
				?parent->left = nullptr
				:parent->right = nullptr;

				delete delPtr;
			}
			// 1 child
			//if right child exist
			else if (match->left
				 && !match->right) {
				delPtr = match;
				isLeft == true
				?parent->left = match->right
				:parent->right = match->right;
				
				match->right = nullptr;
				delete delPtr;
			}
			//if left child exist
			else if (match->left 
				&& !match->right) {
				delPtr = match;

				isLeft == true
				?parent->left = match->left
				:parent->right = match->left;

				match->left = nullptr;
				delete delPtr;
			}
			// 2 child
			else {
				smallestInRightSub = findMin_(match->right);
				removeNode_(smallestInRightSub, match);
				match->key = smallestInRightSub;
			}
		}
		else
			throw BinarySearchTreeException("Tree is empty");
	}
	//Create leaf
	//returns pointer for new node
	NodePtr createLeaf(const_reference key) {
		NodePtr leaf = new NodeRef();
		leaf->key = key;
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	}
	// Return node by key
	NodePtr returnNode(const_reference key) {
		return returnNode_(key, root);
	}
public:
	void clear() {
		while (!isEmpty())
			removeRootMatch();
	}
	/*!
		Is the BinarySearchTree empty
		\param[out] bool True,if BinarySearchTree is empty
	*/
	bool isEmpty() const override {
		return !root;
	}
	/*!
		Add item to the tree
		\param[in] const_reference key
	*/
	void  addLeaf(const_reference key) {
		addLeaf_(key, root);
	}
	/*!
		Returns the value in the root
		\param[out] valueType
	*/
	valueType returnRootKey() {
		if (root)
			return root->key;
		else 
			throw BinarySearchTreeException("Tree is emtpy");
	}	
	/*!
		Find minimal element in the tree
		\param[out] valueType key
	*/
	valueType findMin() {
		return findMin_(root);
	}
	/*!
		Remove element from the tree by key
		\param[out] valueType key
	*/
	void removeByKey(const_reference key) {
		removeNode_(key, root);
	}
public:
	/*!
		Default BinarySearchTree constructor
	*/
	BinarySearchTree() :root(nullptr) { }
	/*!
		Parameterized BinarySearchTree constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	BinarySearchTree(const std::initializer_list<valueType>& data) :
		root(nullptr) {
		for (auto i : data)
			this->addLeaf(i);
	}
	/*!
		BinarySearchTree destructor
	*/
	~BinarySearchTree() { }
};
