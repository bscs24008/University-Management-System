#ifndef USER_H
#define USER_H

#include "name.h"
#include "date.h"
#include "address.h"


class User {
protected:
	my_string password;
	Name name;
	Date dob;
	Address address;
	my_string email;
public:
	User();
	User(my_string passed_password, Name passed_name, Date passed_date, Address passed_address, my_string email);
	User(const User& u);
	void set_user(my_string passed_password, Name passed_name, Date passed_date, Address passed_address, my_string email);
	User& operator=(const User& other);
	void virtual save_to_file(ofstream& out_file) = 0;
	void virtual load_from_file(ifstream& file) = 0;
	void display_user() const;
	void virtual display() = 0;
	my_string virtual get_role() = 0;
	//void virtual menu() = 0;
	bool are_credentials_correct(my_string passed_email, my_string passed_password);
};



#endif