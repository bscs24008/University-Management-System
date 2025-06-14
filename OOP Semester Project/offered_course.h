#ifndef OFFERED_COURSE_H
#define OFFERED_COURSE_H

#include "course.h"
#include "my_string.h"
#include "teacher.h"
#include "discussion.h"

class Registeration;
class Student;

class offered_course : public course
{
private:
	my_string offered_course_id;
	Teacher* course_instructor = nullptr;
	Discussion discussion;
	Registeration** enrollments = nullptr;
	int number_of_enrollments = 0;
public:
	offered_course();
	void set_offered_course(course* c, Teacher* t, my_string passed_offered_course_id);
	offered_course& operator=(offered_course const& other);
	void print_offered_course();
	void initialize_offered_courses(ifstream& f, course*& courses, int number_of_courses, my_string**& teacher_ids, int& number_of_teacher_ids);
	Discussion& get_Discussion();
	my_string get_course_id();
	my_string get_offered_course_id();
	void offer_course(User**& teachers, int& number_of_users, my_string* teacher_id);
	void save_off_course_to_file(ofstream& out_file);
	Registeration**& get_enrollments();
	int& get_number_of_enrollments();
	void set_offered_course(course c, my_string off_course_id);
	
};

int& get_number_of_off_courses();
offered_course*& get_offered_courses();


#endif