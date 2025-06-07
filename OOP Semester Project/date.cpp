#include <iostream>
#include "date.h"
#include "my_string.h"
using namespace std;

Date::Date() : day(1), month(1), year(1)
{

}
Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{

}
Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year)
{

}
Date& Date :: operator=(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;

	return *this;
}

Date::Date(my_string passed_date)
{
	int count = 0;
	my_string* date = passed_date.split('/', count);
	day = date[0].convert_string_to_int();
	month = date[1].convert_string_to_int();
	year = date[2].convert_string_to_int();
}

void Date::display() const
{
	cout << day << "/" << month << "/" << year << endl;
}