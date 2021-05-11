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
}

TEST(polynomial, can_copy)
{
	TPolinom polinom;
	polinom += TMonom(2,3, new double[3]{ 1, 2, 3 });
	polinom += TMonom(3,4, new double[4]{ 5, 6, 7, 9 });
	ASSERT_NO_THROW(TPolinom polinom2(polinom));
	TPolinom polinom2(polinom);
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
}
