// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double U, R, I;
	cout << "Введите значение напряжения (вольт) : ";
	cin >> U;
	cout << "Введите значение сопротивления (Ом) : ";
	cin >> R;
	cout << "Сила тока (ампер) : " << U / R;
	return 0;
}