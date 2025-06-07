#include <iostream>
#include <fstream>
#include "my_string.h"
#include "student.h"
#include "teacher.h"
#include "discussion.h"
#include "course.h"
#include "offered_course.h"

using namespace std;

int main()
{
	fstream Courses("Courses.txt", ios::in);
	fstream Teachers("Teachers.txt", ios::in);
	fstream offered_courses_file("offered_courses.txt", ios::in);

	int number_of_courses = 0;
	int number_of_teachers = 0;
	int number_of_offered_courses = 0;

	Courses >> number_of_courses;
	Teachers >> number_of_teachers;

	course* courses = new course[number_of_courses];
	Teacher* teachers = new Teacher[number_of_teachers];

	for (int i = 0; i < number_of_courses; i++)
	{
		courses[i].initialize_course(Courses);
	}

	for (int i = 0; i < number_of_teachers; i++)
	{
		teachers[i].initialize_teacher(Teachers);
	}

	offered_courses_file >> number_of_offered_courses;

	offered_course* offered_courses = new offered_course[number_of_offered_courses];



	try
	{
		for (int i = 0; i < number_of_offered_courses; i++)
		{
			offered_courses[i].initialize_offered_courses(offered_courses_file, courses, teachers, number_of_courses, number_of_teachers);
		}
	}
	catch (const char*)
	{
		cout << "Teacher / course Not found";
	}



	Discussion discussion;


	Student* students = nullptr;

	int number_of_students = 0;

	add_student(students, number_of_students, "BSCS24008", "bscs24008@itu.edu.pk", Date("31/3/2006"), Name("Abdullah", "Khalid"), Address("Lahore", "Pakistan"), 1);
	add_student(students, number_of_students, "BSCS24118", "bscs24118@itu.edu.pk", Date("5/10/2005"), Name("Talha", "Ismail"), Address("Lahore", "Pakistan"), 1);



	offered_course* ptr = &offered_courses[0];

	try
	{
		students[0].enroll(1, offered_courses, "CS101", number_of_offered_courses);
		students[1].enroll(1, offered_courses, "CS102", number_of_offered_courses);
	}
	catch (const char*)
	{
		cout << "No such course exist or semester doesent exist for students";
	}

	teachers[0].display(offered_courses, number_of_offered_courses);


}