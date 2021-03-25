#include<iostream>
#include<ctime>
using namespace std;
/*
Задание 8. Добавить в функцию из задания 7 возможность выбирать
направление сортировки (по возрастанию или по убыванию)
при помощи дополнительного параметра. В качестве возвращаемого
значения функция должна возвращать количество выполненных перемещений элементов.

*/

void fill_arr(int arr[], const int SIZE);
void print_array(int a[], int n);
int buble_sort(int a[], const int S, char direction);
void the_task();
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	const int SIZE = 10;
	//int arr[SIZE]{9, 12, 5, 8, 3};
	int arr[SIZE]{};
	the_task();
	fill_arr(arr, SIZE);
	print_array(arr, SIZE);

	char direction = ' ';
	cout << "To sort array ascending press a : \n";
	cout << "To sort array descending press any other key : \n";
	cin >> direction;

	int change_count = buble_sort(arr, SIZE, direction);

	print_array(arr, SIZE);

	cout << "number of changes = " << change_count << endl;


	return 0;
}
void the_task()
{
	cout << "Задание 8. Добавить в функцию из задания 7 возможность выбирать \n";
	cout << "направление сортировки (по возрастанию или по убыванию)\n";
	cout << "при помощи дополнительного параметра. В качестве возвращаемого \n";
	cout << "значения функция должна возвращать количество выполненных перемещений элементов.\n\n";
}


void fill_arr(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = -20 + rand() % 41;
	}
}
void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//.......................
int buble_sort(int a[], const int S, char direction)
{
	int changes_count = 0;
	int iter_count = 0;
	if (direction == 'a')
	{
		for (int i = 1; i < S; i++)
		{
			int tmp = a[i];
			for (int j = 0; j < S - i; j++)
			{

				if (a[j] > a[j + 1])
				{
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
					changes_count++;
				}
				iter_count++;
			}
		}

	}
	else
	{
		for (int i = 1; i < S; i++)
		{
			int tmp = a[i];
			for (int j = 0; j < S - i; j++)
			{
				if (a[j] < a[j + 1])
				{
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;

					changes_count++;
				}
				iter_count++;
			}
		}


	}
	cout << "number of  iteration is: " << iter_count << endl;

	return changes_count;
	
}
