#pragma once

#include "Teacher.h"


class Graduate :public Student {
	string subject;
public:
	const string& get_subject()const;

	void set_subject(const string&);

	//                Constructors:

	Graduate(human_take_parameters, student_take_parameters, const string& subject)
		:Student(human_give_parameters, student_give_parameters);

	~Graduate();

	void print()const;
};
