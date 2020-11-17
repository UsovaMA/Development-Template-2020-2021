#include "priority_queue.h"
#include <gtest.h>

TEST(PriorityQueue, can_create_with_default_constractor) {
  ASSERT_NO_THROW(PriorityQueue pq;);
}

TEST(PriorityQueue, can_push_in_current_position) {
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.push(3, 2);

  int true_indx = 2;
  for (int i = 1; i < true_indx; i++)
    pq.pop();

  EXPECT_EQ(pq.top(), 3);
}

TEST(PriorityQueue, can_push_with_eq_priority) {
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.push(6, 5);

  int true_indx = 5;
  for (int i = 1; i < true_indx; i++)
    pq.pop();

  EXPECT_EQ(pq.top(), 6);
}

TEST(PriorityQueue, can_push_in_head) {
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.push(14, 0);

  int true_indx = 1;
  for (int i = 1; i < true_indx; i++)
    pq.pop();

  EXPECT_EQ(pq.top(), 14);
}

TEST(PriorityQueue, can_push_in_tail) {
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.push(7, 10);

  int true_indx = 6;
  for (int i = 1; i < true_indx; i++)
    pq.pop();

  EXPECT_EQ(pq.top(), 7);
}

TEST(PriorityQueue, can_push_in_head_with_eq_priority) {
  PriorityQueue pq;
  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.push(0, 5);
  pq.push(5, 7);

  pq.push(4, 1);

  int true_indx = 2;
  for (int i = 1; i < true_indx; i++)
    pq.pop();

  EXPECT_EQ(pq.top(), 4);
}

TEST(PriorityQueue, can_check_is_empty_after_def_constructor) {
  PriorityQueue pq;

  EXPECT_EQ(pq.isEmpty(), true);
}

TEST(PriorityQueue, can_check_is_empty_any_sample) {
  PriorityQueue pq;

  pq.push(4, 1);
  pq.pop();

  EXPECT_EQ(pq.isEmpty(), true);
}

TEST(PriorityQueue, can_delete_priority_queue) {
  PriorityQueue pq;

  pq.push(3, 1);
  pq.push(5, 4);
  pq.push(7, 4);
  pq.DelPQueue();

  EXPECT_EQ(pq.isEmpty(), true);
}
