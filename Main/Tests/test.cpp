#include <gtest/gtest.h>
#include "../Main/Stack.h"
#include "../Main/Queue.h"
#include "../Main/DoubleLinkedList.h"
#include "../Main/BinaryHeap.h"
#include "../Main/SparseMatrix.h"
#include "../Main/BinaryHeap.h"
#include "../Main/BinarySearchTree.h"
#include "../Main/AvlTree.h"
#include "../Main/RBTree.h"
TEST(StackTests, SizeTest) 
{
	Stack<int> stack;
	ASSERT_EQ(stack.getSize(), 0);
}
TEST(StackTests, IsEmptyTest) 
{
	Stack<int> stack;
	ASSERT_TRUE(stack.isEmpty());
	stack.push(1);
	ASSERT_FALSE(stack.isEmpty());
}
TEST(StackTests, NullptrTopTest) 
{
	Stack<int> stack;
	ASSERT_THROW(stack.peek(), StackException);
}
TEST(StackTests, CountTest)
{
	Stack<int> stack;
	stack.push(1);
	ASSERT_EQ(stack.getSize(), 1);
}
TEST(StackTests, StackInitializerListTest)
{
	std::initializer_list<int> initlist = { 1,2,3,4,5 };
	Stack<int>* stack = new Stack<int>(initlist);
	ASSERT_EQ(stack->getSize(), initlist.size());
}
TEST(StackTests, PopFromEmptyStack)
{
	Stack<int> stack;
	ASSERT_THROW(stack.pop(), StackException);
	stack.push(1);
	ASSERT_NO_THROW(stack.pop());
	ASSERT_THROW(stack.pop(), StackException);
}



TEST(DoubleLinkedListTests, ConstructorTest)
{
	DoubleLinkedList<int> list;
	ASSERT_THROW(list.pop_back(),DoubleLinkedListException);
	ASSERT_THROW(list.pop_front(), DoubleLinkedListException);
	ASSERT_TRUE(list.isEmpty());
	ASSERT_EQ(list.getSize(), 0);
}
TEST(DoubleLinkedListTests, EmptyListTest)
{
	DoubleLinkedList<int> list;
	ASSERT_THROW(list.pop_back(), DoubleLinkedListException);
	ASSERT_THROW(list.pop_front(), DoubleLinkedListException);
	ASSERT_TRUE(list.isEmpty());
	list.push_back(1);
	ASSERT_FALSE(list.isEmpty());
	list.pop_back();
	ASSERT_TRUE(list.isEmpty());
	list.push_front(1);
	ASSERT_FALSE(list.isEmpty());
	list.pop_front();
	ASSERT_TRUE(list.isEmpty());
}
TEST(DoubleLinkedListTests, InsertAndDelTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	ASSERT_EQ(list.back(),5);
	list.push_front(6);
	ASSERT_EQ(list.front(), 6);
	list.pop_back();
	ASSERT_EQ(list.back(), 6);
	list.pop_back();
	ASSERT_TRUE(list.isEmpty());

}
TEST(DoubleLinkedListTests, PopBackTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_front(6);
	ASSERT_EQ(list.back(), 5);
	list.pop_back();
	ASSERT_EQ(list.back(), 6);
}
TEST(DoubleLinkedListTests, PopFrontTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_front(6);
	ASSERT_EQ(list.front(), 6);
	list.pop_front();
	ASSERT_EQ(list.back(), 5);
}
TEST(DoubleLinkedListTests, BackTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_front(6);
	ASSERT_EQ(list.back(), 5);
}
TEST(DoubleLinkedListTests, FrontTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_front(6);
	ASSERT_EQ(list.front(), 6);
}
TEST(DoubleLinkedListTests, ListSizeTest)
{
	DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_front(6);
	ASSERT_EQ(list.getSize(), 2);
}
TEST(DoubleLinkedListTests, InitializerTest)
{
	DoubleLinkedList<int> list;
	
}

