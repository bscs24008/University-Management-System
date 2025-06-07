
#include <iostream>
#include "teacher.h"
#include "my_string.h"
#include "person.h"
#include "offered_course.h"

using namespace std;


Teacher::Teacher() : Person(), salary(0), courses_taught(nullptr), number_of_courses_taught(0)
{

}
Teacher::Teacher(const Teacher& other) : Person(other), salary(other.salary), courses_taught(other.courses_taught), number_of_courses_taught(other.number_of_courses_taught)
{

}
Teacher::Teacher(my_string passed_Teacher_id, int salary, const my_string& email, const Date& dob, const Name& name, const Address& addr) : Person(name, dob, addr, email), Teacher_id(passed_Teacher_id), salary(salary), courses_taught(nullptr), number_of_courses_taught(0)
{

}
Teacher& Teacher ::  operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		salary = other.salary;
		number_of_courses_taught = other.number_of_courses_taught;
		courses_taught = new offered_course[number_of_courses_taught];
		for (int i = 0; i < other.number_of_courses_taught; i++)
		{
			courses_taught[i] = other.courses_taught[i];
		}

	}


	return *this;
}

my_string Teacher::get_teacher_id()
{
	return Teacher_id;
}

void Teacher::display(offered_course*& offered_courses, int number_of_courses)
{
	Person::display_person();
	cout << endl;
	cout << salary;
	cout << endl << endl;

	cout << "Courses Taught:" << endl;
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		cout << "Course offering id: " << courses_taught[i].get_offered_course_id();
		courses_taught[i].get_course_id();
		cout << endl;
	}
}


void Teacher::initialize_teacher(istream& file)
{
	my_string first_name, last_name;

	my_string date;
	my_string city, country;

	file >> first_name;
	file >> last_name;
	Name name_of_person(first_name, last_name);

	file >> date;

	file >> city;
	file >> country;

	my_string email_of_teacher;

	file >> email_of_teacher;

	Address address_of_Teacher(city, country);

	Date date_of_birth(date);

	my_string id;

	file >> id;

	int teacher_salary;

	file >> teacher_salary;

	Person p(name_of_person, date_of_birth, address_of_Teacher, email_of_teacher);

	Person::operator=(p);

	salary = teacher_salary;

	Teacher_id = id;


}

offered_course*& Teacher::get_courses_taught()
{
	return courses_taught;
}
int& Teacher::get_number_of_courses_taught()
{
	return number_of_courses_taught;
}

void Teacher::post(my_string message, int id_of_course_taught)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i].get_offered_course_id() == i)
		{
			Discussion& discussion = courses_taught[i].get_Discussion();
			discussion.post(Teacher_id, message);
		}
	}
	throw("Course not found");

}
void Teacher::reply(my_string message, int id_of_course_taught, int post_id)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i].get_offered_course_id() == i)
		{
			Discussion& discussion = courses_taught[i].get_Discussion();
			discussion.reply_to_post(post_id, Teacher_id, message);
		}
	}
	throw("Course not found");
}