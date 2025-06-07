#include <iostream>
#include "name.h"
#include "my_string.h"

using namespace std;

Name::Name() : firstName("first name\0"), lastName("last name\0")
{

}
Name::Name(const my_string& f, const my_string& l) : firstName(f), lastName(l)
{

}
Name::Name(const Name& other) : firstName(other.firstName), lastName(other.lastName)
{

}
Name& Name:: operator=(const Name& other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;

		return *this;
	}


}

void Name::display() const
{
	firstName.print_string();
	cout << " ";
	lastName.print_string();
	cout << endl;
}