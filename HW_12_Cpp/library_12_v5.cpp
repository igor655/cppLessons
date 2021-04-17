

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


void printBook(char** book)
{
	cout << "Name  : " << book[0] << endl;
	cout << "Author: " << book[1] << endl;
	cout << "Year : " << book[2] << endl;
	cout << "****************************\n";
}

void printBooks(char*** books, int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "book " << i + 1 << endl;;
		printBook(books[i]);
	}
}

//void remoove_book_from_lib(char*** books, int& n, int& book_index)
void remoove_book_from_lib(char*** books, int& n)
{
	cout << " remoove book from library\n";
	int book_index{0};
	printBooks(books, n);

	cout << "Enter number of book You want to remove from library: \n";
	cin >> book_index; // номер книги в библионеке
	cin.ignore(1, '\n');
	book_index--;  // индекс книги в массиве



	//создаем массив книг на 1 меньше
	char*** less_books = new char** [n-1];
	// копируем со старого массива в новый все до удаляемой книги
	for (int i = 0; i < book_index; i++)
	{
		less_books[i] = books[i];
	}
	// копируем со старого массива в новый все после удаляемой книги
	for (int i = book_index+1; i < n; i++)
	{
		less_books[i-1] = books[i];
	}
	books = less_books;
	n--;
	//printBooks(less_books, n);
	printBooks(books, n);
	delete[] less_books;
	
}

// заполняем поля книги 
void fill_in_book(char*** books, int& n, int& fld)
{
	char* temp = new char[40];
	cout << "Введите название книги: " << endl;
	cin.getline(temp, 39);

	books[n][0] = new char[strlen(temp) + 1]; // название книги 
	strcpy_s(books[n][0], strlen(temp) + 1, temp);


	cout << "Введите автора книги : " << endl;
	cin.getline(temp, 39);

	books[n][1] = new char[strlen(temp) + 1]; // автор книги
	strcpy_s(books[n][1], strlen(temp) + 1, temp);

	cout << " Введите  год книги: " << endl;
	cin.getline(temp, 39);

	books[n][2] = new char[strlen(temp) + 1]; //  год
	strcpy_s(books[n][2], strlen(temp) + 1, temp);

	delete[] temp;
	temp = nullptr;

}
//добавляем новую пустую книгу в массив книг
void add_empty_book(char*** books, int& n, int& fields)
{
	// создаем массив на 1 больше
	char*** new_books = new char** [n + 1];
	//копируем из старого массива в новый
	for (int i = 0; i < n; i++)
	{
		new_books[i] = books[i];

	}
	// создаем новую книгу

	new_books[n] = new char* [fields];

	// 4. Удаляем старый массив, увеличиваем значение n 
	n++;
	books = new_books;
	delete[]new_books;


}
// создает новую книгу и заполняет поля
void create_books(int& n, char*** books, int& fld)
{

	books[n] = new char* [fld];
	fill_in_book(books, n, fld);

}
// clean up memory
void delete_books(char*** books, int& n, int& fld)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < fld; j++)
		{
			delete[] books[i][j];

		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] books[i];
	}
	delete[] books;

}
// Edit book press 1
//Delete book press 2
//Add book press 
void submenu(char*** books, int& n, int& fields)
{
	int chs{ 0 }; // choice operation
	cout << " Edit book press 1\n";
	cout << " Delete book press 2\n";
	cout << " Add book press 3\n";
	cin >> chs;
	cin.ignore(1, '\n');
	if (chs == 1)
	{
		cout << "edit book\n";

	}
	else if (chs == 2)
	{
		//cout << " delete book\n";
		//int book_index = 4;
		//remoove_book_from_lib(books, n, book_index);
		remoove_book_from_lib(books, n);
	}
	else if (chs == 3)
	{
		cout << " add book\n";
		create_books(n, books, fields);
		add_empty_book(books, n, fields);
		printBooks(books, n);
	}


}

