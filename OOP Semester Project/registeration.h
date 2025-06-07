#ifndef REGISTERATION_H
#define REGISTERATION_H

#include "offered_course.h"

class Registeration
{
	offered_course* off_course;
	my_string grade;

public:
	Registeration();
	Registeration(offered_course* passed_off_courses, my_string passed_grade);
	void set(offered_course* passed_off_course, my_string passed_grade);
	void assign_grade(my_string passed_grade);
	my_string get_grade();
	void print_registeration();
	offered_course* get_off_course();
	Discussion& get_discussion();
};

void regrow_registeration(Registeration*& registerations, int number_of_registerations);
#endif
