#include <iostream>
#include "theoryFunctions.h"
#include <locale>

using namespace std;

void menuProbability() // ��������
{
	setlocale(LC_ALL, "Rus");

	int choice;

	do
	{
		cout << "1. ���������� ����������� m/n" << endl;
		cout << "2. ������ ��������� ��� ����������� ������������� �������" << endl;
		cout << "3. �������������� �������� ��� ����������� ������������� �������" << endl;
		cout << "0. �����";
		cout << endl;
		cout << "�������� ����� ����: ";
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
			cout << "����� �� ���������." << endl;
			break;
		default:
			cout << "������: �������� ����� ����." << endl;
			break;
		}
	} while (choice != 0);
	{
		return;
	}
}

void calculateProbability() // ��������
{
	cout << "������ �����������" << endl;
}
void calculateVariance() // ��������
{
	cout << "������ ���������" << endl;
}
void calculateMean() // ��������
{
	cout << "������ ��������������� ��������" << endl;
}