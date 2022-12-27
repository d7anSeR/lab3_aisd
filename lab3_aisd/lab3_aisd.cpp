#include <iostream>
#include <cstdlib>
#include <math.h>
#include <conio.h>
#include <vector>

using namespace std;
template<class C>
class Complex {
private:
	struct PointsC
	{
		C reX = 0, imX = 0, reY = 0, imY = 0;
		PointsC operator=(const PointsC& point)
		{
			this->imX = point.imX;
			this->imY = point.imY;
			this->reX = point.reX;
			this->reY = point.reY;
			return *this;
		}
	};
	std::vector<PointsC> a;
	int number_points = 0;
public:
	Complex(const Complex<C>& src) = default;
	~Complex() = default;
	Complex<C>& operator= (const Complex<C>& src) = default;
	Complex<C>(int number_points = 0)
	{
		if (number_points == 0)
		{
			this->number_points = number_points;
			return;
		}
		a.resize(number_points);
		this->number_points = number_points;
	}
	int Get_number_points() const { return number_points; }
	Complex operator +(const Complex& other) //конкатенация двух линий 
	{
		Complex<C> tmp(number_points + other.number_points);
		tmp.number_points = number_points + other.number_points;
		int j = 0;
		for (const auto& i : a)
		{
			tmp[j] = i;
			j++;
		}
		for (const auto& i : other.a)
		{
			tmp[j] = i;
			j++;
		}
		return tmp;
	}

	Complex operator +(const PointsC& point)//сложение ломаной и точки, добавление в конец 
	{
		number_points++;
		a.push_back(point);
		return *this;
	}

	friend Complex operator +(const PointsC& point, Complex& tmp_line)//сложение точки и ломанной, добавление в начало
	{
		std::vector<PointsC> tmp(tmp_line.Get_number_points() + 1);
		int j = 0;
		for (const auto& i : tmp_line.a)
		{
			tmp[j + 1] = i;
			j++;
		}
		tmp[0] = point;
		tmp_line.a = tmp;
		tmp_line.number_points++;
		return tmp_line;
	}
	PointsC operator [] (int other_point) const //for reading
	{
		if (other_point >= 0 && other_point < number_points)
			return (a[other_point]);
		throw "!invalid index!";
	}
	PointsC& operator [] (int other_point) //for writing
	{
		if (other_point >= 0 && other_point < number_points)
			return (a[other_point]);
		throw "!invalid index!";
	}

	friend ostream& operator<<(ostream& out, PointsC& a)
	{
		return out << "(" << "(" << a.reX << ", " << a.imX << ")" << ";" << "(" << a.reY << ", " << a.imY << ")" << ")";
	}
	//	Complex<C>& operator=(const Complex&) = default;
	friend bool operator !=(const PointsC& point1, const PointsC& point2)
	{
		if (point1.reX != point2.reX || point1.imX != point2.imX || point1.reY != point2.reY || point1.imY != point2.imY) return true;
		return false;
	}
	bool operator == (const Complex& other)
	{
		if (this->Get_number_points() == other.Get_number_points())
		{
			int count = 0;
			for (auto i : other.a)
			{
				if (a[count] != i)
					return false;
				count++;
			}
			return true;
		}
		return false;
	}
	bool operator != (const Complex& other)
	{
		return !((*this) == other);
	}
	auto begin() {
		return a.begin();
	}
	auto end() {
		return a.end();
	}

};
template<class C>
std::ostream& operator<<(ostream& out, Complex<C>& a)
{
	int j = 0;
	for (auto i : a)
	{
		out << i;
		if (j < a.Get_number_points() - 1) out << endl;
		j++;
	}
	return out;
}

template <typename T>
class Line
{
private:
	struct Points
	{
		T x = 0, y = 0;
		Points operator=(const Points& point)
		{
			this->x = point.x;
			this->y = point.y;
			return *this;
		}
	};
	std::vector<Points> a;
	int number_points = 0;

public:

	Line<T>(int number_points = 0)
	{
		if (number_points == 0)
		{
			this->number_points = number_points;
			return;
		}
		a.resize(number_points);
		this->number_points = number_points;
	}
	Line(const Line<T>&) = default;
	~Line() = default;
	int Get_number_points() const { return number_points; }

	


