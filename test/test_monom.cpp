#include "TMonom.h"
#include <gtest.h>

TEST(monom, can_create_monom)
{

	ASSERT_NO_THROW(TMonom monom);
}
TEST(monom, can_get_K)
{
TMonom monom(5, 3, new double[3]{ 1, 2, 3 });

	EXPECT_EQ(monom.GetK(), 5);
}

TEST(monom, can_get_dim)
{
	TMonom monom(5, 3, new double[3]{ 1, 2, 3 });
	EXPECT_EQ(monom.GetDim(), 3);
}


TEST(monomial, can_set_dim)
{
	TMonom monom(5, 5, new double[5]{ 4, 5, 3, 2, 6 });
	TMonom monom2(monom);

	monom.SetDim(3);
	EXPECT_EQ(3, monom.GetDim());
	EXPECT_EQ(3, monom[2]);

	monom2.SetDim(6);
	EXPECT_EQ(6, monom2.GetDim());
	EXPECT_EQ(0, monom2[5]);
}

TEST(monomial, can_ravno)
{
	TMonom monom(5, 5, new double[5]{ 1, 2, 3, 4, 5 });

	ASSERT_NO_THROW(TMonom monom2 = monom);
	TMonom monom2 = monom;

	EXPECT_EQ(5, monom2.GetK());
	EXPECT_EQ(3, monom2[2]);
}

TEST(monomial, can_multiply)
{
	TMonom monom1(4, 3, new double[3]{ 1, 2, 3 });
	TMonom monom2(3, 3, new double[3]{ 1, 2, 3 });

	ASSERT_NO_THROW(monom1 * monom2);
	TMonom m3 = monom1 * monom2;

	EXPECT_EQ(12, m3.GetK());
	EXPECT_EQ(4, m3[1]);
}

TEST(monomial, can_divide)
{
	TMonom monom1(6, 3, new double[3]{ 1, 4, 3 });
	TMonom monom2(3, 3, new double[3]{ 1, 2, 3 });

	ASSERT_NO_THROW(monom1 / monom2);
	TMonom m3 = monom1 / monom2;

	EXPECT_EQ(2, m3.GetK());
	EXPECT_EQ(2, m3[1]);
}

TEST(monomial, can_equal)
{
	TMonom monom1(2, 2, new double[2]{ 2, 3 });
	TMonom monom2(1, 2, new double[2]{ 2, 3 });

	ASSERT_NO_THROW(monom1 == monom2);
	EXPECT_EQ(true, monom1 == monom2);
}