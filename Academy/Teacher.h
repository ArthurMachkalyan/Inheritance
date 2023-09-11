#pragma once
#include "Human.h"
#include "Student.h"

#define teacher_take_parameters const string& speciality, int experience
#define teacher_give_parameters speciality, experience

class Teacher :public Human {
	string speciality;
	int experience;
public:
	const string get_speciality()const;

	int get_experiance()const;

	void set_speciality(const string& speciality);

	void set_experience(int experience);

	//                 Constructors:

	Teacher(human_take_parameters, teacher_take_parameters) :Human(human_give_parameters);

	~Teacher();

	void print()const;

};


