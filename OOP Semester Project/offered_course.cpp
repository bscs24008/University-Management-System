#include <iostream>
#include "offered_course.h"
#include "teacher.h"
#include "course.h"
#include "my_string.h"
using namespace std;

class teacher {};

offered_course::offered_course() : offered_course_id(0), course()
{
}
offered_course& offered_course :: operator=(offered_course const& other)
{
	if (this != &other)
	{
		course::operator=(other);
		offered_course_id = other.offered_course_id;
		course_instructor = other.course_instructor;
	}

	return *this;
}

offered_course* regrow_offered_courses(int current_number_of_courses, offered_course* old_ptr)
{
	offered_course* new_ptr = new offered_course[current_number_of_courses + 1];
	for (int i = 0; i < current_number_of_courses; i++)
	{
		new_ptr[i] = old_ptr[i];
	}

	new_ptr[current_number_of_courses] = offered_course();
	return new_ptr;
}

void offered_course::set_offered_course(course* c, Teacher* t, int passed_offered_course_id)
{
	course::operator=(*c);
	course_instructor = t;
	offered_course_id = passed_offered_course_id;
}

void offer_course(offered_course*& offered_courses, int& current_number_of_offered_courses, int current_number_of_courses, course* courses, my_string course_id, Teacher* teachers, my_string teacher_id, int current_number_of_teachers)
{
	int index_of_Teacher = 0;
	int index_of_Course = 0;
	bool flag = false;
	for (int i = 0; i < current_number_of_courses; i++)
	{
		if (courses[i].get_course_id().string_equality(course_id))
		{
			index_of_Course = i;
			flag = true;
			break;

		}
	}
	if (!flag)
	{
		throw("Course Not found");
	}
	flag = false;
	for (int i = 0; i < current_number_of_teachers; i++)
	{
		if (teachers[i].get_teacher_id().string_equality(teacher_id))
		{
			index_of_Teacher = i;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		throw("Teacher Not found");
	}

	offered_courses = regrow_offered_courses(current_number_of_offered_courses, offered_courses);
	offered_courses[current_number_of_offered_courses].set_offered_course(&courses[index_of_Course], &teachers[index_of_Teacher], current_number_of_offered_courses);
	current_number_of_offered_courses++;

	offered_course* ids_of_courses = teachers[index_of_Teacher].get_courses_taught();
	int& number_of_courses_taught = teachers[index_of_Teacher].get_number_of_courses_taught();

	ids_of_courses = regrow_offered_courses(number_of_courses_taught, ids_of_courses);

	ids_of_courses[number_of_courses_taught] = offered_courses[current_number_of_offered_courses - 1];

	number_of_courses_taught++;

}

void offered_course::print_offered_course()
{
	course::print_course();
	course_instructor->display_person();
}

void offered_course::initialize_offered_courses(fstream& f, course*& courses, Teacher*& teachers, int number_of_courses, int number_of_teachers)
{
	bool flag = false;

	my_string course_id, teacher_id;

	f >> course_id;
	f >> teacher_id;
	f >> offered_course_id;

	int index_of_teacher = 0;

	int index_of_course;

	for (int i = 0; i < number_of_courses; i++)
	{
		if (course_id.string_equality(courses[i].get_course_id()))
		{
			course::operator=(courses[i]);
			flag = true;
			index_of_course = i;
			break;
		}
	}
	if (!flag)
	{
		throw("Teacher or Course not found");
	}

	flag = false;
	for (int i = 0; i < number_of_teachers; i++)
	{
		if (teachers[i].get_teacher_id().string_equality(teacher_id))
		{
			course_instructor = &teachers[i];
			flag = true;
			index_of_teacher = i;
			break;
		}
	}
	if (!flag)
	{
		throw("Teacher or Course not found");
	}

	offered_course*& courses_taught = teachers[index_of_teacher].get_courses_taught();
	int& number_of_courses_taught = teachers[index_of_teacher].get_number_of_courses_taught();

	courses_taught = regrow_offered_courses(number_of_courses_taught, courses_taught);

	my_string off_course_id;

	off_course_id.convert_int_to_string(offered_course_id);


	courses_taught[number_of_courses_taught] = *this;

	number_of_courses_taught++;


}

Discussion& offered_course::get_Discussion()
{
	return discussion;
}

my_string offered_course::get_course_id()
{
	return course::get_course_id();
}

int offered_course::get_offered_course_id()
{
	return offered_course_id;
}