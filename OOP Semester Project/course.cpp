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

int& get_number_of_courses()
{
	static int no_of_courses = 0;
	static bool has_data_been_loaded1 = false;

	if (!has_data_been_loaded1)
	{
		ifstream file("Courses.txt");
		file >> no_of_courses;
		file.close();
	}
	
	return no_of_courses;
}


course*& get_courses()
{
	static course* courses = nullptr;
	static bool has_data_been_loaded2 = false;
	int no_of_courses = 0;

	if (!has_data_been_loaded2)
	{
		ifstream file("Courses.txt");
		file >> no_of_courses;
		courses = new course[no_of_courses];
		for (int i = 0; i < no_of_courses; i++)
		{
			courses[i].initialize_course(file);
		}
		file.close();
	}

	return courses;
}

course::course(my_string passed_course_id, my_string passed_course_title, int passed_credits) : course_id(passed_course_id), course_title(passed_course_title), credits(passed_credits)
{

}

void course::save_to_file(ofstream& course_file)
{
	course_file << course_id;
	course_file << " ";
	course_file << course_title;
	course_file << " ";
	course_file << credits;
}