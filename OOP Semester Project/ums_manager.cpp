#include "ums_manager.h"
#include "utills.h"
#include "student.h"

UMS_manager::UMS_manager()
{

}
void UMS_manager::add_student(my_string password, my_string roll_no, Name name, my_string email, Date dob, Address address, User**& users, int& number_of_users)
{
	// users -> [user_ptr, ....]
	regrow_array_2d(users, number_of_users);
	users[number_of_users] = new Student;

	users[number_of_users]->set_user(password, name, dob, address, email);
	Student* student_ptr = (Student*)(users[number_of_users]);
	student_ptr->set_student(roll_no);

	number_of_users++;
}
void UMS_manager::add_teacher(my_string password, my_string teacher_id, Name name, my_string email, Date dob, Address address, int salary, User**& users, int& number_of_users)
{
	regrow_array_2d(users, number_of_users);
	users[number_of_users] = new Teacher;

	users[number_of_users]->set_user(password, name, dob, address, email);
	Teacher* teacher_ptr = (Teacher*)(users[number_of_users]);
	teacher_ptr->set_teacher(teacher_id, salary);

	number_of_users++;
}

void UMS_manager::save_to_file(ofstream& out_file)
{
	out_file << "UMS_Manager ";
	
	my_string first_name, last_name, date_of_birth, city, country;

	first_name = name.get_first_name();
	last_name = name.get_last_name();
	date_of_birth = dob.get_date_in_string();
	city = address.get_city();
	country = address.get_country();

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
	out_file << "\n";

}
void UMS_manager::load_from_file(ifstream& in_file)
{
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

	in_file >> salary;
}

my_string UMS_manager::get_role()
{
	my_string str = "UMS_Manager";
	return str;
}

void UMS_manager::display()
{
	User::display_user();
	cout << endl;
	cout << salary;
	cout << endl << endl;
}

void UMS_manager::add_course(course*& courses, int& number_of_courses, my_string course_id, my_string course_title, int credit_hours)
{
	regrow_array(courses, number_of_courses);

	courses[number_of_courses] = course{ course_id, course_title, credit_hours };

	number_of_courses++;
}

void UMS_manager::offer_course(offered_course*& offered_courses, int& current_number_of_offered_courses, int& current_number_of_courses, course*& courses, my_string course_id, Teacher**& teachers, my_string teacher_id, int& current_number_of_teachers, my_string offered_course_id)
{
	int index_of_Teacher = 0;
	int index_of_Course = 0;
	//bool flag = false;
	for (int i = 0; i < current_number_of_courses; i++)
	{
		if (courses[i].get_course_id().string_equality(course_id))
		{
			index_of_Course = i;
			//flag = true;
			break;

		}
	}
	//if (!flag)
	// 
	// 
	// 
	// 
	//{
	//	throw("Course Not found");
	//}
	//flag = false;
	for (int i = 0; i < current_number_of_teachers; i++)
	{
		if (teachers[i]->get_teacher_id().string_equality(teacher_id))
		{
			index_of_Teacher = i;
			//flag = true;
			break;
		}
	}
	//if (!flag)
	//{
	//	throw("Teacher Not found");
	//}

	offered_courses = regrow_offered_courses(current_number_of_offered_courses, offered_courses);
	offered_courses[current_number_of_offered_courses].set_offered_course(&courses[index_of_Course], teachers[index_of_Teacher], offered_course_id);
	current_number_of_offered_courses++;

	offered_course* ids_of_courses = teachers[index_of_Teacher]->get_courses_taught();
	int& number_of_courses_taught = teachers[index_of_Teacher]->get_number_of_courses_taught();

	ids_of_courses = regrow_offered_courses(number_of_courses_taught, ids_of_courses);

	ids_of_courses[number_of_courses_taught] = offered_courses[current_number_of_offered_courses - 1];

	number_of_courses_taught++;

}
/*
Entity: UMS Manager, Student, Teacher

UMS Manager(*)
	- add teacher
	- add student
	- add course
	- offer course

Student:(completed)
	- enroll course
	- see grades
	- post
	- reply

Teacher:(*)
	- give grade
	- post
	- reply



Post / Thread
Comment
*/