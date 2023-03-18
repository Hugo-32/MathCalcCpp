#include <iostream>
#include "theoryFunctions.h"
#include <locale>

using namespace std;

void menuProbability() // Васильев
{
	setlocale(LC_ALL, "Rus");

	int choice;

	do
	{
		cout << "1. Вычисление вероятности m/n" << endl;
		cout << "2. Расчет дисперсии для дискретного распределения величин" << endl;
		cout << "3. Матиматическое ожидание для дискретного распределения величин" << endl;
		cout << "0. Выход";
		cout << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			calculateProbability();
			break;
		case 2:
			calculateVariance();
			break;
		case 3:
			calculateMean();
			break;
		case 0:
			cout << "Выход из программы." << endl;
			break;
		default:
			cout << "Ошибка: неверный пункт меню." << endl;
			break;
		}
	} while (choice != 0);
	{
		return;
	}
}

void calculateProbability() // Васильев
{
	cout << "Расчет вероятности" << endl;
}
void calculateVariance() // Васильев
{
	cout << "Расчет дисперсии" << endl;
}
void calculateMean() // Васильев
{
	cout << "Расчет математического ожидания" << endl;
}