TEST(QueueTests, ConstructorTest)
{
	Queue<int> queue;
	ASSERT_THROW(queue.pop(),QueueException);
	ASSERT_THROW(queue.peek(), QueueException);
	ASSERT_TRUE(queue.isEmpty());
	ASSERT_EQ(queue.getLenght(), 0);
}
TEST(QueueTests, PeekTest)
{
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	ASSERT_EQ(queue.peek(), 1);
}
TEST(QueueTests, ContainTest)
{
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	ASSERT_TRUE(queue.contain(1));
	ASSERT_FALSE(queue.contain(5));
}
TEST(QueueTests, InitializerListTest)
{
	Queue<int> queue{ 1,2,3 };
	ASSERT_EQ(queue.getLenght(), 3);
	ASSERT_EQ(queue.peek(), 1);
	ASSERT_TRUE(queue.contain(1));
	ASSERT_TRUE(queue.contain(2));
	ASSERT_TRUE(queue.contain(3));
}
TEST(QueueTests, PushTest)
{
	Queue<int> queue;
	queue.push(1);
	ASSERT_TRUE(queue.contain(1));
	ASSERT_EQ(queue.peek(), 1);
}
TEST(QueueTests, PopTest)
{
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	ASSERT_TRUE(queue.contain(1));
	ASSERT_EQ(queue.peek(), 1);
	queue.pop();
	ASSERT_EQ(queue.peek(), 2);
}
TEST(QueueTests, IsEmptyTest)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.isEmpty());
	queue.push(1);
	ASSERT_FALSE(queue.isEmpty());
}
TEST(QueueTests, CountTest)
{
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	ASSERT_EQ(queue.getLenght(), 3);
	queue.pop();
	ASSERT_EQ(queue.getLenght(), 2);
	queue.clear();
	ASSERT_EQ(queue.getLenght(), 0);
}
TEST(QueueTests, EmptyPopTest)
{
	Queue<int> queue;
	ASSERT_THROW(queue.pop(), QueueException);
	queue.push(1);
	ASSERT_NO_THROW(queue.pop());
}
 

TEST(BinaryHeapTests, ConstructorTest)
{
	BinaryHeap<int> heap;
	ASSERT_EQ(heap.getSize(), 0);
	ASSERT_TRUE(heap.isEmpty());
}
TEST(BinaryHeapTests, IsEmptyTest)
{
	BinaryHeap<int> heap;
	ASSERT_TRUE(heap.isEmpty());
	heap.addItem(5);
	ASSERT_FALSE(heap.isEmpty());
}
TEST(BinaryHeapTests, AddItemTest)
{
	BinaryHeap<int> heap;
	heap.addItem(5);
	heap.addItem(50);
	heap.addItem(3);
	heap.addItem(7);
	ASSERT_EQ(heap.peekMax(), 50);
}
TEST(BinaryHeapTests, RemoveMaxTest)
{
	BinaryHeap<int> heap;
	heap.addItem(5);
	heap.addItem(50);
	heap.addItem(3);
	heap.addItem(7);
	ASSERT_EQ(heap.peekMax(), 50);
	ASSERT_EQ(heap.getmax(), 50);
	ASSERT_EQ(heap.getmax(), 7);
	ASSERT_EQ(heap.getmax(), 5);	
	ASSERT_EQ(heap.getmax(), 3);
}

TEST(BinaryHeapTests, PeekMaxTest)
{
	BinaryHeap<int> heap;
	heap.addItem(5);
	heap.addItem(50);
	heap.addItem(3);
	heap.addItem(7);
	ASSERT_EQ(heap.peekMax(), 50);
}



TEST(BinarySearchTreeTests, ConstructorTest)
{
	BinarySearchTree<int> tree;
	ASSERT_TRUE(tree.isEmpty());
	ASSERT_THROW(tree.removeByKey(3), BinarySearchTreeException);
}
TEST(BinarySearchTreeTests, IsEmptyTest)
{
	BinarySearchTree<int> tree;
	ASSERT_TRUE(tree.isEmpty());
	ASSERT_THROW(tree.removeByKey(3), BinarySearchTreeException);
	tree.addLeaf(5);
	ASSERT_FALSE(tree.isEmpty());
}
TEST(BinarySearchTreeTests, AddLeafTest)
{
	BinarySearchTree<int> tree;
	tree.addLeaf(5);
	tree.addLeaf(6);
	tree.addLeaf(4);
	ASSERT_EQ(tree.findMin(), 4);
	tree.addLeaf(1);
	ASSERT_EQ(tree.findMin(), 1);
}
TEST(BinarySearchTreeTests, RemoveLeafTest)
{
	BinarySearchTree<int> tree;
	tree.addLeaf(5);
	tree.addLeaf(6);
	tree.addLeaf(4);
	ASSERT_EQ(tree.findMin(), 4);
	tree.removeByKey(4);
	ASSERT_EQ(tree.findMin(), 5);
}
TEST(BinarySearchTreeTests, RootKeyTest)
{
	BinarySearchTree<int> tree;
	tree.addLeaf(5);
	tree.addLeaf(6);
	tree.addLeaf(4);
	ASSERT_EQ(tree.returnRootKey(), 5);
}
TEST(BinarySearchTreeTests, FindMinTest )
{
	BinarySearchTree<int> tree;
	tree.addLeaf(5);
	tree.addLeaf(6);
	tree.addLeaf(3);
	tree.addLeaf(11);
	tree.addLeaf(4);
	tree.addLeaf(7);
	tree.addLeaf(111);
	tree.addLeaf(1);

	ASSERT_EQ(tree.findMin(), 1);
}

