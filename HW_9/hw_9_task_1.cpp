#include<iostream>
using namespace std;
# define PI 3.14159 

//const  double PI = 3.141592653589793;

double circle_area_calculate(double r)
{
	return  PI *pow(r, 2);
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 1. Написать функцию, которая будет вычислять площадь круга.\n"
		"В качестве параметра функция должна принимать радиус,\n"
		"возвращать значение площади типа double.\n";
	double radius = 0;
	cout << "===================================\n\n";
	cout << "Enter radius of circle\n";
	cin >> radius;
	cout << "circle_area = " << circle_area_calculate(radius) << "\n";
		
	


	return 0;
}

