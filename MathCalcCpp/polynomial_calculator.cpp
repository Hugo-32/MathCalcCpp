//
//  polynomial_calculator.cpp
//  �������� �������
//

#include "polynomial_calculator.h"

// ����
vector<double> input_polynomial()
{
	int n;
	cout << "������� �������� ������� ��� ������� ���������: ";
	cin >> n;
	vector<double> coefficients(n + 1);
	cout << "������� ������������ ��� ������� ��������� � ������� �� ������ �� ������ �������: ";
	for (int i = n; i >= 0; i--) {
		cin >> coefficients[i];
	}
	return coefficients;
}

// �����
void print_polynomial(vector<double>& coefficients)
{
	int degree = coefficients.size() - 1;
	for (int i = degree; i >= 0; i--) {
		if (coefficients[i] == 0) continue;
		if (i == degree) {
			if (coefficients[i] == 1) cout << "x^" << i;
			else if (coefficients[i] == -1) cout << "-x^" << i;
			else cout << coefficients[i] << "x^" << i;
		}
		else if (i == 1) {
			if (coefficients[i] == 1) cout << " + x";
			else if (coefficients[i] == -1) cout << " - x";
			else if (coefficients[i] > 0) cout << " + " << coefficients[i] << "x";
			else cout << " - " << -coefficients[i] << "x";
		}
		else if (i == 0) {
			if (coefficients[i] < 0) cout << " - " << i;
			else cout << " + " << coefficients[i];
		}
		else if (coefficients[i] == 1) cout << " + x^" << i;
		else if (coefficients[i] == -1) cout << " - x^" << i;
		else if (coefficients[i] > 0) cout << " + " << coefficients[i] << "x^" << i;
		else cout << " - " << -coefficients[i] << "x^" << i;
	}
	cout << endl;
}

// ��������
vector<double> add_polynomials(vector<double>& a, vector<double>& b)
{
	vector<double> c(max(a.size(), b.size()));
	for (int i = 0; i < c.size(); i++) {
		double x = 0;
		if (i < a.size()) x += a[i];
		if (i < b.size()) x += b[i];
		c[i] = x;
	}
	return c;
}

// ���������
vector<double> subtract_polynomials(vector<double>& a, const vector<double>& b)
{
	vector<double> c(max(a.size(), b.size()));
	for (int i = 0; i < c.size(); i++) {
		double x = 0;
		if (i < a.size()) x += a[i];
		if (i < b.size()) x -= b[i];
		c[i] = x;
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

// ���������
vector<double> multiply_polynomials(vector<double>& a, vector<double>& b)
{
	int n = a.size() + b.size() - 1;
	vector<double> c(n);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

// ��������� �� �����
vector<double> multiply_polynomial_by_num(vector<double>& a, double& k)
{
	vector<double> c(a.size());
	for (int i = 0; i < a.size(); i++) {
		c[i] = a[i] * k;
	}
	return c;
}

// ������� � �������
vector<double> div_polynomials(vector<double>& a, vector<double>& b)
{
	int n = a.size() - 1, m = b.size() - 1;
	vector<double> q(n - m + 1), r(a);
	for (int k = n - m; k >= 0; k--) {
		q[k] = r[m + k] / b[m];
		for (int i = m + k - 1; i >= k; i--) {
			r[i] -= q[k] * b[i - k];
		}
	}
	while (r.size() > 1 && r.back() == 0) r.pop_back();
	return q;
}

// ���������� �����������
vector<double> calculate_derivative(vector<double>& a)
{
	int n = a.size() - 1;
	vector<double> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = (i + 1) * a[i + 1];
	}
	return b;
}

void menuPolynomial()
{
	setlocale(LC_ALL, "Russian");
	int mode;
	system("cls");
	do {
		cout << "����������� �����������: " << endl << endl;
		cout << "1. �������� �����������\n";
		cout << "2. ��������� �����������\n";
		cout << "3. ��������� �����������\n";
		cout << "4. ��������� ���������� �� �����\n";
		cout << "5. ������� ����������� � �������\n";
		cout << "6. ���������� ����������� �� ����������\n";
		cout << "0. ����� � ������� ����\n";
		cout << endl << "�������� ����� ����: ";
		cin >> mode;
		switch (mode) {
		case 1: {
			system("cls");
			vector<double> a = input_polynomial();
			vector<double> b = input_polynomial();
			vector<double> c = add_polynomials(a, b);
			cout << "�����: ";
			print_polynomial(c);
			break;
		}
		case 2: {
			system("cls");
			vector<double> a = input_polynomial();
			vector<double> b = input_polynomial();
			vector<double> c = subtract_polynomials(a, b);
			cout << "��������: ";
			print_polynomial(c);
			break;
		}
		case 3: {
			system("cls");
			vector<double> a = input_polynomial();
			vector<double> b = input_polynomial();
			vector<double> c = multiply_polynomials(a, b);
			cout << "������������: ";
			print_polynomial(c);
			break;
		}
		case 4: {
			system("cls");
			vector<double> a = input_polynomial();
			double k;
			cout << "������� �����, �� ������� ������� �������� ���������: ";
			cin >> k;
			vector<double> c = multiply_polynomial_by_num(a, k);
			cout << "���������: ";
			print_polynomial(c);
			break;
		}
		case 5: {
			system("cls");
			vector<double> a = input_polynomial();
			vector<double> b = input_polynomial();
			vector<double> quotient = div_polynomials(a, b);
			vector<double> remainder = subtract_polynomials(a, multiply_polynomials(b, quotient));
			cout << "�������: ";
			print_polynomial(quotient);
			cout << "������� �� �������: ";
			if (remainder[0] == 0) cout << "�����������.";
			else print_polynomial(remainder);
			break;
		}
		case 6: {
			system("cls");
			vector<double> a = input_polynomial();
			vector<double> b = calculate_derivative(a);
			cout << "�����������: ";
			print_polynomial(b);
			break;
		}
		case 0: 
		{
			break;
		}
		default:
			system("cls");
			cout << "������: �������� ����� ����. ���������� ��� ���!" << endl;
			break;
		}
	} while (mode != 0);
	{
		return;
	}
}