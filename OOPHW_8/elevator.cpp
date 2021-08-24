//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctime>

using namespace std;

/*
* 1. Создать класс «Лифт», представляющий собой пре-
дельно упрощенную модель лифта. Класс должен
обеспечить:
	 установку диапазона движения лифта (нижний
иверхний этаж);
	 включение / выключение лифта;
	возвращение текущего состояния лифта (работа-
ет / не работает);
	возвращение текущего положения лифта (этаж);
 обработку вызова лифта (этаж).
	Написать программу, тестирующую класс «Лифт».
*/


class Elevator
{
	short top_floor{0};
	short lower_floor{0};
	short current_floor{0};
	bool is_on{ false };

	void moov_elevator()
	{
		if (get_is_on())
		{
			cout << "elevator is turned on!!!!!!!\n";
			cout << "Выберите этаж: \n";
			short floor{ 1 };
			cin >> floor;

			if (floor >= lower_floor && floor <= top_floor)
			{
				current_floor = floor;
				cout << "Вы приехали на " << current_floor << " этаж" << endl;
			}
			else
			{
				cout << "В доме нет " << floor << " этажа\n";
			}


		}
		else
		{
			cout << "elevator is turned off!!!!!!!\n";
		}

	}
public:
	Elevator(short top_floor, short lower_floor) : top_floor{ top_floor }, lower_floor{ lower_floor }
	{
		current_floor = 0;
	}

	Elevator(){}
	

	
	void set_is_on(bool is_on)
	{
		this->is_on = is_on;

	}

	bool get_is_on()
	{
		return is_on;
	}

	void set_current_floor(short current_floor)
	{
		this->current_floor = current_floor;
	}
	short get_current_floor()
	{
		return  current_floor;
	}

	void elevator_position()
	{
		cout << "Лифт находится на " << current_floor << " Этаже" << endl;
	}

	void elevator_init()
	{

		cout << "Введите нижний этаж\n";
		cin >> lower_floor;
		cout << "Введите количество этажей в доме\n";
		cin >> top_floor;
		

		if (lower_floor >= top_floor) // если нижний этаж выше верхнего выход из программы
		{
			cout << "Неправильный ввод\n";
			cout << "Exit programm\n";
			exit(0);
		}
		cout << "в доме " << top_floor << " этажей\n";
		
		//лифт находится на случайном этаже в диапазоне от lower_floor до top_floor включительно
		current_floor = lower_floor + rand()% (top_floor -1);

	}

	void use_elevator()
	{
		short on{ 0 };
		cout << "Включить лифт : 1 , Выключить лифт : 0 или любая клавиша " << endl;
		cin >> on;
		/*
		если ввод: 1 лифт включен
		любой другой ввод:  лифт ыключен
		*/
		if (on == 1)
		{
			is_on = true;

		}
		
		moov_elevator(); // приватный метод

	}

};

void start_programm()
{
	Elevator elevator{ 2, 11 };
	elevator.elevator_init();

	elevator.elevator_position();

	elevator.use_elevator();
	elevator.elevator_position();

}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	start_programm();

	/*Elevator elevator{2, 11};
	elevator.elevator_init();

	elevator.elevator_position();

	elevator.use_elevator();
	elevator.elevator_position();*/

	//cout << 2 + rand() % (4-1) << endl; // 2 to 4 включительно

	return 0;
}