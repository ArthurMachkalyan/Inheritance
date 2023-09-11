#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "Graduate.h"

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
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenbers")
	};
	cout << delimeter << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimeter << endl;
	}

}