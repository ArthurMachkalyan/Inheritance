#include "Graduate.h"

const string& Graduate::get_subject()const {
	return subject;
}

void Graduate::set_subject(const string&) {
	this->subject = subject;
}

//                Constructors:

Graduate::Graduate(human_take_parameters, student_take_parameters, const string& subject)
	:Student(human_give_parameters, student_give_parameters) {
	set_subject(subject);
	cout << "GConstructor:\t" << this << endl;
}

Graduate::~Graduate() {
	cout << "GDestructor:\t" << this << endl;
}

void Graduate::print()const {
	Student::print();
	cout << subject << endl;
}
