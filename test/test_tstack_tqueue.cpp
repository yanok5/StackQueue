#include "stackqueue.h"

#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(Stack<int> s(MAX_STACK_SIZE + 1));
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> s(10));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> s(-1));
}

TEST(Stack, cant_create_stack_with_very_big_length)
{
	ASSERT_ANY_THROW(Stack<int> s(1001));
}

TEST(Stack, can_push)
{
	Stack<int> s(2);
	ASSERT_NO_THROW(s.Push(1));
}

TEST(Stack, can_pop)
{
	Stack<int> s;
	ASSERT_ANY_THROW(s.Pop());
}

TEST(Stack, can_repack_when_push)
{
	Stack<int> s(1);
	s.Push(1);
	ASSERT_NO_THROW(s.Push(2));
	ASSERT_EQ(2, s.Top());
}

TEST(Stack, throws_when_free)
{
	Stack<int> s(2);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(Stack, can_get_top)
{
	Stack<int> s(3);
	s.Push(1);
	ASSERT_NO_THROW(s.Top());
}
/*---------------------------------------------------------------------------------------------------------*/

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> s);
}

TEST(Queue, can_push)
{
	Queue<int> q;
	ASSERT_NO_THROW(q.Push(1));
}

TEST(Queue, no_throw_when_push_into_full_queue)
{
	Queue<int> q(3);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	ASSERT_NO_THROW(q.Push(4));
}

TEST(Queue, can_pop)
{
	Queue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, throws_when_pop_from_empty_stack)
{
	Queue<int> q;
	ASSERT_ANY_THROW(q.Pop());
}

TEST(Queue, no_throw_when_many_pushes_and_pops)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Pop();
	q.Push(6);
	ASSERT_NO_THROW(q.Pop());
}

TEST(Queue, works_correctly)
{
	Queue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	q.Pop();
	q.Push(6);
	EXPECT_EQ(6, q[4]);
}

TEST(Queue, can_return_element)
{
	Queue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q[0]);
}
