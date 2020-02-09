#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename T>
class DoubleLinkedList;
template<typename T>
class Node;
template<typename T>
class DoubleLinkedListIterator : iterator<std::input_iterator_tag, Node<T>> {
	friend class DoubleLinkedList<T>;
	friend struct Node<T>;
private:
	Node<T>* p;
public:
	bool operator!=(DoubleLinkedListIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(DoubleLinkedListIterator const& other) const //BOOST_FOREACH
	{
		return p == other.p;
	}
	typename DoubleLinkedListIterator::reference operator*() const
	{
		return *p;
	}
	DoubleLinkedListIterator& operator++()
	{
		p = p->next;
		return *this;
	}
	DoubleLinkedListIterator& operator--()
	{
		p = p->prev	;
		return *this;
	}
	DoubleLinkedListIterator& operator++(int)
	{
		p = p->next;
		return *this;
	}
public:
	DoubleLinkedListIterator(Node<T>* p) :
		p(p)
	{

	}
public:
	DoubleLinkedListIterator(const DoubleLinkedListIterator& it) :
		p(it.p)
	{

	}
};
template<typename T>
ostream& operator << (ostream& os, Node<T>& rhs)
{
	return os << rhs.value;
}