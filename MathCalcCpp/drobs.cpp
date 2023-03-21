#define _CRT_SECURE_NO_WARNINGS
#include "Drobs.h"

using namespace std;

// Главное меню
void menuDrobs()
{
	int n;
	system("cls");
	do
	{
		cout << " Функции калькулятора обыкновенных дробей:" << endl
			<< " 1. Сложение дробей " << endl
			<< " 2. Вычитание дробей " << endl
			<< " 3. Умножение дробей " << endl
			<< " 4. Деление дробей " << endl
			<< " 5. Сравнение дробей " << endl
			<< " 6. Сокращение дроби " << endl
			<< " 7. Представление в виде десятичной дроби " << endl
			<< " 0. Выход " << endl
			<< endl << " Выберите функцию калькулятора : ";
		cin >> n;
		
		if ((n < 0) or (n > 7)) { cout << "  Введено неверное значение" << endl << endl; }
		
		cin.get();
		switch (n)
		{
		case 1: {Sum(); break; }
		case 2: {Razn(); break; }
		case 3: {Proizv(); break; }
		case 4: {Del(); break; }
		case 5: {Sravn(); break; }
		case 6: {Sokr(); break; }
		case 7: {DesDrob(); break; }
		case 0: { system("cls"); break; }
		default: break;
		}
	} while (n!=0);
}

// Поиск общего знаменателя
double OZ(int a, int b)
{
	if (a == 0)
		return b;
	return OZ(b % a, a);
}

// Наименьший общий знаменатель
double NOZ(int a, int b)
{
	return (a * b) / OZ(a, b);
}

