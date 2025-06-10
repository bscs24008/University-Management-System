#ifndef UMS_MANAGER_H
#define UMS_MANAGER_H

#include "user.h"
#include "student.h"
#include "teacher.h"


class UMS_manager : public User
{
	int salary;
public:
	UMS_manager();
	void add_student(my_string password, my_string roll_no, Name name, my_string email, Date dob, Address address, User**& users, int& number_of_users);
	void add_teacher(my_string password, my_string teacher_id, Name name, my_string email, Date dob, Address address, int salary, User**& users, int& number_of_users);
	void save_to_file(ofstream& out_file) override;
	void load_from_file(ifstream& in_file) override;
	void display() override;
	my_string get_role() override;
	//void menu() override;
};


#endif // !UMS_MANAGER_H
