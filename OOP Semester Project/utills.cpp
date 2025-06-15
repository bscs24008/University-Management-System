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