
#include<iostream>
#include<ctime>
//#include<iomanip>

using namespace std;
// 

/*
	* HW_8_1
	1 создать массив на N элементов, заполнить его случайными числами от 1 до 100.
	* Вывести на экран элемент, предпоследнее четное значение массива и его индекс.
	*

	*/

void fill_arr(int arr[], int size);
void print_arr(int arr[], int size);
void penultimate_even_num(int arr[], int size);


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	const int SIZE = 28;

	int m_arr[SIZE]{ 0 };
	fill_arr(m_arr, SIZE);
	print_arr(m_arr, SIZE);
	//cout << endl;
	penultimate_even_num(m_arr, SIZE);

	return 0;
}

void fill_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 99 + 1;
	}

}
void print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n";

}
//...опрнделение предпоследнего четного значения массива и его индекса..........
void penultimate_even_num(int arr[], int size)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{

		if (arr[i] % 2 == 0)
		{
			index = i;
			int n = index;
			for (int j = 0; j < n; j++)
			{
				if (arr[j] % 2 == 0)
				{
					index = j;
				}
			}
		}
	}

	cout << "предпоследнее четное значение массива: "
		<< arr[index] << "\nindex: " << index << endl;

}
