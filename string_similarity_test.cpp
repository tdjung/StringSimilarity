#include "gmock/gmock.h"
#include "string_similarity.cpp"

class StringCheckerFixture : public testing::Test {
public:
	StringChecker sc;

	void lengthCheck(double expectPoint, const string& firstString, const string& secondString) {
		EXPECT_DOUBLE_EQ(expectPoint, sc.lengthPoint(firstString, secondString));
	}
};

TEST_F(StringCheckerFixture, string1) {
	lengthCheck(60,"ASD", "DSA");
}

TEST_F(StringCheckerFixture, string2) {
	lengthCheck(0 ,"A", "BB");
}

TEST_F(StringCheckerFixture, string3) {
	lengthCheck(20, "AAABB", "BAA");;
}

TEST_F(StringCheckerFixture, string4) {
	lengthCheck(30, "AA", "AAE");
}

TEST(StringCheckAlpha, tc1) {
	StringChecker sc;

	double alpha_point = sc.alphaPoint("ASD", "DSA");
	EXPECT_DOUBLE_EQ(40, alpha_point);
}

TEST(StringCheckAlpha, tc2) {
	StringChecker sc;

	double alpha_point = sc.alphaPoint("A", "BB");
	EXPECT_DOUBLE_EQ(0, alpha_point);
}

TEST(StringCheckAlpha, tc3) {
	StringChecker sc;

	double alpha_point = sc.alphaPoint("AAABB", "BA");
	EXPECT_DOUBLE_EQ(40, alpha_point);
}

TEST(StringCheckAlpha, tc4) {
	StringChecker sc;

	double alpha_point = sc.alphaPoint("AA", "AAE");
	EXPECT_DOUBLE_EQ(20, alpha_point);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}