#include<iostream>
#include<ctime>
using namespace std;


void fill_arr(int arr[], const int SIZE);
void print_array(int* a, int n);
void the_task();
void push_arr(int*& arr, int& size, int value);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	the_task();

	int size = 10;
	int* arr = new int[size] {};
	fill_arr(arr, size);


	print_array(arr, size);
	//.......................................
	push_arr(arr, size, 17);
	print_array(arr, size);
	push_arr(arr, size, 23);
	print_array(arr, size);

	delete[]arr;
	arr = nullptr;

	return 0;
}
void the_task()
{
	cout << "Задание 9. Написать функцию, которая будет в качестве параметров принимать \n";
	cout << "указатель на динамический массив, количество элементов в нем и значение \n";
	cout << "для нового элемента. В результате работы функции переданный массив должен\n";
	cout << "быть увеличен на один элемент, который добавляется в конец массива и \n";
	cout << "заполняется переданным значением. Для проверки правильности работы функции, \n";
	cout << "до и вызова функции добавления элемента в массив, он должен быть распечатан \n";
	cout << "используя функцию распечатки массива из задания 5.\n\n";
}


void fill_arr(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = -20 + rand() % 41;
	}
}
void print_array(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void push_arr(int*& arr, int& size, int value)

{
	int* arr2 = new int[size + 1]{ 0 };
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	arr2[size] = value;
	size++;
	delete[]arr;
	arr = arr2;
}


