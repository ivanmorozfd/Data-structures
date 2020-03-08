#pragma once
#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename T>
class SingleLinkedList;
template<typename T>
class Node;
template<typename T>
class SingleLinkedListIterator : iterator<std::input_iterator_tag, Node<T> > 
{
	friend Node<T>;
	friend class SingleLinkedList<T>;
private:
	Node<T>* p;
public:
	bool operator!=(SingleLinkedListIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(SingleLinkedListIterator const& other) const //BOOST_FOREACH
	{
		return p == other.p;
	}
	typename SingleLinkedListIterator::reference operator*() const
	{
		return *p;
	}
	SingleLinkedListIterator& operator++()
	{
		p = p->next;
		return *this;
	}
public:
	SingleLinkedListIterator(Node<T>* p) :
		p(p)
	{

	}
public:
	SingleLinkedListIterator(const SingleLinkedListIterator& it) :
		p(it.p)
	{

	}
};
template<typename T>
ostream& operator << (ostream& os, Node<T>& rhs)
{
	return os << rhs.data;
}
