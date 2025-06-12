#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include "my_string.h"

class Attendance {
	int lecture_no;
	my_string attd; // attendance
public:
	Attendance();
	Attendance(int passed_lecture_no, my_string passed_attd);
	void print_attendance();
	void set_attendance(my_string passed_atd);
	Attendance& operator=(const Attendance& other);
};

#endif // !ATTENDANCE_H
