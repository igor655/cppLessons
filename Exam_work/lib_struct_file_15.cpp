#include <iostream>
//#include <string>
//#include <cstdio>
//#include<fstream>
#include<windows.h> // для кирилицы в консоли

// C
//#include<stdio.h>
//#include<stdlib.h>
using namespace std;
//Язык Си с нуля - Урок 37 - Работа с файлом в бинарном режиме

struct Book
{
	char b_name[100];
	char b_author[100];
	char b_genre[100];
	int b_year;
	//size = 304
};

Book* init_book();

void print_one_book(Book* b);
Book* add_book_to_library(Book* library, int& lib_size);
void print_library(Book* library, int lib_size);
void menu();
int read_lib_size_from_file();
Book* read_lib_from_file(int lib_size);
void add_books_to_lib(Book*& library, int& lib_size);
void print_all_books(Book*& library, int& lib_size);
void delete_book_from_lib(Book*& library, int& lib_size);
//Заапись количества введённых книг в файл
void book_count_to_file(int& lib_size);
// запись добавленных книг в файл
void write_lib_to_file(Book* library, int& lib_size);
void book_search(Book* library, int& lib_size);

void find_book_by_name(Book*& library, int& lib_size);
void find_book_by_author(Book*& library, int& lib_size);
void find_book_by_genre(Book*& library, int& n);
void find_book_by_year(Book*& library, int& n);

void edit_book(Book*& library, int& n);


int main()
{
	setlocale(LC_ALL, "Russian");
	menu();


	return 0;
}

Book* init_book()
{
	Book* b = new Book;
	char tmp[100];

	cout << "Enter book name\n";
	cin.getline(tmp, 99);

	strcpy_s(b->b_name, strlen(tmp) + 1, tmp);


	cout << "Enter book author\n";
	cin.getline(tmp, 99);

	strcpy_s(b->b_author, strlen(tmp) + 1, tmp);



	cout << "Enter book genre\n";
	cin.getline(tmp, 49);

	strcpy_s(b->b_genre, strlen(tmp) + 1, tmp);


	cout << "Enter book year\n";
	cin >> b->b_year;

	cin.ignore(1, '\n');


	return b;
}


void print_one_book(Book* b)
{
	printf("book name: %s \nbook author: %s \nbook genre: %s \nbook year: %d\n",
		b->b_name, b->b_author, b->b_genre, b->b_year);

}


Book* add_book_to_library(Book* library, int& lib_size)
{
	Book* tmp_book;

	Book* n_library = new Book[lib_size + 1];

	for (int i = 0; i < lib_size; i++)
	{
		n_library[i] = library[i];

	}

	//library = n_library;

	delete[] library; //??


	tmp_book = init_book();
	n_library[lib_size] = *tmp_book;
	lib_size++;
	return n_library;
}

void print_library(Book* library, int lib_size)
{

	for (int i = 0; i < lib_size; i++)

	{

		cout << "=================================\n";
		cout << "Book: " << i + 1 << endl;
		print_one_book(&library[i]);
	}
	//throw gcnew System::NotImplementedException();
}


//
int read_lib_size_from_file()
{
	FILE* count;
	int lib_size = 0;
	fopen_s(&count, "book_count.txt", "r");
	if (!count)
	{
		cout << "В библиотеке нет ни одной книги\n";
		return 0;
	}
	fscanf_s(count, "%d", &lib_size);
	fclose(count);
	cout << "В библиотеке " << lib_size << " книг." << endl;

	return lib_size;


}


//
void menu()
{
	int lib_size = 0;


	int a = 1; // while вечный цикл пока не нажмешь 0
	Book* library = nullptr;
	lib_size = read_lib_size_from_file(); // чтение количества книг из файла
	library = read_lib_from_file(lib_size); // чтение книг из файла в структкру

	while (a != 0)
	{
		int choice = 0;
		cout << "Для вывода всех книг из библиотеки: 1  \n"; // из файла
		cout << "Для добавления  книг в библиотеку: 2  \n"; // в  массив структур
		cout << "Для удаления книги: 3\n";
		cout << "Для поиска: 4\n";
		cout << "Редактировать книгу: 5\n";
		cout << "Для выхода из программы нажмите 0 .\n";
		cin >> choice;
		cin.ignore(1, '\n');
		switch (choice)
		{
		case 0:
		{
			write_lib_to_file(library, lib_size); // Запись библиотеки в файл перед выходом из программы
			book_count_to_file(lib_size);
			exit(0);

		}

		break;

		case 1:
		{
			print_all_books(library, lib_size);
		}
		break;
		case 2:
		{
			{
				add_books_to_lib(library, lib_size);
				write_lib_to_file(library, lib_size);

			}

		}
		break;

		case 3:
		{
			//system("cls");
			cout << "Удаление книги из библиотеки.\n";
			delete_book_from_lib(library, lib_size);
			write_lib_to_file(library, lib_size);
			book_count_to_file(lib_size); // новое количество книг в файл -1
			//print_library(library, lib_size);
		}
		break;
		case 4:
			//cout << "Реализовать поиск\n";
			book_search(library, lib_size);
			break;

		case 5:
		{
			edit_book(library, lib_size);
			write_lib_to_file(library, lib_size);
			book_count_to_file(lib_size);
		}

		break;
		}
		cout << "Для возврата в меню: 1\n";
		cout << "Для выхода из программы: 0 \n";
		cin >> a;
		//cin.ignore(1, '\n');
	}

}






