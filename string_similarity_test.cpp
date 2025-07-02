#include "gmock/gmock.h"
#include "string_similarity.cpp"

class StringCheckerFixture : public testing::Test {
public:
	StringChecker sc;

	void lengthCheck(double expectPoint, const string& firstString, const string& secondString) {
		EXPECT_DOUBLE_EQ(expectPoint, sc.lengthPoint(firstString, secondString));
	}

	void alphaCheck(double expectPoint, const string& firstString, const string& secondString) {
		EXPECT_DOUBLE_EQ(expectPoint, sc.alphaPoint(firstString, secondString));
	}

	void similarityCheck(double expectPoint, const string& firstString, const string& secondString) {
		EXPECT_DOUBLE_EQ(expectPoint, sc.stringSimilarityPoint(firstString, secondString));
	}
};

TEST_F(StringCheckerFixture, lenghCheckString1) {
	lengthCheck(60,"ASD", "DSA");
}

TEST_F(StringCheckerFixture, lenghCheckString2) {
	lengthCheck(0 ,"A", "BB");
}

TEST_F(StringCheckerFixture, lenghCheckString3) {
	lengthCheck(20, "AAABB", "BAA");;
}

TEST_F(StringCheckerFixture, lenghCheckString4) {
	lengthCheck(30, "AA", "AAE");
}

TEST_F(StringCheckerFixture, alphaCheckString1) {
	alphaCheck(40, "ASD", "DSA");
}

TEST_F(StringCheckerFixture, alphaCheckString2) {
	alphaCheck(0 , "A", "BB");
}

TEST_F(StringCheckerFixture, alphaCheckString3) {
	alphaCheck(40, "AAABB", "BA");
}

TEST_F(StringCheckerFixture, alphaCheckString4) {
	alphaCheck(20, "AA", "AAE");
}

TEST_F(StringCheckerFixture, StringSimilarityPoint1) {
	similarityCheck(0, "A", "BBB");
}

TEST_F(StringCheckerFixture, StringSimilarityPoint2) {
	similarityCheck(50, "AA", "AAE");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}