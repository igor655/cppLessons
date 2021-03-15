
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T> void print_aaray(T *a, int N , int direct);

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 6. Предусмотреть в функции из задания 5 дополнительный параметр\n";
	cout << "который позволит пользователю выбрать вариант распечатки массива: в строку\n";
	cout << "или в столбик. Изменить реализацию функции соответственно.\n";
	cout << "Для вывода массива в строку можно использовать манипулятор std::setw из библиотеки iomanip.\n";

	const int N = 10;
	int m_arr[N]{ 3, 12, 4, 8, 32, 11, 2, 6, 19, 9 };
	float m_arr_1[N]{ 3.3, 12.5, 4.72, 8, 3.2, 11.8, 2.9, 6.2, 19.4, 9 };
	cout << "===========================================================\n";
	cout << "Выберите формат вывода массива на экран: 1 в строку, 2 в столбик." << endl;
	int direction{ 0 };
	cin >> direction;

	print_aaray(m_arr, N, direction);
	print_aaray(m_arr_1, N, direction);

	return 0;
}
template<typename T> void print_aaray(T *a, int N, int direct)
{
	if (direct == 1)
	{
		for (int i = 0; i < N; i++)
		{
			cout << a[i] << setw(4) << " ";

		}
		cout << endl;
	}
	else if (direct == 2)
	{
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			cout << a[i] << endl;

		}
	}
}

