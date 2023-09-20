#include <iostream>
#include <Windows.h>
using namespace std;

// enum (enumeration - �����������) - ����� ������������� ��������.
enum Color {
	red    = 0x000000FF,
	green  = 0x0000FF00,
	blue   = 0x00FF0000,
	yellow = 0x0000FFFF,
	purple = 0x00FF00FF,
	white  = 0x00FFFFFF
};

#define shape_take_parameters Color color, int start_x, int start_y, int line_width
#define shape_give_parameters color, start_x, start_y, line_width

class Shape {
	static const int MIN_START_X = 10;
	static const int MAX_START_X = 800;

	static const int MIN_START_Y = 10;
	static const int MAX_START_Y = 500;

	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 30;
protected:
	Color color;
	int start_x;
	int start_y;
	int line_width;
public:
	Color get_color()const {
		return color;
	}

	int get_start_x()const {
		return start_x;
	}
	int get_start_y()const {
		return start_y;
	}
	int get_line_width()const {
		return line_width;
	}

	void set_color(Color color) {
		this->color = color;
	}

	void set_start_x(double start_x) {
		if (start_x < MIN_START_X)start_x = MIN_START_X;	
		if (start_x > MAX_START_X)start_x = MAX_START_X;
		this->start_x = start_x;
	}

	void set_start_y(int start_y) {
		if (start_y < MIN_START_Y)start_y = MIN_START_Y;
		if (start_y > MAX_START_Y)start_y = MAX_START_Y;
		this->start_y = start_y;
	}

	void set_line_width(int line_width) {
		if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
		if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
		this->line_width;
	}

	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;

	Shape(shape_take_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}

	~Shape() {}

};

class Square : public Shape {
	double side;
public:
	double get_side()const {
		return side;
	}

	void set_side(double side) {
		this->side = side;
	}

	Square(double side, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_side(side);
	}


	~Square() {}

	double get_area()const override {
		return side * side;
	}
	double get_perimeter()const override {
		return side * 4;
	}

	void draw()const override {
		/*for (int i = 0; i < side; i++)
		{
			for (int i = 0; i < side; i++)
			{
				cout << "* ";
			}
			cout << endl;
		}*/

		cout << endl;

		HWND hwnd = GetConsoleWindow(); // 1) �������� ���� �������:
		HDC hdc = GetDC(hwnd); // 2) �������� �������� ���������� ��� ���� ������� 

		HPEN hPen = CreatePen(PS_SOLID, line_width, color); // 3) ������� ��������, ������� ������ ������ ������
		HBRUSH hBrush = CreateSolidBrush(color); // 4) ������� �����, ��� ������ ������� ������

		// 5) ��������, ��� � �� ��� ��������. ������ ������ �� ��������� ����������,
		// ��� ��������� ���������� ��������
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		
		// 6) ������ �������������. ��� ��� ��������� ������� ���������� ��������-������
		// � �������-������� ����
		Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

		// 7) ������� ��� ��������� �����������
		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);
	}

	void info() {
		cout << "����� �������:  \t" << get_side() << endl;
		cout << "������� ������: \t" << get_area() << endl;
		cout << "�������� ������: \t" << get_perimeter() << endl;
	}

};

class Rectangle : public Shape {
	double side_a;
	double side_b;
public:
	double get_side_a()const {
		return side_a;
	}
	double get_side_b()const {
		return side_b;
	}

	void set_side_a(double side_a) {
		this->side_a = side_a;
	}
	void set_side_b(double side_b) {
		this->side_b = side_b;
	}

	double get_area()const override {
		return side_a * side_b;
	}
	double get_perimeter()const override {
		return (side_a + side_b) * 2;
	}


	void draw()const override {
		
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);

	}
	
	Rectangle(double side_a, double side_b, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_side_a(side_a);
		set_side_b(side_b);
	}

	~Rectangle() {}

	void info() {
		cout << "������� �:\t" << get_side_a() << endl;
		cout << "������� B: \t" << get_side_b() << endl;
		cout << "������� ������:\t" << get_area() << endl;
		cout << "�������� ������:\t" << get_perimeter() << endl << endl;
	}
};



class Triangle : public Shape {
	double side_a;
	double side_b;
	double side_c;
	double height;
public:
	double get_side_a()const {
		return side_a;
	}
	double get_side_b()const {
		return side_b;
	}
	double get_side_c()const {
		return side_c;
	}
	double get_height()const {
		return height;
	}

	void set_side_a(double side_a) {
		this->side_a = side_a;
	}
	void set_side_b(double side_b) {
		this->side_b = side_b;
	}
	void set_side_c(double side_c) {
		this->side_c = side_c;
	}
	void set_height(double height) {
		this->height = height;
	}

	double get_area()const override {
		return (side_a * height) / 2;
	}

	double get_perimeter()const override {
		return side_a + side_b + side_c;
	}
	
	Triangle(double side_a, double side_b, double side_c, double height, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_side_a(side_a);
		set_side_b(side_b);
		set_side_c(side_c);
		set_height(height);
	}

	~Triangle() {}

	void draw()const override {

		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);

	}

	void info() {
		cout << "������� �:\t" << get_side_a() << endl;
		cout << "������� B: \t" << get_side_b() << endl;
		cout << "������� C: \t" << get_side_c() << endl;
		cout << "������: \t" << get_side_c() << endl;
		cout << "������� ������:\t" << get_area() << endl;
		cout << "�������� ������:\t" << get_perimeter() << endl << endl;
	}
	
};

static const double Pi = 3.14;

class Circle : public Shape {
	double radius;
public:
	double get_radius()const {
		return radius;
	}
	void set_radius(double radius) {
		this->radius = radius;
	}

	double get_perimeter()const override {
		return 2 * Pi * radius;
	}

	double get_area()const override {
		return Pi * pow(radius, 2);
	}

	Circle(double radius, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_radius(radius);
	}

	~Circle() {}

	void draw()const override {

		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		::Rectangle(hdc, start_x, start_y, start_x , start_y);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);

	}

	void info() {
		cout << "������:\t" << get_radius() << endl;
		cout << "������� ������:\t" << get_area() << endl;
		cout << "�������� ������:\t" << get_perimeter() << endl << endl;
	}
};

void main() {
	setlocale(LC_ALL, "");

	Square square(150, Color::red, 200, 20, 5);
	square.info();
	square.draw();

	class Rectangle rect(200, 150,Color::blue, 400, 20, 5);
	rect.info();
	rect.draw();

	class Triangle trigon(20, 5, 10, 15, Color::yellow, 200, 20, 5);
	trigon.info();
	trigon.draw();

	class Circle circ(5, Color::red, 200, 20, 5);
	circ.info();
}
