#include <string>

using std::string;

class StringChecker {
public:
	double lengthPoint(string firstString, string secondString) {
		if (firstString.size() == secondString.size())
			return LENGTH_CHECK_MAX_POINT;

		if (firstString.size() * 2 <= secondString.size())
			return LENGTH_DOUBLE_DIFF_POINT;

		if (secondString.size() * 2 <= firstString.size())
			return LENGTH_DOUBLE_DIFF_POINT;

		return partialPoint(firstString, secondString);
	}

	double partialPoint(std::string& firstString, std::string& secondString)
	{
		if (firstString.size() > secondString.size())
			return (1 - (double)(firstString.size() - secondString.size()) / secondString.size()) * LENGTH_CHECK_MAX_POINT;
		else
			return (1 - (double)(secondString.size() - firstString.size()) / firstString.size()) * LENGTH_CHECK_MAX_POINT;
	}
private:
	const double LENGTH_CHECK_MAX_POINT = 60;
	const double LENGTH_DOUBLE_DIFF_POINT = 0;
};