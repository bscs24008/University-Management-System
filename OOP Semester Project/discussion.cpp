#include "discussion.h"
#include "my_string.h"
#include "post.h"
#include "reply.h"
#include <iostream>
using namespace std;


Discussion::Discussion()
{

}
void Discussion::post(my_string id_of_person, my_string content_of_post)
{
	posts = regrow_post(posts, current_number_of_posts);
	posts[current_number_of_posts].set_value_of_post(current_number_of_posts, id_of_person, content_of_post);
	current_number_of_posts++;
}
void Discussion::reply_to_post(int post_id, my_string id_of_person, my_string content_of_reply)
{
	int index_of_post = -1;
	try
	{
		for (int i = 0; i < current_number_of_posts; i++)
		{
			if (posts[i].get_post_id() == post_id)
			{
				index_of_post = i;
				break;
			}
		}
		if (index_of_post == -1)
		{
			throw("No such post id");
		}
	}
	catch (const char*)
	{
		cout << "No such Post id, so no reply was added";
		return;
	}

	int& current_number_of_replies = posts[index_of_post].get_number_of_replies();
	Reply*& replies = posts[index_of_post].get_replies();

	replies = regrow_reply(replies, current_number_of_replies);
	replies[current_number_of_replies].set_value_of_reply(id_of_person, content_of_reply);
	current_number_of_replies++;

	return;
}

void Discussion::print_discussion()
{
	for (int i = 0; i < current_number_of_posts; i++)
	{
		posts[i].print_Post();
	}
}

int& Discussion::get_number_of_posts()
{
	return current_number_of_posts;
}
Post*& Discussion::get_posts()
{
	return posts;
}

