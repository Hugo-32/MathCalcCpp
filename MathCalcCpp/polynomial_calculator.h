//
//  polynomial_calculator.h
//  Меркулов Н.С.
//

#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<double> input_polynomial();
void print_polynomial(vector<double>& coefficients);
vector<double> add_polynomials(vector<double>& a, vector<double>& b);
vector<double> subtract_polynomials(vector<double>& a, const vector<double>& b);
vector<double> multiply_polynomials(vector<double>& a, vector<double>& b);
vector<double> multiply_polynomial_by_num(vector<double>& a, double& k);
vector<double> div_polynomials(vector<double>& a, vector<double>& b);
vector<double> calculate_derivative(vector<double>& a);
void menuPolynomial();