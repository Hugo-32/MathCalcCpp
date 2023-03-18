#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <locale>
#include "Drobs.h"

using namespace std;

void menuDrobs()
{
	int n;
	system("cls");
	do
	{
		cout << " ¬ыберите функцию калькул€тора: ";
		cin >> n;
		if ((n < 1) or (n > 7)) { cout << " ¬ведено неверное значение" << endl; }
	} while ((n < 1) or (n > 7));
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
	default: break;
	}
}
void Sum()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	int Sl = 0;
	int k = 0, t = 0;
	do
	{
		cout << " ¬ведите первую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_1[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob1.chisl = atoi(Chisl_1);
		EdinDrob1.znam = atoi(Znam_1);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob1.znak == 1)
	{
		cout << '-' << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		cout << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}

	Sl = 0;
	do
	{
		cin.get();
		cout << " ¬ведите вторую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_2[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob2.chisl = atoi(Chisl_2);
		EdinDrob2.znam = atoi(Znam_2);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob2.znak == 1)
	{
		cout << '-' << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
	else
	{
		cout << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
}
void Razn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	int Sl = 0;
	int k = 0, t = 0;
	do
	{
		cout << " ¬ведите первую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_1[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob1.chisl = atoi(Chisl_1);
		EdinDrob1.znam = atoi(Znam_1);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob1.znak == 1)
	{
		cout << '-' << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		cout << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}

	Sl = 0;
	do
	{
		cin.get();
		cout << " ¬ведите вторую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_2[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob2.chisl = atoi(Chisl_2);
		EdinDrob2.znam = atoi(Znam_2);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob2.znak == 1)
	{
		cout << '-' << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
	else
	{
		cout << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
}
void Proizv()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	int Sl = 0;
	int k = 0, t = 0;
	do
	{
		cout << " ¬ведите первую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_1[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob1.chisl = atoi(Chisl_1);
		EdinDrob1.znam = atoi(Znam_1);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob1.znak == 1)
	{
		cout << '-' << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		cout << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}

	Sl = 0;
	do
	{
		cin.get();
		cout << " ¬ведите вторую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_2[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob2.chisl = atoi(Chisl_2);
		EdinDrob2.znam = atoi(Znam_2);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob2.znak == 1)
	{
		cout << '-' << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
	else
	{
		cout << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
}
void Del()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	int Sl = 0;
	int k = 0, t = 0;
	do
	{
		cout << " ¬ведите первую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_1[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob1.chisl = atoi(Chisl_1);
		EdinDrob1.znam = atoi(Znam_1);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob1.znak == 1)
	{
		cout << '-' << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		cout << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}

	Sl = 0;
	do
	{
		cin.get();
		cout << " ¬ведите вторую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_2[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob2.chisl = atoi(Chisl_2);
		EdinDrob2.znam = atoi(Znam_2);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob2.znak == 1)
	{
		cout << '-' << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
	else
	{
		cout << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
}
void Sravn()
{
	char FullDrob[255] = { 0 }, Znam_1[255] = { 0 }, Chisl_1[255] = { 0 }, Znam_2[255] = { 0 }, Chisl_2[255] = { 0 };
	Drob EdinDrob1;
	Drob EdinDrob2;
	int Sl = 0;
	int k = 0, t = 0;
	do
	{
		cout << " ¬ведите первую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_1[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob1.chisl = atoi(Chisl_1);
		EdinDrob1.znam = atoi(Znam_1);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob1.znak == 1)
	{
		cout << '-' << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}
	else
	{
		cout << EdinDrob1.chisl << " / " << EdinDrob1.znam << endl;
	}

	Sl = 0;
	do
	{
		cin.get();
		cout << " ¬ведите вторую дробь в формате m/n :";
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
					Sl = 1;
				}
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam_2[t] = FullDrob[i];
					t++;
				}
			}
		}
		EdinDrob2.chisl = atoi(Chisl_2);
		EdinDrob2.znam = atoi(Znam_2);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob2.znak == 1)
	{
		cout << '-' << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
	else
	{
		cout << EdinDrob2.chisl << " / " << EdinDrob2.znam << endl;
	}
}
void Sokr()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	Drob EdinDrob;
	int Sl = 0;
	do
	{
		cout << " ¬ведите дробь в формате m/n :";
		cin >> FullDrob;
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			int k = 0, t = 0;
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
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam[t] = FullDrob[i];
					t++;
				}
			}
		}

		EdinDrob.chisl = atoi(Chisl);
		EdinDrob.znam = atoi(Znam);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob.znak == 1)
	{
		cout << '-' << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	else
	{
		cout << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
}
void DesDrob()
{
	char FullDrob[255] = { 0 }, Znam[255] = { 0 }, Chisl[255] = { 0 };
	Drob EdinDrob;
	int Sl = 0;
	do
	{
		cout << " ¬ведите дробь в формате m/n :";
		cin >> FullDrob;
		for (int i = 0; i < strlen(FullDrob); i++)
		{
			int k = 0, t = 0;
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
				if ((Sl == 1) and (FullDrob[i] != '/'))
				{
					Znam[t] = FullDrob[i];
					t++;
				}
			}
		}

		EdinDrob.chisl = atoi(Chisl);
		EdinDrob.znam = atoi(Znam);
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
		if (Sl == 0) { cout << " ¬ведено неверное значение" << endl; }
	} while (Sl == 0);

	if (EdinDrob.znak == 1)
	{
		cout << '-' << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
	else
	{
		cout << EdinDrob.chisl << " / " << EdinDrob.znam << endl;
	}
}