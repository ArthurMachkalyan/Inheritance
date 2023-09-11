#include "Student.h"

const string Student::get_speciality()const {
	return speciality;
}

const string Student::get_group()const {
	return group;
}

double Student::get_rating()const {
	return rating;
}

double Student::get_attendance()const {
	return attendance;
}

void Student::set_speciality(const string& speciality) {
	this->speciality = speciality;
}

void Student::set_group(const string& group) {
	this->group = group;
}

void Student::set_rating(double rating) {
	this->rating = rating;
}

void Student::set_attendance(double attendance) {
	this->attendance = attendance;
}

//                       Constructors:

Student::Student(human_take_parameters, student_take_parameters) :Human(human_give_parameters) {
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}

void Student::print()const {
	Human::print();
	cout << speciality << " " << group << " " << rating << " " << attendance << endl;
}
