#include <iostream>
#include "polynomial_calculator.h"
#include <locale>

using namespace std;

void menuPolinom() // ��������
{
    setlocale(LC_ALL, "Russian");
    int n;
    do {
        cout << "����������� �����������\n";
        cout << "---------------------\n";
        cout << "1. ������� ����������� � �������\n";
        cout << "2. �������� �����������\n";
        cout << "3. ��������� �����������\n";
        cout << "4. ��������� �����������\n";
        cout << "5. ��������� ���������� �� �����\n";
        cout << "6. ���������� ����������� �� ����������\n";
        cout << "0. ����� � ������� ����\n";
        cout << "---------------------\n";
        cout << "�������� ����� (1-6) ��� 0, ����� ����� � ������� ����: "; cin >> n;
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

void div_polynominals() // ������� ����������� � ������� // ��������
{}
void add_polynominals() // �������� ����������� // ��������
{}
void subtract_polynominals() // ��������� ����������� // ��������
{}
void mulitply_polynominals() // ��������� ����������� // ��������
{}
void multiply_polynominals_by_num() // ��������� ���������� �� ����� // ��������
{}
void calculate_derivative() // ���������� ����������� �� ���������� // ��������
{}