#include <iostream>
#include <fstream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main() {
	setlocale(LC_ALL, "");


#ifdef WRITE_TO_FILE
	std::ofstream fout;          // 1) Создаем поток
	fout.open("File.txt", std::ios_base::app);          // 2) Открываем поток
	fout << "Hello Files" << endl;  // 3) Пишем в поток (в файл)
	fout << "Привет!\n";
	fout.close();          // 4) Когда поток уже не нужен, его обязательно нужно закрыть!

	system("notepad File.txt");

#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open()) {
		//to do read file
		const int SIZE = 10240;
		char sz_buffer[SIZE] = {};
		while (!fin.eof())
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		
		fin.close();

	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

#endif // READ_FROM_FILE

  
}