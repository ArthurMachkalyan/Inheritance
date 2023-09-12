#include <iostream>
#include <fstream>
using namespace std;

#define human_take_parameters const string first_name, const string last_name, int age
#define human_give_parameters first_name, last_name, age

#define delimeter "\n----------------------------------------\n"

class Human {
	string last_name;
	string first_name;
	int age;
public:
	const string& get_last_name()const {
		return last_name;
	}
	
	const string& get_first_name()const {
		return first_name;
	}

	int get_age()const {
		return age;
	}

	void set_last_name(const string& last_name) {
		this->last_name = last_name;
	}
	
	void set_first_name(const string& first_name) {
		this->first_name = first_name;
	}

	void set_age(int age) {
		this->age = age;
	}

	//                  Constructors

	Human(human_take_parameters) {
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}

	virtual ~Human() {
		cout << "HDestructor:\t" << this << endl;
	}

	virtual void print()const {
		cout << last_name << " " << first_name << " " << age << " y.o." << endl;
	}
};

std::ostream& operator<<(std::ostream os, const Human& obj) {
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " лет";
}

#define student_take_parameters const string& speciality, const string& group, double rating, double attendance
#define student_give_parameters speciality, group, rating, attendance

class Student :public Human {
	string speciality;
	string group;
	double rating;
	double attendance;
public:
	const string get_speciality()const {
		return speciality;
	}

	const string get_group()const {
		return group;
	}

	double get_rating()const {
		return rating;
	}

	double get_attendance()const {
		return attendance;
	}

	void set_speciality(const string& speciality) {
		this->speciality = speciality;
	}
	
	void set_group(const string& group) {
		this->group = group;
	}

	void set_rating(double rating) {
		this->rating = rating;
	}
	
	void set_attendance(double attendance) {
		this->attendance = attendance;
	}

	//                       Constructors:
	
	Student(human_take_parameters,student_take_parameters):Human(human_give_parameters) {
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}

	void print()const {
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}

	~Student() {
		cout << "SDestructor\t" << this << endl;
	}

};

#define teacher_take_parameters const string& speciality, int experience
#define teacher_give_parameters speciality, experience

class Teacher :public Human {
	string speciality;
	int experience;
public:
	const string get_speciality()const {
		return speciality;
	}

	int get_experiance()const {
		return experience;
	}

	void set_speciality(const string& speciality) {
		this->speciality = speciality;
	}

	void set_experience(int experience) {
		this->experience = experience;
	}

	//                 Constructors:

	Teacher(human_take_parameters, teacher_take_parameters):Human(human_give_parameters) {
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}

	~Teacher() {
		cout << "TDestructor:\t" << this << endl;
	}

	void print()const {
		Human::print();
		cout << speciality << " " << experience << " years" << endl;
	}

};

class Graduate:public Student {
	string subject;
public:
	const string& get_subject()const {
		return subject;
	}

	void set_subject(const string&) {
		this->subject = subject;
	}

	//                Constructors:

	Graduate(human_take_parameters, student_take_parameters, const string& subject)
		:Student(human_give_parameters, student_give_parameters) {
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}

	~Graduate() {
		cout << "GDestructor:\t" << this << endl;
	}

	void print()const {
		Student::print();
		cout << subject << endl;
	}
};



void print(Human* group[], const int n);

void save(Human* group[], const int n, const char sz_filename[]);

//#define INHERITANCE_CHECK

void main() {
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Montana", "Antonio", 25);
	human.print();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95);
	student.print();

	Teacher teacher("Whaite", "Walter", 50, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenbers");
	graduate.print();

#endif // INHERITANCE_CHECK

	Human* group[] = {
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95),
		new Teacher("Whaite", "Walter", 50, "Chemistry", 20),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenbers"),
		new Student ("Vercetti", "Tomas", 30, "Thieft", "Vice", 98, 99),
		new Teacher ("Diaz", "Ricardo", 50, "Weapons distribution", 25)
	};
	cout << delimeter << endl;
	print(group, sizeof(group) / sizeof(group[0]));

}

void save(Human* group[], const int n, const char sz_filename[]) {
	std::ofstream fout(sz_filename);
	fout.close();
}

void print(Human* group[], const int n) {
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimeter << endl;
	}
}