#pragma once
#include "core.h"
#include "Container.h"
#include <initializer_list>
#include "RBTreeExceptions.h"
using std::initializer_list;
using std::string;

/** @enum ELeafColor
  *  \brief is a strongly typed enum class representing the leaf color
  *  @var ELeafColor::BLACK
  *  is coded as std::int8_t of value 0
  *  @var ELeafColor::BLACK
  *  is coded as std::int8_t of value 1
  */
enum class ELeafColor : std::int8_t {
	BLACK,
	RED
};
template <typename _T>
struct _RBtreeNode {
	typedef _RBtreeNode* NodePtr;//!< Node pointer type
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	using const_reference = const _T&;//!< Const reference element type
public:
	NodePtr left;//!< Pointer to left child
	NodePtr right;//!< Pointer to right child
	NodePtr parent;//!< Pointer to parent node
	valueType key;//!< Node key
	ELeafColor color;//!< Leaf Color
public:
	/*!
		Returns the color in string representation
		\param[out] string Leaf color
	*/
	string colorToString() {
		return this->color == ELeafColor::BLACK
			? "Black"
			: "Red";
	}
public:
	/*!
		Parameterized _RBtreeNode constructor
		\param[in] ELeafColor Leaf color
		\param[in] NodePtr Left child
		\param[in] NodePtr Right child
		\param[in] NodePtr Parent node
	*/
	_RBtreeNode(ELeafColor color,
		NodePtr left,
		NodePtr right,
		NodePtr parent,
		const_reference value) :
		color(color),
		key(value),
		left(left),
		right(right),
		parent(parent)
	{

	}
	_RBtreeNode() : color(ELeafColor::RED),
		key(valueType()),
		left(nullptr),
		right(nullptr),
		parent(nullptr) {

	}
};


