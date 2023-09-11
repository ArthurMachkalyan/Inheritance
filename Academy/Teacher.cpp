#include "Teacher.h"
const string Teacher::get_speciality()const {
	return speciality;
}

int Teacher::get_experiance()const {
	return experience;
}

void Teacher::set_speciality(const string& speciality) {
	this->speciality = speciality;
}

void Teacher::set_experience(int experience) {
	this->experience = experience;
}

//                 Constructors:

Teacher::Teacher(human_take_parameters, teacher_take_parameters) :Human(human_give_parameters) {
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}

Teacher::~Teacher() {
	cout << "TDestructor:\t" << this << endl;
}

void Teacher::print()const {
	Human::print();
	cout << speciality << " " << experience << " years" << endl;
}
