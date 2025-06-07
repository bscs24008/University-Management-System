#ifndef DISCUSSION_H
#define DISCUSSION_H

#include "post.h"

class Discussion
{
private:
	Post* posts = nullptr;
	int current_number_of_posts = 0;
public:
	Discussion();
	void post(my_string id_of_person, my_string content_of_post);
	void reply_to_post(int post_id, my_string id_of_person, my_string content_of_reply);
	void print_discussion();

};

#endif
