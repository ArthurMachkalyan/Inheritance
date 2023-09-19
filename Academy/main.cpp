#include <iostream>
#include <fstream>
#include "string"
using namespace std;

#define human_take_parameters const string first_name, const string last_name, int age
#define human_give_parameters first_name, last_name, age

#define delimeter "\n----------------------------------------\n"

class Human {
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 3;

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

	virtual std::ostream& print(std::ostream& os)const {
		return os << last_name << " " << first_name << " " << age << " y.o.";
	}

	virtual std::ofstream& print(std::ofstream& ofs)const {
		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << std::left;
		ofs << first_name;
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}

	virtual std::ifstream& scan(std::ifstream& ifs) {
		 ifs >> last_name >> first_name >> age;
		 return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj) {
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& ofs, const Human& obj) {
	obj.print(ofs);
	return ofs;
}

std::istream& operator>>(std::ifstream& ifs, Human& obj) {
	return obj.scan(ifs);
}


#define student_take_parameters const string& speciality, const string& group, double rating, double attendance
#define student_give_parameters speciality, group, rating, attendance

class Student :public Human {
	static const int SPECIALITY_WIDTH = 25;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
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

	Student(human_take_parameters, student_take_parameters) :Human(human_give_parameters) {
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}


	~Student() {
		cout << "SDestructor\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const override {
		return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}

	std::ofstream& print(std::ofstream& ofs)const override {
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}

	std::ifstream& scan(std::ifstream& ifs) override {
		Human::scan(ifs);
		char sz_buffer[SPECIALITY_WIDTH + 1] = {};
		ifs.read(sz_buffer, SPECIALITY_WIDTH);
		for (int i = SPECIALITY_WIDTH - 1; sz_buffer[i] == ' '; i--)
		{
			sz_buffer[i] = 0;
		}
		while (sz_buffer[0] == ' ')
		{
			for (int i = 0; sz_buffer[i]; i++)
			{
				sz_buffer[i] = sz_buffer[i + 1];
			}
		}
		this->speciality = sz_buffer;
		ifs >> group;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
		
	}
};

#define teacher_take_parameters const string& speciality, int experience
#define teacher_give_parameters speciality, experience

class Teacher :public Human {
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 3;
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

	Teacher(human_take_parameters, teacher_take_parameters) :Human(human_give_parameters) {
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}

	~Teacher() {
		cout << "TDestructor:\t" << this << endl;
	}

	std::ostream& print(std::ostream& os)const override {
		return Human::print(os) << " " << speciality << " " << experience << " years";
	}

	std::ofstream& print(std::ofstream& ofs)const override {
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return (ofs);
	}

	std::ifstream& scan(std::ifstream& ifs) override {
		Human::scan(ifs);
		char sz_buffer[SPECIALITY_WIDTH + 1] = {};
		 ifs.read(sz_buffer, SPECIALITY_WIDTH);
		for (int i = SPECIALITY_WIDTH - 1; sz_buffer[i] == ' '; i--)
		{
			sz_buffer[i] = 0;
		}
		while (sz_buffer[0] == ' ')
		{
			for (int i = 0; sz_buffer[i]; i++)
			{
				sz_buffer[i] = sz_buffer[i + 1];
			}
		}
		this->speciality = sz_buffer;
		ifs >> experience;
		return ifs;
	}
};

class Graduate :public Student {
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

	std::ostream& print(std::ostream& os)const override {
		return Student::print(os) << " " << subject;
	}

	std::ofstream& print(std::ofstream& ofs)const override {
		Student::print(ofs) << " " << subject;
		return (ofs);
	}

	std::ifstream& scan(std::ifstream& ifs)override {
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
	
};



void print(Human* group[], const int n);

void save(Human* group[], const int n, const char sz_filename[]);

Human* human_factory(const string& type);

Human** load(const char sz_filename[], int& n);

//#define INHERITANCE_CHECK
//#define POLYMORPHISM_CHECK

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
#ifdef POLYMORPHISM_CHECK
	Human* group[] = {
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95),
		new Teacher("Whaite", "Walter", 50, "Chemistry", 20),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenbers"),
		new Student("Vercetti", "Tomas", 30, "Thieft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25)
	};
	cout << delimeter << endl;
	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}


#endif // POLYMORPHISM_CHECK

	int n = 0;
	Human** group = load("group.txt", n);
	print(group, n);

}

void save(Human* group[], const int n, const char sz_filename[]) {
	std::ofstream fout(sz_filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ": ";
		fout << *group[i] << endl;
	}
	fout.close();
	std::string command = "notepad ";
	command += sz_filename;
	system(command.c_str());
}

void print(Human* group[], const int n) {
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimeter << endl;
	}
}

Human* human_factory(const string& type) {
	if (type.find("Student") != string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != string::npos)return new Teacher("", "", 0, "", 0);
}

Human** load(const char sz_filename[], int& n) {
	n = 0; // размер массива
	Human** group = nullptr;
	std::ifstream fin(sz_filename);
	if (fin.is_open())
	{
		// 1) Считаем кол-во объектов сохраненных в файл
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.empty())continue;
			n++;
		}
		// 2) Выделяем память под массив
		group = new Human * [n] {};

		//3) Возвращаемся в начало файла для того, чтобы загрузить объекты:
		cout << "Position:\t" << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Position:\t" << fin.tellg() << endl;

		// 4) Читаем объекты из файла 
		for (int i = 0; i < n; i++)
		{
			getline(fin, buffer, ':');
			group[i] = human_factory(buffer);
			if(group[i])fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;

}
