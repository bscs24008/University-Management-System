#include <iostream>
#include "address.h"
#include "my_string.h"

using namespace std;

Address::Address() : city("city"), country("country")
{

}
Address::Address(const my_string& c, const my_string& co) : city(c), country(co)
{

}
Address::Address(const Address& other) : city(other.city), country(other.country)
{

}
Address& Address :: operator=(const Address& other)
{
	if (this != &other)
	{
		city = other.city;
		country = other.country;

		return *this;
	}

}

void Address::display() const
{
	country.print_string();
	cout << ", ";
	city.print_string();
	cout << endl;
}

my_string Address::get_city()
{
	return city;
}
my_string Address::get_country()
{
	return country;
}