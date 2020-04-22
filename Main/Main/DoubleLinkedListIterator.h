#pragma once
#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename _T>
class DoubleLinkedList;
template<typename _T>
class Node;
template<typename _T>
class DoubleLinkedListIterator : iterator<std::input_iterator_tag, Node<_T>> {
	friend Node<_T>;
	friend DoubleLinkedList<_T>;
private:
	Node<_T>* p;
public:
	bool operator!=(DoubleLinkedListIterator const& other) const {
		return p != other.p;
	}
	bool operator==(DoubleLinkedListIterator const& other) const {
		return p == other.p;
	}
	typename DoubleLinkedListIterator::reference operator*() const {
		return *p;
	}
	DoubleLinkedListIterator& operator++() {
		p = p->next;
		return *this;
	}
	DoubleLinkedListIterator& operator--() {
		p = p->prev	;
		return *this;
	}
	DoubleLinkedListIterator& operator++(int) {
		p = p->next;
		return *this;
	}
public:
	DoubleLinkedListIterator(Node<_T>* p) :
		p(p) { }
public:
	DoubleLinkedListIterator(const DoubleLinkedListIterator& it) :
		p(it.p) { }
};
template<typename __T>
ostream& operator << (ostream& os, Node<__T>& rhs) {
	return os << rhs.value;
}