/*!
	RBTree class
	\brief Use to store data in tree view
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class RBTree : public Container {
	friend class RBTreeHelper;
	typedef _RBtreeNode<_T>* NodePtr;//!< Node pointer type
	typedef _RBtreeNode<_T> NodeRef;//!< Node pointer type
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	using const_reference = const _T&;//!< Const reference element type
private:
	NodePtr root;
private:
	// Left turn relative to the vertex
	void rotateLeft(NodePtr ptr) {
		NodePtr right_child = ptr->right;
		ptr->right = right_child->left;

		if (ptr->right)
			ptr->right->parent = ptr;

		right_child->parent = ptr->parent;

		if (!ptr->parent)
			root = right_child;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = right_child;
		else
			ptr->parent->right = right_child;

		right_child->left = ptr;
		ptr->parent = right_child;
	}
	// Right turn relative to the vertex
	void rotateRight(NodePtr ptr) {
		NodePtr left_child = ptr->left;
		ptr->left = left_child->right;

		if (ptr->left)
			ptr->left->parent = ptr;

		left_child->parent = ptr->parent;

		if (!ptr->parent)
			root = left_child;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = left_child;
		else
			ptr->parent->right = left_child;

		left_child->right = ptr;
		ptr->parent = left_child;
	}
	//Fix tree after inserti
	void fixInsertion(NodePtr ptr) {
		//if ptr is root just set black color and return
		if (ptr == root) {
			ptr->color = ELeafColor::BLACK;
			return;
		}
		NodePtr parent = nullptr;
		NodePtr grandparent = nullptr;
		//while father is red 
		//property 3 is violated
		while (ptr != root
			&& ptr->color == ELeafColor::RED
			&& ptr->parent->color == ELeafColor::RED) {
			parent = ptr->parent;
			grandparent = parent->parent;
			//if father left child and uncle exist and have red color
			//set black color to uncle and parent
			if (parent == grandparent->left) {
				NodePtr uncle = grandparent->right;
				if (uncle && uncle->color == ELeafColor::RED) {
					uncle->color = ELeafColor::BLACK;
					parent->color = ELeafColor::BLACK;
					grandparent->color = ELeafColor::RED;
					ptr = grandparent;
				}
				//if uncle not exist
				else {\
					//if right child need left rotate
					if (ptr == parent->right) {
						rotateLeft(parent);
						ptr = parent;
						parent = ptr->parent;
					}
					//other wise right chidl
					rotateRight(grandparent);
					std::swap(parent->color, grandparent->color);
					ptr = parent;
				}
			}
			else {//if father right child
				NodePtr uncle = grandparent->left;
				if (uncle && uncle->color == ELeafColor::RED) {
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
		root->color = ELeafColor::BLACK;
	}
	//insert node to the tree
	//works like default BST insert
	NodePtr insert_(NodePtr root, NodePtr ptr) {
		if (!root)
			return ptr;

		if (ptr->key < root->key) {
			root->left = insert_(root->left, ptr);
			root->left->parent = root;
		}
		else if (ptr->key >= root->key)  {
			root->right = insert_(root->right, ptr);
			root->right->parent = root;
		}
		return root;
	}
	//Find min element in tree
	valueType findMin_(NodePtr ptr) {
		if (!root)
			throw RBTreeException("Tree is empty");
		else {
			if (ptr->left)
				return findMin_(ptr->left);
			else
				return ptr->key;

		}
	}
	void fixDeleting(NodePtr pNode) {
		while (pNode->color == ELeafColor::BLACK && pNode != root) {
			//if pNode is right child
			NodePtr brother = nullptr;
			if (pNode->parent->right == pNode) {
				brother = pNode->parent->right;
				if (brother->color == ELeafColor::RED) {
					brother->color = ELeafColor::BLACK;
					pNode->parent->color = ELeafColor::BLACK;
					rotateLeft(pNode->parent);
					brother = brother = pNode->parent->right;
					
					if (brother->left->color == ELeafColor::BLACK
						&& brother->right->color == ELeafColor::BLACK) {
						brother->color = ELeafColor::RED;
						pNode = pNode->parent;
					}
					else {
						if (brother->left->color == ELeafColor::BLACK) {
							brother->right->color = ELeafColor::BLACK;
							brother->color = ELeafColor::RED;
							rotateRight(brother);
						}
						brother->color = pNode->parent->color;
						pNode->parent->color = ELeafColor::BLACK;
						brother->right->color = ELeafColor::BLACK;
						rotateLeft(pNode->parent);
						pNode = root;
					}
				}
			}
			else {
				brother = pNode->parent->left;
				if (brother->color == ELeafColor::RED) {
					brother->color = ELeafColor::BLACK;
					pNode->parent->color = ELeafColor::BLACK;
					rotateRight(pNode->parent);
					brother = brother = pNode->parent->left;

					if (brother->left->color == ELeafColor::BLACK
						&& brother->right->color == ELeafColor::BLACK) {
						brother->color = ELeafColor::RED;
						pNode = pNode->parent;
					}
					else {
						if (brother->left->color == ELeafColor::BLACK) {
							brother->right->color = ELeafColor::BLACK;
							brother->color = ELeafColor::RED;
							rotateLeft(brother);
						}
						brother->color = pNode->parent->color;
						pNode->parent->color = ELeafColor::BLACK;
						brother->left->color = ELeafColor::BLACK;
						rotateRight(pNode->parent);
						pNode = root;
					}
				}
			}
		}
		pNode->color = ELeafColor::BLACK;
		root->color = ELeafColor::BLACK;
	}
	//Remove node from tree recursively
	void removeNode_(const_reference key, NodePtr parent) {
		if (root) {
			if (root->key == key) {
				removeRootMatch();
			}
			else {
				if (key < parent->key
					&& parent->left) {
					parent->left->key == key
						? removeMatch(parent, parent->left, true)
						: removeNode_(key, parent->left);
				}
				else if (key > parent->key
					&& parent->right) {
					parent->right->key == key
						? removeMatch(parent, parent->right, false)
						: removeNode_(key, parent->right);
				}
				else
					throw RBTreeException("This key is not exist");
			}
		}
		else
			throw RBTreeException("Tree is empty");
	}
	//Remove tree root
	void removeRootMatch() {
		if (root) {
			NodePtr delPtr = root;
			valueType rootK = root->key;
			valueType smallInRghtSubtr;
			// 0 children
			if (!root->left && !root->right) {
				root = nullptr;
				delete delPtr;
			}
			// 1 child
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
			else {
				smallInRghtSubtr = findMin_(root->right);
				removeNode_(smallInRghtSubtr, root);
				root->key = smallInRghtSubtr;
			}
		}
		else
			throw RBTreeException("Tree is empty");
	}
	//Remove node match 
	void removeMatch(NodePtr parent,
		NodePtr match,
		const bool& isLeft) {
		if (root) {
			NodePtr delPtr = nullptr;
			valueType matchK = match->key;
			valueType smallestInRightSub = valueType();
			NodePtr child;
			// zero child
			if (!match->right
				&& !match->left) {
				delPtr = match;

				isLeft == true
					? parent->left = nullptr
					: parent->right = nullptr;

				delete delPtr;
				
			}
			// 1 child
			//if right child exist
			else if (match->left
				&& !match->right) {
				delPtr = match;
				if (isLeft) {
					parent->left = match->left;
					fixDeleting(parent->left);
				}
				else {
					parent->right = match->left;
					fixDeleting(parent->right);
				}
				match->right = nullptr;
				delete delPtr;
			}
			//if left child exist
			else if (match->left
				&& !match->right) {
				delPtr = match;

				if (isLeft) {
					parent->left = match->left;
					fixDeleting(parent->left);
				}
				else {
					parent->right = match->left; 
					fixDeleting(parent->right);
				}
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
			throw RBTreeException("Tree is empty");
	}
public:
	void clear() {
		while (!isEmpty())
			removeRootMatch();
	}
	valueType getMin() {
		return findMin_(root);
	}
	/*!
		Is the RBTree empty
		\param[out] bool True,if RBTree is empty
	*/
	bool isEmpty() const override {
		return !root;
	}
	/*!
		Add item to the tree
		\param[in] const_reference item
	*/
	void addItem(const_reference item) {
		NodePtr node = new NodeRef(ELeafColor::RED,
			nullptr,
			nullptr,
			nullptr,
			item);

		root = insert_(root, node);
		fixInsertion(node);
	}
	void remove(const_reference key) {
		removeNode_(key, root);
	}
public:
	/*!
		Default RBTree constructor
	*/
	RBTree() :root(nullptr) {}
	/*!
		Parameterized RBTree constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	RBTree(const initializer_list<_T>& data) {
		for (auto& i : data)
			this->addItem(i);
	}
};
