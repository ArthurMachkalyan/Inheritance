#include <iostream>
using namespace std;

const char* Hello() {
	return "Hello";
}

int Sum(int a, int b) {
	return a + b;
}

void main() {
	setlocale(LC_ALL, "");
	cout << Hello << endl;  // Просто адресс функции
	const char* (*pHello)() = Hello;
	cout << pHello << endl;  //Адрес той же функции, сохраненный в указателе
	cout << pHello() << endl;  // Вызов функции 'Hello()' через указатель 'pHello()'

	cout << Sum(2, 3) << endl;
	cout << Sum << endl;
	int (*pSum)(int a, int b) = Sum;
	cout << pSum(3,5) << endl;
}