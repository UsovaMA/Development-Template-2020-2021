#include "QueueOnList.h"

#include <gtest.h>


TEST(QueueOnList, mozhet_sozdat_obekt_classa)
{
  EXPECT_NO_THROW(QueueOnList<int> q);
}

TEST(QueueOnList, size_vozvrashaet_0)
{
	QueueOnList<int> q;
	EXPECT_EQ(q.size(),0);
}

TEST(QueueOnList, size_vozvrashaet_size)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_EQ(q.size(), 1);
}

TEST(QueueOnList, size_rabotaet)
{
	QueueOnList<int> q;
	EXPECT_NO_THROW(q.size());
}

TEST(QueueOnList, empty_rabotaet)
{
	QueueOnList<int> q;
	EXPECT_NO_THROW(q.empty());
}

TEST(QueueOnList, empty_returns_true)
{
	QueueOnList<int> q;
	EXPECT_TRUE(q.empty());
}

TEST(QueueOnList, empty_returns_false)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_FALSE(q.empty());
}

TEST(QueueOnList, pop_throws_when_empty)
{
	QueueOnList<int> q;
	EXPECT_ANY_THROW(q.pop());
}

TEST(QueueOnList, pop_rabotaet)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_NO_THROW(q.pop());
}

TEST(QueueOnList, push_rabotaet)
{
	QueueOnList<int> q;
	EXPECT_NO_THROW(q.push(1););
}

TEST(QueueOnList, front_rabotaet)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_NO_THROW(q.front());
}

TEST(QueueOnList, front_returns_first_elem)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_EQ(q.front(),1);
}

TEST(QueueOnList, front_throws_when_empty)
{
	QueueOnList<int> q;
	EXPECT_ANY_THROW(q.front());
}

TEST(QueueOnList, back_rabotaet)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_NO_THROW(q.back());
}

TEST(QueueOnList, back_returns_last_elem)
{
	QueueOnList<int> q;
	q.push(1);
	EXPECT_EQ(q.back(), 1);
}

TEST(QueueOnList, back_throws_when_empty)
{
	QueueOnList<int> q;
	EXPECT_ANY_THROW(q.back());
}