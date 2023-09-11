#pragma once

#include <iostream>
using namespace std;

#define human_take_parameters const std::string first_name, const std::string last_name, int age
#define human_give_parameters first_name, last_name, age

#define delimeter "\n----------------------------------------\n"

class Human {
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const;

	const std::string& get_first_name()const;

	int get_age()const;

	void set_last_name(const std::string& last_name);

	void set_first_name(const std::string& first_name);
	void set_age(int age);


	//                  Constructors

	Human(human_take_parameters);

	~Human();

	virtual void print()const;
};

