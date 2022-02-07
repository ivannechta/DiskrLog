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