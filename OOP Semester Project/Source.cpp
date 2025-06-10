#include <iostream>
#include <fstream>
#include "my_string.h"
#include "student.h"
#include "teacher.h"
#include "discussion.h"
#include "course.h"
#include "offered_course.h"
#include "utills.h"
#include "ums_manager.h"

using namespace std;

int main()
{
	fstream Courses("Courses.txt", ios::in);
	fstream offered_courses_file("offered_courses.txt", ios::in);

	Courses.close();
	offered_courses_file.close();

	int number_of_courses = 0;
	int number_of_offered_courses = 0;

	Courses >> number_of_courses;

	course* courses = new course[number_of_courses];

	for (int i = 0; i < number_of_courses; i++)
	{
		courses[i].initialize_course(Courses);
	}

	User** users = nullptr;
	int number_of_users = 0;

	initialize_users(users, number_of_users);

	my_string email;
	my_string password;

	cout << "Enter email for logging in: ";
	cin >> email;
	cout << "Enter password for logging in: ";
	cin >> password;

	User* logged_in_user = nullptr;
	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->are_credentials_correct(email, password))
		{
			logged_in_user = users[i];
			break;
		}
	}

	my_string role_of_log_in_user = logged_in_user->get_role();

	if (role_of_log_in_user.string_equality("UMS_Manager"))
	{
		UMS_manager* admin_user = (UMS_manager*)logged_in_user;
		int choice = 0;
		do {
			system("cls");
			cout << "Enter what operation you want to perform: 1 for adding a student, 2 for adding a teacher, 3 for exit";
			cin >> choice;
			if (choice == 1)
			{
				my_string Password, roll_no, first_name, last_name, email, date_of_birth, city, country;
				//cout << "Enter first name of student: ";
				//cin >> first_name;
				//cout << "Enter last name of student: ";
				//cin >> last_name;
				//cout << "Enter roll no: ";
				//cin >> roll_no;
				//cout << "Enter city of student: ";
				//cin >> city;
				//cout << "Enter country of student: ";
				//cin >> country;
				//cout << "Enter date_of_birth of student in the format dd/mm/yyyy: ";
				//cin >> date_of_birth;
				//cout << "Enter email of student: ";
				//cin >> email;
				//cout << "Enter password for student: ";
				//cin >> Password;
				Password = "1234";
				roll_no = "24008";
				first_name = "Abdullah";
				last_name = "Khalid";
				email = "@itu.edu.pk";
				city = "Lahore";
				country = "Pakistan";
				date_of_birth = "31/03/2006";


				Name name_of_student(first_name, last_name);
				Address addr_of_student(city, country);
				Date dob_of_student(date_of_birth);

				admin_user->add_student(Password, roll_no, name_of_student, email, dob_of_student, addr_of_student, users, number_of_users);
			}
			else if (choice == 2)
			{
				my_string Password, teacher_id, first_name, last_name, email, date_of_birth, city, country;
				int salary = 0;

				//cout << "Enter first name of teacher: ";
				//cin >> first_name;
				//cout << "Enter last name of teacher: ";
				//cin >> last_name;
				//cout << "Enter teacher id: ";
				//cin >> roll_no;
				//cout << "Enter city of teacher: ";
				//cin >> city;
				//cout << "Enter country of teacher: ";
				//cin >> country;
				//cout << "Enter date_of_birth of teacher in the format dd/mm/yyyy: ";
				//cin >> date_of_birth;
				//cout << "Enter email of teacher: ";
				//cin >> email;
				//cout << "Enter password for teacher: ";
				//cin >> Password;
				//cout << "Enter salary: ";
				//cin >> salary;

				Password = "1234";
				teacher_id = "T001";
				first_name = "Husnain";
				last_name = "Haider";
				email = "@itu.edu.pk";
				city = "Lahore";
				country = "Pakistan";
				date_of_birth = "31/03/2006";

				salary = 200000;

				Name name_of_teacher(first_name, last_name);
				Address addr_of_teacher(city, country);
				Date dob_of_teacher(date_of_birth);

				admin_user->add_teacher(Password, teacher_id, name_of_teacher, email, dob_of_teacher, addr_of_teacher, salary, users, number_of_users);
			}
			else if (choice == 3)
			{
				break;
			}
		} while (choice != 3);

		ofstream out_file_for_users("users.txt");
		out_file_for_users << number_of_users;
		out_file_for_users << "\n";
		for (int i = 0; i < number_of_users; i++)
		{
			users[i]->save_to_file(out_file_for_users);
		}


	}

}