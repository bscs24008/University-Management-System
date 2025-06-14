#include <iostream>
#include "offered_course.h"
#include "teacher.h"
#include "course.h"
#include "my_string.h"
#include "utills.h"
#include "registeration.h"
#include "offered_course.h"
using namespace std;

class teacher {};


offered_course::offered_course() : offered_course_id(), course()
{
}
offered_course& offered_course :: operator=(offered_course const& other)
{
	if (this != &other)
	{
		course::operator=(other);
		offered_course_id = other.offered_course_id;
		course_instructor = other.course_instructor;
		number_of_enrollments = other.number_of_enrollments;
		enrollments = new Registeration * [other.number_of_enrollments];
		for (int i = 0; i < number_of_enrollments; i++)
		{
			enrollments[i] = other.enrollments[i];
		}
	}

	return *this;
}

offered_course* regrow_offered_courses(int current_number_of_courses, offered_course* old_ptr)
{
	offered_course* new_ptr = new offered_course[current_number_of_courses + 1];
	for (int i = 0; i < current_number_of_courses; i++)
	{
		new_ptr[i] = old_ptr[i];
	}

	//new_ptr[current_number_of_courses] = offered_course();
	return new_ptr;
}

void offered_course::set_offered_course(course* c, Teacher* t, my_string passed_offered_course_id)
{
	course::operator=(*c);
	course_instructor = t;
	offered_course_id = passed_offered_course_id;
}

//void offer_course(offered_course*& offered_courses, int& current_number_of_offered_courses, int current_number_of_courses, course* courses, my_string course_id, Teacher* teachers, my_string teacher_id, int current_number_of_teachers)
//{
//	int index_of_Teacher = 0;
//	int index_of_Course = 0;
//	bool flag = false;
//	for (int i = 0; i < current_number_of_courses; i++)
//	{
//		if (courses[i].get_course_id().string_equality(course_id))
//		{
//			index_of_Course = i;
//			flag = true;
//			break;
//
//		}
//	}
//	if (!flag)
//	{
//		throw("Course Not found");
//	}
//	flag = false;
//	for (int i = 0; i < current_number_of_teachers; i++)
//	{
//		if (teachers[i].get_teacher_id().string_equality(teacher_id))
//		{
//			index_of_Teacher = i;
//			flag = true;
//			break;
//		}
//	}
//	if (!flag)
//	{
//		throw("Teacher Not found");
//	}
//
//	offered_courses = regrow_offered_courses(current_number_of_offered_courses, offered_courses);
//	offered_courses[current_number_of_offered_courses].set_offered_course(&courses[index_of_Course], &teachers[index_of_Teacher], current_number_of_offered_courses);
//	current_number_of_offered_courses++;
//
//	offered_course* ids_of_courses = teachers[index_of_Teacher].get_courses_taught();
//	int& number_of_courses_taught = teachers[index_of_Teacher].get_number_of_courses_taught();
//
//	ids_of_courses = regrow_offered_courses(number_of_courses_taught, ids_of_courses);
//
//	ids_of_courses[number_of_courses_taught] = offered_courses[current_number_of_offered_courses - 1];
//
//	number_of_courses_taught++;
//
//}

void offered_course::print_offered_course()
{
	course::print_course();
	course_instructor->display_user();
}

//void offered_course::initialize_offered_courses(ifstream& f, course*& courses, Teacher*& teachers, int number_of_courses, int number_of_teachers)
//{
//	bool flag = false;
//
//	my_string course_id, teacher_id;
//
//	f >> course_id;
//	f >> teacher_id;
//	f >> offered_course_id;
//
//	int index_of_teacher = 0;
//
//	int index_of_course;
//
//	for (int i = 0; i < number_of_courses; i++)
//	{
//		if (course_id.string_equality(courses[i].get_course_id()))
//		{
//			course::operator=(courses[i]);
//			flag = true;
//			index_of_course = i;
//			break;
//		}
//	}
//	if (!flag)
//	{
//		throw("Teacher or Course not found");
//	}
//
//	flag = false;
//	for (int i = 0; i < number_of_teachers; i++)
//	{
//		if (teachers[i].get_teacher_id().string_equality(teacher_id))
//		{
//			course_instructor = &teachers[i];
//			flag = true;
//			index_of_teacher = i;
//			break;
//		}
//	}
//	if (!flag)
//	{
//		throw("Teacher or Course not found");
//	}
//
//	offered_course*& courses_taught = teachers[index_of_teacher].get_courses_taught();
//	int& number_of_courses_taught = teachers[index_of_teacher].get_number_of_courses_taught();
//
//	courses_taught = regrow_offered_courses(number_of_courses_taught, courses_taught);
//
//	my_string off_course_id;
//
//	off_course_id.convert_int_to_string(offered_course_id);
//
//
//	courses_taught[number_of_courses_taught] = *this;
//
//	number_of_courses_taught++;
//
//
//}