//preliminarily create and fill 5  books
void fill_books(char*** books, int& f)
{
	books[0] = new char* [3];
	books[1] = new char* [3];
	books[2] = new char* [3];
	books[3] = new char* [3];
	books[4] = new char* [3];
	books[5] = new char* [3];
	//......................................
	/*const char* temp = "The Outsiders";
	books[0][0] = new char[strlen(temp) + 1];
	strcpy_s(books[0][0], strlen(temp) + 1, temp);

	temp = "S.E. Hinton";
	books[0][1] = new char[strlen(temp) + 1];
	strcpy_s(books[0][1], strlen(temp) + 1, temp);

	temp = "1967";
	books[0][2] = new char[strlen(temp) + 1];
	strcpy_s(books[0][2], strlen(temp) + 1, temp);*/

	//..........................
	//0.....................................
	books[0][0] = new char[strlen("The Outsiders") + 1];
	strcpy_s(books[0][0], strlen("The Outsiders") + 1, "The Outsiders");


	books[0][1] = new char[strlen("S.E. Hinton") + 1];
	strcpy_s(books[0][1], strlen("S.E. Hinton") + 1, "S.E. Hinton");

	books[0][2] = new char[strlen("1967") + 1];
	strcpy_s(books[0][2], strlen("1967") + 1, "1967");
	//Severity	Code	Description	Project	File	Line	Suppression State
	//Warning	C6386	Buffer overrun while writing to 'books[0]':  the writable size is 'f*4' bytes, but '8' bytes might be written.FP_Lessons	C : \Users\bells\source\repos\FP_Lessons\FP_Lessons\hw_9.cpp	105

	////1................................................
	books[1][0] = new char[strlen("Robinson Crusoe") + 1];
	strcpy_s(books[1][0], strlen("Robinson Crusoe") + 1, "Robinson Crusoe");

	books[1][1] = new char[strlen("Daniel Defoe") + 1];
	strcpy_s(books[1][1], strlen("Daniel Defoe") + 1, "Daniel Defoe");

	books[1][2] = new char[strlen("1719") + 1];
	strcpy_s(books[1][2], strlen("1719") + 1, "1719");
	//2................................................
	books[2][0] = new char[strlen("The House On Mango Street") + 1];
	strcpy_s(books[2][0], strlen("The House On Mango Street") + 1, "The House On Mango Street");

	books[2][1] = new char[strlen("Sandra Cisneros") + 1];
	strcpy_s(books[2][1], strlen("Sandra Cisneros") + 1, "Sandra Cisneros");

	books[2][2] = new char[strlen("1984") + 1];
	strcpy_s(books[2][2], strlen("1984") + 1, "1984");
	//3................................................
	books[3][0] = new char[strlen("Peter Pan") + 1];
	strcpy_s(books[3][0], strlen("Peter Pan") + 1, "Peter Pan");

	books[3][1] = new char[strlen("J.M. Barrie") + 1];
	strcpy_s(books[3][1], strlen("J.M. Barrie") + 1, "J.M. Barrie");

	books[3][2] = new char[strlen("1911") + 1];
	strcpy_s(books[3][2], strlen("1911") + 1, "1911");

	//4...........................................
	books[4][0] = new char[strlen("David Copperfield") + 1];
	strcpy_s(books[4][0], strlen("David Copperfield") + 1, "David Copperfield");

	books[4][1] = new char[strlen("Charles Dickens") + 1];
	strcpy_s(books[4][1], strlen("Charles Dickens") + 1, "Charles Dickens");

	books[4][2] = new char[strlen("1850") + 1];
	strcpy_s(books[4][2], strlen("1850") + 1, "1850");

	//5...........................................
	books[5][0] = new char[strlen("David Copperfield") + 1];
	strcpy_s(books[5][0], strlen("David Copperfield") + 1, "David Copperfield");

	books[5][1] = new char[strlen("Charles Dickens") + 1];
	strcpy_s(books[5][1], strlen("Charles Dickens") + 1, "Charles Dickens");

	books[5][2] = new char[strlen("1850") + 1];
	strcpy_s(books[5][2], strlen("1850") + 1, "1850");

}
void search_by_name(char*** books, int& n, int& fields)
{
	bool is_book_in_lib = false;
	cout << "Enter name of book\n";
	char* book_name = new char[80];
	cin.getline(book_name, 79);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < fields; j++)
		{
			if (strcmp(books[i][j], book_name) == 0)
			{
				printBook(books[i]);
				

				is_book_in_lib = true;
			}


		}



	}
	if (!is_book_in_lib)
	{
		cout << "Book is not found\n";
	}
	else
	{

		submenu(books, n, fields);

	}


}
void search_by_author(char*** books, int& n, int& fields)
{
	bool is_book_in_lib = false;
	cout << "Enter author of book\n";
	char* book_author = new char[80];
	cin.getline(book_author, 79);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < fields; j++)
		{
			if (strcmp(books[i][j], book_author) == 0)
			{
				printBook(books[i]);
		
				is_book_in_lib = true;
			}


		}



	}
	if (!is_book_in_lib)
	{
		cout << "Book is not found\n";
	}
	else
	{

		submenu(books, n, fields);

	}


}

