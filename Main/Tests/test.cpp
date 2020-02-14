#include <gtest/gtest.h>
#include "../Main/Stack.h"

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
	ASSERT_THROW(stack.getTop(), StackException);
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
	ASSERT_NO_THROW(stack.pop(), StackException);
	ASSERT_THROW(stack.pop(), StackException);
}
TEST(StackTests, StackDestructorTest)
{
	//TODO
}
TEST(StackTests, StackConstructorTest)
{
	//TODO
}
TEST(StackTests, StackCopyConstructorTest)
{
	//TODO
}
TEST(StackTests, MemoryTest)
{

}


TEST(SingleLinkedListTests, ConstructorTest)
{
	//TODO
}
TEST(SingleLinkedListTests, EmptyListTest)
{
	//TODO
}
TEST(SingleLinkedListTests, InsertAndDelTest)
{
	//TODO
}
TEST(SingleLinkedListTests, PopFromEmptyList)
{
	//TODO
}
TEST(SingleLinkedListTests, ListSizeTest)
{
	//TODO
}
TEST(SingleLinkedListTests, InitializerTest)
{
	//TODO
}
TEST(SingleLinkedListTests, ListIteratorTest)
{
	//TODO
}
TEST(SingleLinkedListTests, CopyConstructorTest)
{
	//TODO
}
TEST(SingleLinkedListTests, MemoryTest)
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



