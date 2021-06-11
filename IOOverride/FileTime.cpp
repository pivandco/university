// FileTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Time
{
public:
	Time(short h = 0, short m = 0) {
		hour = h;
		minute = m;
	}
	void setTime(short h, short m) {
		hour = h;
		minute = m;
	}

	friend istream& operator>>(istream& in, Time& t)
	{
		short hour;
		char sep, median[3];
		in >> hour >> sep >> t.minute >> median;

		if (!strcmp(median, "pm") && hour != 12)
			t.hour = hour + 12;
		else if (!strcmp(median, "am") && hour == 12)
			t.hour = 0;
		else
			t.hour = hour;

		return in;
	}

	friend ostream& operator<<(ostream& out, const Time& t)
	{
		out << setfill('0') << setw(2) << t.hour << ":" << setfill('0') << setw(2) << t.minute;
		return out;
	}

private:
	short hour;
	short minute;
};



int main()
{
	setlocale(LC_ALL, "");
	std::cout << "Полученное из файла время: ";
	ifstream fin("E:\\test\\time.txt");
	Time c1;
	fin >> c1;
	cout << c1 << endl;
	fin.close();
	std::cout << "Заменяем время в файле: ";
	c1.setTime(2, 22);
	ofstream fout("E:\\test\\time.txt");
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
