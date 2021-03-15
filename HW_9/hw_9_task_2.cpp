
#include<iostream>
using namespace std;

double semi_perimeter(double a, double b, double c)
{
	return (a + b + c) / 2;
}

double triangle_area(double a, double b, double c)
{
	double sp = semi_perimeter(a, b, c);

	//проверка на существование треугольника
	if (sp * (sp - a) * (sp - b) * (sp - c) > 0)
	{

		return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
	}
	else
		cout << "такого треугольника не существует\n";
	return sqrt(sp * (sp - a) * (sp - b) * (sp - c));;


}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 2. Написать функцию, которая будет вычислять площадь треугольника по трем известным сторонам.\n";
	cout << "В качестве параметров функция будет принимать длины трех сторон, возвращать значение площади треугольника\n";
	cout << " типа double. Формула для нахождения площади по трем сторонам (формула Герона):\n";
	cout << "Для вычисления полупериметра также используйте отдельную функцию.\n";

	//double a{ 3 }, b{ 4 }, c{5};
	double a, b, c;
	cout << "=====================================================\n\n";
	cout << " Введите длину стороны треугольника: a : \n";
	cin >> a;
	cout << " Введите длины стороны треугольника: b : \n";
	cin >> b;
	cout << " Введите длины стороны треугольника: c : \n";
	cin >> c;
	cout << " Площадь треугольника = " << triangle_area(a, b, c) << endl;

	return 0;
}


