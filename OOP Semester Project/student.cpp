#include <iostream>
#include "student.h"
#include "my_string.h"

using namespace std;

Student::Student() : User(), rollNumber("bscs24xxx"), sems(nullptr), number_of_sems(1)
{

}
Student::Student(const Student& other) : User(other), rollNumber(other.rollNumber)
{
    sems = new Semester[other.number_of_sems];
    for (int i = 0; i < other.number_of_sems; i++)
    {
        sems[i] = other.sems[i];
    }

    number_of_sems = other.number_of_sems;
}
//Student::Student(const my_string password, const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_no) : User(name, dob, addr, email), rollNumber(rollNumber)
//{
//    sems = new Semester[sem_no];
//
//    number_of_sems = sem_no;
//}
Student& Student ::operator=(const Student& other)
{
    if (this != &other)
    {
        User::operator=(other);
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

void Student::display()
{
    User::display_user();
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

void Student::set_student(const my_string& passed_rollNumber)
{
    rollNumber = passed_rollNumber;
    sems = new Semester;
    number_of_sems = 1;
}



//void add_student(Student*& students, int& number_of_students, const my_string& rollNumber, const my_string& email, const Date& dob, const Name& name, const Address& addr, int sem_number)
//{
//    regrow_student_array(students, number_of_students);
//
//
//    students[number_of_students].set_student(rollNumber, email, dob, name, addr, sem_number);
//
//    number_of_students++;
//
//
//}

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

void Student::save_to_file(ofstream& out_file)
{
    my_string first_name, last_name, date_of_birth, city, country;

    first_name = name.get_first_name();
    last_name = name.get_last_name();
    date_of_birth = dob.get_date_in_string();
    city = address.get_city();
    country = address.get_country();
    
    out_file << "Student";
    out_file << ' ';
    out_file << rollNumber;
    out_file << ' ';
    out_file << first_name;
    out_file << ' ';
    out_file << last_name;
    out_file << ' ';
    out_file << email;
    out_file << ' ';
    out_file << password;
    out_file << ' ';
    out_file << date_of_birth;
    out_file << ' ';
    out_file << city;
    out_file << ' ';
    out_file << country;
    out_file << ' ';
    out_file << number_of_sems;
    //for (int i = 0; i < number_of_sems; i++)
    //{
    //    out_file << sems[i].get_number_of_enrollments();
    //    out_file << ' ';
    //    for (int j = 0; j < sems[i].get_number_of_enrollments(); j++)
    //    {
    //        out_file << sems[j].get_registerations()[j].get_off_course()->get_offered_course_id();
    //        if (i != number_of_sems - 1 && j != sems[i].get_number_of_enrollments() - 1)
    //        {
    //            out_file << ' ';
    //        }
    //    }
    //}
    out_file << '\n';
}
void Student::load_from_file(ifstream& in_file)
{
    my_string id;
    in_file >> id;
    rollNumber = id;

    my_string first_name, last_name;
    in_file >> first_name;
    in_file >> last_name;
    Name name_of_person(first_name, last_name);

    my_string email_of_teacher;
    in_file >> email_of_teacher;

    my_string password;
    in_file >> password;

    my_string date;
    in_file >> date;

    Date dob(date);

    my_string city, country;
    in_file >> city;
    in_file >> country;
    Address address_of_Teacher(city, country);

    User::set_user(password, name_of_person, dob, address_of_Teacher, email_of_teacher);

    in_file >> number_of_sems;

    sems = new Semester[number_of_sems];

    //offered_course*& off_courses = get_offered_courses();
    //int no_of_off_courses = get_number_of_off_courses();

    //for (int i = 0; i < number_of_sems; i++)
    //{
    //    int number_of_courses_enrolled;

    //    in_file >> number_of_courses_enrolled;

    //    for (int j = 0; j < number_of_courses_enrolled; j++)
    //    {
    //        my_string target_course_id;
    //        in_file >> target_course_id;

    //        this->enroll(i, off_courses, target_course_id, no_of_off_courses);
    //    }
    //}

}

my_string Student::get_role()
{
    my_string str = "Student";
    return str;
}