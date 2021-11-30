#include "gtest.h"

#include "..\HTStack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> v(5));
}

TEST(TStack, cant_create_stack_with_positive_length)
{
	ASSERT_ANY_THROW(TStack<int> v(-5));
}

TEST(TStack, can_push_in_stack) {
	TStack<int> v(5);
	ASSERT_NO_THROW(v.push(5));
}

TEST(TStack, can_get_top_of_stack) {
	TStack<int> v(5);
	v.push(5);
	ASSERT_NO_THROW(v.top());
}
TEST(TStack, top_of_stack_equal) {
	TStack<int> v(5);
	v.push(5);
	EXPECT_EQ(v.top(),5);
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> s(5);
	s.push(3);
	s.push(2);
	TStack<int> s1(s);
	EXPECT_EQ(s1,s);
}

TEST(TStack, copied_and_changed_stack_is_equal_to_source_one)
{
	TStack<int> s;
	s.push(3);
	s.push(2);
	TStack<int> s1(s);
	s1.push(4);
	EXPECT_NE(s1, s);
}

TEST(TStack, can_push_to_not_full_stack)
{
	TStack<int> s(10);
	for (int i = 0; i < 10; i++)
		ASSERT_NO_THROW(s.push(i));
}

TEST(TStack, cant_push_to_full_stack)
{
	TStack<int> s(10);
	for (int i = 0; i < 10; i++)
		s.push(i);
	ASSERT_ANY_THROW(s.push(5));
}
TEST(TStack, can_check_full_stack)
{
	TStack<int> s(10);
	EXPECT_FALSE(s.full());
	for (int i = 0; i < 9; i++)
		s.push(i);
	EXPECT_FALSE(s.full());
	s.push(5);
	EXPECT_TRUE(s.full());
}
TEST(TStack, can_check_empty_stack)
{
	TStack<int> s(10);
	EXPECT_TRUE(s.empty());
	for (int i = 0; i < 9; i++)
		s.push(i);
	EXPECT_FALSE(s.empty());
	s.push(5);
	EXPECT_FALSE(s.empty());
}

TEST(TStack, can_pop_from_not_empty_stack)
{
	TStack<int> s(10);
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++)
		ASSERT_NO_THROW(s.pop());
}

TEST(TStack, cant_pop_from_empty_stack)
{
	TStack<int> s(10);
	for (int i = 0; i < 10; i++)
		s.push(i);
	for (int i = 0; i < 10; i++)
		s.pop();
	ASSERT_ANY_THROW(s.pop());
}


