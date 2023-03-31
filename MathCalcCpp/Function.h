#pragma once
#include <iostream>
#include <locale>
#include <SDL.h>
#include <math.h>
#include <conio.h>
#define Rl 0.001

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void Function();

void DefIntegral();
void Graph();
void Root();
void Extreme();

void Polinomial(double *Pol, int &N);
void DegreeF(double& a, double& b, double& c);
void IndexF(double& a, double& b, double& c, double& d);
void LogF(double& a, double& b, double& c);
void SinF(double& a, double& b, double& c, double& d);
void CosF(double& a, double& b, double& c, double& d);

double ResPolinomialF(const double *Pol, const int& N, const double &x);
double ResDegreeF(const double& a, const double& b, const double& c, const double& x);
double ResIndexF(const double& a, const double& b, const double& c, const double& d, const double& x);
double ResLogF(const double& a, const double& b, const double& c, const double& x);
double ResSinF(const double& a, const double& b, const double& c, const double& d, const double& x);
double ResCosF(const double& a, const double& b, const double& c, const double& d, const double& x);