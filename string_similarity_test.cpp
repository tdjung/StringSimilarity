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

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}