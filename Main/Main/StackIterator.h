#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename T>
class Stack;
template<typename T>
class Node;
template<typename T>
class StackIterator : iterator<std::input_iterator_tag, Node<T>> {
	friend class Stack<T>;
	friend struct Node<T>;
private:
	Node<T>* p;
public:
	bool operator!=(StackIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(StackIterator const& other) const //BOOST_FOREACH
	{
		return p == other.p;
	}
	typename StackIterator::reference operator*() const
	{
		return *p;
	}
	StackIterator& operator--()
	{
		p = p->prev;
		return *this;
	}
public:
	StackIterator(Node<T>* p) :
		p(p)
	{

	}
public:
	StackIterator(const StackIterator& it) :
		p(it.p)
	{

	}
};
template<typename T>
ostream& operator << (ostream& os, Node<T>& rhs)
{
	return os << rhs.data;
}