Book* read_lib_from_file(int lib_size)
{
	//cout << "чтение массива книг из  файла в новую структуру\n \n";
	FILE* f;

	Book* library_n = new Book[lib_size];
	fopen_s(&f, "librari_binary.txt", "rb");
	if (!f)
	{
		cout << "file is not found\n";
		return 0;
	}
	fread(library_n, lib_size, sizeof(*library_n), f);


	fclose(f);

	return library_n;


}


void add_books_to_lib(Book*& library, int& lib_size)
{
	int i{ 1 };
	while (i != 0)
	{
		library = add_book_to_library(library, lib_size); // добавление одной книги в библиотеку
		book_count_to_file(lib_size); // запись количества книг в файл
		cout << "Для продолжения ввода книг: 1 \n";
		cout << "Для возврата в меню: 0 \n";
		cin >> i;
		//cin.ignore(1, '\n');

	}



}

//Заапись количества введённых книг в файл
void book_count_to_file(int& lib_size)
{
	FILE* count;
	fopen_s(&count, "book_count.txt", "w");
	if (!count)
	{
		cout << "error file doesn't exist\n";
		//return 0;
	}
	else
	{
		fprintf(count, "%d", lib_size);
		fclose(count);
	}
}


//
void write_lib_to_file(Book* library, int& lib_size)
{
	FILE* f;
	//запись в файл
	fopen_s(&f, "librari_binary.txt", "wb");
	if (!f)
	{
		cout << "file is not found\n";
		//return 0;
	}
	else
	{
		fwrite(library, lib_size, sizeof(*library), f);
		fclose(f);
	}
}

//
void print_all_books(Book*& library, int& lib_size)
{
	// чтение из файла
	//lib_size = read_lib_size_from_file(); // чтение количества книг из файла
	//library = read_lib_from_file(lib_size); // чтение книг из файла в структкру
	// 
	//cout << "Вывод на экран новой структуры\n";
	print_library(library, lib_size); // выод структуры на экран
	cout << "lib_size  = " << lib_size << endl; // вывод количества книг
	cout << "______________________________\n";

}

void delete_book_from_lib(Book*& library, int& lib_size)
{
	system("cls");
	cout << "Реализовать удаление одной книги\n";
	print_all_books(library, lib_size);
	cout << "Введите номер книги для удаления\n";
	cout << "Для отмены и возврата в меню: 0\n";
	int n_del{ 0 }; // номер удаляемой книги
	cin >> n_del; // 
	cin.ignore(1, '\n');
	//создать новый массив на 1 меньше
	Book* less_lib = new Book[lib_size - 1];
	// копируем все до удаляемой книги
	// n_del-1 = индекс удаляемой книги
	if (n_del <= lib_size && n_del > 0)// проверка. для того чтобы VS не выводила предупреждение 
	{
		for (int i = 0; i < n_del - 1; i++)
		{
			less_lib[i] = library[i];
		}
		//копируем после удаляемой книги
		for (int i = n_del; i < lib_size; i++)
		{
			less_lib[i - 1] = library[i];
		}
		library = less_lib;
		lib_size--;
	}
	else
	{
		cout << "Такого номера книги нет в библиотеке\n";
	}
}

//
void book_search(Book* library, int& lib_size)
{
	cout << "Реализовать поиск\n";
	cout << "Выберите критерий поиска.\n";
	cout << "По названию: 1\n";
	cout << "По автору: 2\n";
	cout << "По жанру: 3\n";
	cout << "По году: 4\n";
	cout << "Возврат в меню: 0\n";

	int choice{ 0 };
	cin >> choice;
	cin.ignore(1, '\n');
	switch (choice)
	{
	case 1:
		system("cls");
		find_book_by_name(library, lib_size);
		break;
	case 2:
		system("cls");
		find_book_by_author(library, lib_size);
		break;
	case 3:

		system("cls");
		find_book_by_genre(library, lib_size);
		break;
	case 4:
		system("cls");
		find_book_by_year(library, lib_size);
		break;
	}
}

