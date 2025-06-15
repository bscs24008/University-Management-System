#include "reply.h"
#include <iostream>

using namespace std;

Reply::Reply()
{

}
//Post(my_string id, my_string content_of_post);
void Reply:: operator=(Reply other)
{
	id_of_person_replying = other.id_of_person_replying;
	content_of_reply = other.content_of_reply;
}
void Reply::print_Reply()
{
	cout << "\t\t";
	id_of_person_replying.print_string();
	cout << ":";
	cout << "\t";
	content_of_reply.print_string();
	cout << endl;
}

Reply*& regrow_reply(Reply*& reply, int& current_number_of_replies)
{
	Reply* temp = new Reply[current_number_of_replies + 1];
	for (int i = 0; i < current_number_of_replies; i++)
	{
		temp[i] = reply[i];
	}

	return temp;
}

void Reply::set_value_of_reply(my_string passed_id_of_person, my_string passed_content_of_reply)
{
	id_of_person_replying = passed_id_of_person;
	content_of_reply = passed_content_of_reply;
}

my_string& Reply::get_content_of_reply()
{
	return content_of_reply;
}
my_string& Reply::get_id_of_person_from_reply()
{
	return id_of_person_replying;
}