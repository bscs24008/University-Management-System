#ifndef DATE_H
#define DATE_H

#include "my_string.h"

class Date {
    int day;
    int month;
    int year;
public:


    Date();
    Date(my_string passed_date);
    Date(int d, int m, int y);
    Date(const Date& other);
    Date& operator=(const Date& other);
    my_string get_date_in_string();

    void display() const;
};

#endif