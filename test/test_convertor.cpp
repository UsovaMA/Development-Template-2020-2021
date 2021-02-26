#include "convertor.cpp"
#include "convertor.h"
#include <gtest.h>


TEST(test_convertor, ar1)
{
	Convertor my_conv;
	my_conv.ar.value = 1;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("I", v);
}

TEST(test_convertor, ar25)
{
	Convertor my_conv;
	my_conv.ar.value = 25;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("XXV", v);
}

TEST(test_convertor, ar3904)
{
	Convertor my_conv;
	my_conv.ar.value = 3904;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("MMMCMIV", v);
}

TEST(test_convertor, ar4)
{
	Convertor my_conv;
	my_conv.ar.value = 4;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("IV", v);
}

TEST(test_convertor, ar46)
{
	Convertor my_conv;
	my_conv.ar.value = 46;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("XLVI", v);
}

TEST(test_convertor, ar695)
{
	Convertor my_conv;
	my_conv.ar.value = 695;
	string v = my_conv.toRoman(my_conv.ar).value;
	EXPECT_EQ("DCXCV", v);
}

TEST(test_convertor, ro5)
{
	Convertor my_conv;
	my_conv.ro.value = "V";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(5, v);
}

TEST(test_convertor, ro46)
{
	Convertor my_conv;
	my_conv.ro.value = "XLVI";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(46, v);
}

TEST(test_convertor, ro647)
{
	Convertor my_conv;
	my_conv.ro.value = "DCXLVII";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(647, v);
}

TEST(test_convertor, ro16)
{
	Convertor my_conv;
	my_conv.ro.value = "XVI";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(16, v);
}

TEST(test_convertor, ro109)
{
	Convertor my_conv;
	my_conv.ro.value = "CIX";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(109, v);
}

TEST(test_convertor, ro2999)
{
	Convertor my_conv;
	my_conv.ro.value = "MMCMXCIX";
	int v = my_conv.toArabic(my_conv.ro).value;
	EXPECT_EQ(2999, v);
}

TEST(test_convertor, check1)
{
	Convertor my_conv;
	my_conv.ro.value = "MLMMMMIC";
	EXPECT_EQ(1, my_conv.check(my_conv.ro));
}
TEST(test_convertor, check2)
{
	Convertor my_conv;
	my_conv.ro.value = "MLXXXXXXXII";
	EXPECT_EQ(1, my_conv.check(my_conv.ro));
}
TEST(test_convertor, check3)
{
	Convertor my_conv;
	my_conv.ro.value = "VMXIIIIC";
	EXPECT_EQ(1, my_conv.check(my_conv.ro));
}