	Points operator [] (int other_point) const //for reading
	{
		if (other_point >= 0 && other_point < number_points)
			return (a[other_point]);
		throw "!invalid index!";
	}
	Points& operator [] (int other_point) //for writing
	{
		if (other_point >= 0 && other_point < number_points)
			return (a[other_point]);
		throw "!invalid index!";
	}

	Line operator +(const Line& other) //конкатенация двух линий 
	{
		Line<T> tmp(number_points + other.number_points);
		tmp.number_points = number_points + other.number_points;
		int j = 0;
		for (const auto& i : a)
		{
			tmp[j] = i;
			j++;
		}
		for (const auto& i : other.a)
		{
			tmp[j] = i;
			j++;
		}
		return tmp;
	}

	Line operator +(const Points& point)//сложение ломаной и точки, добавление в конец 
	{
		number_points++;
		a.push_back(point);
		return *this;
	}
	friend Line operator +(const Points& point, Line& tmp_line)////сложение точки и ломанной, добавление в начало
	{
		std::vector<Points> tmp(tmp_line.Get_number_points() + 1);
		int j = 0;
		for (const auto& i : tmp_line.a)
		{
			tmp[j + 1] = i;
			j++;
		}
		tmp[0] = point;
		tmp_line.a = tmp;
		tmp_line.number_points++;
		return tmp_line;
	}
	Line<T>& operator =(const Line&) = default;
	bool operator == (const Line& other)
	{
		if (this->Get_number_points() == other.Get_number_points())
		{
			int count = 0;
			for (auto i : other.a)
			{
				if (a[count] != i)
					return false;
				count++;
			}
			return true;
		}
		return false;
	}

	friend bool operator !=(const Points& point1, const Points& point2)
	{
		if (point1.x != point2.x || point1.y != point2.y) return true;
		return false;
	}

	bool operator != (const Line& other)
	{
		return !((*this) == other);
	}
	friend ostream& operator<<(ostream& out, Points& a)
	{
		return out << "(" << a.x << ", " << a.y << ")";
	}
	auto begin() {
		return a.begin();
	}
	auto end() {
		return a.end();
	}

};
template <class T>
std:: ostream& operator<<(ostream& out, Line<T>& a)
{
	int j = 0;
	for (auto i : a)
	{
		out << i;
		if (j < a.Get_number_points() - 1) out << endl;
		j++;
	}
	return out;
}



template <class T>
Line<T> CreatingLine(Line<T>& start_line) {
	T x, y;
	for (int i = 0; i < start_line.Get_number_points(); i++)
	{
		std::cout << endl << endl << "Enter the coordinates of the point:" << endl;
		std::cout << endl << "x = ";
		std::cin >> x;
		std::cout << endl << "y = ";
		std::cin >> y;
		start_line[i].x = x;
		start_line[i].y = y;
	}
	return start_line;
}

template <class C>
Complex<C> CreatingLineC(Complex<C> start_line) {
	C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	for (int i = 0; i < start_line.Get_number_points(); i++)
	{
		cout << endl << endl << "Enter the coordinates of the point:" << endl;
		cout << "x1: ";
		cin >> x1;
		cout << "x2: ";
		cin >> x2;
		cout << "y1: ";
		cin >> y1;
		cout << "y2: ";
		cin >> y2;
		start_line[i].reX = x1;
		start_line[i].imX = x2;
		start_line[i].reY = y1;
		start_line[i].imY = y2;
	}
	return start_line;
}


