#include "multistack.h"

#include <gtest.h>

TEST(multistack, konstruktor_rabotaet)
{
	EXPECT_NO_THROW(TMultistack st);
}
TEST(multistack, konstructor_s_parametrom_rabotaet)
{
	EXPECT_NO_THROW(TMultistack ms);
}
TEST(multistack, isempty_rabotaet) {
	TMultistack ms;

	for (int i = 0; i < StackNum; i++) {
		EXPECT_TRUE(ms.IsEmpty(i));
	}
}

TEST(multistack, isfull_rabotaet) {
	TMultistack ms;

	for (int i = 0; i < StackNum; i++) {
		EXPECT_FALSE(ms.IsFull(i));
	}
}
TEST(multistack, put_rabotaet) {
	TMultistack ms;

	int stackSize = MemLimit / StackNum;
	for (int i = 0; i < stackSize; i++) {

     ms.Put(0,10);

	}
	EXPECT_TRUE(ms.IsFull(0));
	EXPECT_FALSE(ms.IsEmpty(0));
}

TEST(multistack, get_rabotaet) {
	TMultistack ms;
	ms.Put(0, 0);
	ms.Put(0, 1);
	ms.Put(0, 2);
	ms.Put(0, 3);

	EXPECT_TRUE(ms.Get(0)==3);
	EXPECT_TRUE(ms.Get(0) == 2);
	EXPECT_TRUE(ms.Get(0) == 1);
	EXPECT_TRUE(ms.Get(0) == 0);

	EXPECT_TRUE(ms.IsEmpty(0));
}

TEST(multistack, print_rabotaet) {
	TMultistack ms;

	int stackSize = MemLimit / StackNum;

	for (int i = 0; i < StackNum; i++) {
		for (int j = 0; j < stackSize; j++) {
			ms.Put(i, i*j);
		}
	}

	ms.print();

	//EXPECT_NO_THROW(ms.print());
}
TEST(multistack, freemem_rabotaet)
{
	TMultistack ms;
	//ms.
}
TEST(multistack, Perepackovka_rabotaet)
{
	TMultistack ms;
	for (int i = 0; i < StackNum; i++)
	{
		int max_val = 80;

		for (int j = 0; j < max_val; j++) {
			ms.Put(i, j);
			//std::cout << j << " ";
		}
		
		std::cout << std::endl;

		for (int j = 0; j < max_val; j++) {
			int a = ms.Get(i);
			//std::cout << a << " ";
			EXPECT_TRUE(a == max_val-j-1);
		}

		int b = 10;
	}

}
	