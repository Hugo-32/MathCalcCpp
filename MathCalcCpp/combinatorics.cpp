//
//  combinatorics.cpp
//  �������� ����
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
        cout << "������� ����� �������, ������� ������ ������������" << endl;
        cout << "1. ���������� � ������������" << endl;
        cout << "2. ���������� ��� ����������" << endl;
        cout << "3. ��������� � ������������" << endl;
        cout << "4. ��������� ��� ����������" << endl;
        cout << "5. ������������" << endl;
        cout << "0. ����� � ������� ����";
        cout << endl;
        cout << endl << "�������� ����� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            do {
                cout << "������� ���������� ���������, �� ������� �� ��������: ";
                cin >> n;
                if (n <= 0) {
                    cout << "������: ���������� ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "������� ���������� ��������� � ������ ����������: ";
                cin >> k;
                if (k <= 0) {
                    cout << "������: ���������� ��������� � ������ ���������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (k <= 0);

            cout << "���������� ���������� � ������������: " << PermutationWithRep(n, k) << endl << endl;
            break;
        }
        case 2: {
            system("cls");
            do {
                cout << "������� ���������� ���������, �� ������� �� ��������: ";
                cin >> n;
                if (n <= 0) {
                    cout << "������: ���������� ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "������� ���������� ��������� � ������ ����������: ";
                cin >> k;
                if (k <= 0 || k > n) {
                    cout << "������: ���������� ��������� � ������ ���������� ������ ���� ������������� ������ � �� ������, ��� ����� ���������� ���������. ���������� ��� ���!" << endl << endl;
                }
            } while (k <= 0 || k > n);

            cout << "���������� ���������� ��� ����������: " << PermutationWithoutRep(n, k) << endl << endl;
            break;
        }
        case 3: {
            system("cls");
            do {
                cout << "������� ���������� ���������, �� ������� �� ��������: ";
                cin >> n;
                if (n <= 0) {
                    cout << "������: ���������� ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "������� ���������� ��������� � ������ ���������: ";
                cin >> k;
                if (k <= 0) {
                    cout << "������: ���������� ��������� � ������ ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (k <= 0);

            cout << "���������� ��������� � ������������: " << CombinationWithRep(n, k) << endl << endl;
            break;
        }
        case 4: {
            system("cls");
            do {
                cout << "������� ���������� ���������, �� ������� �� ��������: ";
                cin >> n;
                if (n <= 0) {
                    cout << "������: ���������� ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (n <= 0);

            do {
                cout << "������� ���������� ��������� � ������ ���������: ";
                cin >> k;
                if (k <= 0 || k > n) {
                    cout << "������: ���������� ��������� � ������ ��������� ������ ���� ������������� ������ � �� ������, ��� ����� ���������� ���������. ���������� ��� ���!" << endl << endl;
                }
            } while (k <= 0 || k > n);

            cout << "���������� ��������� ��� ����������: " << CombinationWithoutRep(n, k) << endl << endl;
            break;
        }
        case 5: {
            system("cls");
            do {
                cout << "������� ���������� ���������, ������� ����� �����������: ";
                cin >> n;
                if (n <= 0) {
                    cout << "������: ���������� ��������� ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
                }
            } while (n <= 0);

            cout << "���������� ������������ � ������������: " << RepeatedCombination(n) << endl << endl;
            break;
        }
        case 0:
            break;
        default:
            system("cls");
            cout << "������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
            break;
        }
    } while (choice != 0);
    {
        return;
    }
}