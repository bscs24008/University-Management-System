#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "my_string.h"
#include "semester.h"

class Student : public User {
private:
    my_string rollNumber;
    Semester* sems = nullptr;
    int number_of_sems = 0;


public:
    Student();
    Student(const Student& other);
    //Student(const my_string password, const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_number);
    Student& operator=(const Student& other);
    void enroll(int sem_no, offered_course*& off_courses, my_string passsed_course_id, int number_of_offered_courses);
    void display() override;
    void display_transcript();
    void set_student(const my_string& passed_rollNumber);
    void post(my_string message, int sem_number, my_string id_of_target_course);
    void reply(my_string message, int sem_number, my_string id_of_target_course, int post_id);
    void save_to_file(ofstream& out_file) override;
    void load_from_file(ifstream& in_file) override;
    my_string get_role() override;
    void load_enrolled_courses(offered_course*& offered_courses, int& number_of_courses, ifstream& enrollement_file);
    void save_enrollments_to_file(ofstream& out_file);
    void print_discussion(my_string off_id, int sem_no);
};

void regrow_student_array(Student*& arr, int number_of_students);
//void add_student(Student*& students, int& number_of_students, const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_number);

#endif

