#include "offered_course.h"
#include "my_string.h"
#include "registeration.h"


Registeration::Registeration() : off_course(nullptr), grade("Not Assigned Yet")
{

}
Registeration::Registeration(offered_course* passed_off_course, my_string passed_grade) : off_course(passed_off_course), grade(passed_grade)
{

}
void Registeration::assign_grade(my_string passed_grade)
{
	grade = passed_grade;
}
my_string Registeration::get_grade()
{
	return grade;
}

void Registeration::set(my_string passed_rollno, offered_course*& passed_off_course, my_string passed_grade)
{
	rollno = passed_rollno;
	off_course = passed_off_course;
	grade = passed_grade;
}

void  Registeration::print_registeration()
{
	off_course->print_offered_course();
	cout << " : ";
	grade.print_string();
	cout << endl;
}

Discussion& Registeration::get_discussion()
{
	return off_course->get_Discussion();
}

offered_course* Registeration::get_off_course()
{
	return off_course;
}

Attendance*& Registeration::get_attendance()
{
	return attendance;
}
int& Registeration::get_number_of_lectures()
{
	return number_of_lectures;
}

my_string& Registeration::get_roll_no()
{
	return rollno;
}