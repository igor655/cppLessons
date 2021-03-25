#include<iostream>
#include<ctime>
using namespace std;
/*
Задание 7. Написать функцию bubbleSort, которая
будет принимать в качестве параметров массив и его
размер и сортировать массив по возрастанию, 
используя алгоритм пузырьковой сортировки.

*/

void fill_arr(int arr[], const int SIZE);
void print_array(int a[], int n);
void buble_sort(int a[], const int S);
void the_task();
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	const int SIZE = 10;
	int arr[SIZE]{};
	the_task();
	fill_arr(arr, SIZE);
	print_array(arr, SIZE);
	buble_sort(arr, SIZE);
	print_array(arr, SIZE);
	
	return 0;
}
void the_task()
{
	cout << "Задание 7. Написать функцию bubbleSort, которая\n";
	cout << "будет принимать в качестве параметров массив и его\n";
	cout << "размер и сортировать массив по возрастанию, \n";
	cout << "используя алгоритм пузырьковой сортировки.\n";
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
void buble_sort(int a[], const int S)
{
	for (int i = 1; i < S; i++)
	{
		int tmp = a[i];
		for (int j = 0; j < S - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

			}
		}
	}
}
