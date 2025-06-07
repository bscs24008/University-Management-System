#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include "my_string.h"
#include <fstream>

class course;


class course
{
	my_string course_id;
	my_string course_title;
	int credits = 0;
public:
	course();
	void print_course();
	void initialize_course(istream& file);
	course(const course& c);
	void operator=(const course& c);
	my_string& get_course_id();
	my_string& get_course_title();
	course& get_course();

};

course* regrow_course(int current_number_of_courses, course* courses);

#endif