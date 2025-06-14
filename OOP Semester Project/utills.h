#ifndef UTILLS_H
#define UTILLS_H

template <class T>

void regrow_array(T*& t, int no_of_t)
{
	T* new_t = new T[no_of_t + 1];
	for (int i = 0; i < no_of_t; i++)
	{
		new_t[i] = t[i];
	}

	delete t;

	t = new_t;
}

template <class T>

void regrow_array_2d(T**& t, int no_of_t)
{
	T** new_t = new T * [no_of_t + 1];
	for (int i = 0; i < no_of_t; i++)
	{
		new_t[i] = t[i];
	}

	delete[] t;

	t = new_t;
}

void initialize_users(User**& users, int& number_of_users);

#endif // UTILLS_H


