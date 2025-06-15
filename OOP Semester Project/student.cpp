#include <iostream>
#include "student.h"
#include "my_string.h"
#include "utills.h"
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
    cout << "\n";
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
    //if (sem_no > number_of_sems)
    //{
    //    throw("Semester dosent exist for student");
    //}

    for (int i = 0; i < number_of_offered_courses; i++)
    {
        if (off_courses[i].get_offered_course_id().string_equality(passsed_course_id))
        {
            offered_course* ptr = &off_courses[i];

            //adding an enrollment in it self
            Registeration*& registerations = sems[sem_no - 1].get_registerations();
            int& number_of_enrollments = sems[sem_no - 1].get_number_of_enrollments();
            regrow_array(registerations, number_of_enrollments);
            registerations[number_of_enrollments].set(rollNumber, ptr, "Not_Assigned_Yet");

            //setting attendance
            Attendance* attendance = registerations[number_of_enrollments].get_attendance();
            int& number_of_lectures = registerations[number_of_enrollments].get_number_of_lectures();
            attendance = nullptr;
            number_of_lectures = 0;
            number_of_enrollments++;

            //adding its registeration in the course
            Registeration**& enrollments_in_off_course = ptr->get_enrollments();
            int& number_of_enrollments_in_off_course = ptr->get_number_of_enrollments();
            regrow_array_2d(enrollments_in_off_course, number_of_enrollments_in_off_course);
            enrollments_in_off_course[number_of_enrollments_in_off_course] = &registerations[number_of_enrollments -1 ];
            number_of_enrollments_in_off_course++;
            return;
        }
    }

    //throw("No such course exist");



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
    Discussion& discussion = sems[sem_number - 1].get_discussion(id_of_target_course);

    discussion.reply_to_post(post_id, rollNumber, message);
}

void Student::save_to_file(ofstream& out_file)
{
    ofstream enrollment_file("enrollments.txt");
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
    enrollment_file << number_of_sems;
    for (int i = 0; i < number_of_sems; i++)
    {
        enrollment_file << ' ';
        enrollment_file << sems[i].get_number_of_enrollments();
        for (int j = 0; j < sems[i].get_number_of_enrollments(); j++)
        {
            my_string offered_id = sems[j].get_registerations()[j].get_off_course()->get_offered_course_id();
            enrollment_file << ' ';
            enrollment_file << offered_id;
            if (i != number_of_sems - 1 && j != sems[i].get_number_of_enrollments() - 1)
            {
                enrollment_file << ' ';
            }
        }
    }
    enrollment_file << '\n';
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

    //in_file >> number_of_sems;

    //sems = new Semester[number_of_sems];

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

void Student::load_enrolled_courses(offered_course*& offered_courses, int& number_of_courses, ifstream& enrollement_file)
{
    my_string rollno;

    enrollement_file >> rollno;
    enrollement_file >> number_of_sems;

    sems = new Semester[number_of_sems];

    for (int i = 0; i < number_of_sems; i++)
    {
        Registeration*& enrollments = sems[i].get_registerations();
        int no_of_enrollments = sems[i].get_number_of_enrollments();
        enrollement_file >> no_of_enrollments;
        if (no_of_enrollments == 0)
        {
            enrollments = nullptr;
            no_of_enrollments = 0;
        }
        for (int j = 0; j < no_of_enrollments; j++)
        {
            my_string off_course_id;
            enrollement_file >> off_course_id;
            this->enroll(i + 1, offered_courses, off_course_id, number_of_courses);
            enrollments = sems[i].get_registerations();
            no_of_enrollments = sems[i].get_number_of_enrollments();
            my_string grade;
            enrollement_file >> grade;
            enrollments[j].assign_grade(grade);
            Attendance*& attd = enrollments->get_attendance();
            int& no_of_lect = enrollments->get_number_of_lectures();
            enrollement_file >> no_of_lect;
            if (no_of_lect > 0)
            {
                attd = new Attendance[no_of_lect];
            }
            else
            {
                attd = nullptr;
                no_of_lect = 0;
            }
            for (int k = 0; k < no_of_lect; k++)
            {
                my_string attendance;
                enrollement_file >> attendance;
                attd[k].set_attendance(k + 1, attendance);
            }


            
        }

        
    }
}

void Student::save_enrollments_to_file(ofstream& out_file)
{
    out_file << rollNumber;
    out_file << " ";
    if (number_of_sems != 0)
    {
        out_file << number_of_sems;
    }
    else
    {
        out_file << 1;
    }

    out_file << " ";
    for (int i = 0; i < number_of_sems; i++)
    {
        int number_of_enrollements = sems[i].get_number_of_enrollments();
        out_file << number_of_enrollements;
        out_file << " ";
        Registeration* regs = sems[i].get_registerations();
        for (int j = 0; j < number_of_enrollements; j++)
        {
            my_string offered_id = regs[i].get_off_course()->get_offered_course_id();
            out_file << offered_id;
            out_file << " ";
            my_string grade = regs[i].get_grade();
            out_file << grade;
            Attendance* attd = regs[j].get_attendance();
            int no_of_lect = regs[j].get_number_of_lectures();
            out_file << " ";
            out_file << no_of_lect;
       
            for (int k = 0; k < no_of_lect; k++)
            {
                out_file << " ";
                out_file << attd[k].get_attd();
                if (k != no_of_lect)
                {
                    out_file << " ";
                }
            }
            if (j != number_of_enrollements - 1)
            {
                out_file << " ";
            }
            else
            {
                out_file << "\n";
            }
        }
    }
}

void Student::print_discussion(my_string off_id, int sem_no)
{
    sems[sem_no - 1].get_discussion(off_id).print_discussion();
}

void Student::print_attendance_of_course(my_string off_id, int sem_no)
{
    int index_of_off_course = -1;
    Registeration*& courses_enrolled = sems[sem_no - 1].get_registerations();
    int number_of_courses_enrolled = sems[sem_no - 1].get_number_of_enrollments();
    for (int i = 0; i < number_of_courses_enrolled; i++)
    {
        if (courses_enrolled[i].get_off_course()->get_offered_course_id().string_equality(off_id))
        {
            index_of_off_course = i;
            Registeration**& enrollments = courses_enrolled[i].get_off_course()->get_enrollments();
            int number_of_enrollments = courses_enrolled[i].get_off_course()->get_number_of_enrollments();
            for (int j = 0; j < number_of_enrollments; j++)
            {
                if (enrollments[j]->get_roll_no().string_equality(rollNumber))
                {
                    int& number_of_lectures = enrollments[j]->get_number_of_lectures();
                    Attendance* attd = enrollments[j]->get_attendance();
                    for (int k = 0; k < number_of_lectures; k++)
                    {
                        attd[k].print_attendance();
                    }
                }

            }
        }
    }

    //if (index_of_off_course == -1)
    //{

    //}
}