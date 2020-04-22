#pragma once
#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename _T>
class SingleLinkedList;
template<typename _T>
class Node;
template<typename _T>
class SingleLinkedListIterator : iterator<std::input_iterator_tag, Node<_T> > {
	friend Node<_T>;
	friend SingleLinkedList<_T>;
private:
	Node<_T>* p;
public:
	bool operator!=(SingleLinkedListIterator const& other) const {
		return p != other.p;
	}
	bool operator==(SingleLinkedListIterator const& other) const {
		return p == other.p;
	}
	typename SingleLinkedListIterator::reference operator*() const {
		return *p->data;
	}
	SingleLinkedListIterator& operator++() {
		p = p->next;
		return *this;
	}
public:
	SingleLinkedListIterator(Node<_T>* p) :
		p(p) { }
public:
	SingleLinkedListIterator(const SingleLinkedListIterator& it) :
		p(it.p) { }
};

