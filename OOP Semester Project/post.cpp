#include "post.h"
#include <iostream>

using namespace std;

Post::Post()
{

}
void Post:: operator=(const Post& other)
{
	if (this != &other)
	{
		id_of_post = other.id_of_post;
		id_of_person = other.id_of_person;
		content_of_post = other.content_of_post;
		current_number_of_replies = other.current_number_of_replies;
		delete replies;
		replies = new Reply[current_number_of_replies];
		for (int i = 0; i < current_number_of_replies; i++)
		{
			replies[i] = other.replies[i];
		}
	}
}
void Post::print_Post()
{
	cout << id_of_post;
	cout << endl;
	id_of_person.print_string();
	cout << endl;
	cout << "\t";
	content_of_post.print_string();
	cout << endl;
	for (int i = 0; i < current_number_of_replies; i++)
	{
		replies[i].print_Reply();
	}
}

Post*& regrow_post(Post*& Posts, int& current_number_of_posts)
{
	Post* temp = new Post[current_number_of_posts + 1];
	for (int i = 0; i < current_number_of_posts; i++)
	{
		temp[i] = Posts[i];
	}
	return temp;
}

void Post::set_value_of_post(int passed_id_of_post, my_string passed_id_of_person, my_string passed_content_of_post)
{
	id_of_post = passed_id_of_post;
	id_of_person = passed_id_of_person;
	content_of_post = passed_content_of_post;
}

Reply*& Post::get_replies()
{
	return replies;
}

int& Post::get_number_of_replies()
{
	return current_number_of_replies;
}

int Post::get_post_id()
{
	return id_of_post;
}


my_string& Post::get_id_of_person()
{
	return id_of_person;
}

my_string& Post::get_content_of_post()
{
	return content_of_post;
}