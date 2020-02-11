
#pragma once
template<typename T>
class BinarySearchTree {
private:
	struct Node {
		T key;
		Node* left;
		Node* right;
	};
	Node* root;

	void addLeaf_(int key, Node* ptr) {
		if (!root) {
			root = createLeaf(key);
		}
		else if (key < ptr->key) {
			if (ptr->left) {
				addLeaf_(key, ptr->left);
			}
			else {
				ptr->left = createLeaf(key);
			}
		}
		else if (key > ptr->key) {
			if (ptr->right) {
				addLeaf_(key, ptr->right);
			}
			else {
				ptr->right = createLeaf(key);
			}
		}
		else {
			std::cout << "The key : " << key << "just avialable" << std::endl;
		}
	}
	void printInOrder_(Node* ptr) {
		if (root) {
			if (ptr->left) {
				printInOrder_(ptr->left);
			}
			std::cout << ptr->key;
			if (ptr->right) {
				printInOrder_(ptr->right);
			}
		}
		else {
			std::cout << "Tree is empty" << std::endl;
		}
	}
	Node* returnNode_(int key, BinarySearchTree::Node* ptr) {
		if (ptr) {
			if (ptr->key == key)
			{
				return ptr;
			}
			else if (key < ptr->key) {
				return(returnNode_(key, ptr->left));
			}
			else {
				return(returnNode_(key, ptr->right));
			}
		}
		else {
			return nullptr;
		}
	}
	int findSmallestK_(BinarySearchTree::Node* ptr) {
		if (!root) {
			std::cout << "Tree is empty" << std::endl;
			return -1;
		}
		else {
			if (ptr->left) {
				return findSmallestK_(ptr->left);
			}
			else {
				return ptr->key;
			}

		}
	}
	void removeNode_(int key, BinarySearchTree::Node* parent) {
		if (root) {
			if (root->key == key) {
				removeRootMatch();
			}
			else {
				if (key < parent->key && parent->left) {
					parent->left->key == key ?
						removeMatch(parent, parent->left, true) :
						removeNode_(key, parent->left);
				}
				else if (key > parent->key&& parent->right) {
					parent->right->key == key ?
						removeMatch(parent, parent->right, false) :
						removeNode_(key, parent->right);
				}
				else {
					std::cout << "Not found this key" << std::endl;
				}
			}
		}
		else {
			std::cout << "Tree is empty" << std::endl;
		}
	}
	void removeRootMatch() {
		if (root) {
			Node* delPtr = root;
			int rootK = root->key;
			int smallInRghtSubtr;
			// 0 children
			if (!root->left && !root->left) {
				root = nullptr;
				delete delPtr;
			}
			// 1 child
			else if (!root->left && root->right) {
				root = root->right;
				delPtr->right = nullptr;
				delete delPtr;
				std::cout << "The root with key :" << rootK << "was deleted" << std::endl;
			}
			else if (root->left && !root->right) {
				root = root->left;
				delPtr->left = nullptr;
				delete delPtr;
				std::cout << "The root with key :" << rootK << "was deleted" << std::endl;
			}
			else {
				smallInRghtSubtr = findSmallestK_(root->right);
				removeNode_(smallInRghtSubtr, root);
				std::cout << "The root with key" << rootK << " was replased by " << root->key << std::endl;
			}
		}
		else {
			std::cout << "Tree is empty" << std::endl;
		}
	}
	void removeMatch(BinarySearchTree::Node* parent, BinarySearchTree::Node* match, bool isLeft) {
		if (root) {
			Node* delPtr;
			int matchK = match->key;
			int smallestInRightSub;
			// zero child
			if (!match->right && match->left) {
				delPtr = match;
				isLeft == true ?
					parent->left = nullptr
					: parent->right = nullptr;
				delete delPtr;
				std::cout << "Key" << matchK << "was removed" << std::endl;
			}
			// 1 child
			else if (match->left && !match->right ) {
				isLeft == true ?
					parent->left = match->right :
					parent->right = match->right;
				match->right = nullptr;
				delete delPtr;
				std::cout << "Key" << matchK << "was removed" << std::endl;
			}
			else if (match->left && !match->right) {
				isLeft == true ?
					parent->left = match->left :
					parent->right = match->left;
				match->left = nullptr;
				delete delPtr;
				std::cout << "Key" << matchK << "was removed" << std::endl;
			}
			// 2 child
			else {
				smallestInRightSub = findSmallestK_(match->right);
				removeNode_(smallestInRightSub, match);
				match->key = smallestInRightSub;
			}
		}
		else {
			std::cout << "Tree is empty" << std::endl;
		}
	}
public:
	BinarySearchTree() :root(nullptr) {

	}
	~BinarySearchTree() {}

	Node* createLeaf(int key) {
		Node* leaf = new Node();
		leaf->key = key;
		leaf->left = nullptr;
		leaf->right = nullptr;
		return leaf;
	}
	void  addLeaf(int key) {
		addLeaf_(key, root);
	}
	void  printInOrder() {
		printInOrder_(root);
	}
	Node* returnNode(int key) {
		return returnNode_(key, root);
	}

	int returnRootK()
	{
		if (root != nullptr) {
			return root->key;
		}
		else {
			return -1;
		}
	}
	void printChildren(int key) {
		Node* ptr = returnNode(key);
		if (ptr != nullptr) {
			std::cout << "parent Node : " << ptr->key << std::endl;
			if (ptr->left == nullptr) {
				std::cout << "left child point to nullptr " << std::endl;
			}
			else {
				std::cout << " left child = " << ptr->left->key;
			}
			if (ptr->right == nullptr) {
				std::cout << "right child point to nullptr." << std::endl;
			}
			else {
				std::cout << " right child = " << ptr->right->key;
			}

		}
		else {
			std::cout << key << "is not exist";
		}
	}
	int findSmallestK() {
		findSmallestK_(root);
	}
	void removeNode(int key) {
		removeNode_(key, root);
	}
};