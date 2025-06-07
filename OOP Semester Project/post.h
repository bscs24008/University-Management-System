#ifndef POST_H
#define POST_H

#include "my_string.h"
#include "reply.h"

class Post
{
private:
	int id_of_post;
	my_string id_of_person;
	my_string content_of_post;
	Reply* replies = nullptr;
	int current_number_of_replies = 0;
public:
	Post();
	//Post(my_string id, my_string content_of_post);
	void operator=(const Post& other);
	void print_Post();
	void set_value_of_post(int passed_id_of_post, my_string passed_id_of_person, my_string passed_content_of_post);
	int get_post_id();
	Reply*& get_replies();
	int& get_number_of_replies();
};

Post* regrow_post(Post* Posts, int current_number_of_posts);

#endif