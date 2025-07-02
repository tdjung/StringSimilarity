#include "gmock/gmock.h"
#include "string_similarity.cpp"

TEST(Length, tc1) {

	StringChecker sc;

	double length_point = sc.lengthPoint("ASD", "DSA");
	
	EXPECT_DOUBLE_EQ(60, length_point);
}

TEST(Length, tc2) {

	StringChecker sc;

	double length_point = sc.lengthPoint("A", "BB");

	EXPECT_DOUBLE_EQ(0, length_point);
}

TEST(Length, tc3) {

	StringChecker sc;

	double length_point = sc.lengthPoint("AAABB", "BAA");

	EXPECT_DOUBLE_EQ(36, length_point);
}

TEST(Length, tc4) {

	StringChecker sc;

	double length_point = sc.lengthPoint("AA", "AAE");
	EXPECT_DOUBLE_EQ(40, length_point);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}