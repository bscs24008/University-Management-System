
#include <iostream>
#include "teacher.h"
#include "my_string.h"
#include "user.h"
#include "offered_course.h"
#include "address.h"
#include "registeration.h"
#include "utills.h"
using namespace std;


Teacher::Teacher() : User(), salary(0), courses_taught(nullptr), number_of_courses_taught(0)
{

}
Teacher::Teacher(const Teacher& other) : User(other), Teacher_id(other.Teacher_id), salary(other.salary), courses_taught(other.courses_taught), number_of_courses_taught(other.number_of_courses_taught)
{

}
Teacher& Teacher ::  operator=(const Teacher& other)
{
	if (this != &other)
	{
		User::operator=(other);
		salary = other.salary;
		number_of_courses_taught = other.number_of_courses_taught;
		courses_taught = new offered_course*[number_of_courses_taught];
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

void Teacher::display()
{
	User::display_user();
	cout << endl;
	cout << salary;
	cout << endl << endl;
}


offered_course**& Teacher::get_courses_taught()
{
	return courses_taught;
}
int& Teacher::get_number_of_courses_taught()
{
	return number_of_courses_taught;
}

void Teacher::post(my_string message, my_string off_course_id)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(off_course_id))
		{
			Discussion& discussion = courses_taught[i]->get_Discussion();
			discussion.post(Teacher_id, message);
		}
	}
	
	
	
	
	
	
	
	throw("Course not found");

}
void Teacher::reply(my_string message, my_string off_course_id, int post_id)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(off_course_id))
		{
			Discussion& discussion = courses_taught[i]->get_Discussion();
			discussion.reply_to_post(post_id, Teacher_id, message);
			return;
		}
	}
	throw("Course not found");
}

// order of file id FirstName LastName Email Password DOB City Country Salary
void Teacher::save_to_file(ofstream& out_file)
{
	my_string first_name, last_name, date_of_birth, city, country;

	first_name = name.get_first_name();
	last_name = name.get_last_name();
	date_of_birth = dob.get_date_in_string();
	city = address.get_city();
	country = address.get_country();

	out_file << "Teacher";
	out_file << ' ';
	out_file << Teacher_id;
	out_file << ' ';
	out_file << first_name;
	out_file << ' ';
	out_file << last_name;
	out_file << ' ';
	out_file << email;
	out_file << ' ';
	out_file << password;
	out_file << ' ';
	out_file << date_of_birth;
	out_file << ' ';
	out_file << city;
	out_file << ' ';
	out_file << country;
	out_file << ' ';
	out_file << salary;
	out_file << '\n';


}

void Teacher::load_from_file(ifstream& in_file)
{
	my_string id;
	in_file >> id;
	Teacher_id = id;

	my_string first_name, last_name;
	in_file >> first_name;
	in_file >> last_name;
	Name name_of_person(first_name, last_name);

	my_string email_of_teacher;
	in_file >> email_of_teacher;

	my_string password;
	in_file >> password;

	my_string date;
	in_file >> date;

	Date dob(date);

	my_string city, country;
	in_file >> city;
	in_file >> country;
	Address address_of_Teacher(city, country);

	User::set_user(password, name_of_person, dob, address_of_Teacher, email_of_teacher);

	int teacher_salary;
	in_file >> teacher_salary;
	salary = teacher_salary;
}

void Teacher::set_teacher(my_string passed_teacher_id, int passed_salary)
{
	Teacher_id = passed_teacher_id;
	salary = passed_salary;
}


my_string Teacher::get_role()
{
	my_string str = "Teacher";
	return str;
}

void Teacher::mark_attendance(my_string offered_course_id, my_string rollno, int lecture_no, my_string attd)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(offered_course_id))
		{
			Registeration** enrollments = courses_taught[i]->get_enrollments();
			int number_of_enrollments = courses_taught[i]->get_number_of_enrollments();
			for (int j = 0; j < number_of_enrollments; j++)
			{
				if (enrollments[j]->get_roll_no().string_equality(rollno))
				{
					Attendance* attendance = enrollments[j]->get_attendance();
					attendance[lecture_no - 1].set_attendance(lecture_no, attd);
				}
			}
		}
	}
}
void Teacher::print_students_of_course(my_string offered_course_id)
{

	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(offered_course_id))
		{
			Registeration** enrollments = courses_taught[i]->get_enrollments();
			int number_of_enrollments = courses_taught[i]->get_number_of_enrollments();
			for (int j = 0; j < number_of_enrollments; j++)
			{
				my_string roll_no = enrollments[j]->get_roll_no();
				roll_no.print_string();
				if (j != number_of_enrollments - 1)
				{
					cout << "\n";
				}
			}
		}
	}
}

void Teacher::create_lecture(int lecture_no, my_string offered_course_id)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(offered_course_id))
		{
			Registeration**& enrollments = courses_taught[i]->get_enrollments();
			int& number_of_enrollments = courses_taught[i]->get_number_of_enrollments();
			for (int j = 0; j < number_of_enrollments; j++)
			{
				Attendance*& attendance = enrollments[j]->get_attendance();
				int& no_of_lectures = enrollments[j]->get_number_of_lectures();
				regrow_array(attendance, no_of_lectures);
				attendance[no_of_lectures].set_attendance(j + 1, "A");
				no_of_lectures++;
			}
		}
	}
}

void Teacher::mark_grade(my_string roll_no, my_string off_id, my_string grade)
{
	for (int i = 0; i < number_of_courses_taught; i++)
	{
		if (courses_taught[i]->get_offered_course_id().string_equality(off_id))
		{
			Registeration**& enrollments = courses_taught[i]->get_enrollments();
			int& number_of_enrollments = courses_taught[i]->get_number_of_enrollments();
			for (int j = 0; j < number_of_enrollments; j++)
			{
				if (enrollments[j]->get_roll_no().string_equality(roll_no))
				{
					enrollments[j]->assign_grade(grade);
				}
			}
		}
	}
}