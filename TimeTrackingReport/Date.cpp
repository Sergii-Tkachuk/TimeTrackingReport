#include "Date.h"

void Date::convertStringToDate(std::string str)
{
	char separator;
	std::stringstream stream(str);
	stream >> Years >> separator;
	stream >> Months >> separator;
	stream >> Days;
}

std::string Date::getNameMonth() const
{
	switch (Months)
	{
	case January: return "January";
	case February: return "February";
	case March: return "March";
	case April: return "April";
	case May: return "May";
	case June: return "June";
	case July: return "July";
	case August: return "August";
	case September: return "September";
	case October: return "October";
	case November: return "November";
	case December: return "December";
	default: return "NONE";
	}
}