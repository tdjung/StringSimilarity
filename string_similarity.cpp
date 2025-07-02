#include <string>
#include <set>
#include <stdexcept>

using std::string;
using std::set;

class StringChecker {
public:
	double lengthPoint(const string& firstString, const string& secondString) {
		if (isSameLength(firstString, secondString)) return LENGTH_CHECK_MAX_POINT;
		if (isDoubleLength(firstString, secondString)) return LENGTH_DOUBLE_DIFF_POINT;

		return partialPoint(firstString, secondString);
	}

	double alphaPoint(const string& firstString, const string& secondString) {
		int diff_type_count = alphaDiffTypeCount(firstString, secondString);
		int same_type_count = alphaSameTypeCount(firstString, secondString);

		if (diff_type_count == 0)
			throw std::invalid_argument("input string size가 둘 다 0입니다");

		return static_cast<double>(same_type_count) / diff_type_count * ALPHA_CHECK_MAX_POINT;
	}

private:
	int alphaDiffTypeCount(const string& firstString, const string& secondString) {
		set<char> set1(firstString.begin(), firstString.end());
		set<char> set2(secondString.begin(), secondString.end());
		
		int totalCount = set1.size();
		for (auto c : set2)
			if (set1.find(c) == set1.end()) totalCount++;

		return totalCount;
	}
	
	int alphaSameTypeCount(const string& firstString, const string& secondString) {
		set<char> set1(firstString.begin(), firstString.end());
		set<char> set2(secondString.begin(), secondString.end());

		int totalCount = 0;
		for (auto c : set1)
			if (set2.find(c) != set2.end()) totalCount++;

		return totalCount;
	}

	bool isSameLength(const string& firstString, const string& secondString)
	{
		if (firstString.size() == secondString.size())
			return true;

		return false;
	}

	bool isDoubleLength(const string& firstString, const string& secondString)
	{
		if (firstString.size() * 2 <= secondString.size())
			return true;

		if (secondString.size() * 2 <= firstString.size())
			return true;
		
		return false;
	}

	double partialPoint(const string& firstString, const string& secondString)
	{
		if (firstString.size() > secondString.size())
			return (1 - static_cast<double>(firstString.size() - secondString.size()) / secondString.size()) * LENGTH_CHECK_MAX_POINT;
		else
			return (1 - static_cast<double>(secondString.size() - firstString.size()) / firstString.size()) * LENGTH_CHECK_MAX_POINT;
	}

	const double LENGTH_CHECK_MAX_POINT = 60;
	const double LENGTH_DOUBLE_DIFF_POINT = 0;
	const double ALPHA_CHECK_MAX_POINT = 40;
};