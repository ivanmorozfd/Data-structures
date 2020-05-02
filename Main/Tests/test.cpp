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
	ASSERT_THROW(list.pop_back(),StackException);
	ASSERT_THROW(list.pop_front(), StackException);
}
TEST(DoubleLinkedListTests, EmptyListTest)
{
	//TODO
}
TEST(DoubleLinkedListTests, InsertAndDelTest)
{
	//TODO
}
TEST(DoubleLinkedListTests, PopFromEmptyList)
{
	//TODO
}
TEST(DoubleLinkedListTests, ListSizeTest)
{
	//TODO
}
TEST(DoubleLinkedListTests, InitializerTest)
{
	//TODO
}
TEST(DoubleLinkedListTests, ListIteratorTest)
{
	//TODO
}
TEST(DoubleLinkedListTests, CopyConstructorTest)
{
	//TODO
}

TEST(QueueTests, HeadTest)
{
	//TODO
}
TEST(QueueTests, TailTest)
{
	//TODO
}
TEST(QueueTests, ConstructorTest)
{
	//TODO
}
TEST(QueueTests, CopyConstructorTest)
{
	//TODO
}
TEST(QueueTests, DestructorTest)
{
	//TODO
}
TEST(QueueTests, InitializerListTest)
{
	//TODO
}
TEST(QueueTests, PushTest)
{
	//TODO
}
TEST(QueueTests, PopTest)
{
	//TODO
}
TEST(QueueTests, IsEmptyTest)
{
	//TODO
}
TEST(QueueTests, CountTest)
{
	//TODO
}
TEST(QueueTests, EmptyPopTest)
{
	//TODO
}
TEST(QueueTests, IteratorTest)
{
	//TODO
}
TEST(QueueTests, MemoryTest)
{
	//TODO
}

TEST(AVLTreeTests, ConstructorTest)
{

}
