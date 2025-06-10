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

my_string Date::get_date_in_string()
{
	my_string day_str;
	my_string mon_str;
	my_string year_str;

	day_str.convert_int_to_string(day);
	mon_str.convert_int_to_string(month);
	year_str.convert_int_to_string(year);

	my_string date;

	date.string_concatenation(day_str);
	date.string_concatenation("/");
	date.string_concatenation(mon_str);
	date.string_concatenation("/");
	date.string_concatenation(year_str);

	return date;
}