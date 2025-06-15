#ifndef REGISTERATION_H
#define REGISTERATION_H
#include "offered_course.h"
#include "attendance.h"


class Registeration
{
	my_string rollno;
	offered_course* off_course;
	my_string grade;
	Attendance* attendance =  nullptr;
	int number_of_lectures;
public:
	Registeration();
	Registeration(offered_course* passed_off_courses, my_string passed_grade);
	void set(my_string passed_rollno, offered_course*& passed_off_course, my_string passed_grade);
	void assign_grade(my_string passed_grade);
	my_string get_grade();
	void print_registeration();
	offered_course* get_off_course();
	Discussion& get_discussion();
	Attendance*& get_attendance();
	int& get_number_of_lectures();
	my_string& get_roll_no();

};
#endif
