#include<iostream>
using namespace std;
# define PI 3.14159 

double circle_area_calculate()
{
	double radius = 0;
	cout << "===================================\n\n";
	cout << "Enter radius of circle\n";
	cin >> radius;
	cout << "Площадь круга = " << PI * pow(radius, 2) << endl;
	return  PI * pow(radius, 2);
}

double semi_perimeter(double a, double b, double c)
{
	return (a + b + c) / 2;
}

double triangle_area()
{
	double a,  b,  c;
	cout << "Введите сторону a: \n";
	cin >> a;
	cout << "Введите сторону b: \n";
	cin >> b;
	cout << "Введите сторону c: \n";
	cin >> c;
	double sp = semi_perimeter(a, b, c);
	cout << "Площадь треугольника  = " << sqrt(sp * (sp - a) * (sp - b) * (sp - c)) << endl;
	return sqrt(sp*(sp - a) * (sp - b) * (sp - c));
}
void rectangle_area()
{
	double lenght, width;
	cout << "Введите длину прямоугольника : ";
	cin >> lenght;
	cout << "Введите ширину прямоугольника : ";
	cin >> width;
	cout << "Плошадь прямоугольника = " << lenght * width << endl;
}
	
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 3. Написать программу, которая будет предлагать пользователю выбрать фигуру, \n";
	cout << "Для вычисления площадей использовать функции, в том числе те, которые были написаны для заданий 1 и 2.\n";
	cout << "Предусмотреть возможность вычисления площади круга, треугольника и прямоугольника\n";

	//double a{ 3 }, b{ 4 }, c{5};
	int choice{ 0 };
	cout << "=======================================================\n\n";
	cout << "Выберите фигуру: Круг 1, треугольник 2, прямоугольник 3\n ";

	cin >> choice;
	switch (choice)	
	{
	case  1:
		circle_area_calculate();		
		break;
	
	case  2:
		triangle_area();
		break;

	case 3:
		rectangle_area();
		break;

	default:
		break;
	}
		
	return 0;
}


