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
#include <chrono>
#include <thread>


using namespace std;

int main()
{
	ifstream Courses("Courses.txt", ios::in);
	ifstream offered_courses_file("offered_courses.txt", ios::in);
	ifstream enrollment_file("enrollments.txt");
	int number_of_courses = 0;

	Courses >> number_of_courses;

	course* courses = nullptr;
	if (number_of_courses > 0)
	{
		courses = new course[number_of_courses];
	}


	for (int i = 0; i < number_of_courses; i++)
	{
		courses[i].initialize_course(Courses);
	}

	User** users = nullptr;
	int number_of_users = 0;

	initialize_users(users, number_of_users);

	my_string** teacher_ids = nullptr;
	int number_of_teacher_ids = 0;

	offered_course* offered_courses = nullptr;
	int number_of_offered_courses = 0;

	offered_courses_file >> number_of_offered_courses;
	offered_courses = new offered_course[number_of_offered_courses];

	if (number_of_offered_courses == 0)
	{
		offered_courses = nullptr;
	}
	//Teacher** teachers = get_teachers(users, number_of_users);
	//int number_of_teachers = get_number_of_teachers(users, number_of_users);

	Student** students = get_students(users, number_of_users);
	int number_of_students = get_number_of_students(users, number_of_users);

	for (int i = 0; i < number_of_offered_courses; i++)
	{
		offered_courses[i].initialize_offered_courses(offered_courses_file, courses, number_of_courses, teacher_ids, number_of_teacher_ids);
		offered_courses[i].offer_course(users, number_of_users, teacher_ids[i]);
	}

	//for (int i = 0; i < number_of_offered_courses; i++)
	//{
	//	offered_courses[i].print_offered_course();
	//}

	for (int i = 0; i < number_of_students; i++)
	{
		students[i]->load_enrolled_courses(offered_courses, number_of_offered_courses, enrollment_file);
	}



	



	my_string email = "ak@itu.edu.pk";
	my_string password = "1234";

	//cout << "Enter email for logging in: ";
	//cin >> email;
	//cout << "Enter password for logging in: ";
	//cin >> password;

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
			cout << "Enter what operation you want to perform: 1 for adding a student\n2 for adding a teacher\n3 for adding course\n4 for ad";
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
				email = "ak@itu.edu.pk";
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
				my_string course_id, course_title;
				int credit_hours = 4;

				course_id = "CS101";
				course_title = "PF";

				admin_user->add_course(courses, number_of_courses, course_id, course_title, credit_hours);
			}
			else if (choice == 4)
			{
				my_string offered_course_id, course_id, teacher_id;

				offered_course_id = "PF001";
				course_id = "CS101";
				teacher_id = "T001";

				admin_user->offer_course(offered_courses, number_of_offered_courses, number_of_courses, courses, course_id, users, teacher_id, number_of_users, offered_course_id);

			}
			else if (choice == 5)
			{
				break;
			}
		} while (true);
	}
	else if (role_of_log_in_user.string_equality("Student"))
	{
			Student* student_user = (Student*)logged_in_user;
			int choice = 0;
			do
			{
				system("cls");
				cout << "Enter what operation you want to perform: 1 for enrolling a course\n2 for seeing transcript\n3 for posting a message\n4 for seeing a discussion\n5 for exit: ";
				cin >> choice;
				if (choice == 1)
				{
					my_string offered_course_id = "PF001";
					student_user->enroll(1, offered_courses, offered_course_id, number_of_offered_courses);
					system("cls");
				}
				else if (choice == 2)
				{
					int useless_variable;
					student_user->display_transcript();
					this_thread::sleep_for(chrono::seconds(5));
				}
				else if (choice == 3)
				{
					my_string off_id;
					cout << "Enter offered id of course: ";
					cin >> off_id;
					int sem_no;
					cout << "Enter sem no of the course: ";
					cin >> sem_no;
					my_string message;
					cout << "Enter your message: ";
					cin >> message;
					student_user->post(message, sem_no, off_id);
				}
				else if (choice == 4)
				{
					my_string off_id;
					cout << "Enter offered id of course: ";
					cin >> off_id;
					int sem_no;
					cout << "Enter sem no of the course: ";
					cin >> sem_no;
					student_user->print_discussion(off_id, sem_no);
					this_thread::sleep_for(chrono::seconds(5));
				}
				else if (choice == 5)
				{
					break;
				}
			} while (true);
	}
	else if (role_of_log_in_user.string_equality("Teacher"))
	{
		Teacher* teacher_user = (Teacher*)logged_in_user;
		int choice = 0;
		do
		{
			system("cls");
			cout << "Enter what operation you want to perform: 1 for viewing students of a course, 2 for adding a lecture, 3 for marking attendance, 4 for exiting: ";
			cin >> choice;
			if (choice == 1)
			{
				my_string off_course_id;
				cout << "Enter offered course id of the course whose students you wish to see: ";
				cin >> off_course_id;
				teacher_user->print_students_of_course(off_course_id);
			}
			else if (choice == 2)
			{
				my_string off_course_id;
				cout << "Enter offered course id of the course in which you want to add a lecture: ";
				cin >> off_course_id;
				int lect_no;
				cout << "Enter lecture no: ";
				cin >> lect_no;
				teacher_user->create_lecture(lect_no, off_course_id);
			}
			else if (choice == 3)
			{
				my_string off_course_id, student_rollno, attd;
				cout << "Enter offered course id of the course in which you want to add a lecture: ";
				cin >> off_course_id;
				cout << "Enter student roll no: ";
				cin >> student_rollno;
				cout << "Enter what you want to mark, P for present, A for absent: ";
				cin >> attd;
				int lect_no;
				cout << "Enter lecture no: ";
				cin >> lect_no;
				teacher_user->mark_attendance(off_course_id, student_rollno, lect_no, attd);
			}
			else if (choice == 4)
			{
				break;
			}
		} while (true);
	}


	ofstream out_file_for_users("users.txt");
	ofstream out_file_for_courses("Courses.txt");
	ofstream enrollments("enrollments.txt");
	ofstream offered_course_out_file("offered_courses.txt");
	out_file_for_users << number_of_users;
	out_file_for_users << "\n";
	for (int i = 0; i < number_of_users; i++)
	{
		users[i]->save_to_file(out_file_for_users);
	}
	out_file_for_courses << number_of_courses;
	out_file_for_courses << "\n";
	for (int i = 0; i < number_of_courses; i++)
	{
		courses->save_to_file(out_file_for_courses);
		if (i != number_of_courses - 1)
		{
			out_file_for_courses << "\n";
		}
	}
	for (int i = 0; i < number_of_students; i++)
	{
		students[i]->save_enrollments_to_file(enrollments);
	}
	offered_course_out_file << number_of_offered_courses;
	offered_course_out_file << "\n";
	for (int i = 0; i < number_of_offered_courses; i++)
	{
		offered_courses[i].save_off_course_to_file(offered_course_out_file);
	}

	out_file_for_users.close();
	out_file_for_courses.close();
	enrollments.close();
	enrollment_file.close();
	offered_courses_file.close();
	Courses.close();
	offered_course_out_file.close();


}
