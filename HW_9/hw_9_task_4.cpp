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
	//проверка на существование треугольника
	if (sp * (sp - a) * (sp - b) * (sp - c) > 0)
	{

		return sqrt(sp * (sp - a) * (sp - b) * (sp - c));
	}
	else
		cout << "такого треугольника не существует\n";
	return sqrt(sp * (sp - a) * (sp - b) * (sp - c));;
	


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

int figure_choice()
{
	int choice{ 0 };
	cout << "=======================================================\n\n";
	cout << "Выберите фигуру: Круг 1, треугольник 2, прямоугольник 3\n";
	cout << "Для выхода из программы нажмите любую другую клавишу\n";
	cin >> choice;
	return choice;
}
	
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 4. Изменить задание 3 таким образом, чтобы вывод меню для выбора  \n";
	cout << "фигуры и ввод варианта пользователя выполнялся в функции. \n";
	cout << "Функция не принимает параметров и возвращает выбор пользователя в виде целого числа.\n";


int choice = figure_choice();
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
		cout << "Program finished!!!!\n";
		break;
	}
	
		
	return 0;
}


