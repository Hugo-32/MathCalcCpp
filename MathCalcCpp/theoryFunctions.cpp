//
//  theoryFunctions.cpp
//  �������� ����
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
		cout << "����������� ������ ����������� � �������������� ����������: " << endl;
		cout << endl;
		cout << "1. ���������� ����������� m/n" << endl;
		cout << "2. ������ ��������� ��� ����������� ������������� �������" << endl;
		cout << "3. �������������� �������� ��� ����������� ������������� �������" << endl;
		cout << "0. ����� � ������� ����";
		cout << endl;
		cout << endl << "�������� ����� ����: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			calculateProbability();
			break;
		case 2:
			system("cls");
			do
			{
				cout << "������� ������ �������: ";
				cin >> n;
				if (n <= 0)
				{
					cout << "������: ������ ������� �� ����� ���� ������������� ������ ��� ����. ���������� ��� ���!" << endl << endl;
				}
			} while (n <= 0);
			cout << "������� ��������, ������� ���� ������� � ������ ������" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "������� ������� " << i+1 << ": ";
				cin >> *(arr + i);
			}
			cout << "���������: " << calculateVariance(arr, n) << endl << endl;
			break;
		case 3:
			system("cls");
			do
			{
				cout << "������� ������ �������: ";
				cin >> n;
				if (n <= 0)
				{
					cout << "������: ������ ������� �� ����� ���� ������������� ������ ��� ����. ���������� ��� ���!" << endl << endl;
				}
			} while (n <= 0);
			cout << "������� ��������, ������� ���� ������� � ������ ������: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "������� ������� " << i + 1 << ": ";
				cin >> *(arr + i);
			}
			cout << "�������������� ��������: " << calculateMean(arr, n) << endl << endl;
			break;
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

void calculateProbability() 
{
	double m, n, p, q;

	do 
	{
		cout << "������� �������� ��� m: ";
		cin >> m;
		if (m <= 0) {
			cout << "������: �������� m ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
		}
	} while (m <= 0);

	do
	{
		cout << "������� �������� ��� n: ";
		cin >> n;
		if (n <= 0) {
			cout << "������: �������� n ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
		}
	} while (n < 0);

	do 
	{
		if (m > n)
		{
			cout << "������: �������� m ������ ���� ������ � ����� n. ���������� ��� ���!" << endl << endl;
			do
			{
				cout << "������� �������� ��� m: ";
				cin >> m;
				if (m <= 0) {
					cout << "������: �������� m ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
				}
			} while (m <= 0);
			do
			{
				cout << "������� �������� ��� n: ";
				cin >> n;
				if (n <= 0) {
					cout << "������: �������� n ������ ���� ������������� ������. ���������� ��� ���!" << endl << endl;
				}
			} while (n < 0);
		}
	} while (m > n);

	if (n == 0)
	{
		cout << "������������ ����, n �� ����� ���� ������ 0. ���������� �����!";
		return;
	}
	p = m / n;
	cout << "�����������: " << p << endl << endl;
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