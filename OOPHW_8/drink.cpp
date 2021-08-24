//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctime>
//#include "stdafx.h"

using namespace std;

/*
* Home  Work OOP 8
* Реализовать Декоратор 
* из классной работы

*/

class Drink
{
	double drink_cost{};
public:
	Drink(){}

	Drink(double drink_cost)
	{
		this->drink_cost = drink_cost;

	}

	 double getDrinkCost()
	{
		return drink_cost;
	}

	 void setDrinkCost(double cost)
	{
		this->drink_cost = cost;
	}


};

class Espreso : public Drink
{
public:
	Espreso(double drink_cost)
	{
		setDrinkCost(drink_cost);

	}

};

class Cola : public Drink
{
public:
	Cola(double drink_cost)
	{
		setDrinkCost(drink_cost);
	}

};

class Tee : public Drink
{
public:
	Tee(double drink_cost)
	{
		setDrinkCost(drink_cost);
	}

};

class Ingredient : public Drink
{
	Drink* d{nullptr};
	double ingredientCost = 0;
	
public:
	Ingredient(){}

	Ingredient(Drink* d, double ingredientCost)
	{
		this->d = d;
		this->ingredientCost = ingredientCost;

	}
	Drink* getDrink()
	{
		return d;
	}

	void setDrink(Drink* drink)
	{
		d = drink;

	}

	
	void setIngredientCost(double ingredientCost)
	{
		this->ingredientCost = ingredientCost;
		
	}

	 double getIngredientCost()
	{
		return ingredientCost;
	}
	
};

class Cream : public Ingredient
{
public:
	Cream(Drink* drink, double ingredientCost)
	{
		setDrink(getDrink());
		setIngredientCost(ingredientCost);
	}

};

class Camel : public Ingredient
{

public:

	Camel(Drink* drink, double ingredientCost)
	{
		setDrink(getDrink());
		setIngredientCost(ingredientCost);
	}

};


class Marshmallow : public Ingredient
{

public:
	Marshmallow(Drink* drink, double ingredientCost)
	{
		setDrink(getDrink());
		setIngredientCost(ingredientCost);
	}

};


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	Drink* espreso = new Espreso(5.99);
	Ingredient* cream = new Cream(espreso, 0.8);
	Ingredient* camel = new Camel(espreso, 0.50);
	Ingredient* marshmallow = new Camel(espreso, 1.3);
	


	cout << "Drink cost: " << espreso->getDrinkCost() << endl;
	cout << "Cream cost: " <<  cream->getIngredientCost() << endl;
	cout << "Camel cost: " <<  camel->getIngredientCost() << endl;
	cout << "Marshmallow cost: " << marshmallow->getIngredientCost() << endl;
	
	// espresso + cream + camel + marshmallow ;
	cout << "Total Drink + Cream + camel + marshmallow  cost is: "  << cream->getIngredientCost() +
	camel->getIngredientCost()+ marshmallow->getIngredientCost() + espreso->getDrinkCost() << endl;


	cout << " \nИли________________________________________________ \n";
	//
	cream->setDrink(new Tee(1.5)); // молоко с чаем!!!
	cream->setIngredientCost(0.24);
	
	
	cout << "чай =  " << cream->getDrink()->getDrinkCost() << endl;
	cout << "Молоко = " <<  cream->getIngredientCost() << endl;
	cout << "молоко с чаем " << cream->getDrink()->getDrinkCost() + cream->getIngredientCost()
		<< endl;
	
	return 0;
}
