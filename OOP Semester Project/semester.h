#ifndef SEMESTER_H
#define SEMESTER_H

#include "registeration.h"

class Semester
{
private:
	int Semester_no;
	Registeration* registerations = nullptr;
	int number_of_enrollments = 0;

public:
	Semester();
	Semester(int id);
	Semester(const Semester& other);
	Semester& operator=(const Semester& other);
	Registeration*& get_registerations();
	int& get_number_of_enrollments();
	Discussion& get_discussion(my_string id_of_target_course);
};

#endif