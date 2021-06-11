// ComplexFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0, double i = 0) {
		real = r;
		image = i;
	}
	void setComplex(double r, double i) {
		real = r;
		image = i;
	}

	friend istream& operator>>(istream& in, Complex& c)
	{
		in >> c.real >> c.image;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Complex& c)
	{
		out << c.real << showpos << c.image << noshowpos << "i";
		return out;
	}

private:
	double real;
	double image;
};



int main()
{
	ifstream fin("C:\\Users\\1\\test.txt");
	Complex c1;
	fin >> c1;
	cout << c1 << endl;
	fin.close();
	c1.setComplex(5, 2);
	ofstream fout("C:\\Users\\1\\test.txt");
	fout << c1;
	fout.close();
	cout << c1 << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
