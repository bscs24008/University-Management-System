#ifndef NAME_H
#define NAME_H

#include "my_string.h"
using namespace std;

class Name {
    my_string firstName;
    my_string lastName;
public:
    Name();
    Name(const my_string& f, const my_string& l);
    Name(const Name& other);
    Name& operator=(const Name& other);

    void display() const;
};

#endif
