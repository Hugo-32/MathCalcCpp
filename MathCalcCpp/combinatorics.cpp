#include <iostream>
#include <locale>
#include "combinatorics.h"

using namespace std;

void menuComb() { // Авдеенко
    setlocale(LC_ALL, "RUS");
    int choice;

    do {
        cout << "Введите номер фнукции, которую хотите использовать" << endl;
        cout << "1. Размещение с повторениями" << endl;
        cout << "2. Размещение без повторений" << endl;
        cout << "3. Сочетание с повторениями" << endl;
        cout << "4. Сочетание без повторений" << endl;
        cout << "5. Перестановки" << endl;
        cout << "0. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            PermutationWithRep();
            break;
        }
        case 2: {
            PermutationmWithoutRep();
            break;
        }
        case 3: {
            CombinationWithRep();
            break;
        }
        case 4: {
            CombinationWithoutRep();
            break;
        }
        case 5: {
            RepeatedCombination();
            break;
        }
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный ввод. Попробуйте ещё раз" << endl;
            break;
        }
    } while (choice != 0);
}

void PermutationWithRep() {
    cout << "Размещение с повторениями\n" << endl; // Авдеенко
}

void PermutationmWithoutRep() {
    cout << "Размещение без повторений\n" << endl; // Авдеенко
}

void CombinationWithRep() {
    cout << "Сочетание с повтрениями\n" << endl; // Авдеенко
}

void CombinationWithoutRep() {
    cout << "Сочетание без повтрений\n" << endl; // Авдеенко
}

void RepeatedCombination() {
    cout << "Перестановки\n" << endl; // Авдеенко
}