void search_by_year(char*** books, int& n, int& fields)
{
	bool is_book_in_lib = false;
	cout << "Enter year of book\n";
	char* book_year = new char[80];
	cin.getline(book_year, 79);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < fields; j++)
		{
			if (strcmp(books[i][j], book_year) == 0)
			{
				printBook(books[i]);
			
				is_book_in_lib = true;
			}


		}



	}
	if (!is_book_in_lib)
	{
		cout << "Book is not found\n";
		cout << "Книга не найдена!!!\n";
	}
	else
	{

		submenu(books, n, fields);

	}


}

void menu(char*** books, int& n, int& fields)
{
	cout << "Выберите критерй поиска:\n";
	cout << "1: По названию книги\n";
	cout << "2: По автору книги\n";
	cout << "3: По году издания\n";
	int choice{ 0 };
	cin >> choice;
	cin.ignore(1, '\n');

	switch (choice)
	{
	case 1:
		search_by_name(books, n, fields);
		break;
	case 2:
		search_by_author(books, n, fields);
		break;
	case 3:
		search_by_year(books, n, fields);
		break;

	default:
		cout << "Книга не найдена!!!\n";

	}

}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 6;  // количество книг в библиотеке	
	int fields = 3; // количество полей описания книги

	char*** books = new char** [n];  // Создаем библиотеку с n книг
	fill_books(books, fields);  // заполняем массив книгами хард код

	menu(books, n, fields);
	//printBooks(books, n);
	

	/*menu(books, n, fields);
	printBooks(books, n);*/
	


	//............................................................

	//create_books(n, books, fields);  // Создаём n книг
	//cout << "********************************\n";
	//printBooks(books, n);

	//delete_books(books, n, fields);  // удаление динамического массива
	//books = nullptr;

	return 0;
}

/*
 The Outsiders – S.E. Hinton 1967
  The House On Mango Street – Sandra Cisneros 1984
  Peter Pan – J.M. Barrie 1911
  Number the Stars – Lois Lowry
A Wrinkle In Time – Madeline L’engle
Blue Moon Beach
Sue Murray
Red Dog Louis De Bernieres

Robinson Crusoe by Daniel Defoe (1719)
 Gulliver’s Travels by Jonathan Swift (1726)
  Clarissa by Samuel Richardson (1748)
  Emma by Jane Austen (1816)
  Frankenstein by Mary Shelley (1818)
  Nightmare Abbey by Thomas Love Peacock (1818)
  Sybil by Benjamin Disraeli (1845)

  The Narrative of Arthur Gordon Pym of Nantucket by Edgar Allan Poe (1838)
  Jane Eyre by Charlotte Brontë (1847)
  Wuthering Heights by Emily Brontë (1847)
  David Copperfield by Charles Dickens (1850)
  David Copperfield by Charles Dickens (1850)
  Alice’s Adventures in Wonderland by Lewis Carroll (1865)
  Moby-Dick by Herman Melville (1851)
  The Moonstone by Wilkie Collins (1868)
  Middlemarch by George Eliot (1871-2)



*/
