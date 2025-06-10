#include <iostream>
#include <cmath>
#include "my_string.h"

using namespace std;

int power(int base, int exponent) {
	int res = 1;
	for (int i = 0; i < exponent; i++)
	{
		res *= base;
	}

	return res;
}

int* regrow_int_arr(int* old_arr, int& size)
{
	int* new_arr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = old_arr[i];
	}

	delete[] old_arr;

	size++;

	return new_arr;
}
bool is_char_in_string(const char* c, int length, char ch)
{
	for (int i = 0; i < length; i++)
	{
		if (c[i] == ch)
		{
			return true;
		}
	}
	return false;
}


int* indexes = nullptr;
int number_of_locs = 0;

locations:: ~locations()
{
	delete[] indexes;
}



my_string::my_string() : ptr(nullptr), len(0), cap(0)
{

}
my_string::my_string(const char* c)
{
	int length = get_length_of_string(c);

	this->ptr = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->ptr[i] = c[i];
	}
	ptr[length] = '\0';
	this->len = length;
	this->cap = length;
}
my_string::my_string(const char* c, int length_of_c)
{
	this->ptr = new char[length_of_c + 1];

	for (int i = 0; i < length_of_c; i++)
	{
		ptr[i] = c[i];
	}
	ptr[length_of_c] = '\0';
	this->len = length_of_c;
	this->cap = length_of_c;
}
my_string::my_string(const my_string& str)
{
	ptr = new char[str.len + 1];

	for (int i = 0; i < str.len; i++)
	{
		ptr[i] = str.ptr[i];
	}

	ptr[str.len] = '\0';

	cap = str.cap;
	len = str.len;
}
void my_string :: operator=(my_string str)
{
	if (ptr != str.ptr)
	{

		delete[] ptr;
		ptr = new char[str.len + 1];
		for (int i = 0; i < str.len; i++)
		{
			this->ptr[i] = str.ptr[i];
		}
		ptr[str.len] = '\0';
		len = str.len;
		cap = str.len;
	}
}
char my_string :: operator[](int i)
{
	if (this->len <= i || i < 0)
	{
		cout << "Index is out of range";
		return '\0';
	}
	else
	{
		return this->ptr[i];
	}

}
int my_string::get_length_of_string(const char* c)
{
	int length = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}
