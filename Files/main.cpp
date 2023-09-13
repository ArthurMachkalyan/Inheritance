#include <iostream>
#include <fstream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define WRITE_TO_FILE
//#define READ_FROM_FILE
//#define SWAP_IP_MAC
#define NETWORKS

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

#ifdef SWAP_IP_MAC
    std::ofstream fout("201 ready.txt");
	std::ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		cout << "File is open: \n" << endl;
		const int size = 24;
		std::string buff[size]{};
		for (int i = 0; i < 12; i++)
		{
			fin >> buff[i] >> buff[i+1];
			cout << buff[i + 1] << tab << buff[i] << endl;
			fout << buff[i + 1] << tab << buff[i] << endl;
		}
	    fin.close();
	}
	else
	{
		std::cerr << "Error: file not found!" << endl;
		
	}
	fout.close();
	system("notepad 201 ready.txt");
#endif // SWAP_IP_MAC

#ifdef NETWORKS
	std::ofstream fout("201.dhcpd");
	std::ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		cout << "File is open: \n" << endl;
		const int size = 24;
		std::string buff[size]{};
		for (int i = 1; i <= 12; i++)
		{
			fin >> buff[i-1] >> buff[i];
			cout << "host 201-" << i << "\n" << "{\n" << tab << "hardware ethernet" << tab << buff[i] << ";" << endl;
			cout << tab << "fixed-address\t" << tab << buff[i-1] << ";\n}\n" << endl;
			fout << "host 201-" << i << "\n" << "{\n" << tab << "hardware ethernet" << tab << buff[i] << ";" << endl;
			fout << tab << "fixed-address\t" << tab << buff[i-1] << ";\n}\n" << endl;

		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found!" << endl;

	}
	fout.close();
	system("notepad 201.dhcpd");
#endif // NETWORKS
}