#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"
#include "name.h"
#include "address.h"
#include "date.h"
#include <fstream>

class offered_course;

class Teacher : public User {
private:
    my_string Teacher_id;
    offered_course* courses_taught = nullptr;
    int number_of_courses_taught = 0;
    int salary;
public:
    Teacher();
    Teacher(const Teacher& other);
    //Teacher(my_string password, my_string passed_Teacher_id, int salary, const my_string& email, const Date& dob, const Name& name, const Address& addr);
    Teacher& operator=(const Teacher& other);
    my_string get_teacher_id();
    void display();
    offered_course*& get_courses_taught();
    int& get_number_of_courses_taught();
    void post(my_string message, int id_of_course_taught);
    void reply(my_string message, int id_of_course_taught, int post_id);
    void save_to_file(ofstream& out_file) override;
    void load_from_file(ifstream& file) override;
    void set_teacher(my_string passed_teacher_id, int passed_salary);
    my_string get_role() override;
};

#endif