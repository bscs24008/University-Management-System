#include "user.h"
#include "student.h"
#include "teacher.h"
#include "ums_manager.h"
#include "utills.h"

User** users = nullptr;
int number_of_users;

void initialize_users(User**& users, int& number_of_users)
{
	ifstream in_file("users.txt");

	in_file >> number_of_users;
	users = new User * [number_of_users];

	for (int i = 0; i < number_of_users; i++)
	{
		my_string role;
		in_file >> role;
		if (role.string_equality("Student"))
		{
			users[i] = new Student;
			users[i]->load_from_file(in_file);

		}
		else if (role.string_equality("Teacher"))
		{
			users[i] = new Teacher;
			users[i]->load_from_file(in_file);
		}
		else
		{
			users[i] = new UMS_manager;
			users[i]->load_from_file(in_file);
		}
	}
}

Teacher**& get_teachers(User**& users, int& number_of_users)
{
	Teacher** teachers = nullptr;
	int number_of_teachers = 0;

	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->get_role().string_equality("Teacher"))
		{
			regrow_array_2d(teachers, number_of_teachers);
			teachers[number_of_teachers] = (Teacher*)&users[i][0];
			number_of_teachers++;
		}
	}

	return teachers;
}

int get_number_of_teachers(User**& users, int& number_of_users)
{
	int number_of_teachers = 0;

	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->get_role().string_equality("Teacher"))
		{
			number_of_teachers++;
		}
	}

	return number_of_teachers;
}

int get_number_of_students(User**& users, int& number_of_users)
{
	int number_of_students = 0;

	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->get_role().string_equality("Student"))
		{
			number_of_students++;
		}
	}

	return number_of_students;
}

Student**& get_students(User**& users, int& number_of_users)
{
	Student** students = nullptr;
	int number_of_students = 0;

	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->get_role().string_equality("Student"))
		{
			regrow_array_2d(students, number_of_students);
			students[number_of_students] = (Student*)users[i];
			number_of_students++;
		}
	}

	return students;
}