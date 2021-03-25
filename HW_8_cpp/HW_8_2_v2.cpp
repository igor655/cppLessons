#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

/*
* HW_8_2
* Создать массив на N элементов заполнить его случайными числами
в диапазоне от 1 до 1000. Определить и вывести на экран все простые числа,
которые есть в массиве и их количество.
	*/
void print_arr(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n' << '\n';
}

void init_arr(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 1000 + 1;
	}

}

void print_simples(int arr[], int N)
{
	int simple_count = 0;

	for (int i = 0; i < N; i++)
	{
		bool is_simple = true;

		for (int j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				is_simple = false;
			}
		}
		if (is_simple == true)
		{
			cout << arr[i] << setw(4) << " число простое" << endl;
			simple_count++;
		}
	}
	cout << setw(4) << "\nв массиве " << simple_count << " простых чисел \n";

}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int N{30};
	int arr[N]{ };
	
	init_arr(arr, N);	
	print_arr(arr, N);
	print_simples(arr, N);
	
	return 0;
}

