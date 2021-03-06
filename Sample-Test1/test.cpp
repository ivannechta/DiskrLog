#include "pch.h"
#include "../DiskrLog/Number.h"
TEST(Constructor, EqualNum) {
	EXPECT_EQ(Number("0010") == Number("0010"), true);
	EXPECT_EQ(Number("0010") == Number("0100"), false);
	EXPECT_EQ(Number("0010") == Number("010"), false);
}

TEST(Constructor, Throw) {
	ASSERT_THROW(Number(""), int);
}

TEST(AsArray, GetDigit) {
	Number a("0");
	Number b("1");
	Number c("10");
	Number d("11");
	EXPECT_EQ(a[0], 0);
	EXPECT_EQ(b[0], 1);
	EXPECT_EQ(c[0], 1);
	EXPECT_EQ(d[1], 1);
	EXPECT_EQ(a[1], -1);
}

TEST(Shift, Shift) {
	Number a("0");
	a << 1;
	EXPECT_EQ(a == Number("01"), true);
	a << 0;
	EXPECT_EQ(a == Number("010"), true);
	a << 1;
	EXPECT_EQ(a == Number("0101"), true);
}

TEST(Mul, AddZero) {
	Number a("1");
	a * 1;
	EXPECT_EQ(a == Number("1"), true);
	a * 3;
	EXPECT_EQ(a == Number("001"), true);
	a << 1;
	a * 5;
	EXPECT_EQ(a == Number("00011"), true);
	a * 3;
	EXPECT_EQ(a == Number("00011"), true);
}

TEST(Shift, Neg) {
	Number a("0");
	a << 1;
	EXPECT_EQ(a != Number("01"), false);
	a << 0;
	EXPECT_EQ(a != Number("110"), true);
	a << 1;
	EXPECT_EQ(a != Number("0101"), false);
}

TEST(Add, Throw) {
	Number a("0000");
	Number b("011");
	ASSERT_THROW(a + b, int);
}

TEST(Add, Equal) {
	Number a("1010");
	Number b("1010");
	EXPECT_EQ((a + b) == Number("0000"), true);
}

TEST(Add, Diff) {
	Number a("0000");
	Number b("1111");
	EXPECT_EQ((a + b) == Number("1111"), true);
}

TEST(Shift, Back) {
	Number a("0011");
	Number b("11000");
	EXPECT_EQ( (a>>5)== Number("11000"), true);
}

TEST(Shift, Back_Zero) {
	Number a("0000");		
	ASSERT_THROW(a >> 5, int);		
}
TEST(Shift, Back_Trunc) {
	Number a("1000");
	EXPECT_EQ((a >> 3) == Number("100"), true);
}

TEST(Assign, simple) {
	Number a("0011");
	Number b;
	b = a;
	EXPECT_EQ(b == a, true);
}
TEST(Assign, NonZero) {
	Number a("0010");
	Number b("1000");
	b = a;
	EXPECT_EQ(b == Number((char*)"0010"), true);
}

TEST(Compare, Compare) {
	Number a("100");Number b("1000");		
	EXPECT_EQ(a < b, true);
	EXPECT_EQ((b < a), false);
	
	Number c("111"); Number d("111");
	EXPECT_EQ(c < d, false);
	EXPECT_EQ(d < c, false);

	Number e("1"); Number f("0000");
	EXPECT_EQ(f < e, true);
	EXPECT_EQ(e < f, false);
	EXPECT_EQ(e < e, false);		
}



TEST(Compact, Compact) {
	Number a("0011");		
	-a;
	EXPECT_EQ(a==Number("11"), true);

	Number b("1011");
	-b;
	EXPECT_EQ(b == Number("1011"), true);

	Number c("000");
	-c;
	EXPECT_EQ(c == Number("0"), true);

	Number d("0");
	-d;
	EXPECT_EQ(d == Number("0"), true);

	Number e("1");
	-e;
	EXPECT_EQ(e == Number("1"), true);
}

