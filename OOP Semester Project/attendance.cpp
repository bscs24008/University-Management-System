#include "attendance.h"
#include "my_string.h"


Attendance::Attendance()
{

}
Attendance::Attendance(int passed_lecture_no, my_string passed_attd) : lecture_no(passed_lecture_no), attd(passed_attd)
{

}
void Attendance::print_attendance()
{
	cout << "Lecture " << lecture_no << ": " << attd;
}
void Attendance::set_attendance(my_string passed_atd)
{
	attd = passed_atd;
}
Attendance& Attendance::operator=(const Attendance& other)
{
	if (this != &other)
	{
		lecture_no = other.lecture_no;
		attd = other.attd;
	}

	return *this;
}