//
//  polynomial_calculator.cpp
//  Меркулов Николай
//

#include <iostream>
#include "polynomial_calculator.h"
#include <locale>

using namespace std;

void div_polynominals() // деление многочленов в столбик 
{}
void add_polynominals() // сложение многочленов 
{}
void subtract_polynominals() // вычитание многочленов 
{}
void multiply_polynominals() // умножение многочленов 
{}
void multiply_polynominals_by_num() // умножение многочлена на число 
{}
void calculate_derivative() // вычисление производной от многочлена 
{}

void menuPolinom() // Меркулов
{
    setlocale(LC_ALL, "Russian");
    int n;
    do {
        cout << "Калькулятор многочленов\n";
        cout << "---------------------\n";
        cout << "1. Деление многочленов в столбик\n";
        cout << "2. Сложение многочленов\n";
        cout << "3. Вычитание многочленов\n";
        cout << "4. Умножение многочленов\n";
        cout << "5. Умножение многочлена на число\n";
        cout << "6. Вычисление производной от многочлена\n";
        cout << "0. Выход в главное меню\n";
        cout << "---------------------\n";
        cout << "Выберите режим (1-6) ИЛИ 0, чтобы выйти в главное меню: "; cin >> n;
        switch (n)
        {
        case 0: break;
        case 1: div_polynominals(); break;
        case 2: add_polynominals(); break;
        case 3: subtract_polynominals(); break;
        case 4: multiply_polynominals_by_num(); break;
        case 5: multiply_polynominals_by_num(); break;
        case 6: calculate_derivative(); break;
        }
    } while (n != 0);
}