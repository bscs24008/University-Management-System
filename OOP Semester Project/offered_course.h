#ifndef OFFERED_COURSE_H
#define OFFERED_COURSE_H

#include "course.h"
#include "my_string.h"
#include "teacher.h"
#include "discussion.h"


class offered_course : public course
{
private:
	int offered_course_id;
	Teacher* course_instructor = nullptr;
	Discussion discussion;
public:
	offered_course();
	void set_offered_course(course* c, Teacher* t, int passed_offered_course_id);
	offered_course& operator=(offered_course const& other);
	void print_offered_course();
	void initialize_offered_courses(fstream& f, course*& courses, Teacher*& teachers, int number_of_courses, int number_of_teachers);
	Discussion& get_Discussion();
	my_string get_course_id();
	int get_offered_course_id();
};

offered_course* regrow_offered_courses(int current_number_of_courses, offered_course* old_ptr);
void offer_course(offered_course*& offered_courses, int& current_number_of_offered_courses, int current_number_of_courses, course* courses, my_string course_id, Teacher* teachers, my_string teacher_id, int current_number_of_teachers);


#endif