void my_string::replace_first_ch(char c)
{
	this->ptr[0] = c;
}
void my_string::trim()
{
	int starting_idx_of_trimmed_str = 0;
	int ending_idx_of_trimmed_str = 0;
	for (int i = 0; i < len; i++)
	{
		if ((ptr[i] >= 'a' && ptr[i] <= 'z') || (ptr[i] >= 'A' && ptr[i] <= 'Z'))
		{
			starting_idx_of_trimmed_str = i;
			break;
		}
	}

	for (int i = starting_idx_of_trimmed_str; i < len; i++)
	{
		if ((ptr[i] >= 'a' && ptr[i] <= 'z') || (ptr[i] >= 'A' && ptr[i] <= 'Z'))
		{
			ending_idx_of_trimmed_str = i;
		}
	}

	int length_of_trimmed_str = ending_idx_of_trimmed_str - starting_idx_of_trimmed_str + 1;
	char* temp = new char[length_of_trimmed_str];
	for (int i = 0; i < length_of_trimmed_str; i++)
	{
		temp[i] = ptr[starting_idx_of_trimmed_str + i];
	}

	delete[] ptr;

	ptr = temp;

	len = length_of_trimmed_str;

	cap = length_of_trimmed_str;


}
my_string* my_string::split(char c, int& count)
{
	locations locs = this->find_splitting_ranges(c);

	my_string* str = new my_string[locs.number_of_locs];

	int idx = 0;
	int current_index = 0;
	int length_of_current_str = 0;
	bool flag = false;

	do
	{
		for (int i = 0; i < locs.number_of_locs; i++)
		{
			length_of_current_str = locs.indexes[idx] - current_index;
			str[idx] = { new char[length_of_current_str], length_of_current_str };
			for (int j = 0; j < length_of_current_str; j++)
			{
				str[idx].ptr[j] = ptr[current_index + j];
			}
			idx++;
			current_index += length_of_current_str + 1;

			if (i == locs.number_of_locs - 1)
			{
				count = locs.number_of_locs;
				return str;
			}
		}

	} while (true);
}
my_string* my_string::tokenize(const char* c, int& count)
{
	locations locs = this->find_token_ranges(c);

	my_string* str = new my_string[locs.number_of_locs];

	int idx = 0;
	int current_index = 0;
	int length_of_current_str = 0;
	bool flag = false;

	do
	{
		for (int i = 0; i < locs.number_of_locs; i++)
		{
			length_of_current_str = locs.indexes[idx] - current_index;
			str[idx] = { new char[length_of_current_str], length_of_current_str };
			for (int j = 0; j < length_of_current_str; j++)
			{
				str[idx].ptr[j] = ptr[current_index + j];
			}
			idx++;
			current_index += length_of_current_str + 1;

			if (i == locs.number_of_locs - 1)
			{
				count = locs.number_of_locs;
				return str;
			}
		}

	} while (true);
}
void my_string::print_string() const
{
	for (int i = 0; i < this->len; i++)
	{
		cout << ptr[i];
	}
}
int my_string::convert_string_to_int()
{
	int numb_after_conv = 0;

	for (int i = 0; i < this->len; i++)
	{
		numb_after_conv += int(this->ptr[i] - '0') * power(10, this->len - i - 1);
	}

	return numb_after_conv;
}
void my_string::convert_int_to_string(int num)
{
	my_string temp = { nullptr, 0 };
	int length = 0;
	bool flag = false;
	do
	{
		const char* digit = new char[2]{ char(char(num % 10) + '0'), '\0' };
		my_string str(digit);
		num = num / 10;
		this->string_concatenation(str);

		if (flag == true)
		{
			break;
		}
		if (num / 10 == 0)
		{
			flag = true;
		}
	} while (num > 0);

	for (int i = 0; i < len - i - 1; i++)
	{
		swap(ptr[i], ptr[len - i - 1]);

	}

}
void my_string::insert_at(int idx, char c)
{
	if (cap < len + 1)
	{
		this->regrow(2);
	}

	if (idx < 0 || idx >= len)
	{
		cout << "Index dosent exist!";
		return;
	}


	for (int i = cap; i >= idx; i--)
	{
		ptr[i] = ptr[i - 1];
	}

	ptr[idx] = c;

	len = len + 1;
}

