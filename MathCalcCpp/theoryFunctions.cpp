//
//  theoryFunctions.cpp
//  Васильев Артём
//

#include <iostream>
#include "theoryFunctions.h"
#include <locale>
#include <cmath>

using namespace std;

void menuProbability()
{
	setlocale(LC_ALL, "Rus");
	const int MAX_SIZE = 1000;
	int arr[MAX_SIZE];
	int n;
	int choice;
	system("cls");
	do
	{
		cout << "Калькулятор теории вероятности и математической статистики: " << endl;
		cout << endl;
		cout << "1. Вычисление вероятности m/n" << endl;
		cout << "2. Расчет дисперсии для дискретного распределения величин" << endl;
		cout << "3. Матиматическое ожидание для дискретного распределения величин" << endl;
		cout << "0. Вернуться назад";
		cout << endl;
		cout << endl << "Выберите пункт меню: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			calculateProbability();
			break;
		case 2:
			cout << endl;
			cout << "Введите размер массива: ";
			cin >> n;
			cout << "Введите элементы, которые буду входить в данный массив" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "Введите элемент " << i+1 << ": ";
				cin >> *(arr + i);
			}
			cout << "Диспрерсия: " << calculateVariance(arr, n) << endl;;
			break;
		case 3:
			cout << endl;
			cout << "Введите размер массива: ";
			cin >> n;
			cout << "Введите элементы, которые буду входить в данный массив: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "Введите элемент " << i + 1 << ": ";
				cin >> *(arr + i);
			}
			cout << "Математическое ожидание: " << calculateMean(arr, n) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl;
			break;
		}
	} while (choice != 0);
	{
		return;
	}
}

void calculateProbability() 
{
	double m, n, p, q;
	cout << endl;
	cout << "Введите значение для m: ";
	cin >> m;
	cout << "Введите значение для n: ";
	cin >> n;
	if (n == 0)
	{
		cout << "Неправильный ввод, n не может быть равным 0. Попробуйте снова!";
		return;
	}
	p = m / n;
	q = 1 - p;
	cout << "Вероятность: " << p << endl;
	cout << "Дополнительная вероятность: " << q << endl;
}
double calculateVariance(int *arr, int n) 
{
	double sum = 0;
	double mean = 0;
	for (int i = 0; i < n; i++)
	{
		mean += *(arr + i);
	}
	mean /= n;
	for (int i = 0; i < n; i++)
	{
		sum += (*(arr + 1) - mean) * (*(arr + 1) - mean);
	}
	double variance = sum / n;
	return variance;
}



double calculateMean(int *arr, int n) 
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += *(arr + i);
	}
	double mean = sum / n;
	return mean;
}