template <class T>
int IndexPoint(Line<T>& start_line, bool flag)
{
	system("cls");
	flag = true;
	int index = 0;
	while (flag)
	{
		int choice = 0;
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		while (flag)
		{
			std::cout << endl << "Enter index:" << endl;
			std::cin >> index;
			try {
				if (index <= 0 || index > start_line.Get_number_points()) throw "!There is no such index point!";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		flag = true;
		while (flag)
		{
			try {
				std::cout << "Select:" << endl;
				std::cout << "1) Read coordinates";
				std::cout << "   2) Change coordinates" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2) throw"!There is no such index point";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		if (choice == 1) cout << "Coordinates: " << "(" << start_line[index - 1].x << ";" << start_line[index - 1].y << ")" << endl << endl;
		if (choice == 2)
		{
			T x = 0, y = 0;
			std::cout << "Enter х: ";
			std::cin >> x;
			std::cout << "Enter y: ";
			std::cin >> y;
			start_line[index - 1].x = x;
			start_line[index - 1].y = y;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << start_line[index - 1].x << "; " << start_line[index - 1].y << ")" << endl << endl;
		}
		std::cout << endl << "Press 'Backspace' to return";
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}
template <class C>
int IndexPointC(Complex<C>& start_line, bool flag)
{
	system("cls");
	flag = true;
	int index = 0;
	while (flag)
	{
		int choice = 0;
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		while (flag)
		{
			std::cout << endl << "Enter index:" << endl;
			std::cin >> index;
			try {
				if (index <= 0 || index > start_line.Get_number_points()) throw "!There is no such index point!";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		flag = true;
		while (flag)
		{
			try {
				std::cout << "Select:" << endl;
				std::cout << "1) Read coordinates";
				std::cout << "   2) Change coordinates" << endl;
				cin >> choice;
				if (choice != 1 && choice != 2) throw"!There is no such index point";
				flag = false;
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
		}
		if (choice == 1) cout << "Coordinates: " << "(" << "(" << start_line[index - 1].reX << ";" << start_line[index - 1].imX << ")" << "," << "(" << start_line[index - 1].reY << ";" << start_line[index - 1].imY << ")" << ")" << endl;
		if (choice == 2)
		{
			C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			std::cout << "Enter х1: ";
			std::cin >> x1;
			std::cout << "Enter x2: ";
			std::cin >> x2;
			std::cout << "Enter y1: ";
			std::cin >> y1;
			std::cout << "Enter y2: ";
			std::cin >> y2;
			start_line[index - 1].reX = x1;
			start_line[index - 1].imX = x2;
			start_line[index - 1].reY = y1;
			start_line[index - 1].imY = y2;
			std::cout << start_line << endl;
			std::cout << "Coordinates of the point with index " << index << " = (" << "(" << start_line[index - 1].reX << ";" << start_line[index - 1].imX << ")" << "," << "(" << start_line[index - 1].reY << ";" << start_line[index - 1].imY << ")" << ")" << endl << endl;
		}
		std::cout << endl << "Press 'Backspace' to return";
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}
template <class T>
int SumLine(Line<T>& start_line, bool flag)
{
	int choice = 0;
	bool flag1 = true;
	flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;;
	while (flag1)
	{
		try {
			std::cout << endl << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Line<T> tmp_line(n);
		Line<T> new_line = CreatingLine(tmp_line);
		flag1 = false;
		std::cout << "Point coordinates of the second broken line" << endl;
		cout << new_line;
		start_line = start_line + new_line;
		std::cout << endl << "Result: " << endl;
		cout << start_line;
		std::cout << endl << "Press 'Backspace' to return" << endl << endl;
		choice = _getch();
		if (choice == 8) flag1 = true;
	}
	return -1;
}
template <class C>
int SumLineC(Complex<C>& start_line, bool flag)
{
	int choice = 0;
	bool flag1 = true;
	flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		try {
			std::cout << endl << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
		Complex<C> tmp_line(n);
		Complex<C> new_line = CreatingLineC(tmp_line);
		flag1 = false;
		std::cout << "Point coordinates of the second broken line" << endl;
		cout << new_line;
		start_line = start_line + new_line;
		std::cout << endl << "Result: " << endl;
		cout << start_line;
		std::cout << endl << "Press 'Backspace' to return" << endl << endl;
		choice = _getch();
		if (choice == 8) flag1 = true;
	}
	return -1;
}

template <class T>
int SumPoint_Line(Line<T>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		T x = 0, y = 0;
		std::cout << endl << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x = ";
		cin >> x;
		std::cout << "y = ";
		cin >> y;
		Line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		Line<T> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}
template <class C>
int SumPoint_LineC(Complex<C>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		std::cout << endl << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x1 = ";
		cin >> x1;
		std::cout << "x2 = ";
		cin >> x2;
		std::cout << "y1 = ";
		cin >> y1;
		std::cout << "y2 = ";
		cin >> y2;
		Complex<C> point(1);
		point[0].reX = x1;
		point[0].imX = x2;
		point[0].reY = y1;
		point[0].imY = y2;
		Complex<C> tmp_line = point[0] + start_line;
		cout << tmp_line;
		start_line = tmp_line;
		std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}

template <class T>
int SumLine_Point(Line<T>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		T x = 0, y = 0;
		std::cout << endl << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		Line<T> point(1);
		point[0].x = x;
		point[0].y = y;
		Line<T> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}
template <class C>
int SumLine_PointC(Complex<C>& start_line, bool flag)
{
	int choice = 0;
	flag = true;
	while (flag)
	{
		std::cout << endl << "To continue, press any key except 'Backspace'..." << endl;
		std::cout << endl << "or 'Backspace' because to back to main menu" << endl;
		choice = _getch();
		if (choice == 8) return choice;
		C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		std::cout << endl << "Press coordinates of the point which want to add: " << endl;
		std::cout << "x1 = ";
		std::cin >> x1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "y1 = ";
		std::cin >> y1;
		std::cout << "y2 = ";
		std::cin >> y2;
		Complex<C> point(1);
		point[0].reX = x1;
		point[0].imX = x2;
		point[0].reY = y1;
		point[0].imY = y2;
		Complex<C> tmp_line = start_line + point[0];
		start_line = tmp_line;
		cout << tmp_line;
		std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
		choice = _getch();
		if (choice == 8) flag = true;
	}
	return -1;
}
template <class T>
int LenLine(Line<T>& start_line)
{
	int choice = 0;
	double len = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_number_points(); i++)
		len += pow(pow(abs(start_line[i + 1].x - start_line[i].x), 2) + pow(abs(start_line[i + 1].y - start_line[i].y), 2), 0.5);
	std::cout << "Length of the line: " << len << endl;
	std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
	choice = _getch();
	if (choice == 8) return choice;
	return -1;
}
template <class C>
int LenLineC(Complex<C>& start_line)
{
	int choice = 0;
	double len = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	cout << start_line << endl;
	for (int i = 0; (i + 1) < start_line.Get_number_points(); i++)
	{
		a = start_line[i + 1].reX - start_line[i].reX; //действительная часть
		b = start_line[i + 1].imX - start_line[i].imX;//мнимая часть
		c = pow(a, 2) - pow(b, 2);
		d = 2 * a * b; //*i
		e = start_line[i + 1].reY - start_line[i].reY; //действительная часть
		f = start_line[i + 1].imY - start_line[i].imY;//мнимая часть
		g = pow(e, 2) - pow(f, 2);
		h = 2 * e * f; //*i
		len += sqrt(sqrt(pow(c + g, 2) + pow(d + h, 2)));
	}
	cout << "Length of the line: " << len << endl;
	std::cout << endl << "Press 'Backspace' if want to back" << endl << endl;
	choice = _getch();
	if (choice == 8) return choice;
	return -1;
}
template <class T>
int Compare(Line<T>& start_line)
{
	int choice = 0;
	T x = 0, y = 0;
	bool flag1 = true, flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		choice = _getch();
		if (choice == 8) return choice;
		try {
			std::cout << endl << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
					flag1 = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}

		Line<T> tmp_line(n);
		Line<T> new_line = CreatingLine(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << "The broken lines are equal!" << endl;
		if (start_line != new_line) cout << "The broken lines are unequal!" << endl;
		std::cout << endl << "Press 'Backspace' to return" << endl << endl;
		choice = _getch();
		if (choice == 8) flag1 = true;
	}
	return -1;
}
template <class C>
int CompareC(Complex<C>& start_line)
{
	int choice = 0;
	C x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	bool flag1 = true, flag = true;
	int n = 0;
	std::cout << "Point coordinates of the first broken line" << endl;
	cout << start_line;
	while (flag1)
	{
		choice = _getch();
		if (choice == 8) return choice;
		try {
			std::cout << endl << "Press the second broken line " << endl;
			flag = true;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points must be >= 2";
					flag = false;
					flag1 = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}

		Complex<C> tmp_line(n);
		Complex<C> new_line = CreatingLineC(tmp_line);
		flag1 = false;
		cout << new_line;
		if (start_line == new_line) cout << endl << "The broken lines are equal!" << endl;
		if (start_line != new_line) cout << endl << "The broken lines are unequal!" << endl;
		std::cout << endl << "Press 'Backspace' to return" << endl << endl;
		choice = _getch();
		if (choice == 8) flag1 = true;
	}
	return -1;
}

void menu0()
{
	system("cls");
	std::cout << endl << "Choose where you want to start" << endl << endl;
	std::cout << "1. Create a broken line" << endl;
	std::cout << "2. Build a rectangular trapezoid" << endl;
	std::cout << "3. Complete the job" << endl;

}

void menu1()
{
	std::cout << endl << endl << "Next choice: " << endl;
	std::cout << "1. Know/change point coordinates of the broken line" << endl;
	std::cout << "2. Broken lines concatenation" << endl;
	std::cout << "3. Add the line to the point (add a point at the start of the line)" << endl;
	std::cout << "4. Add the point to the line (add a point at the finish of the line)" << endl;
	std::cout << "5. Calculate the length of the line" << endl;
	std::cout << "6. Compare broken lines" << endl;
	std::cout << "7. Back to main menu" << endl;
}

template <class T>
void AutoCreateLine(T x, T y, Line<T>& line, T a, T b, T h)
{
	line[0].x = x;
	line[0].y = y;
	line[1].x = x;
	line[1].y = y + a;
	line[2].x = x + h;
	line[2].y = y + a;
	line[3].x = x + h;
	line[3].y = y + a - b;
	line[4].x = x;
	line[4].y = y;
	cout << endl << line;
}
template <class C>
void AutoCreateLineC(C x1, C x2, C y1, C y2, Complex<C>& line, C a, C b, C h)
{
	line[0].reX = x1;
	line[0].imX = x2;
	line[0].reY = y1;
	line[0].imY = y2;
	line[1].reX = x1;
	line[1].imX = x2;
	line[1].reY = y1 + a;
	line[1].imY = y2 + a;
	line[2].reX = x1 + h;
	line[2].imX = x2 + h;
	line[2].reY = y1 + a;
	line[2].imY = y2 + a;
	line[3].reX = x1 + h;
	line[3].imX = x2 + h;
	line[3].reY = y1 + a - b;
	line[3].imY = y2 + a - b;
	line[4].reX = x1;
	line[4].imX = x2;
	line[4].reY = y1;
	line[4].imY = y2;
	cout << endl << line;
}

template <class T>
Line<T>& CreatingRecTrapezoid(bool flag)
{
	Line<T> line(5);
	int choice = 0;
	T a = 0, b = 0, h = 0, x = 0, y = 0;
	system("cls");
	flag = true;
	while (flag)
	{
		try {
			std::cout << "Enter the bases ( a and b )  and height h:" << endl;
			std::cout << "a: ";
			std::cin >> a;
			if (a <= 0) throw "Value a must be > 0";
			std::cout << "b: ";
			std::cin >> b;
			if (b <= 0) throw "Value b must be > 0";
			std::cout << "h: ";
			std::cin >> h;
			if (h <= 0) throw "Value h must be > 0";
			flag = false;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cout << endl << "Try again" << endl;
		}
	}
	std::cout << endl << "Press coordinaes of the first point" << endl;
	std::cout << "х = ";
	cin >> x;
	std::cout << "y = ";
	cin >> y;
	AutoCreateLine(x, y, line, a, b, h);
	return line;
}

template <class C>
Complex<C>& CreatingRecTrapezoidC(bool flag)
{
	Complex<C> line(5);
	int choice = 0;
	C a = 0, b = 0, h = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	system("cls");
	flag = true;
	while (flag)
	{
		try {
			std::cout << "Enter the bases ( a and b )  and height h:" << endl;
			std::cout << "a: ";
			std::cin >> a;
			if (a <= 0) throw "Value a must be > 0";
			std::cout << "b: ";
			std::cin >> b;
			if (b <= 0) throw "Value b must be > 0";
			std::cout << "h: ";
			std::cin >> h;
			if (h <= 0) throw "Value h must be > 0";
			flag = false;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cout << endl << "Try again" << endl;
		}
	}
	std::cout << endl << "Press coordinaes of the first point" << endl;
	std::cout << "х1 = ";
	cin >> x1;
	std::cout << "х2 = ";
	cin >> x2;
	std::cout << "y1 = ";
	cin >> y1;
	std::cout << "y2 = ";
	cin >> y2;
	AutoCreateLineC(x1, x2, y1, y2, line, a, b, h);
	return line;
}

template <class T>
bool JobWithLine(bool flag, bool flag1, int choice, Line<T>& start_line)
{
	menu1();
	flag = true;
	while (flag)
	{
		try {
			std::cin >> choice;
			if (choice > 8 || choice < 1) throw "!There is no such option!";
			flag = false;
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
	}
	if (choice == 1)
		if (IndexPoint(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLine(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_Line(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (SumLine_Point(start_line, flag) == 8) flag1 = true;
	if (choice == 5)
		if (LenLine(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (Compare(start_line) == 8) flag1 = true;
	if (choice == 7)
	{
		flag = true;
		flag1 = false;
	}
	return flag1;
}
template <class C>
bool JobWithLineC(bool flag, bool flag1, int choice, Complex<C>& start_line)
{
	menu1();
	flag = true;
	while (flag)
	{
		try {
			std::cin >> choice;
			if (choice > 8 || choice < 1) throw "!There is no such option!";
			flag = false;
		}
		catch (const char* ex)
		{
			std::cout << ex << endl;
			std::cout << endl << "Try again" << endl;
		}
	}
	if (choice == 1)
		if (IndexPointC(start_line, flag) == 8) flag1 = true;
	if (choice == 2)
		if (SumLineC(start_line, flag) == 8) flag1 = true;
	if (choice == 3)
		if (SumPoint_LineC(start_line, flag) == 8) flag1 = true;
	if (choice == 4)
		if (SumLine_PointC(start_line, flag) == 8) flag1 = true;
	if (choice == 5)
		if (LenLineC(start_line) == 8) flag1 = true;
	if (choice == 6)
		if (CompareC(start_line) == 8) flag1 = true;
	if (choice == 7)
	{
		flag = true;
		flag1 = false;
	}
	return flag1;
}

int main()
{
	int choice = 0;
	int type = 0;
	bool flag = true, flag1 = true;
	while (flag)
	{
		menu0();
		std::cout << "Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			flag = true;
			int n = 0;

			while (flag)
			{
				try
				{
					std::cout << "Number of points: ";
					std::cin >> n;
					if (n < 2) throw "The numbers of points muct be >= 2";
					flag = false;
				}
				catch (const char* ex)
				{
					std::cout << ex << endl;
					std::cout << endl << "Try again" << endl;
				}
			}
			std::cout << "Choice data type: 1 - int, 2 - float, 3 - double, 4 - complex float, 5 - complex double: ";
			std::cin >> type;
			flag = true;
			flag1 = true;

			if (type == 1) {
				Line<int> tmp_line(n);
				Line<int> start_line = CreatingLine<int>(tmp_line);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;

			}
			else if (type == 2) {
				Line<float> tmp_line(n);
				Line<float> start_line = CreatingLine<float>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 3) {
				Line<double> tmp_line(n);
				Line<double> start_line = CreatingLine<double>(tmp_line);

				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 4) {
				Complex<float> tmp_line(n);
				Complex<float> start_line = CreatingLineC<float>(tmp_line);

				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, start_line);
				break;
			}
			else if (type == 5) {
				Complex<double>tmp_line(n);
				Complex<double> start_line = CreatingLineC<double>(tmp_line);

				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, start_line);
				break;
			}

		}
		case 2:
		{
			std::cout << "Choice data type:1 - int, 2 - float, 3 - double, 4 - complex float, 5 - complex double\n";
			std::cin >> type;
			flag = true;
			flag1 = true;
			if (type == 1) {
				Line<int> line = CreatingRecTrapezoid<int>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;

			}
			if (type == 2) {
				Line<float> line = CreatingRecTrapezoid<float>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			if (type == 3) {
				Line<double> line = CreatingRecTrapezoid<double>(flag);
				while (flag1)
					flag1 = JobWithLine(flag, flag1, choice, line);
				break;
			}
			else if (type == 4) {
				Complex<float> line = CreatingRecTrapezoidC<float>(flag);
				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, line);
				break;
			}

			else if (type == 5) {
				Complex<double> line = CreatingRecTrapezoidC<double>(flag);
				while (flag1)
					flag1 = JobWithLineC(flag, flag1, choice, line);
				break;

			}

		}
		case 3:
		{
			return 0;
		}
		default:
			try {
				if (choice != 1 && choice != 2) throw "!There is no such option!";
			}
			catch (const char* ex)
			{
				std::cout << ex << endl;
				std::cout << endl << "Try again" << endl;
			}
			break;
		}
	}
}
template class Complex <float>;
template class Complex<double>;
template class Line <int>;
template class Line<float>;
template class Line<double>;