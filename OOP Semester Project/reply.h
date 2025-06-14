#ifndef REPLY_H
#define REPLY_H

#include "my_string.h"


class Reply
{
private:
	my_string id_of_person_replying;
	my_string content_of_reply;

public:
	Reply();
	//Post(my_string id, my_string content_of_post);
	void operator=(Reply other);
	void print_Reply();
	void set_value_of_reply(my_string passed_id_of_person, my_string passed_content_of_reply);
	my_string& get_content_of_reply();
	my_string& get_id_of_person_from_reply();
};

Reply* regrow_reply(Reply* reply, int current_number_of_posts);

#endif	