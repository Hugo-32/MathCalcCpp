#define _CRT_SECURE_NO_WARNINGS
#include "Drobs.h"

using namespace std;

// ������� ����
void menuDrobs()
{
	int n;
	system("cls");
	do
	{
		cout << " ������� ������������ ������������ ������:" << endl
			<< " 1. �������� ������ " << endl
			<< " 2. ��������� ������ " << endl
			<< " 3. ��������� ������ " << endl
			<< " 4. ������� ������ " << endl
			<< " 5. ��������� ������ " << endl
			<< " 6. ���������� ����� " << endl
			<< " 7. ������������� � ���� ���������� ����� " << endl
			<< " 0. ����� " << endl
			<< endl << " �������� ������� ������������ : ";
		cin >> n;
		
		if ((n < 0) or (n > 7)) { cout << "  ������� �������� ��������" << endl << endl; }
		
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

// ����� ������ �����������
double OZ(int a, int b)
{
	if (a == 0)
		return b;
	return OZ(b % a, a);
}

// ���������� ����� �����������
double NOZ(int a, int b)
{
	return (a * b) / OZ(a, b);
}

// ������
void Sum()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " ��������" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
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
	
	cout << " ��������� ����������: ";
	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void Razn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " ���������" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cin.get();
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
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
	
	cout << " ��������� ����������: ";
	if ((ResDrob.znak == 1) and (ResDrob.chisl > 0))
	{
		cout << '-' << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	else
	{
		cout << ResDrob.chisl << " / " << ResDrob.znam << endl;
	}
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void Proizv()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " ��������� " << endl << " =========" << endl;

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	cout << " ��������� ����������: ";
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
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void Del()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;

	system("cls");
	cout << " ������� " << endl << " =========" << endl;

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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

		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	cout << " ��������� ����������: ";
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
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void Sravn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	Drob ResDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " ���������" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;

		cin.get();
		cout << " ������� ������ ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
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
		cout << " ����� " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " ������ ��� ����� - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		if (EdinDrob1.znak < EdinDrob2.znak)
		{
			cout << " ����� " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " ������ ��� ����� - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
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
					cout << " ����� - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " ������ ��� ����� - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
				}
				else
				{
					cout << " ����� - " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " ������ ��� ����� - " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
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
					cout << " ����� " << EdinDrob1.chisl << " / " << EdinDrob1.znam << " ������ ��� ����� " << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
				}
				else
				{
					cout << " ����� " << EdinDrob2.chisl << " / " << EdinDrob2.znam << " ������ ��� ����� " << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
				}
			}
		}
	}
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void Sokr()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	DrobND EdinDrob;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " ����������" << endl << " =========" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " ������� ����� � ������� m/n" << endl;
		cout << " �� ���� ��������� ����� � ������������� ���������� � ������������" << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
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
	
	cout << " ��������� ����������: ";
	if ((EdinDrob.znak == 1) and (EdinDrob.chisl > 0))
	{
		cout << '-' << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	else
	{
		cout << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}

// ������
void DesDrob()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	Drob EdinDrob;
	double Res;
	int Sl = 0, Zero = 0, AnSl = 0;
	int k = 0, t = 0;
	
	system("cls");
	cout << " ���������� �����" << endl << " ===================" << endl;
	
	do
	{
		Sl = 0;
		Zero = 0;
		AnSl = 0;
		k = 0;
		t = 0;
		
		cout << " ������� ����� � ������� m/n" << endl;
		cout << " ������������ ����� ������� � ������� y,xxx..." << endl;
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
		
		if ((Sl == 0) or (Zero == 1) or (AnSl == 1)) { cout << " ������� �������� ��������" << endl; }
	} while ((Sl == 0) or (Zero == 1) or (AnSl == 1));

	Res = EdinDrob.chisl / EdinDrob.znam;

	cout << " ���������: ";
	if ((EdinDrob.znak == 1) and (EdinDrob.chisl > 0))
	{
		cout << '-' << Res << endl;
	}
	else
	{
		cout << Res << endl;
	}
	
	cout << " ��� �������� � ��������� ���� ������� ����� �������: ";
	_getch();
	system("cls");
}