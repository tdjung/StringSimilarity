#include <string>

using std::string;

class StringChecker {
public:
	int lengthPoint(string A, string B) {
		if (A.size() == B.size())
			return 60;

		if (A.size() * 2 <= B.size())
			return 0;

		if (B.size() * 2 <= A.size())
			return 0;

		if (A.size() > B.size())
			return (1 - (double)(A.size() - B.size()) / A.size()) * 60;
		else
			return (1 - (double)(B.size() - A.size()) / B.size()) * 60;
	}

};