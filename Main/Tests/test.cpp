#include <gtest/gtest.h>
#include "../Main/Stack.h"

TEST(StackTests, CreatedStackSizeTest) 
{
	Stack<int> stack;
	ASSERT_EQ(stack.getSize(), 0);
}
TEST(StackTests, IsEmptyStackTest) 
{
	Stack<int> stack;
	ASSERT_TRUE(stack.isEmpty());
	stack.push(1);
	ASSERT_FALSE(stack.isEmpty());
}
TEST(StackTests, CreatedStackNullptrTopTest) 
{
	Stack<int> stack;
	ASSERT_THROW(stack.getTop(), StackException);
}
TEST(StackTests, StackCountTest)
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
