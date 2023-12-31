#include "Human.h"

const std::string& Human::get_last_name()const {
	return last_name;
}

const std::string& Human::get_first_name()const {
	return first_name;
}

int Human::get_age()const {
	return age;
}

void Human::set_last_name(const string& last_name) {
	this->last_name = last_name;
}

void Human::set_first_name(const string& first_name) {
	this->first_name = first_name;
}

void Human::set_age(int age) {
	this->age = age;
}

//                  Constructors

Human::Human(human_take_parameters) {
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}

Human::~Human() {
	cout << "HDestructor:\t" << this << endl;
}

 void Human::print()const {
	cout << last_name << " " << first_name << " " << age << " y.o." << endl;
}