void offered_course::initialize_offered_courses(ifstream& f, course*& courses, int number_of_courses, my_string**& teacher_ids, int& number_of_teacher_ids)
{
	bool flag = false;

	my_string course_id, teacher_id;

	f >> offered_course_id;
	f >> course_id;
	f >> teacher_id;

	int index_of_teacher = 0;

	int index_of_course;

	for (int i = 0; i < number_of_courses; i++)
	{
		if (course_id.string_equality(courses[i].get_course_id()))
		{
			course::operator=(courses[i]);
			index_of_course = i;
			break;
		}
	}

	int number_of_posts;
	f >> number_of_posts;

	for (int i = 0; i < number_of_posts; i++)
	{
		my_string rollNo;
		f >> rollNo;
		my_string message;
		f >> message;
		int number_of_replies_for_post = 0;
		f >> number_of_replies_for_post;
		message.replace_all('_', ' ');
		Discussion &d = this->get_Discussion();
		d.post(rollNo, message);
		for (int j = 0; j < number_of_replies_for_post; j++)
		{
			my_string id_of_person_replying, content_of_reply;
			f >> id_of_person_replying;
			f >> content_of_reply;
			d.reply_to_post(i, id_of_person_replying, content_of_reply);
		}
	}
	course_instructor = nullptr;

	regrow_array_2d(teacher_ids, number_of_teacher_ids);

	teacher_ids[number_of_teacher_ids] = new my_string[1];
	teacher_ids[number_of_teacher_ids]->operator=(teacher_id);

	number_of_teacher_ids++;

	return;
}

Discussion& offered_course::get_Discussion()
{
	return discussion;
}

my_string offered_course::get_course_id()
{
	return course::get_course_id();
}

my_string offered_course::get_offered_course_id()
{
	return offered_course_id;
}


int& get_number_of_off_courses()
{
	static int number_of_off_courses = 0;
	static bool was_data_ever_loaded3 = false;

	if (!was_data_ever_loaded3)
	{
		ifstream file("offered_courses.txt");
		file >> number_of_off_courses;
		was_data_ever_loaded3 = true;
		file.close();
	}

	return number_of_off_courses;



}
offered_course*& get_offered_courses()
{
	course* courses = nullptr;
	int number_of_courses = 0;
	static offered_course* off_courses = nullptr;
	static bool was_data_ever_loaded = false;
	int number_of_off_courses = 0;

	courses = get_courses();
	number_of_courses = get_number_of_courses();
	if (!was_data_ever_loaded)
	{
		ifstream file("off_courses.txt");
		file >> number_of_off_courses;
		off_courses = new offered_course[number_of_off_courses];
		
	}

	return off_courses;
	


}

void offered_course::offer_course(User**& users, int& number_of_users, my_string* teacher_id)
{
	for (int i = 0; i < number_of_users; i++)
	{
		if (users[i]->get_role().string_equality("Teacher"))
		{
			Teacher*& ptr = (Teacher*&)users[i];
			this->course_instructor = ptr;
			offered_course**& ids_of_courses = ptr->get_courses_taught();
			int& number_of_courses_taught = ptr->get_number_of_courses_taught();

			regrow_array(ids_of_courses, number_of_courses_taught);
			ids_of_courses[number_of_courses_taught] = this;

			number_of_courses_taught++;
		}
	}

}

void offered_course::save_off_course_to_file(ofstream& out_file)
{
	my_string teacher_id = course_instructor->get_teacher_id();
	out_file << offered_course_id;
	out_file << " ";
	my_string course_id = this->get_course_id();
	out_file << course_id;
	out_file << " ";
	out_file << teacher_id;
	out_file << " ";

	Discussion d = this->get_Discussion();

	int& number_of_posts = d.get_number_of_posts();

	out_file << number_of_posts << " ";

	Post*& posts = d.get_posts();
	for (int i = 0; i < number_of_posts; i++)
	{
		out_file << posts[i].get_id_of_person();
		out_file << " ";
		my_string& message = (posts[i].get_content_of_post());
		message.replace_all(' ', '_');
		out_file << message;
		out_file << " ";
		int& number_of_replies_of_post = posts[i].get_number_of_replies();
		Reply*& replies = posts[i].get_replies();
		out_file << number_of_replies_of_post;
		if (number_of_replies_of_post == 0 && i != number_of_posts - 1)
		{
			out_file << "\n";
		}
		for (int j = 0; j < number_of_replies_of_post; j++)
		{
			out_file << " ";
			out_file << replies[j].get_id_of_person_from_reply();
			out_file << " ";
			my_string reply_message = replies[j].get_content_of_reply();
			reply_message.replace_all(' ', '_');
			out_file << reply_message;
			if (j != number_of_replies_of_post - 1)
			{
				out_file << " ";
			}
			else if (i != number_of_posts - 1)
			{
				out_file << "\n";
			}
		}
	}
}

Registeration**& offered_course::get_enrollments()
{
	return enrollments;
}
int& offered_course::get_number_of_enrollments()
{
	return number_of_enrollments;
}
void offered_course::set_offered_course(course c, my_string off_course_id)
{
	course::operator=(c);
	offered_course_id = off_course_id;
}