void my_string::insert_at(int idx, my_string str) // make it so that it uses regrow function to double cap if cap is less than len + str.len
{
	if (idx < 0 || idx >= len)
	{
		cout << "Index dosent exist!";
		return;
	}
	if (cap < len + str.len)
	{
		this->regrow(len + str.len - cap + 1);
	}


	for (int i = cap; (i - str.len) >= idx; i--)
	{
		ptr[i] = ptr[i - str.len];
	}

	for (int i = 0; i < str.len; i++)
	{
		ptr[idx + i] = str.ptr[i];
	}

	len = len + str.len;

}
void my_string::remove_at(int idx)
{
	if (idx < 0 || idx >= len)
	{
		cout << "Index dosent exist!";
		return;
	}

	for (int i = idx; i + 1 < len; i++)
	{
		ptr[i] = ptr[i + 1];
	}

	len = len - 1;
}
void my_string::string_concatenation(my_string str)
{

	if (cap < len + str.len)
	{
		this->regrow(len + str.len - cap + 1);
	}

	for (int i = 0; i < str.len; i++)
	{
		this->ptr[len + i] = str.ptr[i];
	}

	len = len + str.len;
	cap = len;
}
bool my_string::string_equality(my_string str)
{
	if (len != str.len)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (ptr[i] != str.ptr[i])
			{
				return false;
			}
		}
		return true;
	}
}
locations my_string::find_all(const char* ch)
{
	int length_of_target = get_length_of_string(ch);
	int* locs_of_target_string = nullptr;
	int number_of_occurences = 0;
	for (int i = 0; i < len; i++)
	{
		if (ptr[i] == ch[0])
		{
			for (int j = 1; j < length_of_target && i + j < len; j++)
			{
				if (ptr[i + j] != ch[j])
				{
					break;
				}
				else if (ptr[i + j] == ch[j] && j == length_of_target - 1)
				{
					locs_of_target_string = regrow_int_arr(locs_of_target_string, number_of_occurences);
					locs_of_target_string[number_of_occurences - 1] = i;
				}
			}
		}
	}

	return { locs_of_target_string, number_of_occurences };
}
locations my_string::find_splitting_ranges(char c)
{
	locations loc = { nullptr, 0 };

	int idx = 0;
	for (int i = 0; i < len; i++)
	{
		if (ptr[i] == c || i == len - 1)
		{
			loc.indexes = regrow_int_arr(loc.indexes, loc.number_of_locs);
			if (i != len - 1)
			{
				loc.indexes[idx] = i;
			}
			else
			{
				loc.indexes[idx] = i + 1;
			}
			idx++;
		}
	}

	loc.number_of_locs = idx;

	return loc;
}
locations my_string::find_token_ranges(const char* c)
{
	locations loc = { nullptr, 0 };
	int length = this->get_length_of_string(c);

	int idx = 0;
	for (int i = 0; i < len; i++)
	{
		if (is_char_in_string(c, length, ptr[i]) || i == len - 1)
		{
			loc.indexes = regrow_int_arr(loc.indexes, loc.number_of_locs);
			if (i != len - 1)
			{
				loc.indexes[idx] = i;
			}
			else
			{
				loc.indexes[idx] = i + 1;
			}
			idx++;
		}
	}

	loc.number_of_locs = idx;

	return loc;
}
locations my_string::find_all(const char ch)
{
	int* locs_of_target_ch = nullptr;
	int number_of_occurences = 0;

	for (int i = 0; i < len; i++)
	{
		if (ptr[i] == ch)
		{
			locs_of_target_ch = regrow_int_arr(locs_of_target_ch, number_of_occurences);
			locs_of_target_ch[number_of_occurences - 1] = i;
		}
	}

	return { locs_of_target_ch, number_of_occurences };
}
int my_string::find_first(char ch)
{
	return (this->find_all(ch)).indexes[0];
}
int my_string::find_last(char ch)
{
	locations locs = this->find_all(ch);

	return locs.indexes[locs.number_of_locs - 1];
}
int my_string::find_first(const char* ch)
{
	return (this->find_all(ch)).indexes[0];
}
int my_string::find_last(const char* ch)
{
	locations locs = this->find_all(ch);

	return locs.indexes[locs.number_of_locs - 1];
}
void my_string::remove_first(char ch)
{
	int loc_of_first_occurence = find_first(ch);

	for (int i = loc_of_first_occurence; i + 1 < len; i++)
	{
		ptr[i] = ptr[i + 1];
	}

	len--;
}
void my_string::remove_last(char ch)
{
	int loc_of_last_occurence = find_last(ch);

	for (int i = loc_of_last_occurence; i + 1 < len; i++)
	{
		ptr[i] = ptr[i + 1];
	}
	len--;
}
void my_string::remove_all(char ch)
{
	int idx;
	do
	{
		idx = this->find_all(ch).number_of_locs;
		if (idx == 0)
		{
			break;
		}

		this->remove_first(ch);

	} while (true);
}
void my_string::regrow(int amount_to_regrow)
{
	char* temp = new char[this->cap + amount_to_regrow] { '\0' };

	for (int i = 0; i < this->len; i++)
	{
		temp[i] = ptr[i];
	}

	delete[] ptr;

	ptr = temp;

	cap = cap + amount_to_regrow - 1;


}
void my_string::clear()
{
	delete[] this->ptr;

	ptr = nullptr;

	len = 0;
	cap = 0;
}
my_string :: ~my_string()
{
	delete[] this->ptr;
}

void operator>>(istream& is, my_string& str)
{
	char buffer[256]{ '\0' };

	is >> buffer;

	int len = 0;

	for (int i = 0; i < 256; i++)
	{
		if (buffer[i] == '\0')
		{
			len = i;
			break;
		}
	}

	str.ptr = new char[len + 1];

	for (int i = 0; i < len + 1; i++)
	{
		str.ptr[i] = buffer[i];
	}

	str.ptr[len] = '\0';

	str.len = len;
	str.cap = len;
}

char*& my_string::get_string_ptr()
{
	return ptr;
}

void operator<<(ostream& is, my_string& str)
{
	for (int i = 0; i < str.len; i++)
	{
		is << str.ptr[i];
	}
}

void regrow_string_array(my_string*& arr, int number_of_strings)
{
	my_string* new_arr = new my_string[number_of_strings + 1];

	for (int i = 0; i < number_of_strings; i++)
	{
		new_arr[i] = arr[i];
	}

	delete[] arr;

	arr = new_arr;
}