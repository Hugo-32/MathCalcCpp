//
//  combinatorics.cpp
//  Авдеенко Илья
//

#include <iostream>
#include <locale>
#include "combinatorics.h"

using namespace std;

long long PermutationWithRep(int n, int k) { 
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= n;
    }
    return result;
}

long long PermutationWithoutRep(int n, int k) { 
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
    }
    return result;
}

long long CombinationWithRep(int n, int k) { 
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= (n + i - 1);
        result /= i;
    }
    return result;
}

long long CombinationWithoutRep(int n, int k) { 
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= (n - k + i);
        result /= i;
    }
    return result;
}

long long RepeatedCombination(int n) { 
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void menuComb() { 
    setlocale(LC_ALL, "RUS");
    int choice, n, k;
    system("cls");
    do {
        cout << "Введите номер фнукции, которую хотите использовать" << endl;
        cout << "1. Размещение с повторениями" << endl;
        cout << "2. Размещение без повторений" << endl;
        cout << "3. Сочетание с повторениями" << endl;
        cout << "4. Сочетание без повторений" << endl;
        cout << "5. Перестановки" << endl;
        cout << "0. Выход в главное меню";
        cout << endl;
        cout << endl << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            do {
                cout << "Введите количество элементов, из которых мы выбираем: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Ошибка: количество элементов должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "Введите количество элементов в каждом размещении: ";
                cin >> k;
                if (k <= 0) {
                    cout << "Ошибка: количество элементов в каждом размещении должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (k <= 0);

            cout << "Количество размещений с повторениями: " << PermutationWithRep(n, k) << endl << endl;
            break;
        }
        case 2: {
            system("cls");
            do {
                cout << "Введите количество элементов, из которых мы выбираем: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Ошибка: количество элементов должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "Введите количество элементов в каждом размещении: ";
                cin >> k;
                if (k <= 0 || k > n) {
                    cout << "Ошибка: количество элементов в каждом размещении должно быть положительным числом и не больше, чем общее количество элементов. Попробуйте ещё раз!" << endl << endl;
                }
            } while (k <= 0 || k > n);

            cout << "Количество размещений без повторений: " << PermutationWithoutRep(n, k) << endl << endl;
            break;
        }
        case 3: {
            system("cls");
            do {
                cout << "Введите количество элементов, из которых мы выбираем: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Ошибка: количество элементов должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "Введите количество элементов в каждом сочетании: ";
                cin >> k;
                if (k <= 0) {
                    cout << "Ошибка: количество элементов в каждом сочетании должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (k <= 0);

            cout << "Количество сочетаний с повторениями: " << CombinationWithRep(n, k) << endl << endl;
            break;
        }
        case 4: {
            system("cls");
            do {
                cout << "Введите количество элементов, из которых мы выбираем: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Ошибка: количество элементов должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "Введите количество элементов в каждом сочетании: ";
                cin >> k;
                if (k <= 0 || k > n) {
                    cout << "Ошибка: количество элементов в каждом сочетании должно быть положительным числом и не больше, чем общее количество элементов. Попробуйте ещё раз!" << endl << endl;
                }
            } while (k <= 0 || k > n);

            cout << "Количество сочетаний без повторений: " << CombinationWithoutRep(n, k) << endl << endl;
            break;
        }
        case 5: {
            system("cls");
            do {
                cout << "Введите количество элементов, которые нужно переставить: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Ошибка: количество элементов должно быть положительным числом. Попробуйте ещё раз!" << endl << endl;
                }
            } while (n <= 0);

            cout << "Количество перестановок с повторениями: " << RepeatedCombination(n) << endl << endl;
            break;
        }
        case 0:
            break;
        default:
            system("cls");
            cout << "Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl << endl;
            break;
        }
    } while (choice != 0);
    {
        return;
    }
}