#pragma once
#include "core.h"
#include "Container.h"
#include <initializer_list>
#include "RBTreeExceptions.h"
using std::initializer_list;
using std::string;
/*!
	RBTree class
	\brief Use to store data in tree view
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
template<typename _T>
class RBTree : public Container {
private:
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
	struct _RBtreeNode {
		typedef _RBtreeNode* NodePtr;//!< Node pointer type
		using valueType = _T;//!< Element type
		using reference = valueType&;//!< Reference element type
		using const_reference = const _T&;//!< Const reference element type
	public:
		NodePtr left;//!< Pointer to left child
		NodePtr right;//!< Pointer to right child
		NodePtr parent;//!< Pointer to parent node
		valueType data;//!< Node key
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
			const_reference value):
				color(color),
				data(value), 
				left(left),
				right(right),
				parent(parent) 
		{

		}
	};
	typedef _RBtreeNode* NodePtr;//!< Node pointer type
	typedef _RBtreeNode NodeRef;//!< Node pointer type
	using valueType = _T;//!< Element type
	using reference = valueType&;//!< Reference element type
	using const_reference = const _T&;//!< Const reference element type
private:
	NodePtr m_root;
private:
	// Left turn relative to the vertex
	void rotateLeft(NodePtr ptr) {
		NodePtr right_child = ptr->right;
		ptr->right = right_child->left;

		if (ptr->right)
			ptr->right->parent = ptr;

		right_child->parent = ptr->parent;

		if (!ptr->parent)
			m_root = right_child;
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
			m_root = left_child;
		else if (ptr == ptr->parent->left)
			ptr->parent->left = left_child;
		else
			ptr->parent->right = left_child;

		left_child->right = ptr;
		ptr->parent = left_child;
	}
	//Fix tree after inserti
	void fixInsertion(NodePtr ptr){
		NodePtr parent = nullptr;
		NodePtr grandparent = nullptr;
		while (ptr != m_root 
		       && ptr->color == ELeafColor::RED
		       && ptr->parent->color == ELeafColor::RED) {
			parent = ptr->parent;
			grandparent = parent->parent;
			if (parent == grandparent->left) {
				NodePtr uncle = grandparent->right;
				if (uncle && uncle->color == ELeafColor::RED) {
					uncle->color = ELeafColor::BLACK;
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
				NodePtr uncle = grandparent->left;
				if (uncle && uncle->color == ELeafColor::RED ) {
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
	//insert node to the tree
	NodePtr insert_(NodePtr root, NodePtr ptr) {
		if (!root)
			return ptr;

		if (ptr->data < root->data) {
			root->left = insert_(root->left, ptr);
			root->left->parent = root;
		}
		else if (ptr->data > root->data)  {
			root->right = insert_(root->right, ptr);
			root->right->parent = root;
		}
		return root;
	}
 
	void remove(const_reference key) {
		NodePtr temp = m_root;
		NodePtr temp2 = nullptr;
		NodePtr temp3 = nullptr;
		while (temp->data != key) {
			if (temp->data < key)
				temp = temp->right;
			else
				temp = temp->left;
		}
		//0 children
		if (!temp->right && !temp->left)
			delete temp;
		//1 children
		else if (temp->right && !temp->left) {
			
		}
		else if (!temp->right && temp->left) {

		}
		//2 children
		else if (temp->right && temp->left) {
				
		}
	}
	// print tree in order travers
	void inOrderTraverse(NodePtr ptr) {
		if (!ptr)
			return;
		inOrderTraverse(ptr->left);
		std::cout << ptr->data << " ";
		inOrderTraverse(ptr->right);
	}
	// print tree in pre order travers
	void preOrderTraverse(NodePtr root) {
		if (root) {
			std::cout << root->data << " ";
			preOrderTraverse(root->left);
			preOrderTraverse(root->right);
		}
	}
	// print tree in post order travers
	void postOrderTraverse(NodePtr root) {
		if (root) {
			postOrderTraverse(root->left);
			postOrderTraverse(root->right);
			std::cout << root->data << " ";
		}
	}
public:
	/*!
	Display tree data in order
*/
	void  printInOrder() const {
		this->inOrderTraverse(m_root);
	}
	/*!
		Display tree data in post order
	*/
	void printPostOrder() const {
		this->postOrderTraverse(m_root);
	}
	/*!
		Display tree data in pre order
	*/
	void printPreOrder() const {
		this->preOrderTraverse(m_root);
	}
	/*!
		Is the RBTree empty
		\param[out] bool True,if RBTree is empty
	*/
	bool isEmpty() const override {
		return !m_root;
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

		m_root = insert_(m_root, node);
		fixInsertion(node);
	}
public:
	/*!
		Default RBTree constructor
	*/
	RBTree() :m_root(nullptr) {}
	/*!
		Parameterized RBTree constructor
		\param[in] initializer_list<valueType>list STL init list
	*/
	RBTree(const initializer_list<_T>& data) {
		for (auto& i : data)
			this->addItem(i);
	}
};
