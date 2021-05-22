#include "TPolinom.h"
#include <gtest.h>

TEST(polynom, can_create_polynomial)
{
	ASSERT_NO_THROW(TPolinom polinom);
}

TEST(polynom, can_plus_monom)
{
	TPolinom polinom;
	polinom += TMonom(2, 3, new double[3]{ 1, 2, 3 });
	ASSERT_NO_THROW(polinom += TMonom(3, 3, new double[3]{ 1, 2, 3 }));
	auto i = polinom.begin();
	EXPECT_EQ(5, (*i).K);
	EXPECT_EQ(3, (*i).dim);
	EXPECT_EQ(1, (*i).data[0]);
	EXPECT_EQ(2, (*i).data[1]);
	EXPECT_EQ(3, (*i).data[2]);
}

TEST(polynomial, can_copy)
{
	TPolinom polinom;
	polinom += TMonom(2,3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3,4, new double[4]{ 5, 6, 7, 9 });
	ASSERT_NO_THROW(TPolinom polinom2(polinom));
	TPolinom polinom2(polinom);
	EXPECT_EQ(2, polinom2.GetSize());

	auto i = polinom2.begin();
	EXPECT_EQ(3, (*i).K);
	EXPECT_EQ(4, (*i).dim);
	EXPECT_EQ(5, (*i).data[0]);
	EXPECT_EQ(6, (*i).data[1]);
	EXPECT_EQ(7, (*i).data[2]);
	EXPECT_EQ(9, (*i).data[3]);

	i++;
	EXPECT_EQ(2, (*i).K);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_multi)
{
	TPolinom polinom;
	polinom += TMonom(2,3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3,3, new double[3]{ 7, 8, 9 });

	TPolinom polinom2;
	polinom2 += TMonom(4, 3, new double[3]{ 1, 2, 3 });
	polinom2 += TMonom(5,3, new double[3]{ 8, 9, 1 });

	ASSERT_NO_THROW(polinom * polinom2);

	TPolinom polinom3 = polinom2 * polinom;

	auto i = polinom3.begin();
	EXPECT_EQ(15, (*i).K);
	EXPECT_EQ(3, (*i).dim);
	EXPECT_EQ(15, (*i).data[0]);
	EXPECT_EQ(17, (*i).data[1]);
	EXPECT_EQ(10, (*i).data[2]);

	i++;
	EXPECT_EQ(10, (*i).K);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_plus)
{
	TPolinom polinom;
	polinom += TMonom(2, 3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3, 3, new double[3]{ 8, 9, 1 });

	TPolinom polinom2;
	polinom2 += TMonom(4,3, new double[3]{ 3, 5, 2 });
	polinom2 += TMonom(2,3, new double[3]{ 8, 9, 1 });

	ASSERT_NO_THROW(polinom + polinom2);

	TPolinom polinom3 = polinom2 + polinom;

	auto i = polinom3.begin();
	EXPECT_EQ(5, (*i).K);
	EXPECT_EQ(3, (*i).dim);
	EXPECT_EQ(8, (*i).data[0]);
	EXPECT_EQ(9, (*i).data[1]);
	EXPECT_EQ(1, (*i).data[2]);

	i++;
	EXPECT_EQ(4, (*i).K);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_minus)
{
	TPolinom polinom;
	polinom += TMonom(2,3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3,3, new double[3]{ 8, 9, 1 });

	TPolinom polinom2;
	polinom2 += TMonom(4, 3, new double[3]{ 3, 5, 2 });
	polinom2 += TMonom(2,3, new double[3]{ 8, 9, 1 });

	ASSERT_NO_THROW(polinom - polinom2);

	TPolinom polinom3 = polinom2 - polinom;

	auto i = polinom3.begin();
	EXPECT_EQ(-1, (*i).K);
	EXPECT_EQ(3, (*i).dim);
	EXPECT_EQ(8, (*i).data[0]);
	EXPECT_EQ(9, (*i).data[1]);
	EXPECT_EQ(1, (*i).data[2]);

	i++;
	EXPECT_EQ(4, (*i).K);
	EXPECT_EQ(3, (*i).dim);
}

TEST(polynomial, can_multi_ravno)
{
	TPolinom polinom;
	polinom += TMonom(2, 3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3, 3, new double[3]{ 8, 9, 1 });

	TMonom monom(4, 3, new double[3]{ 2, 6, 5 });

	ASSERT_NO_THROW(polinom *= monom);

	auto i = polinom.begin();
	EXPECT_EQ(12, (*i).K);
	EXPECT_EQ(10, (*i).data[0]);
	EXPECT_EQ(15, (*i).data[1]);
	EXPECT_EQ(6, (*i).data[2]);

	i++;
	EXPECT_EQ(8, (*i).K);
}
