#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

/*
* HW_8_3
* Определить наскольло качественно работает генератор случайных чисел.
* Для этого создайте массив на 10000 элементов типа int. Заполнить его случайными
* числами от 1 до 20. после этого подсчитать сколько раз встречается каждое
* из чисел. Если количество каждого из чисел отличается несущественно ,
* то генератор работает правильно.
* Для того, чтобы сделать реализацию маштабируемой, желательно не использовать
* 20 проверок по одной для каждого числа.
	*/



void init_arr(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 20 + 1;
	}

}

void print_arr(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';

}





int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	unsigned const  long N{ 10000};


	//int arr[N]{ }; // выводит предупреждение
	/*
	Severity	Code	Description	Project	File	Line	Suppression State
Warning	C6262	Function uses '40016' bytes of stack:  exceeds /analyze:stacksize '16384'.  Consider moving some data to heap.	FP_urok_08	C:\Users\bells\source\repos\FP_urok_08\FP_urok_08\Source.cpp	43	

	*/
	int * arr = new int[N] { };
	

	init_arr(arr, N);
	//print_arr(arr, N);


	for (int i = 1; i <= 20; i++)
	{
		int count{ 0 };
		for (int j = 0; j < N; j++)
		{
			if (arr[j] == i)
				count++;


		}
		cout << i << " =  " << count << endl;



	}
	//delete[] arr;




	//return 0;
}

