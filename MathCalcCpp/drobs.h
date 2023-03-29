#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>

struct Drob
{
	double chisl = 0;
	double znam = 0;
	int znak = 0;
};

struct DrobND
{
	int chisl = 0;
	int znam = 0;
	int znak = 0;
};

void menuDrobs();
void Sum();
void Razn();
void Proizv();
void Del();
void Sravn();
void Sokr();
void DesDrob();