//
void find_book_by_name(Book*& library, int& lib_size)
{
	bool is_book_found = false;
	cout << "=====================================\n";
	cout << "Введите назваание книги: \n";
	char tmp[100];
	cin.getline(tmp, 99);

	for (int i = 0; i < lib_size; i++)
	{
		if (strcmp(library[i].b_name, tmp) == 0)
		{
			cout << "=====================================\n";
			is_book_found = true;
			//system("cls");
			cout << "Book number is: " << i + 1 << endl;
			print_one_book(&library[i]);
		}
	}
	if (!is_book_found)
	{
		system("cls");
		cout << "Книга не найдена.\n";
	}
}

void find_book_by_author(Book*& library, int& lib_size)
{
	bool is_book_found = false;
	cout << "=====================================\n";
	cout << "Введите автора книги: \n";
	char tmp[100];
	cin.getline(tmp, 99);

	for (int i = 0; i < lib_size; i++)
	{
		if (strcmp(library[i].b_author, tmp) == 0)
		{
			cout << "=====================================\n";
			is_book_found = true;
			//system("cls");
			cout << "Book number is: " << i + 1 << endl;
			print_one_book(&library[i]);



		}

	}
	if (!is_book_found)
	{

		system("cls");
		cout << "Книга не найдена.\n";

	}
}

//
void find_book_by_genre(Book*& library, int& n)
{
	bool is_book_found = false;
	cout << "=====================================\n";
	cout << "Введите жанр книги: \n";
	char tmp[100];
	cin.getline(tmp, 99);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(library[i].b_genre, tmp) == 0)
		{
			cout << "=====================================\n";
			is_book_found = true;

			cout << "Book number is: " << i + 1 << endl;
			print_one_book(&library[i]);
		}

	}
	if (!is_book_found)
	{
		system("cls");
		cout << "Книга не найдена.\n";
	}
}

//
void find_book_by_year(Book*& library, int& n)
{
	bool is_book_found = false;
	cout << "=====================================\n";
	cout << "Введите год книги: \n";
	int tmp{ 0 };
	cin >> tmp;
	cin.ignore(1, '\n');

	for (int i = 0; i < n; i++)
	{
		if (library[i].b_year == tmp)
		{
			cout << "=====================================\n";
			is_book_found = true;
			cout << "Book number is: " << i + 1 << endl;
			print_one_book(&library[i]);
		}


	}
	if (!is_book_found)
	{

		cout << "Книга не найдена.\n";

	}


}

//edit
void edit_book(Book*& library, int& n)
{
	cout << "Редактирование книги \n";
	cout << "Для отмены и возврата в предыдущее меню: 0\n";
	cout << "Для продолжения: 1\n";
		int cancel = 1;
		cin >> cancel;
		if(cancel == 0 )
		{
			return;
		}
	bool is_continue = true;
	while (is_continue)
	{
		system("cls");
		//cout << "Редактирование книги \n";
		print_library(library, n);

		int book_index{ 0 };
		cout << "Выберите книгу для редактирования : \n";
		



		cin >> book_index; //номер книги
		cin.ignore(1, '\n');
		book_index--;// индекс книги в массиве
		//если пользователь введет неправильный номер книги
		//программа выведет сообщение о некоректном вводе.
		if (book_index >= 1 && book_index <= n)
		{
			char* temp = new char[100];

			cout << "Введите название книги:" << endl; // название книги 
			cin.getline(temp, 99);
			strcpy_s(library[book_index].b_name, strlen(temp) + 1, temp);

			cout << "Введите автора книги :" << endl; // автор книги
			cin.getline(temp, 99);
			strcpy_s(library[book_index].b_author, strlen(temp) + 1, temp);

			cout << "Введите  жанр книги:" << endl; //  год
			cin.getline(temp, 99);
			strcpy_s(library[book_index].b_genre, strlen(temp) + 1, temp);

			cout << "Введите  год книги:" << endl; //  год
			cin >> library[book_index].b_year;
			cin.ignore(1, '\n');

			delete[] temp;
			temp = nullptr;
		}
		else
		{
			// book_index + 1 =  номер редактируемой книги
			cout << "Книги под номером " << book_index + 1 << " Нет в библиотеке.\n";
			cout << "Вернться в предыдущее меню: 0 \n";
			cout << "Ввести номер редактируемой книги ещё раз: 1\n";
			cin >> is_continue;
		}
		

	}

	//
	
}

/* Список книг
The Outsiders – S.E. Hinton 1967
 The House On Mango Street – Sandra Cisneros 1984
 Peter Pan – J.M. Barrie 1911
 Number the Stars – Lois Lowry
A Wrinkle In Time – Madeline L’engle
Blue Moon Beach Sue Murray story 2006

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
  Middlemarch by George Eliot (1871-2)*/




