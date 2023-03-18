#include <iostream>
#include <locale>
#include "combinatorics.h"

using namespace std;

void menuComb() { // ��������
    setlocale(LC_ALL, "RUS");
    int choice;

    do {
        cout << "������� ����� �������, ������� ������ ������������" << endl;
        cout << "1. ���������� � ������������" << endl;
        cout << "2. ���������� ��� ����������" << endl;
        cout << "3. ��������� � ������������" << endl;
        cout << "4. ��������� ��� ����������" << endl;
        cout << "5. ������������" << endl;
        cout << "0. �����" << endl;
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
            cout << "�����..." << endl;
            break;
        default:
            cout << "�������� ����. ���������� ��� ���" << endl;
            break;
        }
    } while (choice != 0);
}

void PermutationWithRep() {
    cout << "���������� � ������������\n" << endl; // ��������
}

void PermutationmWithoutRep() {
    cout << "���������� ��� ����������\n" << endl; // ��������
}

void CombinationWithRep() {
    cout << "��������� � �����������\n" << endl; // ��������
}

void CombinationWithoutRep() {
    cout << "��������� ��� ���������\n" << endl; // ��������
}

void RepeatedCombination() {
    cout << "������������\n" << endl; // ��������
}