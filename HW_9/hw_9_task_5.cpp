#include<iostream>
using namespace std;


 template<typename T> void print_aaray(T a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << "\t";

	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Задание 5.  Написать функцию, которая принимает в качестве параметров\n";
	cout << "массив и его размер и выводит полученный массив на экран.\n";

	const int N = 10;
	int m_arr[N]{ 3, 12, 4, 8, 32, 11, 2, 6, 19, 9 };
	float m_arr_1[N]{ 3.3, 12.5, 4.72, 8, 3.2, 11.8, 2.9, 6.2, 19.4, 9 };
	print_aaray(m_arr, N);
	print_aaray(m_arr_1, N);


	


	return 0;
}

