#include <iostream>
#include "course.h";
#include "my_string.h"
#include <fstream>

using namespace std;

course::course() : course_id(), course_title(), credits(0)
{
}
course::course(const course& c)
{
	course_id = c.course_id;
	course_title = c.course_title;
	credits = c.credits;
}
void course::print_course()
{
	cout << course_id;
	cout << " ";
	cout << course_title;
	cout << " ";
	cout << credits;
	cout << endl;
}
void course::initialize_course(istream& file)
{
	file >> course_id;
	file >> course_title;
	file >> credits;
}

void course :: operator=(const course& c)
{
	course_id = c.course_id;
	course_title = c.course_title;
	credits = c.credits;
}

course* regrow_course(int current_number_of_courses, course* courses)
{
	course* temp = new course[current_number_of_courses + 1];

	for (int i = 0; i < current_number_of_courses; i++)
	{
		temp[i] = courses[i];
	}

	return temp;
}

my_string& course::get_course_id()
{
	return course_id;
}

my_string& course::get_course_title()
{
	return course_title;
}

course& course::get_course()
{
	return *this;
}