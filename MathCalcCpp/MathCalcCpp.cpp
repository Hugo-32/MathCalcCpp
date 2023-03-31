//
//  MathCalcCpp.cpp
//  Васильев Артём
//

#include <iostream>
#include <locale>
#include "theoryFunctions.h"
#include "combinatorics.h"
#include "polynomial_calculator.h"
#include "matrix.h"
#include "drobs.h"
#include "Function.h"

using namespace std;

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Rus");
	int choice;

	do
	{
		cout << "1. Матричный калькулятор" << endl;
		cout << "2. Калькулятор формул комбинаторики" << endl;
		cout << "3. Калькулятор многочленов" << endl;
		cout << "4. Калькулятор теории вероятности и математическая статистика" << endl;
		cout << "5. Калькулятор обыкновенных дробей" << endl;
		cout << "6. Работа с функциями" << endl;
		cout << "0. Выход из программы" << endl;
		cout << endl;
		cout << "Выберите пункт меню: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			matrixMenu();
			break;
		case 2:
			menuComb();
			break;
		case 3:
			menuPolynomial();
			break;
		case 4:
			menuProbability();
			break;
		case 5:
			menuDrobs();
			break;
		case 6:
			Function();
			break;
		case 0:
			cout << "Выход из программы." << endl;
			break;
		default:
			system("cls");
			cout << "Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl << endl;
			break;
		}
	} while (choice != 0);
	{
		return 0;
	}
}