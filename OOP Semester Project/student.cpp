#include <iostream>
#include "student.h"
#include "my_string.h"

using namespace std;

Student::Student() : Person(), rollNumber("bscs24xxx"), sems(nullptr), number_of_sems(1)
{

}
Student::Student(const Student& other) : Person(other), rollNumber(other.rollNumber)
{
    sems = new Semester[other.number_of_sems];
    for (int i = 0; i < other.number_of_sems; i++)
    {
        sems[i] = other.sems[i];
    }

    number_of_sems = other.number_of_sems;
}
Student::Student(const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_no) : Person(name, dob, addr, email), rollNumber(rollNumber)
{
    sems = new Semester[sem_no];

    number_of_sems = sem_no;
}
Student& Student ::operator=(const Student& other)
{
    if (this != &other)
    {
        Person::operator=(other);
        rollNumber = other.rollNumber;
        delete[] sems;
        sems = new Semester[other.number_of_sems];
        for (int i = 0; i < other.number_of_sems; i++)
        {
            sems[i] = other.sems[i];
        }
        number_of_sems = other.number_of_sems;
        return *this;
    }

}

void Student::display() const
{
    Person::display_person();
    rollNumber.print_string();
    cout << endl;
}

void Student::display_transcript()
{
    this->display();
    cout << "Current_semster: " << number_of_sems;
    for (int i = 0; i < number_of_sems; i++)
    {
        cout << "Semester " << i + 1 << endl;
        for (int j = 0; j < sems[i].get_number_of_enrollments(); j++)
        {
            sems[i].get_registerations()[j].get_off_course()->get_course_title().print_string();
            cout << " : ";
            sems[i].get_registerations()[j].get_grade().print_string();
            cout << endl;
        }
    }
}

void Student::enroll(int sem_no, offered_course*& off_courses, my_string passsed_course_id, int number_of_offered_courses)
{
    if (sem_no > number_of_sems)
    {
        throw("Semester dosent exist for student");
    }

    for (int i = 0; i < number_of_offered_courses; i++)
    {
        if (off_courses[i].get_course_id().string_equality(passsed_course_id))
        {
            offered_course* ptr = &off_courses[i];
            Registeration*& registerations = sems[sem_no - 1].get_registerations();
            int& number_of_enrollments = sems[sem_no - 1].get_number_of_enrollments();
            regrow_registeration(registerations, number_of_enrollments);
            registerations[number_of_enrollments].set(ptr, "Not Assigned Yet");
            number_of_enrollments++;
            return;
        }
    }

    throw("No such course exist");



}

void regrow_student_array(Student*& arr, int number_of_students)
{
    Student* new_arr = new Student[number_of_students + 1];

    for (int i = 0; i < number_of_students; i++)
    {
        new_arr[i] = arr[i];
    }

    delete[] arr;

    arr = new_arr;
}

void Student::set_student(const my_string& passed_rollNumber, const my_string& passed_email, const Date& passed_dob, const Name& passed_name, const Address& passed_addr, int sem_number)
{
    Person p(passed_name, passed_dob, passed_addr, passed_email);

    Person::operator=(p);

    rollNumber = passed_rollNumber;

    sems = new Semester[sem_number];

    number_of_sems = sem_number;

}


void add_student(Student*& students, int& number_of_students, const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_number)
{
    regrow_student_array(students, number_of_students);


    students[number_of_students].set_student(rollNumber, email, dob, name, addr, sem_number);

    number_of_students++;


}

void Student::post(my_string message, int sem_number, my_string id_of_target_course)
{
    Discussion& discussion = sems[sem_number - 1].get_discussion(id_of_target_course);

    discussion.post(rollNumber, message);
}

void Student::reply(my_string message, int sem_number, my_string id_of_target_course, int post_id)
{
    Discussion& discussion = sems[sem_number].get_discussion(id_of_target_course);

    discussion.reply_to_post(post_id, rollNumber, message);
}