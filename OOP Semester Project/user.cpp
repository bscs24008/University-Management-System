#include <iostream>
#include "user.h"
#include "fstream"
using namespace std;

User::User() : name(), dob(), address(), email()
{

}
User::User(my_string passed_password, Name passed_name, Date passed_date, Address passed_address, my_string passed_email) : password(passed_password), name(passed_name), dob(passed_date), address(passed_address), email(passed_email)
{

}
User::User(const User& p) : name(p.name), dob(p.dob), address(p.address), email(p.email)
{

}
User& User:: operator=(const User& other)
{
	if (this != &other)
	{
		password = other.password;
		name = other.name;
		dob = other.dob;
		address = other.address;
		email = other.email;

		return *this;
	}

}

void User::display_user() const
{
	name.display();
	cout << endl;
	dob.display();
	cout << endl;
	address.display();
	cout << endl;
	email.print_string();
	cout << endl;
}

void User::set_user(my_string passed_password, Name passed_name, Date passed_date, Address passed_address, my_string passed_email)
{
	password = passed_password;
	name = passed_name;
	dob= passed_date;
	address = passed_address;
	email = passed_email;

}

bool User::are_credentials_correct(my_string passed_email, my_string passed_password)
{
	if (email.string_equality(passed_email) && password.string_equality(passed_password))
	{
		return true;
	}
	return false;
}