#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
using namespace std;

// enum (enumeration - Пречисление) - набор целочисленных констант.
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
protected:
	static const int MIN_START_X = 10;
	static const int MAX_START_X = 900;

	static const int MIN_START_Y = 10;
	static const int MAX_START_Y = 700;

	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 30;

	static const int MIN_DIMENSION = 25;
	static const int MAX_DIMENSION = 500;
	
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
		this->line_width = line_width;
	}

	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
	void draw(WINGDIAPI BOOL(__stdcall*DrawFunction)(HDC, int, int, int, int), double horizontal, double vertical)const {
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);


		::Ellipse(hdc, start_x, start_y, start_x + horizontal, start_y + vertical);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}
	
	Shape(shape_take_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}

	~Shape() {}

	void info()const {
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Периметр фигуры: " << get_perimeter() << endl;
		draw();
	}

};
//#define SQUARE_INDEPENDENT
#ifdef SQUARE_INDEPENDENT
class Square : public Shape {
	double side;
public:
	double get_side()const {
		return side;
	}

	void set_side(double side) {
		this->side = side;
	}


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

		HWND hwnd = GetConsoleWindow(); // 1) Получаем окно консоли:
		HDC hdc = GetDC(hwnd); // 2) Получаем контекст устройства для окна консоли 

		HPEN hPen = CreatePen(PS_SOLID, line_width, color); // 3) Создаем карандаш, который рисует контур фигуры
		HBRUSH hBrush = CreateSolidBrush(color); // 4) Создаем кисть, она рисует заливку фигуры

		// 5) Выбираем, чем и на чем рисовать. Рисуют всегда на контексте устройства,
		// для рисования используем карандаш
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		
		// 6) Рисуем прямоугольник. Для его рисования указать координаты верхнего-левого
		// и правого-нижнего угла
		Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

		// 7) Удаляем все созданные инструменты
		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);
	}

	Square(double side, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_side(side);
	}


	~Square() {}

	 void info()const {
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны:  \t" << get_side() << endl;
		Shape::info();
	}

};
#endif // SQUARE_INDEPENDENT


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
		if (side_a < MIN_DIMENSION)side_a = MIN_DIMENSION;
		if (side_a > MAX_DIMENSION)side_a = MAX_DIMENSION;
		this->side_a = side_a;
	}
	void set_side_b(double side_b) {
		if (side_b < MIN_DIMENSION)side_b = MIN_DIMENSION;
		if (side_b > MAX_DIMENSION)side_b = MAX_DIMENSION;
		this->side_b = side_b;
	}

	double get_diagonal()const {
		return sqrt(side_a * side_a + side_b * side_b);
	}

	double get_area()const override {
		return side_a * side_b;
	}
	double get_perimeter()const override {
		return (side_a + side_b) * 2;
	}


	void draw()const override {
		Shape::draw(::Rectangle, side_a, side_b);
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

	void info()const {
		cout << typeid(*this).name() << endl;
		cout << "Сторона А:\t" << get_side_a() << endl;
		cout << "Сторона B: \t" << get_side_b() << endl;
		cout << "Диагональ: \t" << get_diagonal() << endl;
		Shape::info();

	}
};

class Square :public Rectangle {
public:
	Square(double side, shape_take_parameters):Rectangle(side, side, shape_give_parameters) {}
	~Square() {}
};

class Triangle : public Shape {
public:
	virtual double get_height()const = 0;
	Triangle(shape_take_parameters) :Shape(shape_give_parameters) {}
	~Triangle() {}
	void draw(WINGDIAPI BOOL (__stdcall *Polygon)(HDC, const POINT*, int ), const POINT* vertex)const {
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		/*POINT vertex[] =
		{
			{start_x, start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - get_height()}

		};*/

		Polygon(hdc, vertex, 3);

		DeleteObject(hPen);
		DeleteObject(hBrush);

		ReleaseDC(hwnd, hdc);
	}
	/*double side_a;
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

	~Triangle() {}*/

	void info()const {
		cout << typeid(*this).name() << endl;
		cout << "Высота: \t" << get_height() << endl;
		Shape::info();
		/*cout << "Сторона А:\t" << get_side_a() << endl;
		cout << "Сторона B: \t" << get_side_b() << endl;
		cout << "Сторона C: \t" << get_side_c() << endl;*/
	}
};

class EquilateralTriangle : public Triangle {
	double side;
public:
	double get_side()const {
		return side;
	}
	void set_side(double side) {
		if (side < MIN_DIMENSION)side = MIN_DIMENSION;
		if (side > MAX_DIMENSION)side = MAX_DIMENSION;
		this->side = side;
	}
	double get_height()const override {
		return sqrt(pow(side, 2) - pow(side / 2, 2));
	}
	double get_area()const override {
		return pow(get_height(), 2) * sqrt(3);
	}
	double get_perimeter()const override {
		return side * 3;
	}
	void draw()const override {

		POINT vertex[] =
		{
			{start_x, start_y + side},
			{start_x + side, start_y + side},
			{start_x + side / 2, start_y + side - get_height()}

		};

		Triangle::draw(::Polygon, vertex);

	}

	EquilateralTriangle(double side, shape_take_parameters) :Triangle(shape_give_parameters) {
		set_side(side);
	}

	~EquilateralTriangle() {}

	void info()const {
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны: " << side << endl;
		Triangle::info();
	}

};

class RightTriangle : Triangle {
	double side_a;
	double side_b;
public:

	double get_side_a()const {
		return side_a;
	}
	void set_side_a(double side_a) {
		if (side_a < MIN_DIMENSION)side_a = MIN_DIMENSION;
		if (side_a > MAX_DIMENSION)side_a = MAX_DIMENSION;
		this->side_a = side_a;
	}
	
	double get_side_b()const {
		return side_a;
	}
	void set_side_b(double side_b) {
		if (side_b < MIN_DIMENSION)side_b = MIN_DIMENSION;
		if (side_b > MAX_DIMENSION)side_b = MAX_DIMENSION;
		this->side_b = side_b;
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
		if (radius < MIN_DIMENSION)radius = MIN_DIMENSION;
		if (radius > MAX_DIMENSION)radius = MAX_DIMENSION;
		this->radius = radius;
	}

	double get_diameter()const {
		return 2 * radius;
	}

	double get_perimeter()const override {
		return 2 * M_PI * radius;
	}

	double get_area()const override {
		return M_PI * pow(radius, 2);
	}


	void draw()const override {

		Shape::draw(::Ellipse, (int)get_diameter(), (int)get_diameter());
	}

	Circle(double radius, shape_take_parameters) : Shape(shape_give_parameters) {
		set_color(color);
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
		set_radius(radius);
	}

	~Circle() {}

	void info()const {
		cout << typeid(*this).name() << endl;
		cout << "Радиус круга:\t" << get_radius() << endl;
		cout << "Диаметр круга:\t" << get_diameter() << endl;
		Shape::info();
	}
};


#define delimeter "\n--------------------------\n"

void main() {
	setlocale(LC_ALL, "");

	Square square(150, Color::red, 300, 250, 5);
	square.info();
	cout << delimeter;
	class Rectangle rect(200, 150,Color::blue, 500, 220, 5);
	rect.info();
	cout << delimeter;

	EquilateralTriangle et(100, Color::green, 800, 300, 15);
	et.info();
	cout << delimeter;

	Circle circ(100, Color::yellow, 750, 10, 5);
	circ.info();
}
