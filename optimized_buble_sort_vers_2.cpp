#include<iostream>

using namespace std;
void print_arr(double* arr, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}




//O(n^2 - n)
void buble_sort(double* arr, const int N)
{
	int iterations = 0;
	int changes = 0;

	for (int i = 0; i < N; i++)
	{
		

		for (int j = 0; j < N-1 ; j++)

		{
			iterations++;
			double tmp = arr[j];
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				changes++;

			}

		}		
	}
	cout << "iter = " << iterations << "  changes = " << changes << endl;
}

//
//O((n^2 -n)/2)
void buble_sort_optimized(double* arr, const int N)
{
	int iterations = 0;
	int changes = 0;

	for (int i = 0; i < N; i++)
	{

		for (int j = 0; j < N -1 - i; j++)

		{
			iterations++;
			double tmp = arr[j];
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				changes++;

			}

		}

	}

	cout << "iter = " << iterations << "  changes = " << changes << endl;
}


int main(int argc, char argv[])
{
	setlocale(LC_ALL, "ru");
	const int SIZE = 7;

	double arr[SIZE]{ 5.4, 12.6, 23.2, 11.23, 8.2, 18, 3 };
	cout << "before sort\n";
	print_arr(arr, SIZE);

	//buble_sort(arr, SIZE);
	buble_sort_optimized(arr, SIZE);

	cout << "after sort\n";
	print_arr(arr, SIZE);
		
	return 0;
}

