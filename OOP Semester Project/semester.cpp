#include "semester.h" 
#include <iostream>

using namespace std;

Semester::Semester() : Semester_no(1), number_of_enrollments(0), registerations(nullptr)
{

}
Semester::Semester(int passed_semester_no) : Semester_no(passed_semester_no), number_of_enrollments(0), registerations(nullptr)
{

}
Semester::Semester(const Semester& other) : Semester_no(other.Semester_no), number_of_enrollments(other.number_of_enrollments), registerations(other.registerations)
{

}
Semester& Semester:: operator=(const Semester& other)
{
	Semester_no = other.Semester_no;

	delete[] registerations;

	registerations = new Registeration[other.number_of_enrollments];

	number_of_enrollments = other.number_of_enrollments;

	for (int i = 0; i < number_of_enrollments; i++)
	{
		registerations[i] = other.registerations[i];
	}

	number_of_enrollments = other.number_of_enrollments;


	return  *this;

}

void regrow_semester(Semester*& sems, int number_of_sems)
{
	Semester* new_sems = new Semester[number_of_sems + 1];
	for (int i = 0; i < number_of_sems; i++)
	{
		new_sems[i] = sems[i];
	}
	delete[] sems;

	sems = new_sems;

}

Registeration*& Semester::get_registerations()
{
	return registerations;
}
int& Semester::get_number_of_enrollments()
{
	return number_of_enrollments;
}

Discussion& Semester::get_discussion(my_string id_of_target_course)
{

	for (int i = 0; i < number_of_enrollments; i++)
	{
		if (id_of_target_course.string_equality(registerations[i].get_off_course()->get_course_id().get_string_ptr()))
		{

			return registerations[i].get_discussion();
		}
	}
	throw("No such course");
}