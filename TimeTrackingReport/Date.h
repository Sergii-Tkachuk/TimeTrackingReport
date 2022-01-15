#ifndef DATE_H
#define DATE_H
#include <sstream>
#include <string>

class Date
{
private:
	enum Months
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

public:
	int Years;
	int Months;
	int Days;

	void convertStringToDate(std::string str);
	std::string getNameMonth() const;
};

#endif //DATE_H