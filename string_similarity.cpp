#include <string>

using std::string;

class StringChecker {
public:
	double lengthPoint(const string& firstString, const string& secondString) {
		if (isSameLength(firstString, secondString)) return LENGTH_CHECK_MAX_POINT;
		if (isDoubleLength(firstString, secondString)) return LENGTH_DOUBLE_DIFF_POINT;

		return partialPoint(firstString, secondString);
	}

private:
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
};