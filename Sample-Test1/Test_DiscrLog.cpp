#include "pch.h"
#include "../DiskrLog/Number.h"
#include "../DiskrLog/DiscrLog.h"

TEST(DiscrLog, a_12_mod_19) {
	Number a((char*)"100011");
	Number p((char*)"1010");

	DiscrLog d(a, p);
	d.Divide();
	EXPECT_EQ(d.GetPower(), 12);
}