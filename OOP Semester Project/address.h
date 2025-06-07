#ifndef ADDRESS_H
#define ADDRESS_H

#include "my_string.h"
using namespace std;

class Address {
    my_string city;
    my_string country;
public:


    Address();
    Address(const my_string& c, const my_string& co);
    Address(const Address& other);
    Address& operator=(const Address& other);

    void display() const;
};

#endif