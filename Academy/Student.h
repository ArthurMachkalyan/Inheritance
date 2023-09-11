#pragma once

#include "Human.h"

#define student_take_parameters const string& speciality, const string& group, double rating, double attendance
#define student_give_parameters speciality, group, rating, attendance

class Student :public Human {
	string speciality;
	string group;
	double rating;
	double attendance;
public:
	const string get_speciality()const;

	const string get_group()const;

	double get_rating()const;

	double get_attendance()const;

	void set_speciality(const string& speciality);

	void set_group(const string& group);

	void set_rating(double rating);

	void set_attendance(double attendance);

	//                       Constructors:

	Student(human_take_parameters, student_take_parameters) :Human(human_give_parameters);

	void print()const;

};