// Готово
void Sum()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " Сложение" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " Введите первую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;

		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_1[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if (((FullDrob[i] == '0') and (FullDrob[i+1] != ',') and (FullDrob[i - 1] == '/') and (Zero == 0) and (t == 0)) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '-') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_1[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob1.chisl = atof(Chisl_1);
		EdinDrob1.znam = atof(Znam_1);

		if (EdinDrob1.chisl < 0)
		{
			EdinDrob1.chisl = -EdinDrob1.chisl;
			EdinDrob1.znak = 1;
		}
		if (EdinDrob1.znam < 0)
		{
			EdinDrob1.znam = -EdinDrob1.znam;
			if (EdinDrob1.znak == 1) { EdinDrob1.znak = 0; }
			else { EdinDrob1.znak = 1; }
		}

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " Введите вторую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		k = 0;
		t = 0;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_2[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_2[t] = FullDrob[i];
						t++;
					}
				}
			}
		}
		
		EdinDrob2.chisl = atof(Chisl_2);
		EdinDrob2.znam = atof(Znam_2);
		
		if (EdinDrob2.chisl < 0)
		{
			EdinDrob2.chisl = -EdinDrob2.chisl;
			EdinDrob2.znak = 1;
		}
		if (EdinDrob2.znam < 0)
		{
			EdinDrob2.znam = -EdinDrob2.znam;
			if (EdinDrob2.znak == 1) { EdinDrob2.znak = 0; }
			else { EdinDrob2.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	if (EdinDrob1.znam == EdinDrob2.znam) { ResDrob.znam = EdinDrob1.znam; }
	else
	{
		if ((EdinDrob1.znam < 1) or (EdinDrob2.znam < 1))
		{
			ResDrob.znam = EdinDrob1.znam * EdinDrob2.znam;
		}
		else { ResDrob.znam = NOZ(EdinDrob1.znam, EdinDrob2.znam); }
	}

	if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 1))
	{
		ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam/EdinDrob1.znam) + EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
		ResDrob.znak = 1;
	}
	else
	{
		if ((EdinDrob1.znak == 0) and (EdinDrob2.znak == 1))
		{
			ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
			if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) < EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam)) { ResDrob.znak = 1; }
			else { ResDrob.znak = 0; }
		}
		else
		{
			if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 0))
			{
				ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
				if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) > EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam)) { ResDrob.znak = 1; }
				else { ResDrob.znak = 0; }
			}
			else
			{
				ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) + EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
				ResDrob.znak = 0;
			}
		}
	}
	
	cout << " Результат вычислений: ";
	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void Razn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " Вычитание" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " Введите первую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_1[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if (((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '/') and (Zero == 0) and (t == 0)) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '-') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_1[t] = FullDrob[i];
						t++;
					}
				}
			}
		}
		
		EdinDrob1.chisl = atof(Chisl_1);
		EdinDrob1.znam = atof(Znam_1);
		
		if (EdinDrob1.chisl < 0)
		{
			EdinDrob1.chisl = -EdinDrob1.chisl;
			EdinDrob1.znak = 1;
		}
		if (EdinDrob1.znam < 0)
		{
			EdinDrob1.znam = -EdinDrob1.znam;
			if (EdinDrob1.znak == 1) { EdinDrob1.znak = 0; }
			else { EdinDrob1.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cin.get();
		cout << " Введите вторую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		k = 0;
		t = 0;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_2[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_2[t] = FullDrob[i];
						t++;
					}
				}
			}
		}
		
		EdinDrob2.chisl = atof(Chisl_2);
		EdinDrob2.znam = atof(Znam_2);
		
		if (EdinDrob2.chisl < 0)
		{
			EdinDrob2.chisl = -EdinDrob2.chisl;
			EdinDrob2.znak = 1;
		}
		if (EdinDrob2.znam < 0)
		{
			EdinDrob2.znam = -EdinDrob2.znam;
			if (EdinDrob2.znak == 1) { EdinDrob2.znak = 0; }
			else { EdinDrob2.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	if (EdinDrob1.znam == EdinDrob2.znam) { ResDrob.znam = EdinDrob1.znam; }
	else
	{
		if ((EdinDrob1.znam < 1) or (EdinDrob2.znam < 1))
		{
			ResDrob.znam = EdinDrob1.znam * EdinDrob2.znam;
		}
		else { ResDrob.znam = NOZ(EdinDrob1.znam, EdinDrob2.znam); }
	}
	if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 1))
	{
		ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
		if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) > EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam)) { ResDrob.znak == 1; }
		else {ResDrob.znak == 0; }
	}
	else
	{
		if ((EdinDrob1.znak == 0) and (EdinDrob2.znak == 0))
		{
			ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
			if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) < EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam)) { ResDrob.znak == 1; }
			else { ResDrob.znak == 0; }
		}
		else
		{
			if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 0))
			{
				ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
				ResDrob.znak = 1;
			}
			else
			{
				if ((EdinDrob1.znak == 0) and (EdinDrob2.znak == 1))
				{
					ResDrob.chisl = EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) - EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam);
					ResDrob.znak = 0;
				}
			}
		}
	}
	
	cout << " Результат вычислений: ";
	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void Proizv()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " Умножение " << endl << " =========" << endl;

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " Введите первую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;

		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_1[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if (((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '/') and (Zero == 0) and (t == 0)) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '-') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_1[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob1.chisl = atof(Chisl_1);
		EdinDrob1.znam = atof(Znam_1);

		if (EdinDrob1.chisl < 0)
		{
			EdinDrob1.chisl = -EdinDrob1.chisl;
			EdinDrob1.znak = 1;
		}
		if (EdinDrob1.znam < 0)
		{
			EdinDrob1.znam = -EdinDrob1.znam;
			if (EdinDrob1.znak == 1) { EdinDrob1.znak = 0; }
			else { EdinDrob1.znak = 1; }
		}

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " Введите вторую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		k = 0;
		t = 0;

		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_2[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_2[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob2.chisl = atof(Chisl_2);
		EdinDrob2.znam = atof(Znam_2);

		if (EdinDrob2.chisl < 0)
		{
			EdinDrob2.chisl = -EdinDrob2.chisl;
			EdinDrob2.znak = 1;
		}
		if (EdinDrob2.znam < 0)
		{
			EdinDrob2.znam = -EdinDrob2.znam;
			if (EdinDrob2.znak == 1) { EdinDrob2.znak = 0; }
			else { EdinDrob2.znak = 1; }
		}

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	cout << " Результат вычислений: ";
	ResDrob.chisl = EdinDrob1.chisl * EdinDrob2.chisl;
	ResDrob.znam = EdinDrob1.znam * EdinDrob2.znam;
	if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 0)) { ResDrob.znak = 1; }
	else
	{
		if ((EdinDrob1.znak == 0) and (EdinDrob2.znak == 1)) { ResDrob.znak = 1; }
		else { ResDrob.znak = 0; }
	}	
	
	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void Del()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " Деление " << endl << " =========" << endl;

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " Введите первую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;

		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_1[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if (((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '/') and (Zero == 0) and (t == 0)) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (FullDrob[i - 1] == '-') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_1[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob1.chisl = atof(Chisl_1);
		EdinDrob1.znam = atof(Znam_1);

		if (EdinDrob1.chisl < 0)
		{
			EdinDrob1.chisl = -EdinDrob1.chisl;
			EdinDrob1.znak = 1;
		}
		if (EdinDrob1.znam < 0)
		{
			EdinDrob1.znam = -EdinDrob1.znam;
			if (EdinDrob1.znak == 1) { EdinDrob1.znak = 0; }
			else { EdinDrob1.znak = 1; }
		}

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " Введите вторую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		k = 0;
		t = 0;

		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_2[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_2[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob2.chisl = atof(Chisl_2);
		EdinDrob2.znam = atof(Znam_2);

		if (EdinDrob2.chisl < 0)
		{
			EdinDrob2.chisl = -EdinDrob2.chisl;
			EdinDrob2.znak = 1;
		}
		if (EdinDrob2.znam < 0)
		{
			EdinDrob2.znam = -EdinDrob2.znam;
			if (EdinDrob2.znak == 1) { EdinDrob2.znak = 0; }
			else { EdinDrob2.znak = 1; }
		}

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	cout << " Результат вычислений: ";
	ResDrob.chisl = EdinDrob1.chisl * EdinDrob2.znam;
	ResDrob.znam = EdinDrob1.znam * EdinDrob2.chisl;
	if ((EdinDrob1.znak == 1) and (EdinDrob2.znak == 0)) { ResDrob.znak = 1; }
	else
	{
		if ((EdinDrob1.znak == 0) and (EdinDrob2.znak == 1)) { ResDrob.znak = 1; }
		else { ResDrob.znak = 0; }
	}

	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void Sravn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " Сравнение" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " Введите первую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_1[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_1[t] = FullDrob[i];
						t++;
					}
				}
			}
		}
		
		EdinDrob1.chisl = atof(Chisl_1);
		EdinDrob1.znam = atof(Znam_1);
		
		if (EdinDrob1.chisl < 0)
		{
			EdinDrob1.chisl = -EdinDrob1.chisl;
			EdinDrob1.znak = 1;
		}
		if (EdinDrob1.znam < 0)
		{
			EdinDrob1.znam = -EdinDrob1.znam;
			if (EdinDrob1.znak == 1) { EdinDrob1.znak = 0; }
			else { EdinDrob1.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " Введите вторую дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		k = 0;
		t = 0;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl_2[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam_2[t] = FullDrob[i];
						t++;
					}
				}
			}
		}
		
		EdinDrob2.chisl = atof(Chisl_2);
		EdinDrob2.znam = atof(Znam_2);
		
		if (EdinDrob2.chisl < 0)
		{
			EdinDrob2.chisl = -EdinDrob2.chisl;
			EdinDrob2.znak = 1;
		}
		if (EdinDrob2.znam < 0)
		{
			EdinDrob2.znam = -EdinDrob2.znam;
			if (EdinDrob2.znak == 1) { EdinDrob2.znak = 0; }
			else { EdinDrob2.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	if (EdinDrob1.znam == EdinDrob2.znam) { ResDrob.znam = EdinDrob1.znam; }
	else
	{
		if ((EdinDrob1.znam < 1) or (EdinDrob2.znam < 1))
		{
			ResDrob.znam = EdinDrob1.znam * EdinDrob2.znam;
		}
		else { ResDrob.znam = NOZ(EdinDrob1.znam, EdinDrob2.znam); }
	}

	if (EdinDrob1.znak > EdinDrob2.znak)
	{
		cout << " Дробь " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " больше чем дробь - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		if (EdinDrob1.znak < EdinDrob2.znak)
		{
			cout << " Дробь " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " больше чем дробь - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
		}
		else
		{
			if (EdinDrob1.znak == 1)
			{
				if (EdinDrob1.chisl < 0) { EdinDrob1.chisl = -EdinDrob1.chisl; }
				if (EdinDrob2.chisl < 0) { EdinDrob1.chisl = -EdinDrob2.chisl; }
				if (ResDrob.chisl < 0) { ResDrob.chisl = -ResDrob.chisl; }
				if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) < EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam))
				{
					cout << " Дробь - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " больше чем дробь - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
				}
				else
				{
					cout << " Дробь - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " больше чем дробь - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
				}
			}
			else
			{
				if (EdinDrob1.chisl < 0) { EdinDrob1.chisl = -EdinDrob1.chisl; }
				if (EdinDrob2.chisl < 0) { EdinDrob1.chisl = -EdinDrob2.chisl; }
				if (ResDrob.chisl < 0) { ResDrob.chisl = -ResDrob.chisl; }
				ResDrob.chisl = -ResDrob.chisl;
				if (EdinDrob1.chisl * (ResDrob.znam / EdinDrob1.znam) > EdinDrob2.chisl * (ResDrob.znam / EdinDrob2.znam))
				{
					cout << " Дробь " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " больше чем дробь " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
				}
				else
				{
					cout << " Дробь " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " больше чем дробь " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
				}
			}
		}
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void Sokr()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	DrobND EdinDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " Сокращение" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " Введите дробь в формате m/n" << endl;
		cout << " На ввод ожидается дробь с целочисленным числителем и знаменателем" << endl;
		cout << " => ";
		cin >> FullDrob;
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					Znam[t] = FullDrob[i];
					t++;
				}
			}
		}

		EdinDrob.chisl = atof(Chisl);
		EdinDrob.znam = atof(Znam);

		if (EdinDrob.chisl < 0)
		{
			EdinDrob.chisl = -EdinDrob.chisl;
			EdinDrob.znak = 1;
		}
		if (EdinDrob.znam < 0)
		{
			EdinDrob.znam = -EdinDrob.znam;
			if (EdinDrob.znak == 1) { EdinDrob.znak = 0; }
			else { EdinDrob.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));
	
	for (int i = 2; i <= EdinDrob.znam; i++)
	{
		if ((EdinDrob.chisl % i == 0) and (EdinDrob.znam % i == 0))
		{
			EdinDrob.chisl = EdinDrob.chisl/ i; 
			EdinDrob.znam = EdinDrob.znam / i;
			i = 1;
		}
	}
	
	cout << " Результат вычислений: ";
	if ((EdinDrob.znak == 1) and (EdinDrob.chisl > 0))
	{
		cout << '-' << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	else
	{
		cout << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}

// Готово
void DesDrob()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	Drob EdinDrob;
	double Res;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " Десятичная дробь" << endl << " ===================" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " Введите дробь в формате m/n" << endl;
		cout << " Вещественные числа вводите в формате y,xxx..." << endl;
		cout << " => ";
		cin >> FullDrob;
		
		
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			if ((Sl == 0) and (FullDrob[i] != '/'))
			{
				Chisl[k] = FullDrob[i];
				k++;
			}
			else
			{
				if (FullDrob[i] == '/')
				{
					if (Sl == 1) { AnSl = 1; }
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/') and (AnSl == 0))
				{
					if ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 0) or ((FullDrob[i] == '0') and (FullDrob[i + 1] != ',') and (Zero == 0) and (t == 1))) { Zero = 1; }
					else
					{
						Znam[t] = FullDrob[i];
						t++;
					}
				}
			}
		}

		EdinDrob.chisl = atof(Chisl);
		EdinDrob.znam = atof(Znam);

		if (EdinDrob.chisl < 0)
		{
			EdinDrob.chisl = -EdinDrob.chisl;
			EdinDrob.znak = 1;
		}
		if (EdinDrob.znam < 0)
		{
			EdinDrob.znam = -EdinDrob.znam;
			if (EdinDrob.znak == 1) { EdinDrob.znak = 0; }
			else { EdinDrob.znak = 1; }
		}
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " Введено неверное значение" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	Res = EdinDrob.chisl / EdinDrob.znam;

	cout << " Результат: ";
	if ((EdinDrob.znak == 1) and (EdinDrob.chisl > 0))
	{
		cout << '-' << Res << endl;
	}
	else
	{
		cout << Res << endl;
	}
	
	cout << " Для перехода в начальное меню нажмите любую клавишу: ";
	_getch();
	system("cls");
}