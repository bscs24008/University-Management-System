#ifndef PERSON_H
#define PERSON_H

#include "name.h"
#include "date.h"
#include "address.h"


class Person {
protected:
	Name name;
	Date dob;
	Address address;
	my_string email;
public:
	Person();
	Person(Name passed_name, Date passed_date, Address passed_address, my_string email);
	Person(const Person& p);
	Person& operator=(const Person& other);

	void display_person() const;
};

#endif