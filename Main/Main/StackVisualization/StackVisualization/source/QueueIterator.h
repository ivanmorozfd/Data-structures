#include <iterator>
#include <ostream>
using std::ostream;
using std::iterator;

template<typename T>
class Queue;
template<typename T>
class Node;
template<typename T>
class QueueIterator : iterator<std::input_iterator_tag, Node<T>> {
	friend class Queue<T>;
	friend struct Node<T>;
private:
	Node<T>* p;
public:
	bool operator!=(QueueIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(QueueIterator const& other) const //BOOST_FOREACH
	{
		return p == other.p;
	}
	typename QueueIterator::reference operator*() const
	{
		return *p;
	}
	QueueIterator& operator++()
	{
		p = p->next;
		return *this;
	}
public:
	QueueIterator(Node<T>* p) :
		p(p)
	{

	}
public:
	QueueIterator(const QueueIterator& it) :
		p(it.p)
	{

	}
};
template<typename T>
ostream& operator << (ostream& os, Node<T>& rhs)
{
	return os << rhs.data;
}
