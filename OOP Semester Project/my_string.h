#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cmath>

using namespace std;

int power(int base, int exponent);

int* regrow_int_arr(int* old_arr, int& size);

bool is_char_in_string(const char* c, int length, char ch);

class locations
{
public:
	int* indexes = nullptr;
	int number_of_locs = 0;

	~locations();
};

class my_string
{
	char* ptr;
	int len;
	int cap;

public:
	my_string();

	my_string(const char* c);

	my_string(const char* c, int length_of_c);

	my_string(const my_string& str);

	void operator=(my_string str);

	char operator[](int i);

	int get_length_of_string(const char* c);

	void replace_first_ch(char c);

	void trim();

	my_string* split(char c, int& count);

	my_string* tokenize(const char* c, int& count);

	void print_string() const;

	int convert_string_to_int();

	void convert_int_to_string(int num);

	void insert_at(int idx, char c);

	void insert_at(int idx, my_string str);

	void remove_at(int idx);

	void string_concatenation(my_string str);

	bool string_equality(my_string str);

	locations find_all(const char* ch);

	locations find_splitting_ranges(char c);

	locations find_token_ranges(const char* c);

	locations find_all(const char ch);

	int find_first(char ch);

	int find_last(char ch);

	int find_first(const char* ch);

	int find_last(const char* ch);

	void remove_first(char ch);

	void remove_last(char ch);

	void remove_all(char ch);

	void regrow(int amount_to_regrow);

	void clear();

	~my_string();

	char*& get_string_ptr();

	void friend operator>>(istream& is, my_string& str);

	void friend operator<<(ostream& is, my_string& str);
};

void regrow_string_array(my_string*& arr, int number_of_strings);
#endif