#pragma once
#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename _T>
class DoubleLinkedList;
template<typename _T>
class _ListNode;
template<typename _T>
class DoubleLinkedListIterator : iterator<std::input_iterator_tag, _T> {
	friend _ListNode<_T>;
	friend DoubleLinkedList<_T>;
private:
	_ListNode<_T>* p;
public:
	bool operator!=(DoubleLinkedListIterator const& other) const {
		return p != other.p;
	}
	bool operator==(DoubleLinkedListIterator const& other) const {
		return p == other.p;
	}
	typename DoubleLinkedListIterator::reference operator*() const {
		return p->value;
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
	DoubleLinkedListIterator(_ListNode<_T>* p) :
		p(p) { }
public:
	DoubleLinkedListIterator(const DoubleLinkedListIterator& it) :
		p(it.p) { }
};
