#include <iostream>
#include "person.h"

Person::Person() : name(), dob(), address(), email("default_email@gmail.com")
{

}
Person::Person(Name passed_name, Date passed_date, Address passed_address, my_string passed_email) : name(passed_name), dob(passed_date), address(passed_address), email(passed_email)
{

}
Person::Person(const Person& p) : name(p.name), dob(p.dob), address(p.address), email(p.email)
{

}
Person& Person:: operator=(const Person& other)
{
	if (this != &other)
	{
		name = other.name;
		dob = other.dob;
		address = other.address;
		email = other.email;

		return *this;
	}

}

void Person::display_person() const
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